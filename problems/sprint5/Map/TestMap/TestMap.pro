QT += widgets
QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

MAP_PATH = ../submission

INCLUDEPATH += $$MAP_PATH

SOURCES +=  tst_testmap.cpp \
    $$MAP_PATH//mainwindow.cpp

HEADERS +=  \
    $$MAP_PATH//mainwindow.h

FORMS +=  \
    $$MAP_PATH//mainwindow.ui
