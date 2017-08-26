#include "stdafx.h"
#include "LaserLine.h"

LaserLine::LaserLine(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.lineEdit_ThresholdValue->setValidator(new QIntValidator(0, 255, this));//限制阈值输入范围
    ui.lineEdit_ThresholdValue->setText("100");//阈值默认值设为100
    m_iThresHoldValue = 100;

    connect(ui.pushButton_LoadImg, SIGNAL(clicked()), this, SLOT(OnLoadImg()));
    connect(ui.pushButton_RotateImg, SIGNAL(clicked()), this, SLOT(OnRotateImg()));
    connect(ui.lineEdit_ThresholdValue, SIGNAL(editingFinished()), this, SLOT(OnThresholdValue()));
    connect(ui.pushButton_ReIdentifi, SIGNAL(clicked()), this, SLOT(OnReIdentifi()));
}

void LaserLine::LabelDisplayMat(QLabel *label, cv::Mat &mat)
{
    cv::Mat Rgb;
    QImage Img;
    if (mat.channels() == 3)//RGB Img
    {
        cv::cvtColor(mat, Rgb, CV_BGR2RGB);//颜色空间转换
        Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
    }
    else//Gray Img
    {
        Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
    }
    label->setPixmap(QPixmap::fromImage(Img));
}

void LaserLine::OnLoadImg()
{
    QString SrcImgName = QFileDialog::getOpenFileName(this, tr("Select Image"), "", tr("Images (*.png *.bmp *.jpg *.tif)"));//选择图片路径
    if (SrcImgName.isEmpty())
    {
        return;
    }
    m_strSrcImgName = SrcImgName.toStdString();
    m_mSrcImg = cv::imread(m_strSrcImgName, 1);
    ProcessSrcImg();
}

void LaserLine::ProcessSrcImg()
{
    LabelDisplayMat(ui.label_SrcImg, m_mSrcImg);//展示原图
    cv::Mat Grayimg;
    cvtColor(m_mSrcImg, Grayimg, CV_BGR2GRAY);//原图像转化为灰度图
    GaussianBlur(Grayimg, m_mSmoothImg, cv::Size(9, 9), 0, 0);//平滑去噪——高斯滤波
    ProcessThreshold();
}

void LaserLine::OnRotateImg()
{
    if (m_mSrcImg.empty() || !m_mSrcImg.data)//判断原图是否已加载成功
    {
        return;
    }
    cv::Point2f center = cv::Point2f(m_mSrcImg.cols / 2, m_mSrcImg.rows / 2);//旋转中心
    cv::Mat rotateMat = getRotationMatrix2D(center, 90, 1);
    cv::Mat tmpSrcImg;
    warpAffine(m_mSrcImg, tmpSrcImg, rotateMat, m_mSrcImg.size());
    m_mSrcImg = tmpSrcImg;
    ProcessSrcImg();
    ProcessThreshold();
    ProcessIdentifi();
}

void LaserLine::OnThresholdValue()
{
    int ThresholeValue = ui.lineEdit_ThresholdValue->text().toInt();
    if (m_iThresHoldValue != ThresholeValue)//判断阈值是否改变
    {
        m_iThresHoldValue = ThresholeValue;
        if (m_mSrcImg.empty() || !m_mSrcImg.data)//判断原图是否已加载成功
        {
            return;
        }
    }
    ProcessThreshold();
    ProcessIdentifi();
}

void LaserLine::ProcessThreshold()
{
    cv::threshold(m_mSmoothImg, m_mThresholdImg, m_iThresHoldValue, 255, cv::THRESH_TOZERO);//部分二值化图像
    LabelDisplayMat(ui.label_GrayImg, m_mThresholdImg);//展示部分二值化图像
}

void LaserLine::OnReIdentifi()
{
    if (m_mThresholdImg.empty() || !m_mThresholdImg.data)//判断部分二值化图是否已加载成功
    {
        return;
    }
    ProcessIdentifi();
}

void LaserLine::ProcessIdentifi()
{
    cv::Mat DstImg(m_mThresholdImg.rows, m_mThresholdImg.cols, CV_8UC1, cv::Scalar(0));
    for (int i = 0; i < DstImg.rows; i++)
    {
        long long sxp = 0, sp = 0, xpos;
        for (int j = 0; j < DstImg.cols; j++)
        {
            sxp += (j*(long long)(m_mThresholdImg.at<uchar>(i, j)));
            sp += (long long)(m_mThresholdImg.at<uchar>(i, j));
        }
        if (sp)
        {
            xpos = sxp / sp;//xpos即为每一行的中心坐标
            DstImg.at<uchar>(i, xpos) = 255;//将中心图标在DstImg上用白点标识出来
        }
    }
    LabelDisplayMat(ui.label_DstImg, DstImg);
}
