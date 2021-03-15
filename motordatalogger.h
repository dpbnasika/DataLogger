#ifndef MOTORDATALOGGER_H
#define MOTORDATALOGGER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MotorDataLogger; }
QT_END_NAMESPACE

class MotorDataLogger : public QMainWindow
{
    Q_OBJECT

public:
    MotorDataLogger(QWidget *parent = nullptr);
    ~MotorDataLogger();

private slots:
    void on_connectPushBtn_clicked();

    void on_disconnectPushBtn_clicked();

private:
    Ui::MotorDataLogger *ui;
};
#endif // MOTORDATALOGGER_H
