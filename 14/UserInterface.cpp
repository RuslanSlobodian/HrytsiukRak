#include "UserInterface.h"
#include "globalFunctions.h"
#include "ExpenseInputScreen.h"
#include <iostream>

using namespace std;

UserInterface::UserInterface()
        : ptrTenantList(new TenantList), ptrRentRecord(new RentRecord()),
          ptrExpenseRecord(new ExpenseRecord()) {
}

UserInterface::~UserInterface() {
    delete ptrTenantList;
    delete ptrRentRecord;
    delete ptrExpenseRecord;
}

void UserInterface::interact() {
    while (true) {
        cout << "Для введення даних натисніть 'i'\n"
             << " 'd' для виведення звiту\n"
             << " 'q' для виходу: ";
        ch = getaChar();
        if (ch == 'i') { // Введення даних
            cout << " 't' для додавання мешканця\n"
                 << " 'r' для запису орендної плати\n"
                 << " 'e' для запису витрат: ";

            ch = getaChar();
            switch (ch) {
                // Екрани введення існують тільки під час їх використання
                case 't':
                    ptrTenantInputScreen =
                            new TenantInputScreen(ptrTenantList);
                    ptrTenantInputScreen->getTenant();
                    delete ptrTenantInputScreen;
                    break;
                case 'r':
                    ptrRentInputScreen =
                            new RentInputScreen(ptrTenantList, ptrRentRecord);
                    ptrRentInputScreen->getRent();
                    delete ptrRentInputScreen;
                    break;
                case 'e':
                    ptrExpenseInputScreen =
                            new ExpenseInputScreen(ptrExpenseRecord);
                    ptrExpenseInputScreen->getExpense();
                    delete ptrExpenseInputScreen;
                    break;
                default:
                    cout << "Невiдома функцiя" << endl;
                    break;
            }
        } else if (ch == 'd') { // Виведення даних
            cout << " 't' для виведення мешканцiв\n"
                 << " 'r' для виведення орендної плати\n"
                 << " 'e' для виведення витрат\n"
                 << " 'a' для виведення рiчного звіту: ";
            ch = getaChar();

            switch (ch) {
                case 't':
                    ptrTenantList->Display();
                    break;
                case 'r':
                    ptrRentRecord->Display();
                    break;
                case 'e':
                    ptrExpenseRecord->Display();
                    break;
                case 'a':
                    ptrAnnualReport = new AnnualReport(ptrRentRecord,
                                                       ptrExpenseRecord);
                    ptrAnnualReport->Display();
                    delete ptrAnnualReport;
                    break;
                default:
                    cout << "Невiдома функцiя виведення" << endl;
                    break;
            }
        } else if (ch == 'q')
            return; // Вихід
        else
            cout << "Невiдома функцiя" << endl;
        cout << "Натискайте тiльки 'i', 'd' або 'q'" << endl;
    }
}

