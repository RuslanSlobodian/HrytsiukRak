TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        AnnualReport.cpp \
        Expense.cpp \
        ExpenseInputScreen.cpp \
        ExpenseRecord.cpp \
        RentInputScreen.cpp \
        RentRecord.cpp \
        RentRow.cpp \
        Tenant.cpp \
        TenantInputScreen.cpp \
        TenantList.cpp \
        UserInterface.cpp \
        globalFunctions.cpp \
        main.cpp

HEADERS += \
    AnnualReport.h \
    Expense.h \
    ExpenseInputScreen.h \
    ExpenseRecord.h \
    RentInputScreen.h \
    RentRecord.h \
    RentRow.h \
    Tenant.h \
    TenantInputScreen.h \
    TenantList.h \
    UserInterface.h \
    globalFunctions.h

DISTFILES += \
    CMakeLists.txt
