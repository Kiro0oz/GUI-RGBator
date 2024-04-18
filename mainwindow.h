#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>>
#include <QDebug>
#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPalette>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class RGBator;
}
QT_END_NAMESPACE
class FancyButton : public QPushButton
{
    Q_OBJECT

public:
    explicit FancyButton(QWidget *parent = nullptr)
        : QPushButton(parent)
    {}

protected:
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Set the color and font
        // painter.setPen(QColor("#222222"));
        painter.setFont(QFont("JetBrains mono", 10, QFont::Bold));

        // Create the path for the fancy corners
        QPainterPath path;
        path.moveTo(5, 0);
        path.lineTo(width(), 0);
        path.lineTo(width(), 5);
        path.lineTo(width(), height() - 5);
        path.lineTo(width() - 5, height());
        path.lineTo(5, height());
        path.lineTo(0, height());
        path.lineTo(0, 5);
        path.closeSubpath();

        // Set the clip path
        painter.setClipPath(path);

        // Draw the background
        painter.fillPath(path, QColor("#59FFA0"));

        // Draw the text
        painter.drawText(rect(), Qt::AlignCenter, text());
    }
};

class CustomLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CustomLabel(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *event) override;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool isHolding = false;
signals:
    void mousePressed(const QPoint &);
    void mouseHolding(const QPoint &pos);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void hide_others(std::string curr = "");
    void show_sliderWidgets(bool checked);
    void show_cropWidgets(bool checked);
    //s
private slots:
    // customLabel slots
    void handleMouseHolding(const QPoint &pos);
    //  End custom

    void on_loadImgBtn_clicked();
    void on_saveImgBtn_clicked();
    void outImageDisplay();
    void on_clearImg_clicked();

    void on_redoBtn_clicked();
    void on_undoBtn_clicked();

    void on_invertFilter_clicked();
    void on_rotateRight_clicked();
    void on_rotateLeft_clicked();

    void on_purpleFilter_clicked();

    void on_filterApply_clicked();

    void on_sunLightFilter_clicked(bool checked);

    void on_filterSlider_valueChanged(int value);

    void on_blurFilter_clicked(bool checked);

    void on_oilFilter_clicked(bool checked);

    void on_resizeFilterBtn_clicked();

    void on_widthEditVal_textEdited();

    void on_heightEditVal_textEdited();

    void on_grayFilter_clicked();

    void on_B_W_Filter_clicked();

    void on_DetectFilter_clicked();

    void on_BrightFilter_clicked(bool checked);

    // void on_cropAp_clicked(bool checked);

    void on_cropFilter_clicked(bool checked);

    void on_cropWidth_textEdited(const QString &arg1);

    void on_cropHeight_textChanged(const QString &arg1);

    void on_cropApply_clicked();

    void on_oldtvFilter_clicked();

    void on_NeonFilter_clicked();

    void on_HorizontalFlip_clicked();

    void on_VerticalFlip_clicked();

    void on_infraredFilter_clicked();

    void on_MergeFilter_clicked();

    void on_MergeCrop_clicked();

    void on_empossFilter_clicked();

    void on_SkewFilter_clicked(bool checked);

    void on_swirlFilter_clicked(bool checked);

    void on_FrameFilter_clicked(bool checked);

    void on_colorBtn_clicked();

    void on_fancyBtn_clicked();


    void on_cheesFrameApply_clicked();

    void on_innerFrameApply_clicked();

    void on_coloredFrameApply_clicked();

private:
    Ui::RGBator *ui;
};
#endif // MAINWINDOW_H
