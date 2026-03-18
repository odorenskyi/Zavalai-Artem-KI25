#include "ModulesZavalai.h"
#include <cmath>

double s_calculation(double x, double y, double z) {
    const double PI = 3.14159265358979323846;
    return std::pow(2 * z + 1, 2) - std::sqrt(std::abs(y - 0.5 * z)) + z + PI;
}
