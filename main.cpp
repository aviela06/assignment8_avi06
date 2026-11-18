#include <iostream>
#include "fields.h"

int main()
{
    Electric_Field E1(0, 1e5, 1e3); // constructor sets components
    Magnetic_Field B1(1.0, 2.0, 3.0);

    E1.printMagnitude(); // components and magnitude
    B1.printMagnitude();

    E1.calculateGauss(1e-6, 0.5); // Q = 1 microcoulomb, r = 0.5 m
    std::cout << "Gauss's law E = " << E1.getGaussResult() << " N/C\n";

    B1.calculateAmpere(10.0, 1.0); // I = 10 A, r = 1 m
    std::cout << "Ampere's law B = " << B1.getAmpereResult() << " T\n";

    Electric_Field E2(1, 2, 3), E3(4, 5, 6), E4;
    E4 = E2 + E3; // overloaded +
    std::cout << E4 << std::endl; // overloaded <<

    Magnetic_Field B2(0.5, 0.5, 0.5), B3(1.5, 1.5, 1.5), B4;
    B4 = B2 + B3;
    std::cout << B4 << std::endl;

    return 0;
}
