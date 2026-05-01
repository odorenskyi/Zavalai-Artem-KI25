#include <iostream>
#include "struct_type_project_3.h"
#include <windows.h>
#include "Zavalai.h"
#include "Virchenko.h"

using namespace std;

const char* BIN_FILE = "ukrposhta_db.dat";

int main() {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PostNode* dbHead = nullptr;

    loadFromBinary(dbHead, BIN_FILE);

    int choice;
    do {
        cout << "\n=== ДОВIДНИК УКРПОШТИ (Командний проєкт) ===\n";
        cout << "1. Знайти запис (Модуль Вiрченко)\n";
        cout << "2. Вивести довiдник (Модуль Завалай)\n";
        cout << "3. Експорт у TXT (Модуль Завалай)\n";
        cout << "4. Додати запис (Модуль Завалай)\n";
        cout << "5. Видалити запис (Модуль Вiрченко)\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибiр: ";
        cin >> choice;

        switch (choice) {
            case 1: searchRecord(dbHead); break;
            case 2: printList(dbHead); break;
            case 3: exportToText(dbHead); break;
            case 4: addRecord(dbHead); break;
            case 5: deleteRecord(dbHead); break;
            case 0:
                saveToBinary(dbHead, BIN_FILE); // Модуль Завалай
                freeMemory(dbHead);             // Модуль Вірченко
                cout << "Роботу завершено.\n";
                break;
            default: cout << "Некоректний вибiр!\n";
        }
    } while (choice != 0);

    return 0;
}
