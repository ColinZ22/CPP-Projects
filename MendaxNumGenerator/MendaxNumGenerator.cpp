#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int mendax(int n)
{
  if (n == 1 || n == 2 || n == 3)
    return 1;
  else 
  {
    return mendax(n - 1) * mendax(n - 2) - mendax(n - 3);
  }
}

bool checkInput()
{
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(10000, '\n');
    return false;
  }
  return true;
}

int main()
{
  int num;
  do 
  {
    cout << "Please input a positive integer n and the Mendax numbers from 1 to n will be displayed: ";
    cin >> num;
    if (num < 1)
      cout << "Sorry, your input is invalid, n has to be greater than or equal to 1.\n\n";
  }
  while (num < 1 || !checkInput());

  for (int idx = 1; idx <= num; ++idx)
  {
    cout << idx << " " << mendax(idx) << endl;
  }
  return 0;
} 