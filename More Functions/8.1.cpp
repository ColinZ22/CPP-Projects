#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

bool fill(int a[], int capacity, default_random_engine &e, uniform_int_distribution<int>& u);
bool show(int a[], int capacity, int field_width, ostream& outs = cout);
int find(int a[], int size, int target);

int main()
{
	int seed = static_cast<int>(time(nullptr));
	default_random_engine e(seed);

	const int ubound = 20;
	const int lbound = 10;
	int field_width = static_cast<int>(log10(ubound)) + 1;
	uniform_int_distribution<int> u(lbound, ubound);
	
	const int size = 16;
	int numbers[size] = { 0 };
	show(numbers, size, field_width);
	fill(numbers, size, e, u);
	show(numbers, size, field_width);
}
/*
If the range of random number is less than the array size then the fill function cannot fill the array with unique random numbers. Why?
  If the range of random number is less than the size of the array that needs to be filled, then there is not enough (unique) numbers 
  to fill the entire array. 
*/
bool fill(int a[], int capacity, default_random_engine& e, uniform_int_distribution<int>& u)
{
  int range =  u.max() - u.min() + 1;
	if (capacity < 1 || capacity > range)
		return false;
	for (int idx = 0; idx < capacity; ++idx)
    {
        int generatedNum;
        do
        {
            generatedNum = u(e);
        }
        while (find(a, idx, generatedNum) != -1);
		a[idx] = generatedNum;
  }
  return true;
}
bool show(int a[], int capacity, int field_width, ostream& outs)
{
	if (capacity < 1)
		return false;
	for (int idx = 0; idx < capacity - 1; ++idx)
		outs << setw(field_width) << a[idx] << ", ";
	outs << setw(field_width) << a[capacity - 1] << endl;
  return true;
}
int find(int a[], int size, int target)
{
	int idx = 0;
	while (idx < size && a[idx] != target)
		idx++;
	return idx < size ? idx : -1;
}