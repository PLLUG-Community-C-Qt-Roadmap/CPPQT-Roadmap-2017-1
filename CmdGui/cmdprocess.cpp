#include "cmdprocess.h"

#include <QProcess>

CmdProcess::CmdProcess(QObject *parent)
    : QObject(parent)
    , mProcess{new QProcess(this)}
{
    connect(mProcess, &QProcess::readyReadStandardOutput,
            this, &CmdProcess::slotReadOutput, Qt::UniqueConnection);
    connect(mProcess, &QProcess::readyReadStandardError,
            this, &CmdProcess::slotReadOutput, Qt::UniqueConnection);
    mProcess->setProcessChannelMode(QProcess::MergedChannels);

    mProcess->start("cmd.exe");
}

void CmdProcess::slotExecuteCommand(const QString &command)
{
    mProcess->write(command.toLatin1());
    mProcess->write("\r\n");
}

void CmdProcess::slotReadOutput()
{
    QByteArray output = mProcess->readAll();
    emit outputRead(QString(output));
}
