//Код програми 11.3. Демонстрація механізму використання безпосередньозаданої
//кваліфікації бібліотечних імен префіксом std::

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++


int main()
{
    double n;
    std::cout << "Введiть число: "; std::cin >> n;

    std::cout << "Ви ввели число ";
    std::cout << n;

    //system("PAUSE");
    return EXIT_SUCCESS;
}
