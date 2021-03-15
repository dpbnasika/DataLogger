#include "motordatalogger.h"
#include "ui_motordatalogger.h"
#include <QDebug>
#include <QTimer>
#include <QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QSerialPort* serialPort;
QPalette sample_palette;

MotorDataLogger::MotorDataLogger(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MotorDataLogger)
{
    ui->setupUi(this);
    serialPort= new QSerialPort(this);
    ui->baudList->addItem("9600");
    ui->baudList->addItem("19200");
    ui->baudList->addItem("38400");
    ui->baudList->addItem("57600");
    ui->baudList->addItem("115200");
    ui->baudList->addItem("230400");
    ui->baudList->addItem("460800");
    ui->baudList->addItem("921600");

    QList<QSerialPortInfo> list;

    list = QSerialPortInfo::availablePorts();
    QSerialPortInfo port;
    for(int i=0; i< list.count() ; i++){
        port = list.at(i);
        ui->portList->addItem(port.portName());
    }

}

MotorDataLogger::~MotorDataLogger()
{
    delete ui;
}


void MotorDataLogger::on_connectPushBtn_clicked()
{
    serialPort->setPortName(ui->portList->currentText());
    serialPort->setBaudRate(ui->baudList->currentText().toInt());
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->setParity(QSerialPort::NoParity);
    bool isConnected = serialPort->open(QIODevice::ReadWrite);
    if(isConnected){
        qInfo() << "Connected";
        ui->labelConnected->setText("Device connected");
    }

}

void MotorDataLogger::on_disconnectPushBtn_clicked()
{
    if(serialPort->isOpen() && serialPort->isReadable()){
        serialPort->flush();
        serialPort->close();
        qInfo() << "Disconnected";
        ui->labelConnected->setText("Device disconnected");
    }

}
