#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() 
{
    cout << "Enter source file name: ";
    string inp_name;
    getline(cin, inp_name);

    ifstream inp_stream(inp_name);
    if (!inp_stream.good())
    {
        cout << "The program cannot open " << inp_name << endl;
        system("pause");
        return 1;
    }
    unsigned unsigned_time = static_cast<unsigned>(time(nullptr));
    string string_time = to_string(unsigned_time);
    string out_name = "census" + string_time + ".txt";
    ofstream out_stream(out_name);
    if (!out_stream.good())
    {
        cout << "The program cannot open " << out_name << endl;
        system("pause");
        return 1;
    }
    unsigned alpha_count = 0;
    unsigned digit_count = 0;
    unsigned punc_count = 0;
    unsigned space_count = 0;
    unsigned other_count = 0;
    string line;

    while (getline(inp_stream, line))
    {
        cout << line << endl;
        for (char line_char : line)
            if (isalpha(line_char))
                alpha_count++;
            else if (isdigit(line_char))
                digit_count++;
            else if (ispunct(line_char))
                punc_count++;
            else if (isspace(line_char))
                space_count++;
            else
                //Should the revised program continue to count other characters?
                other_count++; 
                //Yes, the program should still count other characters because there could be 
                //other types of characters within the file (e.g. characters in a different language).
    }

    //putting the counted values into an array
    unsigned counts[] = {alpha_count, digit_count, punc_count, space_count, other_count};
    //finding the largest count value using the max_element function in C++'s <algorithm> library
    unsigned max_count = *max_element(counts, counts+5);

    unsigned fwidth = max_count > 0 ? static_cast<unsigned>(log10(max_count)) + 1 : 1;//see ternary operator

    inp_stream.close();

    out_stream << inp_name << " statistics" << endl;
    out_stream << "letters:      " << setw(fwidth) << alpha_count << endl;
    out_stream << "digits:       " << setw(fwidth) << digit_count << endl;
    out_stream << "punctuations: " << setw(fwidth) << punc_count << endl;
    out_stream << "spaces:       " << setw(fwidth) << space_count << endl;
    out_stream << "others:       " << setw(fwidth) << other_count << endl;

    out_stream.close();

    return 0;
}