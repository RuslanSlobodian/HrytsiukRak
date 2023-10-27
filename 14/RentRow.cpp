#include "RentRow.h"
#include <algorithm>
#include <numeric>

using namespace std;

RentRow::RentRow(int an) : aptNo(an) // Однопараметризований конструктор
{ fill(&rent[0], &rent[12], 0); }

void RentRow::setRent(int m, float am) {
    rent[m] = am;
}

float RentRow::getSumOfRow()    // Сума орендних платежів у рядку
{
    return accumulate(&rent[0], &rent[12], 0.0f);
}

bool operator<(const RentRow& t1, const RentRow& t2) {
    return t1.aptNo < t2.aptNo;
}

bool operator==(const RentRow& t1, const RentRow& t2) {
    return t1.aptNo == t2.aptNo;
}

ostream& operator<<(ostream& s, const RentRow& an) {
    s << an.aptNo << '\t';      // Вивести номер кімнати
    for (float j: an.rent) {    // Вивести 12 орендних платежів
        if (j == 0) s << " 0 ";
        else s << j << " ";
    }
    s << endl;
    return s;
}

bool CompareRows::operator()(const RentRow* ptrR1, const RentRow* ptrR2) const {
    return *ptrR1 < *ptrR2;
}
