########
MOCK_LIB=../../../../mocks_library
########

QT += testlib
QT += gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++17

isEmpty(MOCK_LIB) {
<<<<<<< HEAD
<<<<<<< HEAD
    MOCK_LIB=/tmp/practicum-qt-mocks
=======
    MOCK_LIB=$$(PRACTICUM_MOCK_LIBRARY)
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
    MOCK_LIB=/tmp/practicum-qt-mocks
>>>>>>> 8d1ad25 (Обновление репы из коммита e58c1d9066fd9b4a8c0b5030c44729a77f06dbed (#10))
}

DEFINES += "PRAC_TESTS"

SUBMISSION_PATH = ../submission

INCLUDEPATH += $$SUBMISSION_PATH
INCLUDEPATH += $$MOCK_LIB

TEMPLATE = app

SOURCES += \
    tests.cpp \
    $$SUBMISSION_PATH/winterwindow.cpp

HEADERS +=  \
    $$SUBMISSION_PATH/winterwindow.h\
    $$MOCK_LIB/prac/QPainter

FORMS += \
    $$SUBMISSION_PATH/winterwindow.ui

