#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class CmdProcess;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotProcessCommand();

private:
    Ui::MainWindow *ui;
    CmdProcess *mCmdProcess;
};

#endif // MAINWINDOW_H
