#include "stdafx.h"
#include "LaserLine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LaserLine w;
    w.setWindowState(Qt::WindowMaximized);//窗口最大化
    w.show();
    return a.exec();
}
