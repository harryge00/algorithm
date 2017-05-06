#include <vector>
#include <iostream>
 
 
int main( )
{
    std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> back = c;
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';
 
    c.erase(c.begin());
 
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    c.erase(c.begin()+2, c.begin()+5);
    std::vector<int>::iterator it = c.begin();
    std::cout<< *it << '\n';
    c.insert(it, *it);
    for (auto &i : back) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}