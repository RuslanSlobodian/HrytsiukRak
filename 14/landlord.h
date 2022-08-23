// Заголовний файл landlord.h - містить оголошення класів і т.ін.
#pragma warning(disable:4786) // Для множин (тільки компілятори Microsoft)
#include <iostream> 		// Для потокового введення-виведення
#include <vector> 		// Для роботи з контейнерним класом "Вектор"
#include <set>
#include <string.h> 		// Для роботи з рядковими типами
#include <algorithm> 		// Для sort()
#include <numeric> 		// Для accumulate()

using namespace std; 		// Використання стандартного простору імен

/// Глобальні методи ///
void getaLine(string& inStr); 	// Отримання рядка тексту
char getaChar(); 			// Отримання символу

class tenant {			 // Мешканці
private:
    string name;		 // Ім'я мешканця
    int aptNumber;		 // Номер кімнати мешканця
// Тут може бути будь-яка інша інформація про мешканця,
// наприклад, номер телефону і т.ін.
public:
    tenant(string n, int aNo);
    ~tenant();
    int getAptNumber(); // Потрібно для використання в множині
    friend bool operator < (const tenant&, const tenant&);
    friend bool operator == (const tenant&, const tenant&);
    // Для операцій введення/виведення
    friend ostream& operator << (ostream&, const tenant&);
}; // <------> Кінець оголошення класу tenant

// Функціональний об'єкт для порівняння імен мешканців
class compareTenants {

public:
    bool operator () (tenant*, tenant*) const;
};

// >------> Клас tenantList
class tenantList {
private:
// Встановити покажчики на мешканців
    set<tenant*, compareTenants> setPtrsTens;
    set<tenant*, compareTenants>::iterator iter;
public:
    ~tenantList();		 // Оголошення деструктора (Видалення мешканців)
    void insertTenant(tenant*); 		// Внесення мешканця в перелік
    int getAptNo(string);			 // Повертає номер кімнати
    void Display(); 				// Виведення переліку мешканців
};
// <------> Кінець оголошення класу tenantList
class tenantInputScreen {
private:
    tenantList* ptrTenantList;
    string tName;
    int aptNo;
public:
    tenantInputScreen(tenantList* ptrTL): ptrTenantList(ptrTL)
    { /* тут порожньо */ }
    void getTenant();
}; // <------> Кінець класу tenantInputScreen

// Один рядок таблиці прибутку: адреса і 12 місячних плат
class rentRow {
private:
    int aptNo;
    float rent[12];
public:
    rentRow(int); // Оголошення конструктора з одним параметром
    void setRent(int, float); // Запис плати за місяць
    float getSumOfRow(); // Сума платежів з одного рядка
    // Потрібно для збереження в множині
    friend bool operator < (const rentRow&, const rentRow&);
    friend bool operator == (const rentRow&, const rentRow&);
    friend ostream& operator << (ostream&, const rentRow&); // Для виведення
}; // <------> Кінець класу rentRow

// Функціональний об'єкт порівняння об'єктів rentRows
class compareRows {
public:
    bool operator () (rentRow*, rentRow*) const;
};

class rentRecord {
private:
    // Множину покажчиків на об'єкти rentRow (по одному на мешканця)
    set<rentRow*, compareRows> setPtrsRR;
    set<rentRow*, compareRows>::iterator iter;
public:
    ~rentRecord();
    void insertRent(int, int, float);
    void Display();
    float getSumOfRents(); // Сума усіх платежів
}; // <------> Кінець класу rentRecord

class rentInputScreen {
private:
    tenantList* ptrTenantList;
    rentRecord* ptrRentRecord;
    string renterName;
    float rentPaid;
    int month;
    int aptNo;
public:
    rentInputScreen(tenantList* ptrTL, rentRecord* ptrRR):
    ptrTenantList(ptrTL), ptrRentRecord(ptrRR)
    { /*тут пусто*/ }
    void getRent(); // Орендна плата одного мешканця за один місяць
}; // <------> Кінець класу rentInputScreen

class expense {
public:
    int month, day;
    string category, payee;
    float amount;
    expense() { }
    expense(int m, int d, string c, string p, float a):
    month(m), day(d), category(c), payee(p), amount(a)
    { /* тут порожньо! */ }

    friend bool operator < (const expense&, const expense&);
    friend bool operator == (const expense&, const expense&);
    // Потрібно для виведення
    friend ostream& operator << (ostream&, const expense&);
}; // <------> Кінець класу expense

// Функціональний об'єкт порівняння витрат
class compareDates {
public:
    bool operator () (expense*, expense*) const;
    // Функціональний об'єкт порівняння витрат
};

class compareCategories {
public:
    bool operator () (expense*, expense*) const;
};

class expenseRecord {
private:
    // Вектор покажчиків на витрати
    vector<expense*> vectPtrsExpenses;
    vector<expense*>::iterator iter;
public:
    ~expenseRecord();
    void insertExp(expense*);
    void Display();
    float displaySummary(); // Потрібно для річного звіту
}; // <------> Кінець класу expenseRecord

class expenseInputScreen {
private:
    expenseRecord* ptrExpenseRecord;
public:
    expenseInputScreen(expenseRecord*);
    void getExpense();
}; // <------> Кінець класу expenseInputScreen

class annualReport {
private:
    rentRecord* ptrRR;
    expenseRecord* ptrER;
    float expenses, rents;
public:
    annualReport(rentRecord*, expenseRecord*);
    void Display();
}; // <------> Кінець класу annualReport

class userInterface {
private:
    tenantList* ptrTenantList;
    tenantInputScreen* ptrTenantInputScreen;
    rentRecord* ptrRentRecord;
    rentInputScreen* ptrRentInputScreen;
    expenseRecord* ptrExpenseRecord;
    expenseInputScreen* ptrExpenseInputScreen;
    annualReport* ptrAnnualReport;
    char ch;
public:
    userInterface();
    ~userInterface();
    void interact();
}; // <------> Кінець класу userInterfac

// <------> Кінець файлу landlord.h

