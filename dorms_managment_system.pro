QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../project/dormitory.cpp \
    ../project/restaurant.cpp \
    ../project/room.cpp \
    ../project/student.cpp \
    ../project/university.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../project/dormitory.h \
    ../project/menu.h \
    ../project/restaurant.h \
    ../project/room.h \
    ../project/room_empty.h \
    ../project/room_full.h \
    ../project/student.h \
    ../project/university.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    dorms_managment_system_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
