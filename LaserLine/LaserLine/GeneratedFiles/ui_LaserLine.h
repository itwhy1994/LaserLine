/********************************************************************************
** Form generated from reading UI file 'LaserLine.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASERLINE_H
#define UI_LASERLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LaserLine
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_SrcImg;
    QLabel *label_GrayImg;
    QLabel *label_DstImg;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_LoadImg;
    QPushButton *pushButton_RotateImg;
    QLabel *label_ThresholdSet;
    QLineEdit *lineEdit_ThresholdValue;
    QPushButton *pushButton_ReIdentifi;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LaserLine)
    {
        if (LaserLine->objectName().isEmpty())
            LaserLine->setObjectName(QStringLiteral("LaserLine"));
        LaserLine->resize(884, 584);
        centralWidget = new QWidget(LaserLine);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_SrcImg = new QLabel(centralWidget);
        label_SrcImg->setObjectName(QStringLiteral("label_SrcImg"));
        label_SrcImg->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_SrcImg);

        label_GrayImg = new QLabel(centralWidget);
        label_GrayImg->setObjectName(QStringLiteral("label_GrayImg"));
        label_GrayImg->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_GrayImg);

        label_DstImg = new QLabel(centralWidget);
        label_DstImg->setObjectName(QStringLiteral("label_DstImg"));
        label_DstImg->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_DstImg);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_LoadImg = new QPushButton(centralWidget);
        pushButton_LoadImg->setObjectName(QStringLiteral("pushButton_LoadImg"));

        horizontalLayout_2->addWidget(pushButton_LoadImg);

        pushButton_RotateImg = new QPushButton(centralWidget);
        pushButton_RotateImg->setObjectName(QStringLiteral("pushButton_RotateImg"));

        horizontalLayout_2->addWidget(pushButton_RotateImg);

        label_ThresholdSet = new QLabel(centralWidget);
        label_ThresholdSet->setObjectName(QStringLiteral("label_ThresholdSet"));
        label_ThresholdSet->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_ThresholdSet);

        lineEdit_ThresholdValue = new QLineEdit(centralWidget);
        lineEdit_ThresholdValue->setObjectName(QStringLiteral("lineEdit_ThresholdValue"));

        horizontalLayout_2->addWidget(lineEdit_ThresholdValue);

        pushButton_ReIdentifi = new QPushButton(centralWidget);
        pushButton_ReIdentifi->setObjectName(QStringLiteral("pushButton_ReIdentifi"));

        horizontalLayout_2->addWidget(pushButton_ReIdentifi);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_2);

        LaserLine->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LaserLine);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 884, 23));
        LaserLine->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LaserLine);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LaserLine->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LaserLine);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LaserLine->setStatusBar(statusBar);

        retranslateUi(LaserLine);

        QMetaObject::connectSlotsByName(LaserLine);
    } // setupUi

    void retranslateUi(QMainWindow *LaserLine)
    {
        LaserLine->setWindowTitle(QApplication::translate("LaserLine", "LaserLine", Q_NULLPTR));
        label_SrcImg->setText(QApplication::translate("LaserLine", "SrcImg", Q_NULLPTR));
        label_GrayImg->setText(QApplication::translate("LaserLine", "GrayImg", Q_NULLPTR));
        label_DstImg->setText(QApplication::translate("LaserLine", "DstImg", Q_NULLPTR));
        pushButton_LoadImg->setText(QApplication::translate("LaserLine", "LoadImg", Q_NULLPTR));
        pushButton_RotateImg->setText(QApplication::translate("LaserLine", "RotateImg", Q_NULLPTR));
        label_ThresholdSet->setText(QApplication::translate("LaserLine", "ThresholdSet:", Q_NULLPTR));
        pushButton_ReIdentifi->setText(QApplication::translate("LaserLine", "Identifi/ReIdentifi", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LaserLine: public Ui_LaserLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASERLINE_H
