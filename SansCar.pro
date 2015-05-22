#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T19:25:12
#
#-------------------------------------------------

QT       += core gui
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SansCar
TEMPLATE = app


SOURCES += main.cpp\
    window.cpp \
    cadastrarcarro.cpp \
    cadastrocidade.cpp \
    cadastrarestado.cpp \
    cadastrarcor.cpp \
    filecontrol.cpp \
    login.cpp \
    carromodel.cpp \
    cadastrarmarca.cpp \
    cadastrarmodelo.cpp \
    pagamento.cpp

HEADERS  += \
    window.h \
    cadastrarcarro.h \
    cadastrocidade.h \
    cadastrarestado.h \
    cadastrarcor.h \
    filecontrol.h \
    login.h \
    carromodel.h \
    cadastrarmarca.h \
    cadastrarmodelo.h \
    pagamento.h

FORMS    += \
    window.ui \
    cadastrarcarro.ui \
    cadastrocidade.ui \
    cadastrarestado.ui \
    cadastrarcor.ui \
    login.ui \
    cadastrarmarca.ui \
    cadastrarmodelo.ui \
    pagamento.ui

RESOURCES += \
    data.qrc
