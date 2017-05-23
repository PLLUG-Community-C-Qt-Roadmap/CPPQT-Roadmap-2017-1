#ifndef CMDPROCESS_H
#define CMDPROCESS_H

#include <QObject>

class QProcess;

class CmdProcess : public QObject
{
    Q_OBJECT
public:
    explicit CmdProcess(QObject *parent = 0);

signals:
    void outputRead(QString);

public slots:
    void slotExecuteCommand(const QString &command);

private slots:
    void slotReadOutput();

private:
    QProcess *mProcess;
};

#endif // CMDPROCESS_H
