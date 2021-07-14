#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  double popA, popB, greaterEqualYear = 0;
  double  rateA, rateB; 

  while (popA <= 1 || popB <= 1 || popA >= popB)
  {
    cout << "Please input the population of town A and town B in integer form (A B): ";
    cin >> popA >> popB;
  }
  while (rateA <= 0 || rateB <= 0 || rateA <= rateB)
  {
    cout << "Please input the growth rate of population A, population B in decimal form (A B): ";
    cin >> rateA >> rateB;
  }

  while (!(popA >= popB))
  {
    popA += popA * rateA;
    popB += popB * rateB;
    greaterEqualYear++;
  }
  
  popA =  static_cast<int>(popA);
  popB =  static_cast<int>(popB);

  cout << "After " << greaterEqualYear << " years the population of town A will be greater than or equal to the population of town B.\n";
  cout << "At that time, there are " << popA << " people in town A; " << popB << " people in town B.\n";

 return 0;
}