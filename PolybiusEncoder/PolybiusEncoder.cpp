#include <ctime>
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

const char POLYBIUS_MATRIX[5][5] = {{'A','B','C','D','E'},{'F','G','H','I','j'},{'K','L','M','N','O'},{'P','Q','R','S','T'},{'U','V','W','X','Y'}};
default_random_engine e((unsigned)time(nullptr));
uniform_int_distribution<int> u(0, 1);


vector<int> encode(string str);
string decode(vector<int> encodedMsg);
void printVec(std::vector <int> const &a);

int main()
{
	vector<int> watermelon = {53,11,45,15,43,33,15,32,35,34};
	cout << decode(encode("!ZZZZ@ZZZZ?")) << endl;
	cout << decode(encode("WATERMELON")) << endl;
	printVec(encode(decode(watermelon)));
  return 0;
} 

vector<int> encode(string str)
{
	int strIdx = 0;
	string upperStr = "";
	for (int charIdx = 0; charIdx < str.length(); charIdx++)
	{
		if (isalpha(str[charIdx]))
  		upperStr += (toupper(str[charIdx]));
	}

	vector<int> encodedMsg;
	for (int strIdx = 0; strIdx < upperStr.length(); strIdx++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (upperStr[strIdx] == POLYBIUS_MATRIX[i][j])
					encodedMsg.push_back((i+1)*10+(j+1));
			}
		}
		if (upperStr[strIdx] == 'Z')
			encodedMsg.push_back(55);
	}
	return encodedMsg;
}

string decode(vector<int> encodedMsg)
{
	string decodedMsg = "";
	int charRow, charCol;
	for (int i = 0; i < encodedMsg.size(); i++)
	{
		charRow = encodedMsg[i] / 10 - 1;
		charCol = encodedMsg[i] % 10 - 1;
		if (charRow == 4 && charCol == 4 && u(e))
			decodedMsg += 'Z';
		else
			decodedMsg += POLYBIUS_MATRIX[charRow][charCol];
	}
	return decodedMsg;
}

void printVec(std::vector <int> const &vec) 
{
	for (int i = 0; i < vec.size(); i++)
   	cout << vec.at(i) << ' ';
}