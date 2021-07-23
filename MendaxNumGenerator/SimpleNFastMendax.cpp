#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

/* Below is the function I used in my first version. */
/* Compared to the non-recursive approach, the old   */
/* recursive approach takes much much longer to      */
/* calculate the mendax numbers after the 35th n.    */
// old recursive approach
// int mendax(int n)
// {
//   if (n == 1 || n == 2 || n == 3)
//     return 1;
//   else 
//   {
//     return mendax(n - 1) * mendax(n - 2) - mendax(n - 3);
//   }
// }

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

  int m1 = 1, m2 = 1, m3 = 1, mLast;
  for (int idx = 1; idx <= num; ++idx)
  {
    if (idx <= 3)
    {
      cout << idx << " " << 1 << endl;
      continue;
    }
    mLast = m3*m2-m1;
    cout << idx << " " << mLast << endl;
    m1 = m2;
    m2 = m3;
    m3 = mLast;
  }
  return 0;
} 