<<<<<<< HEAD
MOCK_LIB=../../../../mocks_library
=======
########
MOCK_LIB=../../../../mocks_library
########
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

isEmpty(MOCK_LIB) {
<<<<<<< HEAD
    MOCK_LIB=/tmp/practicum-qt-mocks
=======
    MOCK_LIB=$$(PRACTICUM_MOCK_LIBRARY)
>>>>>>> ed151b7 (Обновление репы из коммита 5bb7176501eee9f1f0866493eda49c1fcf90db60)
}

INCLUDEPATH += $$MOCK_LIB

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h
    prac/QTimer

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
