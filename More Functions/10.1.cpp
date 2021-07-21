#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
using namespace std;

const int capacity = 16;
uniform_int_distribution<int>vud(10, 99);
uniform_int_distribution<int>xud(0, capacity - 1);
int seed = static_cast<int>(time(nullptr));
default_random_engine e(seed);

int findMode(int arr[], int size);
bool show(const int a[], int size, int fwidth = 2, ostream& sout = cout);
bool rfill(int [], int);
int numSearch(int a[], int size, int target);
bool bubbleSort(int[], int);
bool checkInput();

int main() 
{
    int userArrSize;
  do
  {
    cout << "Please input the size of the array that you want to use to test the \"lastLargestIndex\" function: ";
    cin >> userArrSize;
    cout << endl;
  }
  while (!checkInput() || userArrSize <= 0);

  const int arrSize = userArrSize; 
  int testArr[arrSize];
  rfill(testArr, arrSize);
  cout << "Here is the generated array: ";
  show(testArr, arrSize);
  cout << "\nThe mode of this array is " << findMode(testArr, arrSize);
	return 0;
}

int findMode(int arr[], int size)
{
  int sortedArr[size];
  for (int i = 0; i < size; ++i)
    sortedArr[i] = arr[i];
  bubbleSort(sortedArr, size);

  int mode = -1;
  int lastNumOfOccurrence = 1;
  int numOfOccurrence;
  for (int idx = 0; idx < size; ++idx)
  { 
    numOfOccurrence = numSearch(sortedArr, size, sortedArr[idx]);
    if (numOfOccurrence > lastNumOfOccurrence)
    {
      mode = sortedArr[idx];
      lastNumOfOccurrence = numOfOccurrence;
    }
  }
  return mode;
}

bool show(const int a[], int size, int fwidth, ostream& outs)
{
	bool isgood = false;
	if (size > 0)
	{
		for (int idx = 0; idx < size - 1; idx++)
			outs << setw(fwidth) << a[idx] << ',';
		outs << setw(fwidth) << a[size - 1] << endl;
		isgood = true;
	}
	return isgood;
}

bool rfill(int a[], int size)
{
	bool isgood = false;
	if (size > 0)
	{
		for (int idx = 0; idx < size; idx++)
			a[idx] = vud(e);
		isgood = true;
	}
	return isgood;
}

int numSearch(int a[], int size, int target)
{
	int numOfOccurrence = 0;
	for (int idx = 0; idx < size; ++idx)
		if (a[idx] == target)
			numOfOccurrence++;
	return numOfOccurrence;
}

bool bubbleSort(int a[], int size)
{
	if (size < 1)
		return false;
	int temp;
	for(int sorted = 0; sorted < size - 1; sorted++)
		for(int unsorted = size - 1; unsorted > sorted; --unsorted)
			if (a[unsorted - 1] > a[unsorted])
			{
				temp = a[unsorted - 1];
				a[unsorted - 1] = a[unsorted];
				a[unsorted] = temp;
			}
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