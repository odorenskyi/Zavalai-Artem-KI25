#include <iostream>
#include <iomanip>
#include <windows.h>
#include "ModulesZavalai.h" // Підключаємо наш заголовковий файл

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char choice;

    do {
        cout << "\n================= ГОЛОВНЕ МЕНЮ =================" << endl;
        cout << "[n] - Викликати функцію s_calculation" << endl;
        cout << "[v] - Задача 9.1 (Розрахунок за електроенергію)" << endl;
        cout << "[c] - Задача 9.2 (Середньорічна температура)" << endl;
        cout << "[x] - Задача 9.3 (Аналіз бітів числа)" << endl;
        cout << "[z] - Вихід з програми" << endl;
        cout << "================================================" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 'n': {
                double x, y, z;
                cout << "Введіть x, y, z через пробіл: ";
                cin >> x >> y >> z;
                cout << "Результат S = " << fixed << setprecision(4) << s_calculation(x, y, z) << endl;
                break;
            }
            case 'v': {
                double kwh;
                cout << "Введіть кількість спожитої електроенергії (кВт*год): ";
                cin >> kwh;
                cout << "Сума до сплати: " << fixed << setprecision(2) << task9_1(kwh) << " грн" << endl;
                break;
            }
            case 'c': {
                task9_2();
                break;
            }
            case 'x': {
                unsigned int N;
                cout << "Введіть натуральне число N (0 - 4294967295): ";
                cin >> N;
                bool bit10 = (N >> 10) & 1;
                cout << "Біт D10 дорівнює: " << bit10 << endl;
                if (bit10 == 0) cout << "Кількість двійкових нулів: " << task9_3(N) << endl;
                else cout << "Кількість двійкових одиниць: " << task9_3(N) << endl;
                break;
            }
            case 'z':
            case 'Z':
                cout << "Завершення роботи програми..." << endl;
                break;
            default:
                cout << "\a"; // Звук помилки
                cout << "Помилка! Невідомий символ. Спробуйте ще раз." << endl;
                break;
        }

    } while (choice != 'z' && choice != 'Z');

    return 0;
}
