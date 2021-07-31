#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 3;
bool create(int** &square, int size);
bool destroy(int** &square, int size);
bool ismagic(int** square, int size);
bool show(int **square, int size, int fwidth = 2, ostream& sout = cout);
bool copymagic(int srce[][SIZE], int **dest, int size);
bool bubbleSort(int[], int);

int main()
{
	const int size = 3;
	int magic_square[][size] = { {4, 9, 2}, {3, 5, 7}, {8, 1, 6} };
	int other_square[][size] = { {2, 9, 4}, {3, 7, 5}, {8, 7, 6} };
	int **square = nullptr;
	create(square, size);
	copymagic(magic_square, square, size);
	show(square, size);
	if (ismagic(square, size))
		cout << "Is Magic;\n";
	else
		cout << "Is Not Magic;\n";

	cout << endl;
	copymagic(other_square, square, size);
	show(square, size);
  if (ismagic(square, size))
    cout << "Is Magic;\n";
  else
    cout << "Is Not Magic;\n";

  destroy(square,size);

	system("pause");
	return 0;
}

bool ismagic(int** square, int size)
{
  bool ismagic = true;
/*---------------------------------------------------------*/
/* Condition 1 check: the array has n rows and n columns.  */
/* Automatic pass, since the create() function always      */
/* makes 2d arrays with n rows and n columns.          */
/*---------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/* Condition 2 check: the array contains the numbers 1 to n^2 exactly. */
  int expandedSquareSize = size*size;
  int* checkArr = new int[expandedSquareSize];
  int* expandedSquareArr = new int[expandedSquareSize];
  for (int i = 0; i < expandedSquareSize; i++)
  {
    checkArr[i] = i + 1;
  }
  int eidx = 0;
  for (int ridx = 0; ridx < size; ridx++)
	  for (int cidx = 0; cidx < size; ++cidx)
		{
      expandedSquareArr[eidx] = square[ridx][cidx];
      eidx++;
    } 

  bubbleSort(expandedSquareArr, expandedSquareSize);

  for (int i = 0; i < expandedSquareSize; i++)
  {
    if (expandedSquareArr[i] != checkArr[i])
      ismagic = false;
  }
/*---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/* Condition 3 check: the sum of the numbers in each row, each column, */
/* and each diagonal all add up to the same number, n x (n^2 + 1) / 2. */
	int sum = size * (size * size + 1) / 2;
  int rowSum, prevRowSum, colSum, prevColSum, leftDiagSum = 0, rightDiagSum = 0;
	for (int i = 0; i < size; ++i)
  {
    rowSum = 0;
    colSum = 0;
		for (int j = 0; j < size; ++j)
    {
      rowSum += square[i][j];
      colSum += square[j][i];
      if (i == j)
        leftDiagSum += square[i][j];
      if ((i + j) == (size - 1))
        rightDiagSum += square[i][j];
    }
    if (rowSum != prevRowSum && i != 0)
      ismagic = false;
    if (colSum != prevColSum && i != 0)
      ismagic = false;
    prevRowSum = rowSum;
    prevColSum = colSum;
  }
  if (leftDiagSum != sum || rightDiagSum != sum || rowSum != sum || colSum != sum)
    ismagic = false;
/*---------------------------------------------------------------------*/

  delete[] checkArr;
  delete[] expandedSquareArr;
	return ismagic;
}

bool copymagic(int srce[][SIZE], int **dest, int size)
{
	bool isgood = false;
	if (size > 1)
	{
		for (int ridx = 0; ridx < size; ridx++)
			for (int cidx = 0; cidx < size; ++cidx)
				dest[ridx][cidx] = srce[ridx][cidx];
		isgood = true;
	}
	return isgood;
}

bool create(int** &square, int size)
{
	bool isgood = false;
	square = nullptr;
	if (size > 0)
	{
		square = new int*[size];
		for (int ridx = 0; ridx < size; ++ridx)
			square[ridx] = new int[size];
		isgood = true;
	}
	return isgood;
}

bool destroy(int** &a, int size)
{
	bool isgood = false;
	if (size > 0)
	{
		for (int ridx = 0; ridx < size; ++ridx)
			delete[] a[ridx];
		delete[] a;
		isgood = true;
	}
	return isgood;
}

bool show(int **a, int size, int fwidth, ostream& sout)
{
	bool isgood = false;
	if (size > 0)
	{
		for (int ridx = 0; ridx < size; ridx++)
		{
			for (int cidx = 0; cidx < size - 1; cidx++)
				sout << setw(fwidth) << a[ridx][cidx] << ' ';
			sout << setw(fwidth) << a[ridx][size - 1] << endl;
		}
	}
	return isgood;
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