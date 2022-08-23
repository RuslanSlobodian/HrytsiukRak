//Код програми 7.6. Демонстрація механізму створення класу з одним узагальненим типом даних

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;

const int size=100;
// Створення узагальненого класу queueClass.
template <class qType> class queueClass {
    qType array[size];
    int sloc, rloc;
public:
    queueClass() { sloc = rloc = 0; }
    void Get(qType c);
    qType Put(); // Виведення з об'єкта значення
};
// Занесення об'єкта в чергу.
template <class qType> void queueClass<qType>::Get(qType c)
{
    if(sloc==size) { cout << "Черга заповнена" << endl; return; }
    sloc++;
    array[sloc] = c;
}
// Вилучення об'єкта з черги.
template <class qType> qType queueClass<qType>::Put()
{
    if(rloc == sloc) { cout << "Черга порожня" << endl; return 0; }
    rloc++;
    return array[rloc];
}
int main()
{
    queueClass<int> ObjA, ObjB; // Створюємо дві черги для int-значень.
    ObjA.Get(10);
    ObjB.Get(19);
    ObjA.Get(20);
    ObjB.Get(1);
    cout << ObjA.Put() << "\t";
    cout << ObjA.Put() << "\t";
    cout << ObjB.Put() << "\t";
    cout << ObjB.Put() << endl;
    queueClass<double> ObjC, ObjD; // Створюємо дві черги для double-значень
    ObjC.Get(10.12);
    ObjD.Get(19.99);
    ObjC.Get(-20.0);
    ObjD.Get(0.986);
    cout << ObjC.Put() << "\t";
    cout << ObjC.Put() << "\t";
    cout << ObjD.Put() << "\t";
    cout << ObjD.Put() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}
