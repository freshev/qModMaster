#include <QtDebug>
#include <QSerialPortInfo>
#include "settingsmodbusrtu.h"
#include "ui_settingsmodbusrtu.h"

SettingsModbusRTU::SettingsModbusRTU(QWidget *parent,ModbusCommSettings * settings) :
    QDialog(parent),
    ui(new Ui::SettingsModbusRTU),
    m_settings(settings)
{
    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(changesAccepted()));

}

SettingsModbusRTU::~SettingsModbusRTU()
{
    delete ui;
}

void SettingsModbusRTU::showEvent(QShowEvent * event)
{

    //Load Settings
    if (m_settings != NULL) {

        ui->cmbPort->clear();
        ui->cmbRTS->clear();

        //Populate cmbPort-cmbRTS
        const auto serialPortInfos = QSerialPortInfo::availablePorts();
        for (const QSerialPortInfo &portInfo : serialPortInfos) {
        	ui->cmbPort->addItem(portInfo.portName());
        }

        #ifdef Q_OS_WIN32
        ui->cmbRTS->addItem("Disable");
        ui->cmbRTS->addItem("Enable");
        ui->cmbRTS->addItem("Handshake");
        ui->cmbRTS->addItem("Toggle");
        #else
        ui->cmbRTS->addItem("None");
        ui->cmbRTS->addItem("Up");
        ui->cmbRTS->addItem("Down");
        #endif

        if ((ui->cmbPort->findText(m_settings->serialPort()) == -1))
            ui->cmbPort->setCurrentIndex(0);
        else
            ui->cmbPort->setCurrentIndex(ui->cmbPort->findText(m_settings->serialPort()));
        ui->cmbBaud->setCurrentIndex(ui->cmbBaud->findText(m_settings->baud()));
        ui->cmbDataBits->setCurrentIndex(ui->cmbDataBits->findText(m_settings->dataBits()));
        ui->cmbStopBits->setCurrentIndex(ui->cmbStopBits->findText(m_settings->stopBits()));
        ui->cmbParity->setCurrentIndex(ui->cmbParity->findText(m_settings->parity()));
        ui->cmbRTS->setCurrentIndex(ui->cmbRTS->findText(m_settings->RTS()));
    }


}

void SettingsModbusRTU::changesAccepted()
{

    //Save Settings
    if (m_settings != NULL) {

        #ifdef Q_OS_WIN32
        	m_settings->setSerialPort("\\\\.\\" + ui->cmbPort->currentText());
        #else
        	m_settings->setSerialPort(ui->cmbPort->currentText());
        #endif

        m_settings->setBaud(ui->cmbBaud->currentText());
        m_settings->setDataBits(ui->cmbDataBits->currentText());
        m_settings->setStopBits(ui->cmbStopBits->currentText());
        m_settings->setParity(ui->cmbParity->currentText());
        m_settings->setRTS((QString)ui->cmbRTS->currentText());
    }

}

