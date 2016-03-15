#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
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
    void on_playButton_clicked();


private:
    Ui::MainWindow *ui;
    QTimer *timer;

};

class MovableLabel : public QLabel
{
    Q_OBJECT
    bool mouseDragging;
    QPoint offset;

public:
    explicit MovableLabel(QWidget *parent): QLabel(parent) {
        setMouseTracking(true); // enable mouse move events
        mouseDragging = false;
    }
    void mouseMoveEvent(QMouseEvent *ev) {
        if (mouseDragging)
            this->move(mapToParent(ev->pos() - this->offset));
    }

    void mousePressEvent(QMouseEvent *ev) {
        mouseDragging = true;
        offset = ev->pos(); // location where mouse was clicked within the label
    }

    void mouseReleaseEvent(QMouseEvent *) {
        mouseDragging = false;
    }
};

#endif // MAINWINDOW_H
