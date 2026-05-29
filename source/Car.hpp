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

public:
    // constructors
    Car() : mpg(0), name("Car") { }
    Car(const std::string& _name) : mpg(0), name(_name) { }

    // getters and setters
    unsigned getMpg() const { return mpg; }
    void setMpg(unsigned _mpg) { mpg = _mpg; }

    const std::string& getName() const { return name; }
    void setName(const std::string& _name) { name = _name; }

    // overload comparison operators for sorting by mpg
    bool operator<(const Car& rhs) const
    {
        return mpg < rhs.mpg;
    }

    bool operator>(const Car& rhs) const
    {
        return mpg > rhs.mpg;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& c)
    {
        os << c.name << " gets " << c.mpg << " mpg.";
        return os;
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

        vpCars.clear();
    }
};