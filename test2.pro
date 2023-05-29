QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game.cpp \
    Ghost.cpp \
    Player.cpp \
    Score.cpp \
    main.cpp

HEADERS += \
    Game.h \
    Ghost.h \
    Player.h \
    Score.h
MOC_HEADERS += \
Ghost.h \
Player.h
FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
<<<<<<< HEAD

RESOURCES += \
    res.qrc
=======
>>>>>>> bfc35f0ee502c796ce881f165c09b7ca08bac18c
