#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    InitSignalAndSlots();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SltStartSearch()
{
    qDebug() << "Start Search\n";
}

void Widget::InitSignalAndSlots()
{
    // 最后一个参数为Qt::ConnectionType type,表示信号与槽之间的关联方式
    // Qt::AutoConnection(缺省值)：如果信号的接收者与发射者在同一个线程，就使用Qt::Direct Connection方式，否则使用Qt::QueuedConnection方式，在信号发射时自动确定关联方式
    // Qt::DirectionConnect:信号被发射时槽行数立即执行，槽函数与信号在同一个线程
    // Qt::QueuedConnection:在事件循环回到接收者线程后执行槽行数，槽行数与信号在不同的线程
    // Qt::BlockingQueuedConnection:与Qt::QueuedConnection相似，只是信号线程会阻塞直到槽行数执行完毕。当槽行数与信号函数在同一个线程时绝对不能使用这种方式，否则会造成死锁

    // 在输入框里按下回车键开始搜索
    connect(ui->LEFilePath, SIGNAL(returnPressed()), this, SLOT(SltStartSearch()));
}
