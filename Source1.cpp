#include <iostream>

using namespace std;
int main()
{
    setlocale(0, "");
    cout << "int: " << sizeof(int) << "\n";
    cout << "short int: " << sizeof(short int) << "\n";
    cout << "long int: " << sizeof(long int) << "\n";
    cout << "float: " << sizeof(float) << "\n";
    return(0);
}