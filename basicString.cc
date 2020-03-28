// string::substr
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos);     // get from "live" to the end

  std::cout << str2 << ' ' << str3 << '\n';
  std::cout << str.substr(3) << '\n';
  std::unordered_map<char, std::string> m;
  std::cout << m['c'] << '\n';
  if(m['c'] == "") {
  	std::cout << "Y" << '\n';
  }
 

  return 0;
}