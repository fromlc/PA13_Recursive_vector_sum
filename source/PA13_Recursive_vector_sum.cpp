//------------------------------------------------------------------------------
// PA13_Recursive_vector_sum.cpp 
//------------------------------------------------------------------------------
#include "Car.hpp"

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <random>
#include <string>
#include <vector>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
const size_t NUM_CARS = 10;

const unsigned MIN_MPG = 11;
const unsigned MAX_MPG = 49;

const std::string NAME_PREFIX = "RX-";

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void fillVector(std::vector<Car*>& vpCars, unsigned nCars);
void setVectorData(std::vector<Car*>& vpCars, unsigned minMpg, unsigned maxMpg);
void sortVector(std::vector<Car*>& vpCars);
void displayVector(std::vector<Car*>& vpCars);
unsigned rSumVectorElements(std::vector<Car*>& vpCars, size_t n);
void displayAverage(std::vector<Car*>& vpCars);

//------------------------------------------------------------------------------
// comparison function for sorting Car instances by mpg in descending order
//------------------------------------------------------------------------------
static bool compareCars(const Car* pCar1, const Car* pCar2)
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
    displayAverage(vw.vpCars);

    std::cout << "\nHappy motoring!\n";
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
    static std::mt19937 mt {};
    static std::uniform_int_distribution<unsigned> mpgRange { minMpg, maxMpg };

    for (Car* pCar : vpCars)
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
    std::cout << "Cars in descending MPG order:\n\n";

    for (const Car* pCar : vpCars)
    {
        std::cout << *pCar << "\n";
    }
}

//------------------------------------------------------------------------------
// recursively calculate sum of mpg values for passed vector elements
//------------------------------------------------------------------------------
unsigned rSumVectorElements(std::vector<Car*>& vpCars, size_t n)
{
    if (n == 0)
        return 0;

    return vpCars[n - 1]->getMpg() + rSumVectorElements(vpCars, n - 1);
}

//------------------------------------------------------------------------------
// display average mpg for Car instances in passed vector
//------------------------------------------------------------------------------
void displayAverage(std::vector<Car*>& vpCars)
{
    std::cout << std::fixed << "\nAverage mpg: " << std::setprecision(2)
        << rSumVectorElements(vpCars, vpCars.size()) / vpCars.size() << "\n";
}
