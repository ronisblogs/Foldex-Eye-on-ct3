#include <bitset>
#include <QDebug>
#include "RemoteDesktopProcess.h"

RemoteDesktopProcess::RemoteDesktopProcess(QObject *parent) : QProcess(parent)
{

}

void RemoteDesktopProcess::start()
{
	if("spice"==protocol()) {
		QString p="remote-viewer";
		QString program(p);
	
		program.append(" -f")
			   .append(" spice://")
			   .append(host())
			   .append(":")
			   .append(port())
			   .append("/");

		qDebug() << program;
		QProcess::start(program);
	}
	else if("rdp"==protocol()) {
		QString p="xfreerdp";
		QString program(p);

		program.append(" /f")
           .append(" /bpp:24")
           .append(" /rfx")
           .append(" /compression")
           .append(" /sound")
           .append(" /u:").append(username())
           .append(" /p:").append(password())
           .append(" /v:").append(host())
           .append(" /port:").append(port());

		qDebug() << program;
		QProcess::start(program);
	}
	else {
		return;
	}
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

QString RemoteDesktopProcess::protocol() const
{
    return _protocol;
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

void RemoteDesktopProcess::setProtocol(QString protocol)
{
    _protocol = protocol;
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
