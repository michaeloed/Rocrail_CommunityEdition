
#include <mainwindow.h>
#include <QWidget>
#include <ui/ui_mainwindow.h>


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      _ui(new Ui::MainWindow())
{
    _ui->setupUi(this);
}
