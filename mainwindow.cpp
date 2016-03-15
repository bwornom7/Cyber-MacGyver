#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{

    auto label_width = 50, label_height = 50;

    // Pick left hand upper corner
    auto label_top = (120);
    auto label_left = (120);


    // Create label
    MovableLabel *label =  new MovableLabel(this);

    //create pixmap
    QPixmap dude(":/images/runner2.png");
    label->setScaledContents(true);
    label->setPixmap(dude);
    label->setGeometry(QRect(label_left, label_top, label_width, label_height));
    label->show();
}
