#include <ctime>
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
using namespace std;

int main() 
{
    const unsigned ntrials = 100;
    unsigned fwidth = static_cast<unsigned>(log10(ntrials)) + 1;

    const unsigned minval = 0;
    const unsigned maxval = 99;
    const unsigned loval = 20;
    const unsigned hival = 79;

    unsigned seed = static_cast<unsigned>(time(nullptr));
    default_random_engine e(seed);
    uniform_int_distribution<unsigned> u(minval, maxval);

    unsigned inside_hits = 0;
    unsigned outside_hits = 0;
    unsigned border_hits = 0;

    for (unsigned trial = 0; trial < ntrials; ++trial)
    {
        unsigned rval = u(e);
        if (rval < loval || hival < rval)
            outside_hits++;
        else if (rval == loval || rval == hival)
            border_hits++;
        else
            inside_hits++;
    }
    cout << "inside hits  = " << setw(fwidth) << inside_hits << endl;
    cout << "outside hits = " << setw(fwidth) << outside_hits << endl;
    cout << "border hits  = " << setw(fwidth) << border_hits << endl;
    return 0;
}