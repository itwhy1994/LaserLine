#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LaserLine.h"

class LaserLine : public QMainWindow
{
    Q_OBJECT

public:
    LaserLine(QWidget *parent = Q_NULLPTR);

private:
    Ui::LaserLineClass ui;
};
