include(gtest_dependency.pri)
include(zpowcpp_main_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        main.cpp         \
        menu_tests.cpp
