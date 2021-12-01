#ifndef UNTITLED18_PARTICLES_H
#define UNTITLED18_PARTICLES_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Fraction {
    int a;
    unsigned b;
    Fraction(int a, unsigned b) : a(a), b(b) {};
    void print() const {
        cout << a << "/" << b << endl;
    }
};

class Particle {
public:
    constexpr static unsigned SPEED_OF_LIGHT = 299792458;
    constexpr static double SPEED_OF_LIGHT_2 = (double)SPEED_OF_LIGHT*SPEED_OF_LIGHT;

    static double fromEVtoJ(double);
protected:
    bool isStable; // стабильность частицы
    bool hasMass; // безмассовость частицы
    double E0; // энергия покоя/масса
    double timeOfLife; // время жизни, с
    int spin; // спин (целая часть)
    int elCharge; // электрический заряд (кратно элементарному заряду)
public:
    Particle(bool isStable, bool hasMass, int spin, double elCharge, double E0 = 0,
             double timeOfLife = INFINITY) :
            isStable(isStable), hasMass(hasMass), spin(spin),
            elCharge(elCharge), E0(E0), timeOfLife(timeOfLife) {}
    virtual ~Particle() {
        cout << "Particle destructor" << endl;
    }

    bool is_stable() const {return isStable;}
    bool has_mass() const {return hasMass;}
    double getEnergyEV() const {return E0;}
    double getEnergyJ() const {return fromEVtoJ(E0);}
    double getMass() const {return getEnergyJ()/SPEED_OF_LIGHT_2;}
    double getTimeOfLife() const {return timeOfLife;}

    virtual Fraction getSpin() const = 0;
    virtual Fraction getCharge() const {return Fraction(elCharge, 1);}
    virtual void printInfo() const = 0;
    virtual string getName() const = 0;
    virtual void printElCharge() const {
        cout << "Electric charge: " << elCharge << " elementary electric charges" << endl;
    }
};

// производный класс фермион
class Fermion : public Particle {
public:
    Fermion(bool isStable, bool hasMass, int spin, double elCharge, double E0 = 0,
            double timeOfLife = INFINITY) : Particle(isStable, hasMass, spin, elCharge, E0, timeOfLife) {}
    virtual ~Fermion() {cout << "Fermion destructor" << endl;}

    virtual Fraction getSpin() const {return Fraction(spin*2+1, 2);}
    virtual void printInfo() const;
    virtual string getName() const {return "Fermion";}
};

// производные фермиона - кварк и лептон
class Quark : public Fermion {
public:
    enum Flavours {u, d, s, c, b, t};
    static constexpr char FlavorsNames[] {'u', 'd', 's', 'c', 'b', 't'};
private:
    Flavours f;
public:
    Quark(double elCharge, double E0, double timeOfLife, Flavours f) : Fermion(false, true, 0, elCharge, E0, timeOfLife), f(f) {}
    virtual ~Quark() {cout << "Quark destructor" << endl;}

    virtual Fraction getCharge() const {return Fraction(elCharge, 3);}
    virtual void printInfo() const;
    virtual string getName() const {return "Quark";}
    virtual void printElCharge() const {
        cout << "Electric charge: " << elCharge << "/3 elementary electric charges" << endl;
    }
};

class Lepton : public Fermion {
public:
    Lepton(bool isStable, double elCharge, double E0, double timeOfLife = INFINITY) : Fermion(isStable, true, 0, elCharge, E0, timeOfLife) {}
    virtual ~Lepton() {cout << "Lepton destructor" << endl;}

    virtual void printInfo() const;
    virtual string getName() const {return "Lepton";}
};

// производный класс бозон
class Boson : public Particle {
public:
    Boson(bool isStable, bool hasMass, int spin, double elCharge, double E0 = 0,
          double timeOfLife = INFINITY) : Particle(isStable, hasMass, spin, elCharge, E0, timeOfLife) {}
    virtual ~Boson() {cout << "Boson destructor" << endl;}
    // перегрузка виртуальных функций
    virtual Fraction getSpin() const {return Fraction(elCharge, 1);}
    virtual void printInfo() const;
    virtual string getName() const {return "Boson";}
};

// производные частицы

// электрон (является лептоном)
class Electron : public Lepton {
public:
    Electron() : Lepton(true, -1, 0.51099895E6) {}
    virtual ~Electron() {cout << "Electron destructor" << endl;}

    virtual void printInfo() const;
    virtual string getName() const {return "Electron";}
};

// фотон (является бозоном)
class Foton : public Boson {
public:
    Foton() : Boson(true, false, 1, 0) {}
    virtual ~Foton() {cout << "Foton destructor" << endl;}

    virtual void printInfo() const;
    virtual string getName() const {return "Foton";}
};


#endif //UNTITLED18_PARTICLES_H
