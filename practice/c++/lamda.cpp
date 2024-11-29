#include <iostream>
#include  <vector>
#include <algorithm>
#include <functional>

void foreach(const std::vector<int>& values,const std::function<void(int)>& func)
{
    for (int value : values)
        func(value);
}
int main()
{
    std::vector<int> values  = {1,2,3,4};
    auto it = std::find_if(values.begin(), values.end(),  [](int value) { return value > 3; });
    
    std::cout << *it << std::endl;
    
    int a = 5;
    auto lamda  = [=](int value) mutable {a = 10; std::cout << "value: " << value << a<< std::endl;};
    foreach(values, lamda);
}