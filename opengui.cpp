#include "opengui.h"
#include "ui_opengui.h"

OpenGUI::OpenGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenGUI)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->red->hide();

    ui->blue->hide();

    ui->num_1->hide();
    ui->num_2->hide();
    ui->num_3->hide();
    ui->sta->hide();
    ui->good->hide();
    ui->bad->hide();


    ui->test->setAutoFillBackground (true);
    QPalette test = palette();
    test.setColor(QPalette::Background, QColor(0,0,0,195));
    setPalette (test);

    player = new QMediaPlayer(this);
    timer = new QTimer(this);
}

OpenGUI::~OpenGUI()
{
    delete ui;
}

void OpenGUI::keyPressEvent(QKeyEvent *event){

   while (event->key() == Qt::Key_J){
        if( (ui->red->x()>159||ui->red->x()<129) && ui->red->x() < 730){
        combo = 0;
        score = score - 1;
        ui->red->move(69,149);
        ui->red->hide();
    /*    ui->cat_2->hide();
        ui->cat->show();
        ui->cat->setText(QString::number(combo));
        ui->scoreL->setText(QString::number(score));
        ui->bad->show();*/
        t.start();
        while(t.elapsed()<100){
            QApplication::processEvents();
        }
      //  ui->bad->hide();
        ui->red->move(69,149);
        break;
        }

        if( ui->red->x()-144<=15 && ui->red->x()-144 >= -15){
        ui->red->hide();
      //  ui->red->move(69,149);
        score++;
        combo++;

        ui->good->show();
        t.start();
        while(t.elapsed()<100){
            QApplication::processEvents();
        }
        ui->good->hide();

        if(combo<10)
        ui->cat->setText(QString::number(combo));

        else{
        ui->cat->hide();
        ui->cat_2->show();
        ui->cat_2->setText(QString::number(combo));
        }

        ui->scoreL->setText(QString::number(score));
        ui->red->move(69,149);
        }
        break;
    }

    while (event->key() == Qt::Key_L){
        if((ui->blue->x()<129||ui->blue->x()>159) && ui->blue->x() < 730){
        combo = 0;
        score = score - 1;
        //ui->blue->move(69,149);
        ui->blue->hide();
        ui->cat_2->hide();
        ui->cat->show();
        ui->cat->setText(QString::number(combo));
        ui->scoreL->setText(QString::number(score));

        ui->bad->show();
        t.start();
        while(t.elapsed()<100){
            QApplication::processEvents();
        }
        ui->bad->hide();
        ui->blue->move(69,149);
        break;
        }

        if(ui->blue->x()-144<=15 && ui->blue->x()-144 >= -15){
        ui->blue->hide();
       // ui->blue->move(69,149);
        score++;
        combo++;

        ui->good->show();
        t.start();
        while(t.elapsed()<100){
            QApplication::processEvents();
        }
        ui->good->hide();

        if(combo<10)
        ui->cat->setText(QString::number(combo));

        else{
        ui->cat->hide();
        ui->cat_2->show();
        ui->cat_2->setText(QString::number(combo));
        }
        ui->scoreL->setText(QString::number(score));
        ui->blue->move(69,149);
        }
        break;
    }
}

void OpenGUI::taikorun(){

    srand(time(NULL));

        n = rand()%2;
        m = rand()%2+2;
        switch(n){
        case 0:
            ui->red->show();
            while(ui->red->x() > 70){
                ui->red->move(QPoint(ui->red->x()-m,ui->red->y()));
                t.start();
                while(t.elapsed() < 5)
                    QCoreApplication::processEvents();
                }
            if(ui->red->x()<=70){
                ui->bad->show();
                while(t.elapsed()<100)
                    QCoreApplication::processEvents();
                ui->bad->hide();
                ui->cat_2->hide();
                ui->cat->show();
                ui->cat->setText(QString::number(combo));
                ui->red->move(QPoint(760,149));
                ui->red->hide();
                OpenGUI::taikorun();
            }
            break;

        case 1:
            ui->blue->show();

            while(ui->blue->x() > 70){
                ui->blue->move(QPoint(ui->blue->x()-m,ui->blue->y()));
                t.start();
                while(t.elapsed() < 5)
                    QCoreApplication::processEvents();
            }
            if(ui->blue->x()<=70){
                ui->bad->show();
                while(t.elapsed()<100)
                    QCoreApplication::processEvents();
                ui->bad->hide();
                ui->cat_2->hide();
                ui->cat->show();
                ui->cat->setText(QString::number(combo));
                ui->blue->move(QPoint(760,149));
                ui->blue->hide();
                OpenGUI::taikorun();
            }
            break;
        }
   // }
}

void OpenGUI::setup(){

    DouT = 30;
    score = 0;
    combo = 0;

    ui->scoreL->setText(QString::number(score));
    ui->TimeL->setText(QString::number(DouT));

    ui->test->show();
    ui->num_3->show();
    OpenGUI::wait(980);
    ui->num_3->hide();
    OpenGUI::wait(50);
    ui->num_2->show();
    OpenGUI::wait(950);
    ui->num_2->hide();
    OpenGUI::wait(50);
    ui->num_1->show();
    OpenGUI::wait(950);
    ui->num_1->hide();
    OpenGUI::wait(50);
    ui->sta->show();
    OpenGUI::wait(900);
    ui->sta->hide();
    ui->test->hide();

    if(cnt==0){
    timer->start(999);
    connect(timer, SIGNAL(timeout()), this, SLOT(DingT()));
    cnt = cnt+1;
    }

    player->setMedia(QUrl("qrc:/opengui/game01.mp3"));
    player->play();

    timer->start(999);
    taikorun();
}

void OpenGUI::wait(unsigned int msec)
{

QTime dieTime = QTime::currentTime().addMSecs(msec);

while( QTime::currentTime() < dieTime )

QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}

void OpenGUI::DingT(){
    DouT--;
    ui->TimeL->setText(QString::number(DouT));
    if( DouT==0 )
        OpenGUI::EndDL();
}

void OpenGUI::EndDL(){

    if(score <= 0)
    score = 0;
    else
    score = score * (combo+1) / 1.67;

    QString myscore;
    myscore = QString("加權總分你獲得 %1 分, 想要重新開始嗎 ?").arg(score);


    QMessageBox message(QMessageBox::Warning," 分數結算 ", myscore, QMessageBox::Yes|QMessageBox::No);
    if (message.exec()==QMessageBox::Yes)
    {
        ui->red->move(770,149);
        ui->red->hide();    
        ui->blue->move(770,149);
        ui->blue->hide();

        OpenGUI::setup();
    }
    else
    {
        this->close();
    }
}

