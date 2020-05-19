#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget   = new QWidget;
    mainLayout   = new QHBoxLayout;
    firstLayout  = new QVBoxLayout;
    secondLayout = new QVBoxLayout;
    pathLayout   = new QHBoxLayout;
    searchLayout = new QHBoxLayout;
    selectFolder = new QPushButton;
    startIndexing =new QPushButton;
    search       = new QPushButton;
    pathText     = new QLineEdit;
    wordText     = new QLineEdit;
    resultLabel  = new QLabel;
    directoryModel = new QFileSystemModel;
    tree         = new QTreeView();
    resultModel  = new QFileSystemModel;
    resultList       = new myListView;
    pathDialog   = new QFileDialog;
    indexable = false;

    head = new Trie();

    selectFolder->setText("Select Folder");
    pathText->setPlaceholderText("Folder Path");
    search->setText("Search");
    startIndexing->setText("Start Indexing");
    wordText->setPlaceholderText("Word");
    pathDialog->setFileMode(QFileDialog::Directory);
    tree->setModel(directoryModel);
    resultList->setModel(resultModel);

    draw();
    connect(search,SIGNAL(pressed()),this,SLOT(on_search_clicked()));
    connect(startIndexing,SIGNAL(clicked()),this,SLOT(on_startIndexing_clicked()));
    connect(selectFolder,SIGNAL(pressed()),this,SLOT(on_selectFolder_clicked()));
    this->setStyleSheet("QLabel{font-weight:bold;font-size:25px;}");


}

MainWindow::~MainWindow()
{

}

void MainWindow::draw(){
    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);
    firstLayout->addWidget(selectFolder);
    firstLayout->addWidget(tree);
    secondLayout->addLayout(pathLayout);
    pathLayout->addWidget(pathText);
    pathLayout->addWidget(startIndexing);
    secondLayout->addLayout(searchLayout);
    searchLayout->addWidget(wordText);
    searchLayout->addWidget(search);
    secondLayout->addWidget(resultLabel);
    resultLabel->setText("");
    secondLayout->addWidget(resultList);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.47);

    //secondLayout->addWidget(logging);
    //this->setStatusBar(logging);
    //logging->showMessage("Ready");

}

void MainWindow::on_selectFolder_clicked(){
    pathText->setText(pathDialog->getExistingDirectory(this, tr("Open Directory"),
                                                       "/home",
                                                       QFileDialog::ShowDirsOnly
                                                       | QFileDialog::DontResolveSymlinks));
     directoryModel->setRootPath(pathText->text());
     tree->setRootIndex(directoryModel->index(pathText->text()));
     indexable = true;


}



void MainWindow::on_search_clicked(){
    list<string> * result = head->search(wordText->text().toStdString());
    QStringList filters;
    if(result==nullptr || (*result).size() == 0){
        qDebug() << "Word Not Found";
        filters << "*.php";
        resultLabel->setText("Word Not Found");
    }
    else if((*result).size()>=1){
        resultLabel->setText("Word Found in " + QString::number(result->size()) +" File(s)");
        list<string>::iterator it=(*result).begin();
        while(it!=(*result).end()){
            filters << QString::fromStdString(*it);
            std::cout << (*it) << endl;
            it++;
        }
    }

    resultModel->setFilter( QDir::NoDotAndDotDot | QDir::Files );
    resultModel->setRootPath(pathText->text());
    resultList->setRootIndex(resultModel->index(pathText->text()));

    resultModel->setNameFilters(filters);
    resultModel->setNameFilterDisables(false);

    resultList->setOpenFileSettings(pathText->text().toStdString(),wordText->text().toStdString());

}

void MainWindow::on_startIndexing_clicked(){
    if(indexable){
        indexable = false;
        DIR * mydir;
        QDir qdir = pathText->text();
        struct dirent *ent;
        free (head);
        head = new Trie();
        char * direc = pathText->text().toLocal8Bit().data();
        if ((mydir = opendir (direc)) != nullptr) {
          /* print all the files and directories within directory */
          float i=0;
          int count = qdir.count();
          string x;
          while ((ent = readdir (mydir)) != nullptr) {
              x = ent->d_name;
              if(x.length() >2 && x.substr(x.length()-3)=="txt"){
                  indexFile((pathText->text().toStdString()+"/"+ent->d_name),head);
                  i++;
                  std::cout << "currently indexing " + x + "          Progess= " << (i/(count-2)*100) <<"%" <<endl ;
              }
          }
          closedir (mydir);
        }
    }
}


void MainWindow::on_doubleclick_tree(QModelIndex current){
    qDebug() << "hey";
}

