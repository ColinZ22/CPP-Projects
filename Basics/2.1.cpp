#include <iostream>
using namespace std;

int main()
{

    int length;
    int width;
    int perimeter;
    int area;

    cout << "Enter the length: ";
    cin >> length;
    cout <<  endl;
    
    cout << "Enter the width: ";
    cin >> width;
    cout << endl;
    
    area = length * width;
    perimeter = length + length + width + width;

    cout << "Area = " << area << endl;
    cout << "Perimeter = " << perimeter << endl;

    return 0;
} 