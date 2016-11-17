#include <bitset>
#include <QDebug>
#include "spiceprocess.h"
#ifdef Q_OS_WIN
#include <fileapi.h>
#include <intrin.h>
#endif

SpiceProcess::SpiceProcess(QObject *parent) : QProcess(parent)
{

}

void SpiceProcess::start()
{
    QString program("remote-viewer");
    program.append(" -f")
           .append(" spice://")
		   .append(host())
		   .append(":")
		   .append(port())
		   .append("/");

    qDebug() << program;

    QProcess::start(program);
}

int SpiceProcess::status() const
{
    return this->exitCode();
}

QString SpiceProcess::errorCode() const
{
    return this->errorString();
}

void SpiceProcess::kill()
{
    QProcess::kill();
}

QString SpiceProcess::username() const
{
    return _username;
}

QString SpiceProcess::password() const
{
    return _password;
}

QString SpiceProcess::host() const
{
    return _host;
}

bool SpiceProcess::smoothFont() const
{
    return _smoothFont;
}

bool SpiceProcess::dragFullWindow() const
{
    return _dragFullWindow;
}

int SpiceProcess::policy() const
{
    return _policy;
}

QString SpiceProcess::port() const
{
    return _port;
}

void SpiceProcess::setUsername(QString username)
{
    _username = username;
}

void SpiceProcess::setPassword(QString password)
{
    _password = password;
}

void SpiceProcess::setHost(QString host)
{
    _host = host;
}

void SpiceProcess::setSmoothFont(bool smoothFont)
{
    _smoothFont = smoothFont;
}

void SpiceProcess::setDragFullWindow(bool dragFullWindow)
{
    _dragFullWindow = dragFullWindow;
}

void SpiceProcess::setPolicy(int policy)
{
    _policy = policy;
}

void SpiceProcess::setPort(QString port)
{
    _port = port;
}
