// template != generics, 
// template >> generics
// template ~ macros

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
template<typename T> //template<class T>
void print(T value)
{
    std::cout << value << std::endl;
}

// void print(std::string value)
// {
//     std::cout << value << std::endl;
// }

template<typename T,int N> //evaluated at compile time
class Array
{
private:
    T m_Array[N];
public:
    int GetSize() const { return N; } 
};

int main()
{

    // print function doesnt exist if we dont call it,
    // to check this, we can make syntax error , without calling the print , it will not cause issue
    //template gets materialize if it gets called


    print(5); // int 
    print("5555"); // string
    print(5.0); // float

    print<int>(5);

    Array<std::string, 5> array; 
    std::cout << "Array size: " << array.GetSize() << std::endl;

    std::cin.get();
}