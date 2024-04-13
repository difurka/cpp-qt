<<<<<<< HEAD
########
MOCK_LIB=../../../../mocks_library
########

=======
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
QT += testlib
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++17

SUBMISSION_PATH = ../submission

INCLUDEPATH += $$SUBMISSION_PATH

TEMPLATE = app

SOURCES +=  tests.cpp \
    $$SUBMISSION_PATH/mainwindow.cpp
    $$SUBMISSION_PATH/main.cpp

HEADERS +=  \
    $$SUBMISSION_PATH/mainwindow.h

FORMS += \
    $$SUBMISSION_PATH/mainwindow.ui
