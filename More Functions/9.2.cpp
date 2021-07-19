#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <random>
#include <ctime>
#include <random>

using namespace std;

bool fillArray(int arr[], int capacity, default_random_engine& e, uniform_int_distribution<int>& u);
int find(int arr[], int size, int target);
void sortArray(int arr[], int capacity);
bool outputArray(int arr[], int capacity, ostream& outs = cout,  int field_width = 0);
bool checkGuess(int numArr[], int guessArr[], int capacity);
bool checkInput();

int main()
{
  bool keepPlaying;
  cout << "-----Welcome to the weekly lottery game!------------------------------------------------------------\n";
  cout << "In this game, five distinct random integers between 1 to 40 (inclusive) are drawn.\n";
  cout << "You will input 5 different guesses, and if you guess all of the numbers correctly, you will win a big mystery prize!\n";
  cout << "----------------------------------------------------------------------------------------------------\n";
  do
  {
    int arrSize = 5, ubound = 40, lbound = 1;

    int seed = static_cast<int>(time(nullptr));
    default_random_engine e(seed);
    int field_width = static_cast<int>(log10(ubound)) + 1;
    uniform_int_distribution<int> u(lbound, ubound);

    int numArr[arrSize], guessArr[arrSize];
    fillArray(numArr, arrSize, e, u);

    sortArray(numArr, arrSize);
    for (int idx = 0; idx < arrSize; ++idx)
    {
      do 
      {
        cout << "\nPlease input a guess (" << idx << " out of " << arrSize << " guesses recorded): ";
        cin >> guessArr[idx];
      }while (!checkInput() || guessArr[idx] > 40 || guessArr[idx] < 1 || find(guessArr, idx, guessArr[idx]) != -1);
    }
    cout << arrSize << " out of " << arrSize << " guesses recorded!\n";
    cout << "\nHere are your guesses: ";
    outputArray(guessArr, arrSize, cout, field_width);
    if (checkGuess(numArr, guessArr, arrSize))
    {
      cout << "\nCongratulations! You guessed all " << arrSize << " numbers! You've won ---- 1 TacoBell coupon for a free soda!";
      do 
      {
        cout << "\nWould you like to play again? (input 1 for yes, 0 for no): ";
        cin >> keepPlaying;
      }while(!checkInput());
    }
    else 
    {
      cout << "\nSorry, you lost and missed out on the big prize. The lottery numbers were: ";
      outputArray(numArr, arrSize, cout, field_width);
      do 
      {
        cout << "\nWould you like to play again? (input 1 for yes, 0 for no): ";
        cin >> keepPlaying;
      }while(!checkInput());
    }
  }
  while (keepPlaying);

  return 0;
} 

bool fillArray(int arr[], int capacity, default_random_engine& e, uniform_int_distribution<int>& u)
{
	if (capacity < 1)
		return false;
  for (int idx = 0; idx < capacity; ++idx)
      {
          int generatedNum;
          do
          {
              generatedNum = u(e);
          }
          while (find(arr, idx, generatedNum) != -1);
      arr[idx] = generatedNum;
    }
  return true;
}

int find(int arr[], int size, int target)
{
	int idx = 0;
	while (idx < size && arr[idx] != target)
		idx++;
	return idx < size ? idx : -1;
}

void sortArray(int arr[], int capacity)
{
  for (int lastSorted = 0; lastSorted < (capacity - 1); lastSorted++)
  {
    int minIndex = lastSorted;
    int minValue = arr[lastSorted];
    for(int index = lastSorted + 1; index < capacity; index++)
    {
      if (arr[index] < minValue)
      {
        minValue = arr[index];
        minIndex = index;
      }
    }
    arr[minIndex] = arr[lastSorted];
    arr[lastSorted] = minValue;
  }
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

bool checkGuess(int numArr[], int guessArr[], int capacity)
{
  int matchedNums = 0;
  for (int guessIdx = 0; guessIdx < capacity; ++guessIdx)
  {
    for (int numIdx = 0; numIdx < capacity; ++numIdx)
    {
      if (guessArr[guessIdx] == numArr[numIdx])
        matchedNums++;
    }
  }
  return (matchedNums == 5);
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