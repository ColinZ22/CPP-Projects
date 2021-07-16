#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

const double NORMAL_CHARGES = 10.0;
const double PRICE_PER_SPOOL = 100.0;

void checkInput()
{
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(10000, '\n');
  }
}

void gatherData(int &spoolsOrdered, int &spoolsOnHand, double &charges)
{
  while (spoolsOrdered < 1 || spoolsOnHand < 0)
  {
    cout << "Please input the number of spools ordered: ";
    cin >> spoolsOrdered;
    checkInput();
    cout << "Please input the number of spools on hand: ";
    cin >> spoolsOnHand;
    checkInput();
    cout << endl;
  }

  do
  {
    cout << "Please enter special shipping and handling charges per spool(enter -1 if no special charges): ";
    cin >> charges;
    cout << endl;
    checkInput();
    if (charges == -1)
      charges = NORMAL_CHARGES;
  }
  while (charges < 0);

}

void displayFunc(int sOrdered, int sOnHand, double charges = 10.00)
{
  double subtotal, totalShippingCharges, totalCharge;
  if (sOrdered > sOnHand)
  {
    cout << sOnHand << " spools are ready to ship, but " << sOrdered - sOnHand << " more is needed for the order.\n";
    cout << "Subtotal of the portion ready to ship is " << sOnHand * PRICE_PER_SPOOL << " dollars.\n";
    cout << "Total shipping and handling charges on the portion ready to ship is " << sOnHand * charges << " dollars.\n";
    cout << "Total of the order ready to ship is " << sOnHand * (PRICE_PER_SPOOL + charges) << " dollars.\n";
  }
  else
  { 
    cout << sOrdered << " spools are ready to ship.\n";
    cout << "Subtotal of the portion ready to ship is " << sOrdered * PRICE_PER_SPOOL << " dollars.\n";
    cout << "Total shipping and handling charges on the portion ready to ship is " << sOrdered * charges << " dollars.\n";
    cout << "Total of the order ready to ship is " << sOrdered * (PRICE_PER_SPOOL + charges) << " dollars.\n";
  } 
} 

int main()
{
  int spoolsOrdered = -1, spoolsOnHand = -1;
  double charges = NORMAL_CHARGES;

  gatherData(spoolsOrdered, spoolsOnHand, charges);

  displayFunc(spoolsOrdered, spoolsOnHand, charges);

 return 0;
}