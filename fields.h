#ifndef FIELDS_H
#define FIELDS_H

#include <iostream>
#include <cmath>

class Field
{
protected:
    double *value; // x, y, z components

public:
    Field() // default constructor
    {
        value = new double[3]; // array for x, y, z
        value[0] = 0.0; // x component
        value[1] = 0.0; // y component
        value[2] = 0.0; // z component
    }

    Field(double x, double y, double z) // constructor with components
    {
        value = new double[3]; // array for x, y, z
        value[0] = x; // x component
        value[1] = y; // y component
        value[2] = z; // z component
    }

    virtual ~Field() // destructor
    {
        delete[] value; // free the array
    }

    Field(const Field &other) // copy constructor
    {
        value = new double[3]; // its own new array
        value[0] = other.value[0]; // copy x
        value[1] = other.value[1]; // copy y
        value[2] = other.value[2]; // copy z
    }

    Field &operator=(const Field &other) // assignment operator
    {
        value[0] = other.value[0]; // copy x
        value[1] = other.value[1]; // copy y
        value[2] = other.value[2]; // copy z
        return *this;
    }

    // setters
    void setX(double x) { value[0] = x; }
    void setY(double y) { value[1] = y; }
    void setZ(double z) { value[2] = z; }

    // getters
    double getX() const { return value[0]; }
    double getY() const { return value[1]; }
    double getZ() const { return value[2]; }

    void printMagnitude() // prints components and magnitude
    {
        double magnitude = sqrt(value[0] * value[0] + value[1] * value[1] + value[2] * value[2]);
        std::cout << "Components: (" << value[0] << ", " << value[1] << ", " << value[2] << ")"
                  << "  Magnitude: " << magnitude << "\n";
    }
};

class Electric_Field : public Field
{
private:
    double gauss_result; // calculated electric field from Gauss's law

public:
    Electric_Field() : Field() // default constructor, calls base
    {
        gauss_result = 0.0;
    }

    Electric_Field(double x, double y, double z) : Field(x, y, z) // calls base constructor
    {
        gauss_result = 0.0;
    }

    Electric_Field(const Electric_Field &other) : Field(other) // copy constructor
    {
        gauss_result = other.gauss_result;
    }

    void calculateGauss(double Q, double r) // Gauss's law for a spherical charge
    {
        double epsilon_0 = 8.854e-12; // permittivity of free space
        gauss_result = Q / (4 * M_PI * r * r * epsilon_0);
    }

    double getGaussResult() const { return gauss_result; }

    Electric_Field operator+(const Electric_Field &other) const // add two electric fields
    {
        Electric_Field sum(value[0] + other.value[0],  // x
                           value[1] + other.value[1],  // y
                           value[2] + other.value[2]); // z
        return sum;
    }

    friend std::ostream &operator<<(std::ostream &out, const Electric_Field &e) // print with cout
    {
        out << "E = (" << e.getX() << ", " << e.getY() << ", " << e.getZ() << ")";
        return out;
    }
};

class Magnetic_Field : public Field
{
private:
    double ampere_result; // calculated magnetic field from Ampere's law

public:
    Magnetic_Field() : Field() // default constructor, calls base
    {
        ampere_result = 0.0;
    }

    Magnetic_Field(double x, double y, double z) : Field(x, y, z) // calls base constructor
    {
        ampere_result = 0.0;
    }

    Magnetic_Field(const Magnetic_Field &other) : Field(other) // copy constructor
    {
        ampere_result = other.ampere_result;
    }

    void calculateAmpere(double I, double r) // Ampere's law for a wire
    {
        double mu_0 = 4 * M_PI * 1e-7; // permeability of free space
        ampere_result = I / (2 * M_PI * r * mu_0);
    }

    double getAmpereResult() const { return ampere_result; }

    Magnetic_Field operator+(const Magnetic_Field &other) const // add two magnetic fields
    {
        Magnetic_Field sum(value[0] + other.value[0],  // x
                           value[1] + other.value[1],  // y
                           value[2] + other.value[2]); // z
        return sum;
    }

    friend std::ostream &operator<<(std::ostream &out, const Magnetic_Field &b) // print with cout
    {
        out << "B = (" << b.getX() << ", " << b.getY() << ", " << b.getZ() << ")";
        return out;
    }
};

#endif
