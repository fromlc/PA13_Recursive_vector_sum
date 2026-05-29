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
typedef std::vector<Car*> PCarVector;

void fillVector(PCarVector& vpCars, unsigned nCars);
void setVectorData(PCarVector& vpCars, unsigned minMpg, unsigned maxMpg);
void sortVector(PCarVector& vpCars);
void displayVector(PCarVector& vpCars);
unsigned rSumVectorElements(PCarVector& vpCars, size_t n);
void displayAverage(PCarVector& vpCars);

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
void fillVector(PCarVector& vpCars, unsigned NUM_CARS)
{
    for (size_t i = 0; i < NUM_CARS; ++i)
    {
        vpCars.push_back(new Car(NAME_PREFIX + std::to_string(i + 1)));
    }
}

//------------------------------------------------------------------------------
// generate random mpg values for Car instances in passed vector
//------------------------------------------------------------------------------
void setVectorData(PCarVector& vpCars, unsigned minMpg, unsigned maxMpg)
{
     // seeded Mersenne Twister random number generator
    static std::mt19937 mt { std::random_device{}() };
    static std::uniform_int_distribution<unsigned> mpgRange { minMpg, maxMpg };

    for (Car* pCar : vpCars)
    {
        pCar->setMpg(mpgRange(mt));
    }
}

//------------------------------------------------------------------------------
// sort passed vector of Car pointers by mpg in descending order
//------------------------------------------------------------------------------
void sortVector(PCarVector& vpCars)
{
    std::sort(vpCars.begin(), vpCars.end(), compareCars);
}

//------------------------------------------------------------------------------
// display vector elements
//------------------------------------------------------------------------------
void displayVector(PCarVector& vpCars)
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
unsigned rSumVectorElements(PCarVector& vpCars, size_t n)
{
    if (n == 0)
        return 0;

    return vpCars[n - 1]->getMpg() + rSumVectorElements(vpCars, n - 1);
}

//------------------------------------------------------------------------------
// display average mpg for Car instances in passed vector
//------------------------------------------------------------------------------
void displayAverage(PCarVector& vpCars)
{
    if (vpCars.empty())
    {
        std::cout << "\nNo cars, can't calculate average mpg.\n";
        return;
    }

    unsigned mpgSum = rSumVectorElements(vpCars, vpCars.size());
    float mpgAvg = static_cast<float>(mpgSum) / vpCars.size();

    std::cout << std::fixed << "\nAverage mpg: " << std::setprecision(2)
        << mpgAvg << "\n";
}
