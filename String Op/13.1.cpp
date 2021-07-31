#include <iostream>

using namespace std;

bool checkInput();


int main()
{
  string userString, processedString;
  do
  {
  cout << "Please input a sentence in which all of the words are run together,\n but the first character of each word is upper cases: ";
  cin >> userString;
  }
  while (!checkInput());

  bool newSentence = true;
  for (char lineChar : userString)
          if (isupper(lineChar))
          {
            if  (!newSentence)
            {
              processedString += " ";
              processedString += tolower(lineChar);
            }
            else
              processedString += lineChar;
              newSentence = false;
          }
          else if (islower(lineChar))
          {
            processedString += lineChar;
          }
          else if (lineChar == '.' || lineChar == ';' || lineChar == '!')
          {
            processedString += lineChar;
            processedString += " ";
            newSentence = true;
          }
          else if (ispunct(lineChar))
            processedString += lineChar;

  cout << endl << processedString;

  return 0;
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