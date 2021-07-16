#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void reduceToOne(int num)
{
  int theNumber = num;
  
  if (num == 1)
  {
    cout << "The number given is already 1." << endl;
  }

  while (num != 1)
  {
    if ((num % 2) == 0)
    {
      num /= 2;
      cout << num << endl;
    }
    else 
    {
      num *= 3;
      num ++;
      cout << num << endl;
    }
  }

  cout << "---------" << theNumber << " was successfully reduced to 1." << endl;
}

int main()
{
  
  cout << "\nTest Trial 1: 1" << endl;
  reduceToOne(1);
  cout << "\nTest Trial 2: 131070" << endl;
  reduceToOne(131070);
  cout << "\nTest Trial 3: 131071" << endl;
  reduceToOne(131071);
  cout << "\nTest Trial 4: 131072" << endl;
  reduceToOne(131072);

  return 0;
} 