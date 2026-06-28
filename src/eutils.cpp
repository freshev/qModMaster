#include "eutils.h"

EUtils::EUtils()
{
}

int EUtils::rts(QString r)
{
    #ifdef Q_OS_WIN32
    if (r == "Disable") return 0; // RTS_CONTROL_DISABLE
    if (r == "Enable") return 1;  // RTS_CONTROL_ENABLE
    if (r == "Handshake") return 2; // RTS_CONTROL_HANDSHAKE
    if (r == "Toggle") return 3; // RTS_CONTROL_TOGGLE
    #else
    if (r == "None") return 0; // MODBUS_RTU_RTS_NONE
    if (r == "Up") return 1; // MODBUS_RTU_RTS_UP
    if (r == "Down") return 2; // MODBUS_RTU_RTS_DOWN
    #endif
    return 0;
}

QString EUtils::formatValue(int value,int frmt, bool is16Bit)
{
    QString convertedValue;

    switch(frmt){

        case 2://Binary
        if (is16Bit)
            convertedValue = QString("%1").arg(value,16,2,QLatin1Char('0')).toUpper();
        else
            convertedValue = QString("%1").arg(value,0,2).toUpper();
        break;

        case 10://Decimal - Unsigned Integer
            convertedValue = QString("%1").arg((unsigned short)value,0,10).toUpper();
        break;

        case 16://Hex
        if (is16Bit)
            convertedValue = QString("%1").arg((unsigned short)value,4,16,QLatin1Char('0')).toUpper();
        else
            convertedValue = QString("%1").arg(value,0,16).toUpper();
        break;

        default://Default
        convertedValue = QString("%1").arg(value,0,10).toUpper();

    }

    return convertedValue;

}

