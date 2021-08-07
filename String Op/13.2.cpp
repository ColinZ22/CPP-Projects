#include <iostream>

using namespace std;

bool checkInput();

int main()
{
  string userString, translatedString;
  char ch = ' ';
  do
  {
    cout << "Please input a sentence in English and it will be converted to Pig Latin: ";
    while (ch != '\n')
    {
      cin.get(ch);
      userString += ch;
    }
  }
  while (!checkInput());

  int wordLength = 0;
  bool foundPunct = false;
  char temp = ' ';
  for (int lineCharIdx = 0; lineCharIdx < userString.length(); lineCharIdx++)
  {
    if (userString[lineCharIdx] != ' ' && userString[lineCharIdx] != '\n' && !ispunct(userString[lineCharIdx]))
      wordLength++;
    else if (ispunct(userString[lineCharIdx]))
    {
      wordLength++;
      foundPunct = true;
      temp = userString[lineCharIdx];
    }
    else
    {
      for (int wordIdx = lineCharIdx - wordLength + 1; wordIdx < lineCharIdx; wordIdx++)
      {
        if (!ispunct(userString[wordIdx]))
          translatedString += userString[wordIdx];
      }
      translatedString += userString[lineCharIdx - wordLength];
      translatedString += "ay";
      if (foundPunct)
      {
        translatedString += temp;
        translatedString += ' ';
        temp = ' ';
        foundPunct = false;
      }
      else
        translatedString += ' ';
      wordLength = 0;
    }
  }

  for (int charIdx = 0; charIdx < translatedString.length(); charIdx++)
    translatedString[charIdx] = (toupper(translatedString[charIdx]));

  cout << endl << translatedString;

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