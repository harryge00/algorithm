#include <iostream>
#include <set>
#include <unordered_set>


void unorderSetTest() {
  std::unordered_set<std::string> myset =
  {"USA","Canada","France","UK","Japan","Germany","Italy"};

  myset.erase ( myset.begin() );                    // erasing by iterator
  // myset.erase ( "France" );                         // erasing by key
  // myset.erase ( myset.find("Japan"), myset.end() ); // erasing by range

  std::cout << "myset contains:";
  for ( const std::string& x: myset ) std::cout << " " << x;
  std::cout << std::endl;
}

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator it;

  // insert some values:
  for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90; 10 30. 50

  it = myset.begin();
  ++it;                                         // "it" points now to 20

  myset.erase (it);

  myset.erase (40);

  it = myset.find (60);
  myset.erase (it, myset.end());

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  unorderSetTest();
  return 0;
}