########
MOCK_LIB=../../../../mocks_library
########

<<<<<<< HEAD
<<<<<<< HEAD
=======
#-------------------------------------------------
#
# Project created by QtCreator 2023-12-11T13:40:17
#
#-------------------------------------------------

>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

<<<<<<< HEAD
<<<<<<< HEAD
CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    functions.cpp \
    main.cpp \
    mainwindow.cpp \
    setting.cpp

HEADERS += \
    functions.h \
    mainwindow.h \
    setting.h

FORMS += \
    mainwindow.ui \
    setting.ui
=======
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
=======
CONFIG += c++20
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))

isEmpty(MOCK_LIB) {
    MOCK_LIB=$$(PRACTICUM_MOCK_LIBRARY)
}

INCLUDEPATH += $$MOCK_LIB

SOURCES += \
    functions.cpp \
    main.cpp \
    mainwindow.cpp \
    setting.cpp

HEADERS += \
    functions.h \
    mainwindow.h \
    setting.h

FORMS += \
<<<<<<< HEAD
        additemsnotification.ui \
        cartwindow.ui \
        selector.ui
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
=======
    mainwindow.ui \
    setting.ui
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
