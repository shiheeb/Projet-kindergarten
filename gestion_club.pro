QT       += core gui network sql printsupport serialport charts  \
            multimedia multimediawidgets
QT += multimedia widgets texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestion_club
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS SMTP_BUILD

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    club.cpp \
    connexion.cpp \
    emailaddress.cpp \
    main.cpp \
    gestion_club.cpp \
    membre.cpp \
    mimeattachment.cpp \
    mimecontentformatter.cpp \
    mimefile.cpp \
    mimehtml.cpp \
    mimeinlinefile.cpp \
    mimemessage.cpp \
    mimemultipart.cpp \
    mimepart.cpp \
    mimetext.cpp \
    popup.cpp \
    quotedprintable.cpp \
    smtpclient.cpp \
    statisitique_club.cpp

HEADERS += \
    SmtpMime \
    club.h \
    connexion.h \
    emailaddress.h \
    gestion_club.h \
    membre.h \
    mimeattachment.h \
    mimecontentformatter.h \
    mimefile.h \
    mimehtml.h \
    mimeinlinefile.h \
    mimemessage.h \
    mimemultipart.h \
    mimepart.h \
    mimetext.h \
    popup.h \
    quotedprintable.h \
    smtpclient.h \
    smtpexports.h \
    statisitique_club.h

FORMS += \
    gestion_club.ui \
    statisitique_club.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    gestion_club.pro.user
