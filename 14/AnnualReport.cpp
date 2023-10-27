#include "AnnualReport.h"
#include <iostream>

using namespace std;

AnnualReport::AnnualReport(RentRecord* pRR, ExpenseRecord* pER) : ptrRR(pRR), ptrER(pER) {}

//---------------------------------------------------------
void AnnualReport::Display() {
    cout << "Рiчний звіт\n--------------" << endl;
    cout << "Доходи" << endl;
    cout << "\tОрендна плата\t\t";
    rents = ptrRR->getSumOfRents();
    cout << rents << endl;
    cout << "Витрати" << endl;
    expenses = ptrER->displaySummary();
    cout << endl << "Баланс\t\t\t" << rents - expenses << endl;
}
