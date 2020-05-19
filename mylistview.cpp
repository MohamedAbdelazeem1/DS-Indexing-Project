#include "mylistview.h"

myListView::myListView(QWidget *parent) : QListView(parent)
{

    m_button = Qt::NoButton;
    connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem*, int)),
            this, SLOT(slot_doubleClick(QListWidgetItem*,int)));
}


void myListView::mouseDoubleClickEvent(QMouseEvent* event){

            m_button = event->button();
            if(event==nullptr)return;
            QModelIndex idx = QListView::indexAt(event->pos());

            logging * fileOpen = new logging(folderPath+"\\"+idx.data().toString().toStdString(),searchWord);
            fileOpen->show();
            qDebug()<<"File " + idx.data().toString();
}


void myListView::setOpenFileSettings(std::string Path,std::string Word){
    folderPath = Path;
    searchWord = Word;
}

void myListView::slot_doubleClick(QListWidgetItem* item, int column){
    qDebug()<<"nooo";
}




