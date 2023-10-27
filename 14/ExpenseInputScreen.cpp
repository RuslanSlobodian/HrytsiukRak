#include "ExpenseInputScreen.h"
#include "globalFunctions.h"
#include <iostream>

using namespace std;

ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord* per) : ptrExpenseRecord(per) {}

void ExpenseInputScreen::getExpense() {
    int month;
    int day;
    string category;
    string payee;
    float amount;
    cout << "Введiть місяць (1-12): ";
    cin >> month;
    cin.ignore(80, '\n');
    cout << "Введiть день (1-31): ";
    cin >> day;
    cin.ignore(80, '\n');
    cout << "Введiть категорiю витрат (Ремонт, Податки): ";
    getaLine(category);
    cout << "Введiть отримувача " << "(ЛьвiвЕлектроЗбут): ";
    getaLine(payee);
    cout << "Введiть суму (39.95): ";
    cin >> amount;
    cin.ignore(80, '\n');
    Expense* ptrExpense = new Expense(month, day, category, payee, amount);

    ptrExpenseRecord->insertExp(ptrExpense);
}
