#include "logging.h"

logging::logging(std::string filePath , std::string word,QWidget *parent) : QDialog(parent)
{

    docViewer * myViewer;

    mainLayout = new QVBoxLayout;
    editor = new QTextEdit();
    QString qFilePath = QString::fromStdString(filePath);
    editor->setDocumentTitle(QString::fromStdString(filePath.substr(filePath.find_last_of("/")+1)));
    QFile file(qFilePath);
    //QFile file("test.txt");

    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream ReadFile(&file);
    editor->setText(ReadFile.readAll());
    myViewer = new docViewer(editor->document());
    myViewer->addRule(word);
    this->setLayout(mainLayout);
    mainLayout->addWidget(editor);
    this->setWindowTitle(QString::fromStdString(filePath.substr(filePath.find_last_of("\\")+1)));


}



logging::~logging(){

}

void logging::draw(){

}
