#include <iostream>
#include <QtCore/QObject>
#include <QtGui/QDesktopWidget>
#include <QtGui/QApplication>
#include "kpassivepopup.h"

using namespace std;

int main(int argc, char **argv) {
    cout << "Hello, World!" << endl;

    QApplication app(argc, argv);
    QWidget *widget = NULL;

    QString title = QString::fromLatin1("Test passive popup");
    QString content = QString::fromLatin1("Click popup to close");

    KPassivePopup *popup = new KPassivePopup(widget);
    popup->setTimeout(0); // no auto close
    popup->setPopupStyle(KPassivePopup::Boxed);
    popup->setAutoDelete(true);
    popup->setView(title, content);

    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->availableGeometry();

    int posX = screenRect.left() + (screenRect.width() - popup->sizeHint().width()) / 2;
    int posY = screenRect.bottom() - popup->sizeHint().height() - 30;
    QPoint point = QPoint( posX, posY );
    QObject::connect(popup, SIGNAL(clicked()), &app, SLOT(quit()));
    popup->show(point);

    return app.exec();
}