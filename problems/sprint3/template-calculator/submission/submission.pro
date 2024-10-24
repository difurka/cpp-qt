########
MOCK_LIB=../../../../mocks_library
########

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    calculator.h \
    controller.h \
    mainwindow.h \
<<<<<<< HEAD
    rational.h \
    pow.h \
    enums.h
=======
    rational.h
>>>>>>> 6c5c66a (Обновление репы из коммита 53668ea9ce6dd95fb405d3721acc88e641f7360c (#8))

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
