#include "landlord.h"

void getaLine(string& inStr) // Отримання рядка тексту
{
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n');
    inStr = temp;
} // <------> Кінець getaLine()

char getaChar() // Отримання символу
{
    char ch = cin.get();
    cin.ignore(80, '\n');
    return ch;
} // <------> Кінець getaChar()

// >------> Методи класу tenant
tenant::tenant(string n, int aNo) : name(n), aptNumber(aNo)
    { /* тут порожньо */ }
//---------------------------------------------------------
tenant::~tenant()
    { /* тут також порожньо */ }
//---------------------------------------------------------
int tenant::getAptNumber()
    { return aptNumber; }

bool operator < (const tenant& t1, const tenant& t2)
    { return t1.name < t2.name; }
//---------------------------------------------------------
bool operator == (const tenant& t1, const tenant& t2)
    { return t1.name == t2.name; }
//---------------------------------------------------------
ostream& operator << (ostream& s, const tenant& t)
    { s << t.aptNumber << '\t' << t.name << endl; return s; }
//---------------------------------------------------------

// >------> Методи класу tenantInputScreen
void tenantInputScreen::getTenant() // Отримання даних про мешканцях
{
    cout << "Введiть iм'я мешканця (Тарас Редько): ";
    getaLine(tName);
    cout << "Введiть номер кiмнати (101): ";
    cin >> aptNo;
    cin.ignore(80, '\n'); // Створити мешканця
    tenant* ptrTenant = new tenant(tName, aptNo);
    ptrTenantList->insertTenant(ptrTenant); // Занести перелік мешканців
}
bool compareTenants::operator () (tenant* ptrT1, tenant* ptrT2) const
    { return *ptrT1 < *ptrT2; }
//---------------------------------------------------------
// >------> Методи класу tenantList
tenantList::~tenantList() // Оголошення деструктора
{
    while( !setPtrsTens.empty() ) { 	// Видалення усіх мешканців
        // Видалення покажчиків з множини
        iter = setPtrsTens.begin();
        delete *iter;
        setPtrsTens.erase(iter);
    }
} // <------> Кінець ~tenantList()
void tenantList::insertTenant(tenant* ptrT)
{
    setPtrsTens.insert(ptrT); // Вставка
}
//---------------------------------------------------------
int tenantList::getAptNo(string tName) // Ім'я присутнє у переліку?
{
    int aptNo;
    tenant dummy(tName, 0);
    iter = setPtrsTens.begin();
    while( iter != setPtrsTens.end() ) {
        aptNo = (*iter)->getAptNumber(); 		// Пошук мешканця
        if(dummy == **iter++) 				// В переліку?
        return aptNo; 					// Так
    }
    return -1; 							// Немає
} // <------> Кінець getAptNo()

void tenantList::Display() // Виведення переліку мешканців
{
    cout << endl << "Apt#\tIм'я мешканця\n-------------------" << endl;
    if( setPtrsTens.empty() )
        cout << "***Нема мешканцiв***" << endl;
    else {
        iter = setPtrsTens.begin();
        while( iter != setPtrsTens.end() ) cout << **iter++;
    }
} // <------> Кінець Display()

// >------> Методи класу rentRow
rentRow::rentRow(int an) : aptNo(an) // Однопараметризований конструктор
    { fill( &rent[0], &rent[12], 0); }
//---------------------------------------------------------
void rentRow::setRent(int m, float am)
    { rent[m]= am; }
//---------------------------------------------------------
float rentRow::getSumOfRow() // Сума орендних платежів у рядку
    { return accumulate( &rent[0], &rent[12], 0); }
//---------------------------------------------------------
bool operator < (const rentRow& t1, const rentRow& t2)
    { return t1.aptNo < t2.aptNo; }
//---------------------------------------------------------
bool operator == (const rentRow& t1, const rentRow& t2)
    { return t1.aptNo == t2.aptNo; }
//---------------------------------------------------------
ostream& operator << (ostream& s, const rentRow& an)
{
    s << an.aptNo << '\t'; // Вивести номер кімнати
    for(int j=0; j<12; j++) { // Вивести 12 орендних платежів
        if(an.rent[j] == 0) s << " 0 ";
        else s << an.rent[j] << " ";
    }
    s << endl;
    return s;
} // <------> Кінець operator <<
bool compareRows::operator () (rentRow* ptrR1, rentRow* ptrR2) const
    { return *ptrR1 < *ptrR2; }
// >------> Методи класу rentRecord
rentRecord::~rentRecord() // Оголошення деструктора
{
    while( !setPtrsRR.empty() ) { 		// Видалити рядки з платежами

    // Видалити покажчики з множини
    iter = setPtrsRR.begin();
    delete *iter;
    setPtrsRR.erase(iter);
    }
} // <------> Кінець ~rentRecord()

void rentRecord::insertRent(int aptNo, int month, float amount)
{
    rentRow searchRow(aptNo); // Тимчасовий рядок з тим самим aptNo
    iter = setPtrsRR.begin(); // Пошук setPtrsRR
    while( iter != setPtrsRR.end() ) {
        if(searchRow==**iter) { // rentRow знайдений?
            // так, заносимо
            (*iter)->setRent(month, amount); // Рядок у перелік
            return;
        }
        else iter++;
    } // Не знайдений
    rentRow* ptrRow = new rentRow(aptNo); 		// Новий рядок
    ptrRow->setRent(month, amount); 			// Занести в неї платіж
    setPtrsRR.insert(ptrRow); 				// Занести рядок вектор
} // <------> Кінець insertRent()

void rentRecord::Display()
{
    cout << endl << "AptNo\tСiч Лют Бер Квiт Трав Черв "
    << "Лип Серп Вер Жовт Лист Груд\n"
    << "---------------------------------"
    << "---------------------------------" << endl;
    if( setPtrsRR.empty() )
        cout << "***Нема платежiв!***" << endl;
    else {
        iter = setPtrsRR.begin();
        while( iter != setPtrsRR.end() )
        cout << **iter++;
    }
} // <------> Кінець Display()

float rentRecord::getSumOfRents() 		// Сума усіх платежів
{
    float sumRents = 0.0;
    iter = setPtrsRR.begin();
    while( iter != setPtrsRR.end() ) {
        sumRents += (*iter)->getSumOfRow();
        iter++;
    }
    return sumRents;
} // <------> Кінець getSumOfRents()

// >------> Методи класу rentInputScreen
void rentInputScreen::getRent()
{
    cout << "Введiть iм'я мешканця: ";
    getaLine(renterName);
    aptNo = ptrTenantList->getAptNo(renterName);
    if(aptNo > 0) { 		// Якщо ім'я знайдене
                                // Отримати суму платежу
        cout << "Введiть суму платежу (345.67): ";
        cin >> rentPaid;
        cin.ignore(80, '\n');
        cout << "Введiть номер мiсяця оплати (1-12): ";
        cin >> month;
        cin.ignore(80, '\n');
        month--; // (внутрішня нумерація 0-11)
        ptrRentRecord->insertRent(aptNo, month, rentPaid);
    }
    else 					// Повернення
    cout << "Такого мешканця немає" << endl;
} // <------> Кінець getRent()
// Методи класу expense
bool operator < (const expense& e1, const expense& e2)
{ 						// Порівнює дати

    if(e1.month == e2.month) 	// Якщо той же місяць
    return e1.day < e2.day; 			// Порівняти дні
    else 								// Інакше
    return e1.month < e2.month; 		// Порівняти місяці
}
//---------------------------------------------------------
bool operator == (const expense& e1, const expense& e2)
    { return e1.month == e2.month && e1.day == e2.day; }
//---------------------------------------------------------
ostream& operator << (ostream& s, const expense& exp)
    {
    s << exp.month << '/' << exp.day << '\t' << exp.payee << '\t' ;

    s << exp.amount << '\t' << exp.category << endl;
    return s;
}
//---------------------------------------------------------
bool compareDates::operator () (expense* ptrE1, expense* ptrE2) const
    { return *ptrE1 < *ptrE2; }
//---------------------------------------------------------
bool compareCategories::operator ()(expense* ptrE1, expense* ptrE2) const
    { return ptrE1->category < ptrE2->category; }
//---------------------------------------------------------
// >------> Методи класу expenseRecord
expenseRecord::~expenseRecord() 		// Оголошення деструктора
{
    while( !vectPtrsExpenses.empty() ) { 	// Видалити об'єкти expense

        // Видалити покажчики на вектор
        iter = vectPtrsExpenses.begin();
        delete *iter;
        vectPtrsExpenses.erase(iter);
    }
} // <------> Кінець ~expenseRecord()
void expenseRecord::insertExp(expense* ptrExp)
    { vectPtrsExpenses.push_back(ptrExp); }
//---------------------------------------------------------
void expenseRecord::Display()
{
    cout << endl << "Дата\tОтримувач\t\tСума\tКатегорiя\n"
    << "----------------------------------------" << endl;
    if( vectPtrsExpenses.size() == 0 )
    cout << "*** Витрат немає ***" << endl;
    else {
        sort( vectPtrsExpenses.begin(), // Сортування за датою
        vectPtrsExpenses.end(), compareDates() );
        iter = vectPtrsExpenses.begin();
        while( iter != vectPtrsExpenses.end() ) cout << **iter++;
    }
} // <------> Кінець Display()

float expenseRecord::displaySummary() // Використовується під час складання річного звіту
{
    float totalExpenses = 0; // Сума, всі категорії
    if( vectPtrsExpenses.size() == 0 ) {
        cout << "\tВсi категорiї\t0" << endl;
        return 0;
    }
    // Сортувати за категоріями
    sort( vectPtrsExpenses.begin(), vectPtrsExpenses.end(), compareCategories() );
    // По кожній категорії сума записів
    iter = vectPtrsExpenses.begin();
    string tempCat = (*iter)->category;
    float sumCat = 0.0;
    while( iter != vectPtrsExpenses.end() ) {
        if(tempCat == (*iter)->category)
            sumCat += (*iter)->amount; // Та ж категорія
        else { 				// Інша
            cout << '\t' << tempCat << '\t' << sumCat << endl;
            totalExpenses += sumCat; // Додати попередню категорію
            tempCat = (*iter)->category;
            sumCat = (*iter)->amount; // Додати остаточне значення суми
        }
        iter++;
    } // <------> Кінець while
    totalExpenses += sumCat; // Додати суму кінцевої категорії
    cout << '\t' << tempCat << '\t' << sumCat << endl;
    return totalExpenses;
} // <------> Кінець displaySummary()
// >------> Методи класу expenseInputScreen
expenseInputScreen::expenseInputScreen(expenseRecord* per) : ptrExpenseRecord(per)
{ /*пусто*/ }
//------------------------------------------------------
void expenseInputScreen::getExpense()
{
    int month, day;
    string category, payee;
    float amount;
    cout << "Введiть місяць (1-12): "; cin >> month; cin.ignore(80, '\n');
    cout << "Введiть день (1-31): "; cin >> day; cin.ignore(80, '\n');
    cout << "Введiть категорiю витрат (Ремонт, Податки): ";
    getaLine(category);
    cout << "Введiть отримувача " << "(ЛьвiвЕлектроЗбут): ";
    getaLine(payee);
    cout << "Введiть суму (39.95): "; cin >> amount; cin.ignore(80, '\n');
    expense* ptrExpense = new
    expense(month, day, category, payee, amount);

    ptrExpenseRecord->insertExp(ptrExpense);
} // <------> Кінець getExpense()
// >------> Методи класу annualReport
annualReport::annualReport(rentRecord* pRR, expenseRecord* pER) : ptrRR(pRR), ptrER(pER)
{ /* порожньо */ }
//---------------------------------------------------------
void annualReport::Display()
{
    cout << "Рiчний звіт\n--------------" << endl;
    cout << "Доходи" << endl;
    cout << "\tОрендна плата\t\t";
    rents = ptrRR->getSumOfRents();
    cout << rents << endl;
    cout << "Витрати" << endl;
    expenses = ptrER->displaySummary();
    cout << endl << "Баланс\t\t\t" << rents - expenses << endl;
} // <------> Кінець Display()
// >------> Методи класу userInterface
userInterface::userInterface()
{ // Це життєво важливо для програми
    ptrTenantList = new tenantList;
    ptrRentRecord = new rentRecord;
    ptrExpenseRecord = new expenseRecord;
} // <------> Кінець userInterface()
userInterface::~userInterface() // Оголошення деструктора
{
    delete ptrTenantList;
    delete ptrRentRecord;
    delete ptrExpenseRecord;
} // <------> Кінець ~userInterface()
void userInterface::interact()
{
    while(true) {
        cout << "Для введення даних натисніть 'i'\n"
        << " 'd' для виведення звiту\n"
        << " 'q' для виходу: ";
        ch = getaChar();
        if(ch=='i') { // Введення даних
            cout << " 't' для додавання мешканця\n"
            << " 'r' для запису орендної плати\n"
            << " 'e' для запису витрат: ";

            ch = getaChar();
            switch(ch) {
                // Екрани введення існують тільки під час їх використання
                case 't': ptrTenantInputScreen =
                new tenantInputScreen(ptrTenantList);
                ptrTenantInputScreen->getTenant();
                delete ptrTenantInputScreen;
                break;
                case 'r': ptrRentInputScreen =
                new rentInputScreen(ptrTenantList, ptrRentRecord);
                ptrRentInputScreen->getRent();
                delete ptrRentInputScreen;
                break;
                case 'e': ptrExpenseInputScreen =
                new expenseInputScreen(ptrExpenseRecord);
                ptrExpenseInputScreen->getExpense();
                delete ptrExpenseInputScreen;
                break;
                default: cout << "Невiдома функцiя" << endl;
                break;
            } // <------> Кінець секції switch
        } // <------> Кінець умови if
        else if(ch=='d') { // Виведення даних
            cout << " 't' для виведення мешканцiв\n"
            << " 'r' для виведення орендної плати\n"
            << " 'e' для виведення витрат\n"
            << " 'a' для виведення рiчного звіту: ";
            ch = getaChar();
            switch(ch) {
                case 't': ptrTenantList->Display();
                break;
                case 'r': ptrRentRecord->Display();
                break;
                case 'e': ptrExpenseRecord->Display();
                break;
                case 'a':
                ptrAnnualReport = new annualReport(ptrRentRecord,
                ptrExpenseRecord);
                ptrAnnualReport->Display();
                delete ptrAnnualReport;
                break;
                default: cout << "Невiдома функцiя виведення" << endl;
                break;
            } // <------> Кінець switch
        } // <------> Кінець elseif
        else if(ch=='q')
        return; // Вихід
        else
        cout << "Невiдома функцiя" << endl;
        cout << "Натискайте тiльки 'i', 'd' або 'q'" << endl;
    } // <------> Кінець while
} // <------> Кінець interact()
// <------> Кінець файлу landlord.cpp

