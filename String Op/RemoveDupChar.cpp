#include <iostream>

using namespace std;

string remDups(const string& original);
void remDups(const string& original, string& nodups);

int main()
{
  string nodups = "";
  string ori = "\nMyrtle has\n big!@! fEet_|_";
  remDups(ori, nodups);
  cout << nodups << endl;
  cout << remDups(ori);
  return 0;
} 

string remDups(const string& original)
{
  string noDups = "";
  string upperOrig;
  for (int charIdx = 0; charIdx < original.length(); charIdx++)
    upperOrig += (toupper(original[charIdx]));
  for (int cIdx = 0; cIdx < original.length(); cIdx++)
  {
    if (noDups.find(upperOrig[cIdx]) == string::npos)
      noDups += upperOrig[cIdx];
  }
  return noDups;
}

void remDups(const string& original, string& nodups)
{
  string upperOrig;
  for (int charIdx = 0; charIdx < original.length(); charIdx++)
    upperOrig += (toupper(original[charIdx]));
  for (int cIdx = 0; cIdx < original.length(); cIdx++)
  {
    if (nodups.find(upperOrig[cIdx]) == string::npos)
      nodups += upperOrig[cIdx];
  }
}
