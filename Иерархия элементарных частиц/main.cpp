#include <iostream>
#include <string>
#include <cmath>
#include "Particles.h"

using namespace std;

double Particle::fromEVtoJ(double e) {
    return e * 1.602176634E-19;
}

void Fermion::printInfo() const {
    cout << getName() << endl;
    cout << "Refers to fermions (particles with a half-integer spin value)" << endl;
    if (isStable) {
        cout << "Stable" << endl;
    }
    else {
        cout << "Unstable, lifetime: " << timeOfLife << " c" << endl;
    }
    if (hasMass) {
        cout << "The mass is equal to " << E0 << " EV/c^2" << endl;
    }
    else {
        cout << "Has no mass" << endl;
    }
    cout << "Spin: " << (spin > 0 ? to_string(spin) : "") << " 1/2" << endl;
    printElCharge();
}

void Quark::printInfo() const {
    Fermion::printInfo();
    cout << "Smell: " << FlavorsNames[f] << "-quark" << endl;
}

void Lepton::printInfo() const {
    Fermion::printInfo();
}

void Boson::printInfo() const {
    cout << getName() << endl;
    cout << "Refers to bosons (a particle with an integer spin value)" << endl;
    if (isStable) {
        cout << "Stable" << endl;
    }
    else {
        cout << "Unstable, lifetime: " << timeOfLife << " c" << endl;
    }
    if (hasMass) {
        cout << "The mass is equal to " << E0 << " эВ/c^2" << endl;
    }
    else {
        cout << "Has no mass" << endl;
    }
    cout << "Spin: " << spin << endl;
    cout << "Electric charge: " << elCharge << " elementary electric charges" << endl;
}

void Foton::printInfo() const {
    Boson::printInfo();
}

void Electron::printInfo() const {
    Lepton::printInfo();
}


int main() {
    Particle **particles = new Particle*[5];
    particles[0] = new Electron();
    particles[1] = new Quark(2, 173.1E9, 5E-25, Quark::t);
    particles[2] = new Foton();
    particles[3] = new Quark(-1, 4.67E9, 1E-12, Quark::b);
    particles[4] = new Boson(false, true, 0, 0, 125E9, 1.56E-22);

    // выводим информацию
    for (int i = 0; i < 5; i++) {

        particles[i]->printInfo();

        cout << "Weight, kg: " << particles[i]->getMass() << endl;
    }


    for (int i = 0; i < 5; i++) {
        delete particles[i];
    }
    delete [] particles;
    return 0;
}
