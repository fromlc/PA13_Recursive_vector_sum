//------------------------------------------------------------------------------
// PA13_Recursive_vector_sum.cpp 
//------------------------------------------------------------------------------
#include "Car.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
const size_t NUM_CARS = 4;

const unsigned MIN_MPG = 11;
const unsigned MAX_MPG = 49;

const std::string NAME_PREFIX = "RX-7";

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void fillVector(std::vector<Car*>& vpCars, unsigned nCars);
void setVectorData(std::vector<Car*>& vpCars, unsigned minMpg, unsigned maxMpg);
void sortVector(std::vector<Car*>& vpCars);
void displayVector(std::vector<Car*>& vpCars);
//unsigned rSumVectorElements(std::vector<Car*>& vpCars);
//void displayAverage(std::vector<Car*>& vpCars);

//------------------------------------------------------------------------------
// comparison function for sorting Car instances by mpg in descending order
//------------------------------------------------------------------------------
bool compareCars(const Car* pCar1, const Car* pCar2)
{
    return pCar1->getMpg() > pCar2->getMpg();
}

//------------------------------------------------------------------------------
// entry point 
//------------------------------------------------------------------------------
int main()
{
    VectorWrapper vw(NUM_CARS);

    fillVector(vw.vpCars, NUM_CARS);
    setVectorData(vw.vpCars, MIN_MPG, MAX_MPG);
    sortVector(vw.vpCars);
    displayVector(vw.vpCars);
    //rSumVectorElements(vw.vpCars);

    std::cout << "Hello World!\n";
}

//------------------------------------------------------------------------------
// generate Car instances with names and append the pointers to the vector
//------------------------------------------------------------------------------
void fillVector(std::vector<Car*>& vpCars, unsigned NUM_CARS)
{
    for (size_t i = 0; i < NUM_CARS; ++i)
    {
        vpCars.push_back(new Car(NAME_PREFIX + std::to_string(i)));
    }
}

//------------------------------------------------------------------------------
// generate random mpg values for Car instances in passed vector
//------------------------------------------------------------------------------
void setVectorData(std::vector<Car*>& vpCars, unsigned minMpg, unsigned maxMpg)
{
     // Mersenne Twister random number generator
    std::mt19937 mt {};
    std::uniform_int_distribution<unsigned> mpgRange { minMpg, maxMpg };

    for (auto pCar : vpCars)
    {
        pCar->setMpg(mpgRange(mt));
    }
}

//------------------------------------------------------------------------------
// sort passed vector of Car pointers by mpg in descending order
//------------------------------------------------------------------------------
void sortVector(std::vector<Car*>& vpCars)
{
    std::sort(vpCars.begin(), vpCars.end(), compareCars);
}

//------------------------------------------------------------------------------
// display vector elements
//------------------------------------------------------------------------------
void displayVector(std::vector<Car*>& vpCars)
{
    for (auto pCar : vpCars)
    {
        std::cout << *pCar << "\n";
    }
}
