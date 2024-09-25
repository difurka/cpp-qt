########
MOCK_LIB=../../../../mocks_library
########

QT += testlib
QT += gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++17

DEFINES += "PRAC_TESTS"

SUBMISSION_PATH = ../submission

isEmpty(MOCK_LIB) {
<<<<<<< HEAD
    MOCK_LIB=/tmp/practicum-qt-mocks
=======
    MOCK_LIB=$$(PRACTICUM_MOCK_LIBRARY)
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

INCLUDEPATH += $$SUBMISSION_PATH
INCLUDEPATH += $$MOCK_LIB

TEMPLATE = app

SOURCES +=  tests.cpp \
    $$SUBMISSION_PATH/mainwindow.cpp

HEADERS +=  \
    $$SUBMISSION_PATH/mainwindow.h \
    $$MOCK_LIB/prac/QTimer \
    $$MOCK_LIB/prac/QTime

FORMS += \
    $$SUBMISSION_PATH/mainwindow.ui

