#ifndef LANDLORD_EXPENSE_RECORD_H
#define LANDLORD_EXPENSE_RECORD_H

#include <vector>
#include "Expense.h"

class ExpenseRecord {
private:
    // Вектор покажчиків на витрати
    std::vector<Expense*> vectPtrsExpenses;
    std::vector<Expense*>::iterator iter;
public:
    ~ExpenseRecord();

    void insertExp(Expense*);

    void Display();

    float displaySummary(); // Потрібно для річного звіту
};

#endif //LANDLORD_EXPENSE_RECORD_H
