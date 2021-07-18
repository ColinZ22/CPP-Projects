#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

const int NUM_OF_DAYS = 7;
const int NUM_OF_RUNNERS = 5;

void readAndStore(string, string[NUM_OF_RUNNERS][NUM_OF_DAYS], string[]);
void calculate(string[NUM_OF_RUNNERS][NUM_OF_DAYS], double[NUM_OF_RUNNERS][2]);
void outputData(string[NUM_OF_RUNNERS][NUM_OF_DAYS], string[], double[NUM_OF_RUNNERS][2]);

int main()
{
 string milesArr[NUM_OF_RUNNERS][NUM_OF_DAYS];
 string nameArr[NUM_OF_RUNNERS];
 double resultsArr[NUM_OF_RUNNERS][2];

 readAndStore("dataFileName.txt", milesArr, nameArr);
 calculate(milesArr, resultsArr);
 outputData(milesArr, nameArr, resultsArr);

 return 0;
} 

void readAndStore(string inputFileName, string milesArr[NUM_OF_RUNNERS][NUM_OF_DAYS], string nameArr[])
{
  ifstream inp_stream(inputFileName);
  if (!inp_stream.good())
  {
    cout << "The program cannot open " << inputFileName << endl;
    cout << "Press enter to continue.";
    cin.get();
    return;
  }
  while (!inp_stream.eof())
  {
    for (int name = 0; name < NUM_OF_RUNNERS; ++name)
    {
      inp_stream >> nameArr[name];
      for (int miles = 0; miles < NUM_OF_DAYS; ++miles)
      {
        inp_stream >> milesArr[name][miles];
      }
    }
  }
}
void calculate(string milesArr[NUM_OF_RUNNERS][NUM_OF_DAYS], double resultsArr[NUM_OF_RUNNERS][2])
{
  for (int name = 0; name < NUM_OF_RUNNERS; ++name)
    {
      for (int miles = 0; miles < NUM_OF_DAYS; ++miles)
      {
        resultsArr[name][0] += stod(milesArr[name][miles]);
      }
      resultsArr[name][1] = resultsArr[name][0] / NUM_OF_DAYS;
    }
}

void outputData(string milesArr[NUM_OF_RUNNERS][NUM_OF_DAYS], string nameArr[], double resultsArr[NUM_OF_RUNNERS][2])
{
  cout << "\nNum of Miles Each Day:\n";
  for (int name = 0; name < NUM_OF_RUNNERS; ++name)
    {
      cout << nameArr[name] << ":";
      for (int miles = 0; miles < NUM_OF_DAYS; ++miles)
      {
        cout << " " << milesArr[name][miles] << " ";
      }
      cout << endl;
    }
    cout << "\nStats:\n";
    for (int name = 0; name < NUM_OF_RUNNERS; ++name)
    {
      cout << nameArr[name] << "'s total: " << resultsArr[name][0] << "; ";
      cout << nameArr[name] <<  "'s average: " << resultsArr[name][1] << endl;
    }
}