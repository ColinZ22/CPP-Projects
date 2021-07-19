#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;
  const int lbound = 1, ubound = 99999;
  int seed = static_cast<int>(time(nullptr));
	default_random_engine e(seed);
  const int field_width = 6;
	uniform_int_distribution<int> u(lbound, ubound);

int sumDigits(int num)
{
  int sum = 0;
  if (num == 0)
    return 0;
  if (num < 0)
    num = abs(num);
  while (num != 0)
  {  
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

bool digitSumsAreEqual(int num1, int num2)
{
  bool areEqual = false;
  if (sumDigits(num1) == sumDigits(num2))
  {
    areEqual = true;
  }
  return areEqual;
}

void generate()
{
  int pairsGenerated = 0;
  int num1;
  int num2;
  do
  {
    num1 = u(e);
    num2 = u(e);
    pairsGenerated++;
    cout << pairsGenerated << setw(field_width) << num1 << " (" << sumDigits(num1) << ")";
    cout << setw(field_width) << num2 << " (" << sumDigits(num2) << ") \n";
  }
  while (!digitSumsAreEqual(num1, num2));
}

int main()
{
generate();
 return 0;
} 