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
    directoryModel = new QFileSystemModel;
    tree         = new QTreeView();
    resultModel  = new QFileSystemModel;
    resultList       = new myListView;
    pathDialog   = new QFileDialog;

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
    connect(startIndexing,SIGNAL(pressed()),this,SLOT(on_startIndexing_clicked()));
    connect(selectFolder,SIGNAL(pressed()),this,SLOT(on_selectFolder_clicked()));

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


}



void MainWindow::on_search_clicked(){
    map <string,int> result = head->search(wordText->text().toStdString());
    QStringList filters;
    if(result.empty()){
        qDebug() << "Word Not Found";
        filters << "*.php";
    }

    map<string,int>::iterator it=result.begin();
    resultModel->setFilter( QDir::NoDotAndDotDot | QDir::Files );
    resultModel->setRootPath(pathText->text());
    resultList->setRootIndex(resultModel->index(pathText->text()));


    while(it != result.end()){
        filters << QString::fromStdString(it->first);
        qDebug() << QString::fromStdString(it->first);
        qDebug() << it->second;
        it++;
    }
    resultModel->setNameFilters(filters);
    resultModel->setNameFilterDisables(false);

    resultList->setOpenFileSettings(pathText->text().toStdString(),wordText->text().toStdString());




}

void MainWindow::on_startIndexing_clicked(){

    QDir myDir(pathText->text());

    filesList = myDir.entryList(QStringList() << "*.txt",QDir::Files);
    free (head);
    head = new Trie();

    for(int i=0;i<filesList.size();i++){
        QFile testFile(myDir.path()+"/"+filesList[i]);

        qInfo() << ("Currently Indexing File"+filesList[i]);
        indexFile(testFile.fileName().toStdString(),head);
    }
}


void MainWindow::on_doubleclick_tree(QModelIndex current){
    qDebug() << "hey";
}

