#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void SltStartSearch();  //开始搜索

private:
    void InitSignalAndSlots();  //初始化信号与槽

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
