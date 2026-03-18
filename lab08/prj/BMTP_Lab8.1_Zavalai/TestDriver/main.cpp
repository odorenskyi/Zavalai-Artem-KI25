#include <iostream>
#include <iomanip>
#include <windows.h>
#include "ModulesZavalai.h"

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double x, y, z;
    cout << "--- Тестовий драйвер для задачі 8.1 ---" << endl;
    cout << "Введіть x: "; cin >> x;
    cout << "Введіть y: "; cin >> y;
    cout << "Введіть z: "; cin >> z;

    double result = s_calculation(x, y, z);

    cout << fixed << setprecision(4);
    cout << "\nРезультат S: " << result << endl;

    cout << "\nНатисніть Enter для завершення..." << endl;
    cin.ignore();
    cin.get();
    return 0;
}
