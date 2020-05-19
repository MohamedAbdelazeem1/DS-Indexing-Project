#ifndef LOGGING_H
#define LOGGING_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QStatusBar>
#include <QTextEdit>
#include <QBoxLayout>
#include "docviewer.h"
#include <iostream>
extern QStringList filesList;

class logging : public QDialog
{
    Q_OBJECT

public:
    explicit logging(std::string filePath , std::string word,QWidget *parent = nullptr);
    ~logging();

private:
    QStatusBar * status;
    QTextEdit  * logger;
    QVBoxLayout * mainLayout;
    QTextEdit *editor;
    void draw();
};
#endif // LOGGING_H
