#ifndef LANDLORD_RENT_ROW_H
#define LANDLORD_RENT_ROW_H

#include <ostream>

// Один рядок таблиці прибутку: адреса і 12 місячних плат
class RentRow {
private:
    int aptNo;
    float rent[12];
public:
    explicit RentRow(int); // Оголошення конструктора з одним параметром
    void setRent(int, float); // Запис плати за місяць
    float getSumOfRow(); // Сума платежів з одного рядка
    // Потрібно для збереження в множині
    friend bool operator<(const RentRow&, const RentRow&);

    friend bool operator==(const RentRow&, const RentRow&);

    friend std::ostream& operator<<(std::ostream&, const RentRow&); // Для виведення
};

// Функціональний об'єкт порівняння об'єктів rentRows
class CompareRows {
public:
    bool operator()(const RentRow*, const RentRow*) const;
};

#endif //LANDLORD_RENT_ROW_H
