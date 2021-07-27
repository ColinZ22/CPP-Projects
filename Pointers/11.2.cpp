#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>

using namespace std;

bool fillArray(int a[], int arrSize, default_random_engine& e, uniform_int_distribution<int>& u);
bool outputArray(int a[], int arrSize, int field_width = 0, ostream& outS = cout);
int *doubleArray(int oldArr[], int oldArrSize);
bool checkInput();

int main()
{
  int arrSize, lbound = 10, ubound = 50,
      seed = static_cast<int>(time(nullptr)),
      field_width = static_cast<int>(log10(ubound)) + 1;
  int *testArr = nullptr;
  int *newArr = nullptr;

	default_random_engine e(seed);
  uniform_int_distribution<int> u(lbound, ubound);

  do
  {
    cout << "Please input the size of the array that you want to use to test the \"lastLargestIndex\" function: ";
    cin >> arrSize;
    cout << endl;
  }
  while (!checkInput() || arrSize <= 0);
  
  testArr = new int[arrSize];

  fillArray(testArr, arrSize, e, u);
  cout << "The original array is: \n";
  outputArray(testArr, arrSize, field_width);

  newArr = doubleArray(testArr, arrSize);
  cout << "The doubled array is: \n";
  outputArray(newArr, arrSize * 2, field_width);

  delete[] newArr;
  delete[] testArr;

  return 0;
} 

int *doubleArray(int oldArr[], int oldArrSize)
{
  int newArrSize = oldArrSize * 2;
  int *newArr = new int[newArrSize];

  copy(oldArr, oldArr + oldArrSize, newArr);

  return newArr;
}

bool fillArray(int a[], int arrSize, default_random_engine& e, uniform_int_distribution<int>& u)
{
	if (arrSize < 1)
		return false;
	for (int idx = 0; idx < arrSize; ++idx)
  {
    int generatedNum = u(e);
		a[idx] = generatedNum;
  }
  return true;
}

bool outputArray(int a[], int arrSize, int field_width, ostream& outS)
{
	if (arrSize < 1)
		return false;
  outS << "{";
	for (int idx = 0; idx < arrSize - 1; ++idx)
		outS << setw(field_width) << a[idx] << ", ";
	outS << setw(field_width) << a[arrSize - 1] << "}" << endl;
  return true;
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
