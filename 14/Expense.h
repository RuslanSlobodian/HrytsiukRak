#ifndef LANDLORD_EXPENSE_H
#define LANDLORD_EXPENSE_H

#include <string>

class Expense {
public:
    int month;
    int day;
    std::string category;
    std::string payee;
    float amount;

    Expense() = default;

    Expense(int m, int d, const std::string& c, const std::string& p, float a) :
            month(m), day(d), category(c), payee(p), amount(a) {}

    friend bool operator<(const Expense&, const Expense&);

    friend bool operator==(const Expense&, const Expense&);

    // Потрібно для виведення
    friend std::ostream& operator<<(std::ostream&, const Expense&);
};

// Функціональний об'єкт порівняння витрат
class CompareDates {
public:
    bool operator()(const Expense*, const Expense*) const;
};

// Функціональний об'єкт порівняння витрат
class CompareCategories {
public:
    bool operator()(const Expense*, const Expense*) const;
};

#endif //LANDLORD_EXPENSE_H
