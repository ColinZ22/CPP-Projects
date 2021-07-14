#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  double length1, length2, length3;
  const double EPSILON = 1e-05; 
  //Note to Professor Dauzat: Originally when I used == for the comparisons, I discovered that 
  //  in some C++ does not always store the exact value of a floating point number, which leads  
  //  to an incorrect output. So I did some searching and found that the easiest way to fix
  //  this problem is to compare the absolute difference of the results with a fixed epsilon value.

  cout << "Please input lengths of the 3 sides of a triangle (side1 side2 side3): ";
  cin >> length1 >> length2 >> length3;
  cout << endl;

  if (abs(length1 * length1 + length2 * length2 - length3 * length3) <= EPSILON)
  {
    cout << "This triangle is a right triangle!" << endl;
  }
  else if (abs(length2 * length2 + length3 * length3 -length1 * length1) <= EPSILON)
  {
    cout << "This triangle is a right triangle!" << endl;
  }
  else if (abs(length1 * length1 + length3 * length3 - length2 * length2) <= EPSILON)
  {
    cout << "This triangle is a right triangle!" << endl;
  } 
  else
  {
    cout << "This triangle is not a right triangle." << endl;
  }

  return 0;
} 