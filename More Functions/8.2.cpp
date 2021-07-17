#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

int lastLargestIndex(int arr[], int arrSize);
bool fillArray(int a[], int capacity, default_random_engine& e, uniform_int_distribution<int>& u);
bool outputArray(int a[], int capacity, ostream& outs = cout,  int field_width = 0);
bool checkInput();

int main()
{
  int lastLargestNumIndex, userArrSize, ubound, lbound;
  do
  {
    cout << "Please input the size of the array that you want to use to test the \"lastLargestIndex\" function: ";
    cin >> userArrSize;
    cout << endl;
  }
  while (!checkInput() || userArrSize <= 0);

  do
  {
    cout << "Please input the smallest and largest number you want the program to generate and put into the test array(smallest, largest): ";
    cin >> lbound >> ubound;
    cout << endl;
  }
  while (!checkInput() || (ubound < lbound));

  int seed = static_cast<int>(time(nullptr));
	default_random_engine e(seed);
  int field_width = static_cast<int>(log10(ubound)) + 1;
	uniform_int_distribution<int> u(lbound, ubound);

  const int arrSize = userArrSize; 
  int testArr[arrSize];
  
  fillArray(testArr, arrSize, e, u);
  cout << "Here is the generated test array: \n";
  outputArray(testArr, arrSize, cout, field_width);
  lastLargestNumIndex = lastLargestIndex(testArr, arrSize);
  cout << "Largest number in test array is found at index " << lastLargestNumIndex << endl;
  cout << "The number at index " << lastLargestNumIndex << " is " << testArr[lastLargestNumIndex];
  return 0;
}

int lastLargestIndex(int arr[], int arrSize)
{
  int lastLargest = 0;
  for (int idx = 0; idx < arrSize; ++idx)
  {
    if (arr[idx] >= arr[lastLargest])
      lastLargest = idx;
  }
  return lastLargest;
}

bool fillArray(int a[], int capacity, default_random_engine& e, uniform_int_distribution<int>& u)
{
	if (capacity < 1)
		return false;
	for (int idx = 0; idx < capacity; ++idx)
  {
    int generatedNum = u(e);
		a[idx] = generatedNum;
  }
  return true;
}

bool outputArray(int a[], int capacity, ostream& outs, int field_width)
{
	if (capacity < 1)
		return false;
  outs << "{";
	for (int idx = 0; idx < capacity - 1; ++idx)
		outs << setw(field_width) << a[idx] << ", ";
	outs << setw(field_width) << a[capacity - 1] << "}" << endl;
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