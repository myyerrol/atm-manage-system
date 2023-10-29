#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T14:51:01
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = atm_manage_system
TEMPLATE = app


SOURCES +=\
        atm_welcome_form.cpp \
    atm_change_password_form.cpp \
    atm_save_money_form.cpp \
    atm_take_money_form.cpp \
    atm_transfer_money_form.cpp \
    atm_connect_database.cpp \
    atm_action_process_form.cpp \
    atm_query_money_form.cpp \
    atm_login_to_main_form.cpp \
    atm_main_function_form.cpp \
    atm_system_main.cpp

HEADERS  += atm_welcome_form.h \
    atm_change_password_form.h \
    atm_save_money_form.h \
    atm_take_money_form.h \
    atm_transfer_money_form.h \
    atm_connect_database.h \
    atm_action_process_form.h \
    atm_query_money_form.h \
    atm_login_to_main_form.h \
    atm_main_function_form.h

FORMS    += atm_welcome_form.ui \
    atm_change_password_form.ui \
    atm_save_money_form.ui \
    atm_take_money_form.ui \
    atm_transfer_money_form.ui \
    atm_action_process_form.ui \
    atm_query_money_form.ui \
    atm_login_to_main_form.ui \
    atm_main_function_form.ui
