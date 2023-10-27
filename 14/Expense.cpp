#include "Expense.h"
#include <iostream>

using namespace std;

bool operator<(const Expense& e1, const Expense& e2) {  // Порівнює дати

    if (e1.month == e2.month)       // Якщо той же місяць
        return e1.day < e2.day;     // Порівняти дні
    else                            // Інакше
        return e1.month < e2.month; // Порівняти місяці
}

bool operator==(const Expense& e1, const Expense& e2) {
    return e1.month == e2.month && e1.day == e2.day;
}

ostream& operator<<(ostream& s, const Expense& exp) {
    s << exp.month << '/' << exp.day << '\t' << exp.payee << '\t';

    s << exp.amount << '\t' << exp.category << endl;
    return s;
}

bool CompareDates::operator()(const Expense* ptrE1, const Expense* ptrE2) const {
    return *ptrE1 < *ptrE2;
}

bool CompareCategories::operator()(const Expense* ptrE1, const Expense* ptrE2) const {
    return ptrE1->category < ptrE2->category;
}
