#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <ctime>
#include <bitset>
#include <windows.h>
#include "ModulesZavalai.h"

using namespace std;

// Задача 10.1
void task10_1(string inFileName, string outFileName) {
    ifstream inFile(inFileName);
    if (!inFile.is_open()) {
        cout << "Помилка! Не вдалося відкрити вхідний файл: " << inFileName << endl;
        return;
    }

    string word;
    inFile >> word;
    inFile.close();

    // рахуємо малі літери
    int lowerCount = 0;
    for (char c : word) {
        if (islower((unsigned char)c)) {
            lowerCount++;
        }
    }

    // перевіряємо чи є слово у вірші
    string poem = "В хаті сонячний промінь косо На долівку ляга з вікна... Твої чорні шовкові коси Припорошила вже сивина.";
    bool isFound = (poem.find(word) != string::npos);

    ofstream outFile(outFileName);
    if (!outFile.is_open()) return;

    outFile << "--- ЗАДАЧА 10.1 ---" << endl;
    outFile << "Розробник: Завалай Артем" << endl;
    outFile << "Установа: ЦНТУ, м. Кропивницький, Україна, 2026 рік" << endl;
    outFile << "У файлі " << inFileName << " міститься " << lowerCount << " символів нижнього регістру." << endl;

    if (isFound) {
        outFile << "Повідомлення: Слово '" << word << "' ПРИСУТНЄ у вірші В. Симоненка." << endl;
    } else {
        outFile << "Повідомлення: Слово '" << word << "' ВІДСУТНЄ у вірші В. Симоненка." << endl;
    }
    outFile.close();
}

// Задача 10.2
void task10_2(string inFileName, string outFileName) {
    ifstream inFile(inFileName);
    if (!inFile.is_open()) return;

    string word;
    inFile >> word;
    inFile.close();

    // міняємо регістр букв на протилежний
    string flippedWord = "";
    for (char c : word) {
        if (islower((unsigned char)c)) {
            flippedWord += toupper((unsigned char)c);
        } else if (isupper((unsigned char)c)) {
            flippedWord += tolower((unsigned char)c);
        } else {
            flippedWord += c;
        }
    }

    time_t now = time(0);
    string dt = ctime(&now);

    // дозаписуємо дані в існуючий файл
    ofstream outFile(outFileName, ios::app);
    if (outFile.is_open()) {
        outFile << "\n--- ЗАДАЧА 10.2 ---" << endl;
        outFile << "Слово зі зміненим регістром: " << flippedWord << endl;
        outFile << "Дата й час дозапису: " << dt;
        outFile.close();
    }
}

// Задача 10.3
void task10_3(string outFileName, double x, double y, double z, int b) {
    double result = s_calculation(x, y, z);

    // переводимо число в двійковий код
    string binaryB = bitset<32>(b).to_string();

    // відрізаємо нулі зліва
    binaryB.erase(0, binaryB.find_first_not_of('0'));
    if (binaryB.empty()) binaryB = "0";

    ofstream outFile(outFileName, ios::app);
    if (outFile.is_open()) {
        outFile << "\n--- ЗАДАЧА 10.3 ---" << endl;
        outFile << "Результат функції s_calculation(x=" << x << ", y=" << y << ", z=" << z << "): " << result << endl;
        outFile << "Число b (" << b << ") у двійковому коді: " << binaryB << endl;
        outFile.close();
    }
}

// Головна функція
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string inFile = "input.txt";
    string outFile = "output.txt";
    double x, y, z;
    int b;

    cout << "=== ЛАБОРАТОРНА РОБОТА 10 ===" << endl;
    cout << "Введіть значення x: "; cin >> x;
    cout << "Введіть значення y: "; cin >> y;
    cout << "Введіть значення z: "; cin >> z;
    cout << "Введіть натуральне число b: "; cin >> b;
    cout << "-----------------------------" << endl;

    task10_1(inFile, outFile);
    task10_2(inFile, outFile);
    task10_3(outFile, x, y, z, b);

    cout << "-----------------------------" << endl;
    cout << "Роботу завершено! Перевірте файл " << outFile << " у папці з програмою." << endl;

    return 0;
}
