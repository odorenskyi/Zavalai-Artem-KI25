#include "ModulesZavalai.h"
#include <iostream>
#include <cmath>

using namespace std;

// Функція з Лаб 8
double s_calculation(double x, double y, double z) {
    // Встав сюди свою справжню формулу з 8 лаби замість x + y + z, якщо вона є
    return x + y + z;
}

// Задача 9.1: Розрахунок за електроенергію
double task9_1(double kwh) {
    double total_kop = 0.0;
    if (kwh <= 150) {
        total_kop = kwh * 130.843;
    } else if (kwh <= 800) {
        total_kop = 150 * 130.843 + (kwh - 150) * 241.945;
    } else {
        total_kop = 150 * 130.843 + 650 * 241.945 + (kwh - 800) * 534.047;
    }
    return total_kop / 100.0;
}

// Задача 9.2: Середньорічна температура
void task9_2() {
    double sum = 0.0, temp;
    cout << "Введіть 12 середньомісячних температур:\n";
    for (int i = 0; i < 12; i++) {
        cout << "Місяць " << i + 1 << ": ";
        cin >> temp;
        sum += temp;
    }
    double t_c = sum / 12.0;
    double t_f = 32.0 + (9.0 / 5.0) * t_c;
    cout << "Середньорічна температура за Цельсієм: " << t_c << " C\n";
    cout << "Середньорічна температура за Фаренгейтом: " << t_f << " F\n";
}

// Задача 9.3: Аналіз бітів
int task9_3(unsigned int N) {
    bool bit10 = (N >> 10) & 1;
    int count0 = 0, count1 = 0;
    for (int i = 0; i < 32; i++) {
        if ((N >> i) & 1) count1++;
        else count0++;
    }
    if (bit10 == 0) return count0;
    else return count1;
}
