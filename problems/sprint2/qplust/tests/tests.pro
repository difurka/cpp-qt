<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
########
MOCK_LIB=../../../../mocks_library
########

<<<<<<< HEAD
=======
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
=======
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
QT += testlib
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++17
<<<<<<< HEAD
<<<<<<< HEAD

SUBMISSION_PATH = ../submission

INCLUDEPATH += $$SUBMISSION_PATH
=======
#CONFIG += qt console warn_on depend_includepath testcase
#CONFIG -= app_bundle

INCLUDEPATH += ../submission
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
=======

SUBMISSION_PATH = ../submission

INCLUDEPATH += $$SUBMISSION_PATH
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

TEMPLATE = app

SOURCES +=  tests.cpp \
<<<<<<< HEAD
<<<<<<< HEAD
    $$SUBMISSION_PATH/mainwindow.cpp
    $$SUBMISSION_PATH/main.cpp

HEADERS +=  \
    $$SUBMISSION_PATH/mainwindow.h

FORMS += \
    $$SUBMISSION_PATH/mainwindow.ui
=======
    ../submission/mainwindow.cpp
    ../submission/main.cpp
=======
    $$SUBMISSION_PATH/mainwindow.cpp
    $$SUBMISSION_PATH/main.cpp
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

HEADERS +=  \
    $$SUBMISSION_PATH/mainwindow.h

FORMS += \
<<<<<<< HEAD
    ../submission/mainwindow.ui
>>>>>>> 2519a99 (Обновление репы из коммита 8b7cdaeb6ea3f76780108cd6d9982c8b34825e99)
=======
    $$SUBMISSION_PATH/mainwindow.ui
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
