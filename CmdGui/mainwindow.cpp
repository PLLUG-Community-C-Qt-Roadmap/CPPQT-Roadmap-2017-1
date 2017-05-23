#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cmdprocess.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mCmdProcess{new CmdProcess{this}}
{
    ui->setupUi(this);

    connect(ui->commandLineEdit, &QLineEdit::returnPressed,
            this, &MainWindow::slotProcessCommand, Qt::UniqueConnection);

    connect(mCmdProcess, &CmdProcess::outputRead,
        ui->outputTextEdit, &QTextEdit::append);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotProcessCommand()
{
    QString command = ui->commandLineEdit->text();
    mCmdProcess->slotExecuteCommand(command);
    ui->commandLineEdit->clear();
}



