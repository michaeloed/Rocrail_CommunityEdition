#ifndef __MAINWINDOW_H_INCLUDED__
#define __MAINWINDOW_H_INCLUDED__

#include <QMainWindow>
#include <QWidget>
#include <ui/ui_mainwindow.h>


class MainWindow: public QMainWindow
{
    Q_OBJECT

public:    
    MainWindow(QWidget* parent = nullptr);

private:
    Ui::MainWindow* _ui;
};

#endif __MAINWINDOW_H_INCLUDED__
