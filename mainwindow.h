#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opengui.h"
#include "about.h"

#include <QMediaPlayer>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_start_clicked();

    void on_about_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    OpenGUI ou;
    about abt;
};

#endif // MAINWINDOW_H
