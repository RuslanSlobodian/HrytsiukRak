#ifndef LANDLORD_EXPENSE_INPUT_SCREEN_H
#define LANDLORD_EXPENSE_INPUT_SCREEN_H

#include "ExpenseRecord.h"

class ExpenseInputScreen {
private:
    ExpenseRecord* ptrExpenseRecord;
public:
    explicit ExpenseInputScreen(ExpenseRecord*);

    void getExpense();
};

#endif //LANDLORD_EXPENSE_INPUT_SCREEN_H
