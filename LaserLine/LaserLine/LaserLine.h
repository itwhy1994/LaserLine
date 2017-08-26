#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LaserLine.h"
#include "opencv2/opencv.hpp"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class LaserLine : public QMainWindow
{
    Q_OBJECT

public:
    LaserLine(QWidget *parent = Q_NULLPTR);
    //labe显示Mat图像的函数，修改自http://blog.csdn.net/loveaborn/article/details/7680834
    //参数1-显示图像的Label，参数2-要显示的Mat
    void LabelDisplayMat(QLabel *label, cv::Mat &mat);

private:
    void ProcessSrcImg();//原图处理函数
    void ProcessThreshold();//二值化处理函数
    void ProcessIdentifi();//识别中心线函数

private slots:
    void OnLoadImg();//加载图片按钮点击响应
    void OnRotateImg();//旋转图片按钮点击响应
    void OnThresholdValue();//阈值编辑回车响应
    void OnReIdentifi();//重新识别按钮点击响应

private:
    Ui::LaserLine ui;
    std::string m_strSrcImgName;
    int m_iThresHoldValue;
    cv::Mat m_mSrcImg;
    cv::Mat m_mSmoothImg;
    cv::Mat m_mThresholdImg;
};
