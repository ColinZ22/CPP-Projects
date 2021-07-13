#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
  const int CALORIE_PER_COOKIE = 300 / (30 / 10);
  double numOfCookiesEaten;

  cout << "Please input the number of cookies you ate: ";
  cin >> numOfCookiesEaten;
  cout << endl;

  cout << numOfCookiesEaten * CALORIE_PER_COOKIE << " calories were consumed."; 
}