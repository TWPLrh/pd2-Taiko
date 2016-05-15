#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    //  BGM播放
    player = new QMediaPlayer(this);
    player ->setMedia(QUrl("qrc:/main/title04.mp3"));
    setFixedSize(800,545);

    player -> play();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked()
{
    this->close();
    ou.show();
    player->stop();
    ou.setup();
}

void MainWindow::on_about_clicked()
{
    abt.show();
}

void MainWindow::on_exit_clicked()
{
    this->close();
}
