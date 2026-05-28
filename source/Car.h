//------------------------------------------------------------------------------
// Car.h
// 
// - Car class declaration and definition
// - VectorWrapper class contains a vector of Cars.
//------------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------------------------------
// Car class declaration and definition
//------------------------------------------------------------------------------
class Car
{
private:
    unsigned mpg;       // miles per gallon
    std::string name;

    friend std::ostream& operator<<(std::ostream& os, const Car& c)
    {
        os << c.name << " (" << c.mpg << " mpg)";
        return os;
    }

public:
    Car() : mpg(0), name("Car") { }
    Car(const std::string& _name) : mpg(0), name(_name)
    { }

    unsigned getMpg() const { return mpg; }
    void setMpg(unsigned _mpg) { mpg = _mpg; }

    bool operator<(const Car& rhs) const
    {
        return name < rhs.name;
    }
};

//------------------------------------------------------------------------------
// VectorWrapper class contains a vector of Cars and a destructor
//------------------------------------------------------------------------------
class VectorWrapper
{
public:
    std::vector<Car*> vpCars;

    // reserve vector space for nCars
    VectorWrapper(size_t nCars) { vpCars.reserve(nCars * 2); }

    ~VectorWrapper()
    {
        for (Car* pCar : vpCars)
            delete pCar;
    }
};