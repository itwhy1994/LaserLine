#include "stdafx.h"
#include "LaserLine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LaserLine w;
    w.setWindowState(Qt::WindowMaximized);//�������
    w.show();
    return a.exec();
}
