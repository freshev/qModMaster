#-------------------------------------------------
#
# Project created by QtCreator 2010-11-24T09:57:26
#
#-------------------------------------------------

QT += core gui
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat


TARGET = qModMaster
TEMPLATE = app

SOURCES += src/main.cpp \
    3rdparty/libmodbus/modbus-data.cpp \
    3rdparty/libmodbus/modbus-rtu.cpp \
    3rdparty/libmodbus/modbus-tcp.cpp \
    3rdparty/libmodbus/modbus.cpp \
    src/mainwindow.cpp \
    forms/about.cpp \
    forms/settingsmodbusrtu.cpp \
    forms/settingsmodbustcp.cpp \
    src/modbusadapter.cpp \
    src/eutils.cpp \
    src/registersmodel.cpp \
    src/rawdatamodel.cpp \
    forms/settings.cpp \
    forms/busmonitor.cpp \
    src/rawdatadelegate.cpp \
    src/registersdatadelegate.cpp \
    src/modbuscommsettings.cpp \
    3rdparty/QsLog/QsLogDest.cpp \
    3rdparty/QsLog/QsLog.cpp \
    3rdparty/QsLog/QsLogDestConsole.cpp \
    3rdparty/QsLog/QsLogDestFile.cpp \
    src/MyInfoBar.cpp

HEADERS  += src/mainwindow.h \
    3rdparty/libmodbus/modbus.h \
    forms/about.h \
    forms/settingsmodbusrtu.h \
    forms/settingsmodbustcp.h \
    src/modbusadapter.h \
    src/eutils.h \
    src/registersmodel.h \
    src/rawdatamodel.h \
    forms/settings.h \
    forms/busmonitor.h \
    src/rawdatadelegate.h \
    src/registersdatadelegate.h \
    src/modbuscommsettings.h \
    3rdparty/QsLog/QsLog.h \
    3rdparty/QsLog/QsLogDest.h \
    3rdparty/QsLog/QsLogDestConsole.h \
    3rdparty/QsLog/QsLogLevel.h \
    3rdparty/QsLog/QsLogDisableForThisFile.h \
    3rdparty/QsLog/QsLogDestFile.h \
    src/MyInfoBar.h

INCLUDEPATH += 3rdparty/libmodbus \
    3rdparty/QsLog

TRANSLATIONS += translations/$$TARGET"_ru_RU.ts"
TRANSLATIONS += translations/$$TARGET"_zh_CN.ts"
TRANSLATIONS += translations/$$TARGET"_zh_TW.ts"

unix:SOURCES +=

unix:DEFINES += _TTY_POSIX_

win32:SOURCES +=

win32:DEFINES += _TTY_WIN_  WINVER=0x0501

win32:LIBS += -lsetupapi -lwsock32 -lws2_32

DEFINES += QS_LOG_LINE_NUMBERS     # automatically writes the file and line for each log message
#DEFINES += QS_LOG_DISABLE         # logging code is replaced with a no-op
#DEFINES += QS_LOG_SEPARATE_THREAD # messages are queued and written from a separate thread
DEFINES += LIB_MODBUS_DEBUG_OUTPUT # enable debug output from libmodbus

FORMS    += forms/mainwindow.ui \
    forms/about.ui \
    forms/settingsmodbusrtu.ui \
    forms/settingsmodbustcp.ui \
    forms/settings.ui \
    forms/busmonitor.ui

RESOURCES += \
    icons/icons.qrc \
    translations/translations.qrc


















