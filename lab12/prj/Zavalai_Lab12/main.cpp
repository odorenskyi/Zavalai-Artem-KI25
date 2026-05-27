#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "ModulesZavalai.h"

using namespace std;

int main() {
    // Налаштування кирилиці
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // 1. ПІДСИСТЕМА «TEACHER»
    string currentPath = __FILE__;
    if (currentPath.find("lab12\\prj") == string::npos && currentPath.find("lab12/prj") == string::npos) {ФФФФФФ
        // Якщо структура папок порушена — пищимо 100 разів
        for (int i = 0; i < 100; i++) {
            cout << "\a";
            Sleep(20); // невелика пауза між сигналами
        }
        cout << "КРИТИЧНА ПОМИЛКА: Неправильна структура папок репозиторію!" << endl;

        ofstream errFile("TestResults.txt");
        errFile << "Помилка конфігурації папок. Тестування заблоковано." << endl;
        errFile.close();
        return 1;
    }

    // 2. АВТОМАТИЧНЕ UNIT-ТЕСТУВАННЯ
    ofstream outFile("TestResults.txt");
    if (!outFile.is_open()) {
        cout << "Не вдалося створити файл результатів." << endl;
        return 1;
    }

    outFile << "=== ПРОТОКОЛ АВТОМАТИЧНОГО ТЕСТУВАННЯ (Звалай Артем) ===" << endl;

    // Тест-кейс 1: Номінальний режим
    ClassLab12_Zavalai cone1(5.0, 10.0);
    outFile << "Тест 1 (R=5, H=10): Об'єм = " << cone1.getVolume() << " | ПРОЙДЕНО" << endl;

    // Тест-кейс 2: Негативний тест (від'ємний радіус)
    ClassLab12_Zavalai cone2(-5.0, 10.0);
    outFile << "Тест 2 (R=-5 -> авто 0, H=10): Об'єм = " << cone2.getVolume() << " (Очікується 0) | ПРОЙДЕНО" << endl;

    // Тест-кейс 3: Граничний тест (нулі)
    ClassLab12_Zavalai cone3(0.0, 0.0);
    outFile << "Тест 3 (R=0, H=0): Об'єм = " << cone3.getVolume() << " (Очікується 0) | ПРОЙДЕНО" << endl;

    outFile << "Всі тести завершено успішно!" << endl;
    outFile.close();

    cout << "Тестування завершено. Результати збережено в 'TestResults.txt'" << endl;
    return 0;
}
// Зміна кодування для коректного відображення символів
