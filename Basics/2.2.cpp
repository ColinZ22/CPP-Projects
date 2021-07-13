#include <iostream>
using namespace std;

int main()
{
  int totalSecond, hour, minute, second;

  cout << "Please input the the elapsed time for an event in seconds: ";
  cin >> totalSecond;
  cout << endl;

  hour = totalSecond / 3600;

  minute = (totalSecond % 3600) / 60;

  second = totalSecond % 3600 % 60;

  cout << hour << ":" << minute << ":" << second << endl;
  
}