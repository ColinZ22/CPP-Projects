#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void swap(int &x, int &y)

{

   int temp = x;

    x = y;

    y = temp;

}

void swap(int* xPtr, int* yPtr)

{

   int temp = *xPtr;

    *xPtr = *yPtr;

    *yPtr = temp;

}

int main()
{
  int num1 = 11111, num2 = 22222;
  int *num1Ptr = &num1, *num2Ptr = &num2;
  cout << "Num1 is: " << num1 << " Num2 is: " << num2 <<endl;
  swap(num1, num2);
  cout << "Num1 and Num2 swapped using reference variable version of swap: " << endl;
  cout << "Num1 is now: " << num1 << " Num2 is now: " << num2 <<endl;
  swap(num1Ptr, num2Ptr);
  cout << "Num1 and Num2 swapped back using pointer version of swap: " << endl;
  cout << "Num1 is now: " << num1 << " Num2 is now: " << num2 << endl;
  
  return 0;
} 