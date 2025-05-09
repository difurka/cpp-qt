########
MOCK_LIB=../../../../mocks_library
########

QT += testlib
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++17

SUBMISSION_PATH = ../submission

DEFINES += "PRAC_TESTS"

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

INCLUDEPATH += $$SUBMISSION_PATH
INCLUDEPATH += $$MOCK_LIB

TEMPLATE = app

SOURCES += \
        tests.cpp \
        test_functions.cpp \
        $$SUBMISSION_PATH/mainwindow.cpp \
        $$SUBMISSION_PATH/setting.cpp


HEADERS += \
        utils.h \
        actions_logger.h \
        $$MOCK_LIB/prac/QInputDialog \
        $$SUBMISSION_PATH/functions.h \
        $$SUBMISSION_PATH/mainwindow.h \
        $$SUBMISSION_PATH/setting.h

FORMS += \
        $$SUBMISSION_PATH/mainwindow.ui \
        $$SUBMISSION_PATH/setting.ui