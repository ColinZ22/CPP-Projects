#include <iostream>
#include <iomanip>

using namespace std;

const int NCOLS = 2;

bool copy1DTo2D(int d1[], int size, int d2[][NCOLS], int nrows);
bool copy2DTo1D(int d2[][NCOLS], int nrows, int d1[], int size);
bool output2DArray(int d2[][NCOLS], int nrows);
bool outputArray(int arr[], int capacity, ostream& outs = cout,  int field_width = 0);

int main()
{
	const int nRows = 4;
	const int size = nRows * NCOLS;
	int d1[size] = {1,2,3,4,5,6,7,8};
	int d2[nRows][NCOLS];
	
	copy1DTo2D(d1, size, d2, nRows);
	output2DArray(d2, nRows);

	int anotherD1[size];
	int anotherD2[nRows][NCOLS] = {{1,2},{3,4},{5,6},{7,8}};
	
	copy2DTo1D(anotherD2, nRows, anotherD1, size);
	outputArray(anotherD1, size);
	return 0;
} 

bool copy1DTo2D(int d1[], int size, int d2[][NCOLS], int nrows)
{
	if (!(size > 0) || !(NCOLS > 0) || !(nrows > 0))
		return false;
	int d2RowIdx, d2ColIdx;
	for (int i = 0; i < size; i++)
	{
		d2RowIdx = i / NCOLS;
		d2ColIdx = i % NCOLS;
		d2[d2RowIdx][d2ColIdx] = d1[i];
	}
	return true;
}

bool copy2DTo1D(int d2[][NCOLS], int nrows, int d1[], int size)
{
	if (!(size > 0) || !(NCOLS > 0) || !(nrows > 0))
		return false;
	int d1Idx;
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < NCOLS; j++)
		{
			d1Idx = NCOLS * i + j;
			d1[d1Idx] = d2[i][j];
		}
	}
	return true;
}

bool output2DArray(int d2[][NCOLS], int nrows)
{
	if (nrows < 1)
		return false;
	for (int i = 0; i < nrows; ++i)
  {
		cout << "{";
    for (int j = 0; j < NCOLS; ++j)
    {
        cout << d2[i][j] << " ";
    }
    cout << "}" << endl;
  }
	return true;
}

bool outputArray(int arr[], int capacity, ostream& outs, int field_width)
{
	if (capacity < 1)
		return false;
  outs << "{";
	for (int idx = 0; idx < capacity - 1; ++idx)
		outs << setw(field_width) << arr[idx] << ", ";
	outs << setw(field_width) << arr[capacity - 1] << "}" << endl;
  return true;
}