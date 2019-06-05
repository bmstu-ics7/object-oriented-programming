#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>

#include "command.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);

private slots:
    void on_btnOffset_clicked();
    void on_btnRotate_clicked();
    void on_btnScale_clicked();
    void on_bntFile_clicked();
    void on_btnSave_clicked();

private:
    Ui::MainWindow *ui;

    Scene facade;
};

#endif // MAINWINDOW_H
