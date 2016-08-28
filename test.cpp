// my first program in C++
#include <iostream>
#include <climits>

struct s1{
char a;
int b;
};
struct s2{
char a; char c;
int b;
};
struct s3{
char a;
int b;
char c;
};
using namespace std;
int main()
{
    if(int k = 0) {
        std::cout<<0<<endl;
    }
    if(int k = 1) {
        std::cout<<(k = 91)<<endl;
    }
  std::cout << sizeof(s1)<<endl;
  std::cout << sizeof(s2)<<endl;
  std::cout << sizeof(s3)<<endl;
}
