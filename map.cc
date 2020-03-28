// map::begin/end
#include <iostream>
#include <map>

struct tt {
  int a;
  int b;
};
int main ()
{
  std::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  
  std::cout <<mymap['d']<<std::endl;
  
  std::map<char,bool> mm;
  std::cout << mm['d']<<std::endl;
  // std::map<char,tt> mm2;
  // std::cout << mm2['d']<<std::endl;
  // tt v1= {1, 2};
  // mm2['d'] = v1;
  // std::cout << mm2['d']<<std::endl;
  return 0;
}
