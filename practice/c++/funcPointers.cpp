#include <iostream>
#include <vector>

void hello(int a)
{
    std::cout << "Hello! " << a << std::endl;
}

void print(int value)
{
    std::cout << value << std::endl;
}



int main()
{
    // typedef void(*ptrfunc)(int);

    // ptrfunc fun = hello;
    // fun(2);


    // void (*func)() = hello;

    // auto func = hello; // &hello;
    // std::cout << func << std::endl; // 1
    

    std::vector<int> values = {1,2,3,4,5};
    // foreach(values, print);
    foreach(values, [](int value) 
    {
        std::cout  << "value: " << value << std::endl;
    });

    std::cin.get();
}