// Код програми 7.6. Демонстрація механізму створення класу з одним узагальненим типом даних

#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 100;

// Створення узагальненого класу QueueClass
template<typename T>
class QueueClass {
    T array[SIZE];
    int sloc, rloc;
public:
    QueueClass() { sloc = rloc = 0; }

    void push(T c);         // Добавлення об'єкта в чергу

    T pop();                // Виведення об'єкта з черги
};

// Занесення об'єкта в чергу
template<typename T>
void QueueClass<T>::push(T c) {
    if (sloc == SIZE) {
        cout << "Черга заповнена" << endl;
        return;
    }
    sloc++;
    array[sloc] = c;
}

// Вилучення об'єкта з черги
template<typename T>
T QueueClass<T>::pop() {
    if (rloc == sloc) {
        cout << "Черга порожня" << endl;
        return 0;
    }
    rloc++;
    return array[rloc];
}

int main() {
    system("chcp 65001");
    QueueClass<int> queueA, queueB; // Створюємо дві черги для int-значень
    queueA.push(10);
    queueB.push(19);
    queueA.push(20);
    queueB.push(1);
    cout << queueA.pop() << "\t";
    cout << queueA.pop() << "\t";
    cout << queueB.pop() << "\t";
    cout << queueB.pop() << endl;
    QueueClass<double> queueC, queueD; // Створюємо дві черги для double-значень
    queueC.push(10.12);
    queueD.push(19.99);
    queueC.push(-20.0);
    queueD.push(0.986);
    cout << queueC.pop() << "\t";
    cout << queueC.pop() << "\t";
    cout << queueD.pop() << "\t";
    cout << queueD.pop() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}
