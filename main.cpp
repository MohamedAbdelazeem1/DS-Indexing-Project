#include "mainwindow.h"
#include <QApplication>
#include "QDebug"
#include "math.h"
#include "trie.h"
#include "needed_functions.h"
#include "QDir"
#include "QFile"
#include "bst.h"


QStringList filesList;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QDir myDir("C:/Users/Mohamed Abdullah/Downloads/Compressed/questions/questions");

//    QStringList filesList = myDir.entryList(QStringList() << "*.txt",QDir::Files);
//    qDebug() << filesList;
//    qDebug() << myDir.path();
//    for(int i=0;i<filesList.size();i++){
//        QFile testFile(myDir.path()+"/"+filesList[i]);
//        qDebug () << testFile.fileName();
//        indexFile(testFile.fileName().toStdString(),head);
//    }

//    map <string,int> temp = head->search("what");
//    map<string,int>::iterator it=temp.begin();
//    while(it != temp.end()){
//        qDebug() << QString::fromStdString(it->first);
//        qDebug() << it->second;
//        it++;
//    }



//    BST myTree;
//    myTree.insert("5");
//    myTree.insert("4");
//    myTree.insert("7");
//    myTree.insert("1");
//    myTree.insert("2");
//    myTree.insert("9");
//    myTree.insert("3");
//    myTree.insert("3");
//    myTree.insert("8");
//    myTree.insert("9");
//    vector <string> temp = myTree.traverse_tree();
//    for(int i=0;i<temp.size();i++){
//        qDebug() << QString::fromStdString(temp[i]);
//    }

    MainWindow w;
    w.show();
    return a.exec();
}
