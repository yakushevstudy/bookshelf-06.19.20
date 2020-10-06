#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Начальное состояние интерфейса
    ui->groupBox_books->setEnabled(false);
    ui->groupBox_shelfs->setEnabled(false);
    ui->pushButton_delbookshelf->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_addbookshelf_clicked()
{
    //Создаем объект шкаф
    BookShelf bshelf;
    //Добавить объект в вектор
    bookshelfs.push_back(bshelf);
    int size = bookshelfs.size();
    ui->listWidget_bookshelf->addItem(QString::number(size));
}

void MainWindow::on_listWidget_bookshelf_itemClicked(QListWidgetItem *item)
{
    //Активация списка полок
    ui->listWidget_shelfs->setEnabled(true);
    //Получение кол-ва полок
    int N=item->text().toInt();
    int shelfN = bookshelfs[N-1].getShelfs();
    if(shelfN){
        for(int i = 0; i<shelfN;i++){
            ui->listWidget_shelfs->addItem(QString::number(i+1));

        }
    }
    //Запомните выбранный шкаф
    shelfID=N;
}


void MainWindow::on_pushButton_addshelf_clicked()
{
    bookshelfs[shelfID-1].addShelf();
    int shelfN = bookshelfs[shelfID-1].getShelfs();
    ui->listWidget_shelfs->addItem(QString::number(shelfN));
}
