#include "ExpenseRecord.h"
#include "Expense.h"
#include <iostream>
#include <algorithm>

using namespace std;

ExpenseRecord::~ExpenseRecord()        // Оголошення деструктора
{
    while (!vectPtrsExpenses.empty()) {    // Видалити об'єкти Expense

        // Видалити вказівники на вектор
        iter = vectPtrsExpenses.begin();
        delete *iter;
        vectPtrsExpenses.erase(iter);
    }
}

void ExpenseRecord::insertExp(Expense* ptrExp) {
    vectPtrsExpenses.push_back(ptrExp);
}

void ExpenseRecord::Display() {
    cout << endl << "Дата\tОтримувач\t\tСума\tКатегорiя\n"
         << "----------------------------------------" << endl;
    if (vectPtrsExpenses.empty())
        cout << "*** Витрат немає ***" << endl;
    else {
        sort(vectPtrsExpenses.begin(), // Сортування за датою
             vectPtrsExpenses.end(), CompareDates());
        iter = vectPtrsExpenses.begin();
        while (iter != vectPtrsExpenses.end()) cout << **iter++;
    }
}

float ExpenseRecord::displaySummary() // Використовується під час складання річного звіту
{
    float totalExpenses = 0; // Сума, всі категорії
    if (vectPtrsExpenses.empty()) {
        cout << "\tВсi категорiї\t0" << endl;
        return 0;
    }
    // Сортувати за категоріями
    sort(vectPtrsExpenses.begin(), vectPtrsExpenses.end(), CompareCategories());
    // По кожній категорії сума записів
    iter = vectPtrsExpenses.begin();
    string tempCat = (*iter)->category;
    float sumCat = 0.0;

    while (iter != vectPtrsExpenses.end()) {
        if (tempCat == (*iter)->category)
            sumCat += (*iter)->amount; // Та ж категорія
        else {                // Інша
            cout << '\t' << tempCat << '\t' << sumCat << endl;
            totalExpenses += sumCat; // Додати попередню категорію
            tempCat = (*iter)->category;
            sumCat = (*iter)->amount; // Додати остаточне значення суми
        }
        iter++;
    }

    totalExpenses += sumCat; // Додати суму кінцевої категорії
    cout << '\t' << tempCat << '\t' << sumCat << endl;
    return totalExpenses;
}
