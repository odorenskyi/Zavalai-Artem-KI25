#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "ModulesZavalai.h" // Підключаємо нашу готову бібліотеку

using namespace std;

// 8.2.1: Функція повертає рядок з розробником та знаком (C)
string getDeveloperInfo() {
    return "Завалай А. Г. \xC2\xA9"; // UTF-8 код символу ©
}

// 8.2.2: Функція перевіряє логічну умову
bool checkCondition(char a, char b) {
    return (a + 1) >= b;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double x, y, z;
    char a, b;

    cout << "--- ЗАДАЧА 8.2 ---" << endl;
    cout << "Введіть дійсне число x: "; cin >> x;
    cout << "Введіть дійсне число y: "; cin >> y;
    cout << "Введіть дійсне число z: "; cin >> z;
    cout << "Введіть символ a: "; cin >> a;
    cout << "Введіть символ b: "; cin >> b;

    cout << "\n================ РЕЗУЛЬТАТИ ================" << endl;

    // Вивід розробника
    cout << "8.2.1. Розробник: " << getDeveloperInfo() << endl;

    // Вивід результату з boolalpha (буде писати true/false замість 1/0)
    cout << "8.2.2. Умова (a + 1 >= b): " << boolalpha << checkCondition(a, b) << endl;

    // Вивід чисел у шістнадцятковому форматі (hex)
    cout << "8.2.3. Змінні (десяткові): x=" << dec << x << ", y=" << y << ", z=" << z << endl;
    cout << "       Змінні (шістнадцяткові): x=" << hex << (int)x
         << ", y=" << (int)y << ", z=" << (int)z << dec << endl;

    // Виклик функції з нашої підключеної статичної бібліотеки
    cout << "\nЗначення S (з бібліотеки 8.1): " << fixed << setprecision(4)
         << s_calculation(x, y, z) << endl;
    cout << "============================================" << endl;

    cout << "\nНатисніть Enter для завершення..." << endl;
    cin.ignore();
    cin.get();

    return 0;
}
