#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

template<typename T> 
void PrintType() {
    cout << "\t\t\t" <<
    typeid(T).name() << "\n Size : " <<
    sizeof(T) << " Byte" << "\n Min : " <<
    numeric_limits<T>::min() << "\n Max : " <<
    numeric_limits<T>::max() << endl;
}

template<typename T>
void PrintTypeChar() {
    cout << "\t\t\t" << 
    typeid(T).name() << "\n Size : " << 
    sizeof(T) << " Byte" << "\n Min : " << 
    (int)numeric_limits<T>::min() << "\n Max : " << 
    (int)numeric_limits<T>::max() << endl;
}

int main()
{
    PrintTypeChar<char>();
    PrintTypeChar<signed char>();
    PrintTypeChar<unsigned char>();
    PrintType<short>();
    PrintType<short int>();
    PrintType<signed short>();
    PrintType<signed short int>();
    PrintType<unsigned short>();
    PrintType<unsigned short int>();
    PrintType<int>();
    PrintType<signed>();
    PrintType<signed int>();
    PrintType<unsigned>();
    PrintType<unsigned int>();
    PrintType<long>();
    PrintType<long int>();
    PrintType<signed long>();
    PrintType<signed long int>();
    PrintType<unsigned long>();
    PrintType<unsigned long int>();
    PrintType<long long>();
    PrintType<long long int>();
    PrintType<signed long long>();
    PrintType<signed long long int>();
    PrintType<unsigned long long>();
    PrintType<unsigned long long int>();
    PrintType<float>();  
    PrintType<double>();
    PrintType<long double>();
}
