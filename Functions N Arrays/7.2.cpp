#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void displayMenu();
double calculateCost(bool, bool, bool, double);
void gatherInfo(bool&, bool&, bool&);
bool checkInput();

const double costWithoutDiscount = 100.0;

int main()
{
  bool isSenior, moreThan12Months, moreThan5Sessions; 
  double finalCost;
  displayMenu();
  gatherInfo(isSenior, moreThan12Months, moreThan5Sessions);
  finalCost = calculateCost(isSenior, moreThan12Months, moreThan5Sessions, costWithoutDiscount);
  cout << "\nYour Total cost is $" << finalCost;
  return 0;
} 

void displayMenu()
{
  cout << "-----------INFO-----------\n";
  cout << "Membership base fee without discount is $" << costWithoutDiscount << ";\n";
  cout << "Senior citizens discount is 30%;\n";
  cout << "If membership is bought and paid for 12 or more months, the discount is 15%;\n";
  cout << "If more than five personal training sessions are bought and paid for, the discount on each session is 20%;\n";
  cout << "--------------------------\n";
}

void gatherInfo(bool& isSenior, bool& moreThan12Months, bool& moreThan5Sessions)
{
  do
  {
    cout << "Are you a senior citizen? (enter 1 for yes, 0 for no): ";
    cin >> isSenior;
  }
  while (!checkInput());

  do
  {
    cout << "\nAre you paying for more than 12 months? (enter 1 for yes, 0 for no): ";
    cin >> moreThan12Months;
  }
  while (!checkInput());

  do
  {
    cout << "\nAre you paying for more than 5 training sessions per month? (enter 1 for yes, 0 for no): ";
    cin >> moreThan5Sessions;
  }
  while (!checkInput());
}

double calculateCost(bool isSenior, bool moreThan12Months, bool moreThan5Sessions, double costWithoutDiscount )
{
  double discountedCost = costWithoutDiscount;
  double totalDiscount = 0.0;
  if (isSenior)
    totalDiscount += 0.3; 
  if (moreThan12Months)
    totalDiscount += 0.15; 
  if (moreThan5Sessions)
    totalDiscount += 0.20; 
  
  discountedCost *= (1 - totalDiscount);

  return discountedCost;
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
