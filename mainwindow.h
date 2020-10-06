#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>
#include<BShelf.h>
#include<PrintBook.h>
#include<Shelf.h>
#include<QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_addbookshelf_clicked();

    void on_listWidget_bookshelf_itemClicked(QListWidgetItem *item);

    void on_pushButton_addshelf_clicked();

private:
    Ui::MainWindow *ui;
   vector<BookShelf> bookshelfs;
   int shelfID
};
#endif // MAINWINDOW_H
