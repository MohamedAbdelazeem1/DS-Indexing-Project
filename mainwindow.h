#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMouseEvent>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>
#include <QDesktopWidget>
#include "needed_functions.h"
#include <QStatusBar>
#include "trie.h"
#include "mylistview.h"
#include "logging.h"

extern QStringList filesList;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Trie        * head;
    QWidget     * mainWidget;
    QHBoxLayout * mainLayout;
    QVBoxLayout * firstLayout;
    QVBoxLayout * secondLayout;
    QHBoxLayout * pathLayout;
    QHBoxLayout * searchLayout;
    QPushButton * startIndexing;
    QPushButton * selectFolder;
    QPushButton * search;
    QLineEdit   * pathText;
    QLineEdit   * wordText;
    QFileSystemModel * directoryModel;
    QFileSystemModel * resultModel;

    QTreeView   * tree;
    myListView   *resultList;
    //QTextEdit   * logging;
    QFileDialog * pathDialog;
    //QStatusBar  * logging;
    logging * newWindow;
    void draw();
private slots:
    void on_search_clicked();
    void on_startIndexing_clicked();
    void on_selectFolder_clicked();
    void on_doubleclick_tree(QModelIndex);
};

#endif // MAINWINDOW_H
