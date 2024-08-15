QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builddotfreebsddotsh.cpp \
    builddotlinuxdotsh.cpp \
    builddotmacosdotsh.cpp \
    builddotopenbsddotsh.cpp \
    builddotwindowsdotsh.cpp \
    configdotgo.cpp \
    license.cpp \
    main.cpp

HEADERS += \
    builddotfreebsddotsh.h \
    builddotlinuxdotsh.h \
    builddotmacosdotsh.h \
    builddotopenbsddotsh.h \
    builddotwindowsdotsh.h \
    configdotgo.h \
    license.h

FORMS +=

TRANSLATIONS += \
    builddotfreebsddotsh_uk_UA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../.gitattributes
