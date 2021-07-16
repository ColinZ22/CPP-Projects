#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int calculateSize(int start, double birthR, double deathR, int yearsToCalc)
{
  unsigned newSize, prevSize = start;
  for (int year = 0; year < yearsToCalc; year++)
  {
    newSize = prevSize + birthR * prevSize - deathR * prevSize;
    prevSize = newSize;
  }
  return newSize;
}

int main()
{
  double birthRate, deathRate;
  int startSize, numOfYears;

  while (startSize < 2 || numOfYears < 1 || birthRate <= 0 || deathRate <= 0)
  {
    cout << "Please input the starting size of a population, the annual birth rate, the annual death rate, and the number of years to display (in that order): ";
    cin >> startSize >> birthRate >> deathRate >> numOfYears;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
    }
  }
  
  for (int year = 1; year <= numOfYears; year++)
  {
    cout << "After " << year << " year(s), there are " << calculateSize(startSize, birthRate, deathRate, year) << " people in the population.\n";;
  }

 return 0;
}