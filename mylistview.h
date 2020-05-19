#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QListView>
#include <QDebug>
#include <QModelIndex>
#include <logging.h>
#include <QMouseEvent>
#include <QListWidgetItem>

class myListView : public QListView
{
    Q_OBJECT
public:
    myListView(QWidget *parent = 0);
    void mouseDoubleClickEvent(QMouseEvent* event);
    void setOpenFileSettings(std::string,std::string);
protected:

private:
     Qt::MouseButton m_button;
     std::string folderPath;
     std::string searchWord;
private slots:

public slots:
    void slot_doubleClick(QListWidgetItem* item, int column);

signals:
    void itemDoubleClicked(QListWidgetItem* item, int column);

};

#endif // MYLISTVIEW_H
