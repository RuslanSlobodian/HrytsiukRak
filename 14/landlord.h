//#pragma warning(disable:4786) // Для множин (тільки компілятори Microsoft)

#include <iostream>        // Для потокового введення-виведення
#include <vector>        // Для роботи з контейнерним класом "Вектор"
#include <set>
#include <string.h>        // Для роботи з рядковими типами
#include <algorithm>        // Для sort()
#include <numeric>        // Для accumulate()

using namespace std;        // Використання стандартного простору імен

/// Глобальні методи ///
void getaLine(string& inStr);    // Отримання рядка тексту
char getaChar();            // Отримання символу

class Tenant {             // Мешканці
private:
    string name;         // Ім'я мешканця
    int aptNumber;         // Номер кімнати мешканця
// Тут може бути будь-яка інша інформація про мешканця,
// наприклад, номер телефону і т.ін.
public:
    Tenant(string n, int aNo);

    ~Tenant();

    int getAptNumber(); // Потрібно для використання в множині
    friend bool operator<(const Tenant&, const Tenant&);

    friend bool operator==(const Tenant&, const Tenant&);

    // Для операцій введення/виведення
    friend ostream& operator<<(ostream&, const Tenant&);
}; // <------> Кінець оголошення класу Tenant

// Функціональний об'єкт для порівняння імен мешканців
class CompareTenants {

public:
    bool operator()(Tenant*, Tenant*) const;
};

// >------> Клас TenantList
class TenantList {
private:
// Встановити покажчики на мешканців
    set<Tenant*, CompareTenants> setPtrsTens;
    set<Tenant*, CompareTenants>::iterator iter;
public:
    ~TenantList();         // Оголошення деструктора (Видалення мешканців)
    void insertTenant(Tenant*);        // Внесення мешканця в перелік
    int getAptNo(string);             // Повертає номер кімнати
    void Display();                // Виведення переліку мешканців
};

// <------> Кінець оголошення класу TenantList
class TenantInputScreen {
private:
    TenantList* ptrTenantList;
    string tName;
    int aptNo;
public:
    TenantInputScreen(TenantList* ptrTL) : ptrTenantList(ptrTL) { /* тут порожньо */ }

    void getTenant();
}; // <------> Кінець класу TenantInputScreen

// Один рядок таблиці прибутку: адреса і 12 місячних плат
class RentRow {
private:
    int aptNo;
    float rent[12];
public:
    RentRow(int); // Оголошення конструктора з одним параметром
    void setRent(int, float); // Запис плати за місяць
    float getSumOfRow(); // Сума платежів з одного рядка
    // Потрібно для збереження в множині
    friend bool operator<(const RentRow&, const RentRow&);

    friend bool operator==(const RentRow&, const RentRow&);

    friend ostream& operator<<(ostream&, const RentRow&); // Для виведення
}; // <------> Кінець класу RentRow

// Функціональний об'єкт порівняння об'єктів rentRows
class CompareRows {
public:
    bool operator()(RentRow*, RentRow*) const;
};

class RentRecord {
private:
    // Множину покажчиків на об'єкти RentRow (по одному на мешканця)
    set<RentRow*, CompareRows> setPtrsRR;
    set<RentRow*, CompareRows>::iterator iter;
public:
    ~RentRecord();

    void insertRent(int, int, float);

    void Display();

    float getSumOfRents(); // Сума усіх платежів
}; // <------> Кінець класу RentRecord

class RentInputScreen {
private:
    TenantList* ptrTenantList;
    RentRecord* ptrRentRecord;
    string renterName;
    float rentPaid;
    int month;
    int aptNo;
public:
    RentInputScreen(TenantList* ptrTL, RentRecord* ptrRR) :
            ptrTenantList(ptrTL), ptrRentRecord(ptrRR) { /*тут пусто*/ }

    void getRent(); // Орендна плата одного мешканця за один місяць
}; // <------> Кінець класу RentInputScreen

class Expense {
public:
    int month, day;
    string category, payee;
    float amount;

    Expense() {}

    Expense(int m, int d, string c, string p, float a) :
            month(m), day(d), category(c), payee(p), amount(a) { /* тут порожньо! */ }

    friend bool operator<(const Expense&, const Expense&);

    friend bool operator==(const Expense&, const Expense&);

    // Потрібно для виведення
    friend ostream& operator<<(ostream&, const Expense&);
}; // <------> Кінець класу Expense

// Функціональний об'єкт порівняння витрат
class CompareDates {
public:
    bool operator()(Expense*, Expense*) const;
    // Функціональний об'єкт порівняння витрат
};

class CompareCategories {
public:
    bool operator()(Expense*, Expense*) const;
};

class ExpenseRecord {
private:
    // Вектор покажчиків на витрати
    vector<Expense*> vectPtrsExpenses;
    vector<Expense*>::iterator iter;
public:
    ~ExpenseRecord();

    void insertExp(Expense*);

    void Display();

    float displaySummary(); // Потрібно для річного звіту
}; // <------> Кінець класу ExpenseRecord

class ExpenseInputScreen {
private:
    ExpenseRecord* ptrExpenseRecord;
public:
    ExpenseInputScreen(ExpenseRecord*);

    void getExpense();
}; // <------> Кінець класу ExpenseInputScreen

class AnnualReport {
private:
    RentRecord* ptrRR;
    ExpenseRecord* ptrER;
    float expenses, rents;
public:
    AnnualReport(RentRecord*, ExpenseRecord*);

    void Display();
}; // <------> Кінець класу AnnualReport

class UserInterface {
private:
    TenantList* ptrTenantList;
    TenantInputScreen* ptrTenantInputScreen;
    RentRecord* ptrRentRecord;
    RentInputScreen* ptrRentInputScreen;
    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen* ptrExpenseInputScreen;
    AnnualReport* ptrAnnualReport;
    char ch;
public:
    UserInterface();

    ~UserInterface();

    void interact();
}; // <------> Кінець класу userInterfac

// <------> Кінець файлу landlord.h

