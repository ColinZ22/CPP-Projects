#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int reverseDigit(int inputNum)
{
  string reversedNumStr = "";
  int outputNum;

  if (inputNum <= 0)
  {
    reversedNumStr += "-";
    inputNum = abs(inputNum);
  }

  while (inputNum != 0)
  {
    reversedNumStr += to_string(inputNum % 10);
    inputNum /= 10;
  }

  outputNum = stoi(reversedNumStr);
  return outputNum;
}

int main()
{
  return 0;
} 