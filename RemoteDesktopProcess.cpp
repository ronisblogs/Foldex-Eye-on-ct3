#include <bitset>
#include <QDebug>
#include "RemoteDesktopProcess.h"

RemoteDesktopProcess::RemoteDesktopProcess(QObject *parent) : QProcess(parent)
{

}

void RemoteDesktopProcess::start()
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

int RemoteDesktopProcess::status() const
{
    return this->exitCode();
}

QString RemoteDesktopProcess::errorCode() const
{
    return this->errorString();
}

void RemoteDesktopProcess::kill()
{
    QProcess::kill();
}

QString RemoteDesktopProcess::username() const
{
    return _username;
}

QString RemoteDesktopProcess::password() const
{
    return _password;
}

QString RemoteDesktopProcess::host() const
{
    return _host;
}

bool RemoteDesktopProcess::smoothFont() const
{
    return _smoothFont;
}

bool RemoteDesktopProcess::dragFullWindow() const
{
    return _dragFullWindow;
}

int RemoteDesktopProcess::policy() const
{
    return _policy;
}

QString RemoteDesktopProcess::port() const
{
    return _port;
}

void RemoteDesktopProcess::setUsername(QString username)
{
    _username = username;
}

void RemoteDesktopProcess::setPassword(QString password)
{
    _password = password;
}

void RemoteDesktopProcess::setHost(QString host)
{
    _host = host;
}

void RemoteDesktopProcess::setSmoothFont(bool smoothFont)
{
    _smoothFont = smoothFont;
}

void RemoteDesktopProcess::setDragFullWindow(bool dragFullWindow)
{
    _dragFullWindow = dragFullWindow;
}

void RemoteDesktopProcess::setPolicy(int policy)
{
    _policy = policy;
}

void RemoteDesktopProcess::setPort(QString port)
{
    _port = port;
}
