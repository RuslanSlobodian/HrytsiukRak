#ifndef LANDLORD_TENANT_H
#define LANDLORD_TENANT_H

#include <string>

class Tenant {              // Мешканці
private:
    std::string name;       // Ім'я мешканця
    int aptNumber;          // Номер кімнати мешканця
    // Тут може бути будь-яка інша інформація про мешканця,
    // наприклад, номер телефону і т.ін.
public:
    Tenant(const std::string& n, int aNo);

    ~Tenant() = default;

    int getAptNumber() const; // Потрібно для використання в множині
    friend bool operator<(const Tenant&, const Tenant&);

    friend bool operator==(const Tenant&, const Tenant&);

    // Для операцій введення/виведення
    friend std::ostream& operator<<(std::ostream&, const Tenant&);
};

// Функціональний об'єкт для порівняння імен мешканців
class CompareTenants {

public:
    bool operator()(const Tenant*, const Tenant*) const;
};

#endif //LANDLORD_TENANT_H
