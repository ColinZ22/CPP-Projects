#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const string empty_string = "";

vector<string> getWords(const string& text);
int findWord(const vector<string>& words, const string& word);

int main()
{
    vector<string> all_words;             
    vector<vector<int>> all_line_numbers; 

   string input_file_name;
    cout << "Source file name? ";
    getline(cin, input_file_name);
    ifstream finp;
    finp.open(input_file_name);
    assert(finp.good());
   
    string line;
    int word_counter = 0;
    int max_word_length = 0;
    int max_word_count = 0;
    int line_number = 0;
    getline(finp, line);
    while (!finp.eof())
    {
        if (line_number != 0)
            getline(finp, line);
        line_number++;
        vector<string> words = getWords(line);
        word_counter += words.size();
        for (int idx = 0; idx < words.size(); ++idx)
        {
            int widx = findWord(all_words, words[idx]);
            if (widx == -1)
            {
                cout << words[idx] << endl;
                all_words.push_back(words[idx]);   
                vector<int> word_line_numbers;
                word_line_numbers.push_back(line_number);
                all_line_numbers.push_back(word_line_numbers); 
                if (words[idx].length() > max_word_length)
                    max_word_length = words[idx].length();
            }
            else
            {
                all_line_numbers[widx].push_back(line_number);
                if (all_line_numbers[widx].size() > max_word_count)
                    max_word_count = all_line_numbers[widx].size();
            }
        }
    }
    finp.close();

  /* Sorting the 2 parallel vectors in numerical ascending order. */
	int word_count_temp;
  string word_temp;
  vector<int> line_nums_temp;
	for(int sorted = 0; sorted < all_words.size() - 1; sorted++)
		for(int unsorted = all_words.size() - 1; unsorted > sorted; --unsorted)
			if (all_line_numbers[unsorted - 1].size() > all_line_numbers[unsorted].size())
			{
				word_temp = all_words[unsorted - 1];
        line_nums_temp = all_line_numbers[unsorted - 1];

				all_words[unsorted - 1] = all_words[unsorted];
        all_line_numbers[unsorted - 1] = all_line_numbers[unsorted];

				all_words[unsorted] = word_temp;
        all_line_numbers[unsorted] = line_nums_temp;

        line_nums_temp.clear();
			}

    string output_file_name = input_file_name;
    string time_as_string = to_string(static_cast<int>(time(nullptr)));
    int period_pos = input_file_name.find_last_of('.');
    if (period_pos == -1)
        output_file_name = output_file_name + time_as_string + ".txt";
    else
        output_file_name = output_file_name.replace(period_pos, output_file_name.length() - period_pos + 1, time_as_string + ".txt");
    ofstream fout;
    fout.open(output_file_name);
    assert(fout.good());
    
    cout << word_counter << endl;
    const int word_counts_fwidth = static_cast<int>(log10(max_word_count)) + 1;
    const int line_number_fwidth = static_cast<int>(log10(line_number)) + 1;
    const int words_per_line = 36;
    for (int idx = 0; idx < all_words.size(); ++idx)
    {
        fout << setw(max_word_length) << left << all_words[idx] << ' ' << right << setw(word_counts_fwidth) << right << all_line_numbers[idx].size() << endl;
        for (int idx2 = 0; idx2 < all_line_numbers[idx].size(); ++idx2)
        {
            if (idx2 != 0 && idx2 % words_per_line == 0)
                fout << endl;
            fout << setw(line_number_fwidth) << right << all_line_numbers[idx][idx2] << ' ';
        }
        fout << endl;
        fout << endl;
    }
    fout.close();
    system("pause");
    return 0;
}
int findWord(const vector<string>& words, const string& word)
{
    for (int idx = 0; idx < words.size(); ++idx)
        if (words[idx] == word)
            return idx;
    return -1;
}
vector<string> getWords(const string& text)
{
    vector<string> words;
    int start_pos = 0;
    while (start_pos < text.length())
    {
        while (start_pos < text.length() && !isalnum(text[start_pos]))
            start_pos++;
        string word = empty_string;
        while (start_pos < text.length() && (isalnum(text[start_pos])))
        {
            word += static_cast<char>(toupper(text[start_pos]));
            start_pos++;
        }
        if (word.length() > 0)
            words.push_back(word);
    }
    return words;
}