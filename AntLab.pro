QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anthill.cpp \
    egg.cpp \
    orchestrator.cpp \
    foodspawner.cpp \
    larva.cpp \
    main.cpp \
    mainwindow.cpp \
    obstacle.cpp \
    queen.cpp \
    warrior.cpp \
    worker.cpp

HEADERS += \
    anthill.h \
    egg.h \
    orchestrator.h \
    foodspawner.h \
    larva.h \
    mainwindow.h \
    obstacle.h \
    queen.h \
    util.h \
    warrior.h \
    worker.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    AntLab_en_150.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
