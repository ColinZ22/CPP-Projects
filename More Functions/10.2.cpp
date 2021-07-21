#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

uniform_int_distribution<int>vud(10, 50);
int seed = static_cast<int>(time(nullptr));
default_random_engine e(seed);

vector<int> findMode(int arr[], int size);
bool outputArr(const int a[], int size, int fwidth = 2, ostream& outStream = cout);
bool outputVector(vector<int> v, int fwidth = 2, ostream& outStream = cout);
bool rfill(int [], int);
int numSearch(int a[], int size, int target);
bool bubbleSort(int[], int);
bool checkInput();

int main() 
{
  const int arrSize = 16; 
  int testArr[arrSize];

  rfill(testArr, arrSize);
  cout << "Here is the generated array: ";
  outputArr(testArr, arrSize);

  vector<int> modeVector = findMode(testArr, arrSize);
  if (!modeVector.empty())
  {
    cout << "\nMode(s): ";
    outputVector(modeVector);
  }
  else
    cout << "\nThis array of generated integers has no mode.";
	return 0;
}

vector<int> findMode(int arr[], int size)
{
  int sortedArr[size];
  for (int i = 0; i < size; ++i)
    sortedArr[i] = arr[i];
  bubbleSort(sortedArr, size);

  vector<int> mode;
  int lastNumOfOccurrence = 2;
  int numOfOccurrence;
  for (int idx = 0; idx < size; ++idx)
  { 
    numOfOccurrence = numSearch(sortedArr, size, sortedArr[idx]);
    if (numOfOccurrence > lastNumOfOccurrence)
    {
      mode.clear();
      mode.push_back(sortedArr[idx]);
      idx += numOfOccurrence - 1;
      lastNumOfOccurrence = numOfOccurrence;
    }
    else if (numOfOccurrence == lastNumOfOccurrence)
    { 
      mode.push_back(sortedArr[idx]);
      idx += numOfOccurrence - 1;
    }
  }
  return mode;
}

bool outputArr(const int a[], int size, int fwidth, ostream& outStream)
{
	bool isgood = false;
	if (size > 0)
	{
		for (int idx = 0; idx < size - 1; idx++)
			outStream << setw(fwidth) << a[idx] << ',';
		outStream << setw(fwidth) << a[size - 1] << endl;
		isgood = true;
	}
	return isgood;
}

bool outputVector(vector<int> v, int fwidth, ostream& outStream)
{
	bool isgood = false;
	if (v.size() > 0)
	{
		for (int idx = 0; idx < v.size() - 1; idx++)
			outStream << setw(fwidth) << v[idx] << ',';
		outStream << setw(fwidth) << v[v.size() - 1] << endl;
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