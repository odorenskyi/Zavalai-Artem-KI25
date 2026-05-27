#ifndef MODULESZAVALAI_H
#define MODULESZAVALAI_H

class ClassLab12_Zavalai {
private:
    double radius;
    double height;

public:
    ClassLab12_Zavalai(double r = 0.0, double h = 0.0);
    void setRadius(double r);
    void setHeight(double h);
    void setDimensions(double r, double h);
    double getRadius() const;
    double getHeight() const;
    double getVolume() const;
};

#endif
// Інтерфейс класу Конус
