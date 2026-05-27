#include "ModulesZavalai.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

ClassLab12_Zavalai::ClassLab12_Zavalai(double r, double h) {
    setDimensions(r, h);
}

void ClassLab12_Zavalai::setRadius(double r) {
    radius = (r < 0) ? 0.0 : r; // Фільтр від'ємних значень
}

void ClassLab12_Zavalai::setHeight(double h) {
    height = (h < 0) ? 0.0 : h; // Фільтр від'ємних значень
}

void ClassLab12_Zavalai::setDimensions(double r, double h) {
    setRadius(r);
    setHeight(h);
}

double ClassLab12_Zavalai::getRadius() const { return radius; }
double ClassLab12_Zavalai::getHeight() const { return height; }

double ClassLab12_Zavalai::getVolume() const {
    return (1.0 / 3.0) * M_PI * radius * radius * height;
}
// Використано точне значення M_PI для розрахунку конуса
