#-------------------------------------------------
#
# Project created by QtCreator 2019-10-31T19:45:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        source_file/judgewindow.cpp \
        source_file/people.cpp \
        source_file/symmetricpair.cpp \
        source_file/longestshortestdistance.cpp \
        source_file/theeasycity2.cpp \
        source_file/themedian.cpp \
        source_file/manhattandistance.cpp \
        source_file/theeasycity1.cpp \
        source_file/mydatabase.cpp \
        source_file/getsolution.cpp \
        source_file/longest_common_string.cpp \
        source_file/escape.cpp \
        source_file/longestpalindrome.cpp \
        source_file/maze.cpp \
        source_file/subtract1.cpp \
        source_file/closest_longest_pair.cpp \
        source_file/minesweeper.cpp \
        source_file/add1.cpp \
        source_file/shygame.cpp \
        source_file/fibonacci.cpp \
        source_file/getsignature.cpp \
        source_file/factorial.cpp \
        source_file/shortest_sum_distance.cpp \
        source_file/largestroot.cpp \
        source_file/treewalk.cpp \
        source_file/periodofstring.cpp \
        source_file/largefactorial.cpp \
        source_file/largehex.cpp \
        source_file/distanceofprime.cpp \
        source_file/marioojisan.cpp \
        source_file/building.cpp \
        source_file/data.cpp \
        source_file/floor.cpp \
        source_file/mystring.cpp \
        source_file/main.cpp \
        source_file/mainwindow.cpp \
        source_file/mytree.cpp \
        source_file/myother.cpp \
        source_file/mymath.cpp \
        source_file/scheduler.cpp  \
        source_file/problemset.cpp \     

HEADERS += \
        header_file/closest_longest_pair.h \
        header_file/add1.h \
        header_file/escape.h \
        header_file/getsolution.h \
        header_file/judgewindow.h \
        header_file/longest_common_string.h \
        header_file/longestpalindrome.h \
        header_file/longestshortestdistance.h \
        header_file/manhattandistance.h \
        header_file/maze.h \
        header_file/mydatabase.h \
        header_file/people.h \
        header_file/shygame.h \
        header_file/fibonacci.h \
        header_file/minesweeper.h \
        header_file/getsignature.h \
        header_file/factorial.h \
        header_file/shortest_sum_distance.h \
        header_file/largestroot.h \
        header_file/subtract1.h \
        header_file/symmetricpair.h \
        header_file/theeasycity1.h \
        header_file/theeasycity2.h \
        header_file/themedian.h \
        header_file/treewalk.h \
        header_file/periodofstring.h \
        header_file/largefactorial.h \
        header_file/largehex.h \
        header_file/distanceofprime.h \
        header_file/marioojisan.h \
        header_file/building.h \
        header_file/data.h \
        header_file/floor.h \
        header_file/mystring.h \
        header_file/mainwindow.h \
        header_file/mymath.h \
        header_file/myother.h \
        header_file/mytree.h \
        header_file/problems.h \
        header_file/problemset.h \
        header_file/scheduler.h \

FORMS += \
        judgewindow.ui \
        mainwindow.ui  \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
