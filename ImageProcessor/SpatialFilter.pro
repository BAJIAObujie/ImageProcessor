#-------------------------------------------------
#
# Project created by QtCreator 2017-03-26T13:05:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpatialFilter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        mypixmapitem.cpp \
    linearfilterdialog.cpp \
    imageprocessor.cpp \
    gauss_parameter.cpp \
    medianfilterdialog.cpp \
    bilateralfilterdlg.cpp \
    rotatedlg.cpp \
    logtransformdlg.cpp \
    lowpassfilterdlg.cpp \
    highpassfilterdlg.cpp

HEADERS  += mainwindow.h\
            mypixmapitem.h \
    linearfilterdialog.h \
    imageprocessor.h \
    gauss_parameter.h \
    medianfilterdialog.h \
    bilateralfilterdlg.h \
    rotatedlg.h \
    matrix.h \
    logtransformdlg.h \
    lowpassfilterdlg.h \
    highpassfilterdlg.h


FORMS    += mainwindow.ui \
    linearfilterdialog.ui \
    gauss_parameter.ui \
    medianfilterdialog.ui \
    bilateralfilterdlg.ui \
    rotatedlg.ui \
    logtransformdlg.ui \
    lowpassfilterdlg.ui \
    highpassfilterdlg.ui
