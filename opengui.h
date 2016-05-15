#ifndef OPENGUI_H
#define OPENGUI_H

#include <QWidget>

#include "QKeyEvent"
#include "QPoint"
#include "QMediaPlayer"
#include "QTime"
#include "QApplication"
#include "QTimer"
#include "QString"
#include "QMessageBox"
#include "time.h"

namespace Ui {
class OpenGUI;
}

class OpenGUI : public QWidget
{
    Q_OBJECT

public:
    explicit OpenGUI(QWidget *parent = 0);
    void setup();
    void taikorun();
    void EndDL();

    ~OpenGUI();

private slots:

    void DingT();

private:
    Ui::OpenGUI *ui;
    void keyPressEvent(QKeyEvent*);
    void Event(QEvent*);
    void wait(unsigned int msec);
    QMediaPlayer *player;
    QTime t;
    QTimer *timer;
    QMessageBox meg;
    int DouT;
    int n,m;
    int score;
    int cnt=0 ;
    int combo=0 ;
};

#endif // OPENGUI_H
