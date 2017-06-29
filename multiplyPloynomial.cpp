#include <iostream>
#include <string>
#include <stdlib.h> 
#include <vector> 

using namespace std;

vector<int> helper(vector<int> &pA, vector<int> &pB) {
  cout<< "helper"<<endl;
  vector<int> res(1001, 0);
  for(int i = 0; i < pA.size(); i++) {
    if(pA[i]) {
      cout<<pA[i]<<",";
      for(int j = 0; j < pB.size(); j++) {
        if(pB[j]) {
          cout<<pB[j]<<endl;
          int tmp = pA[i] * pB[j];
          res[i + j] = tmp;
        }
      }
    }
  }
  return res;
}

void multiplyPloynomial(string pA, string pB) {
  int m, n;
  vector<int> arr1(1001, 0);
  vector<int> arr2(1001, 0);
  while(true) {
    m = stoi(pA.substr(pA.find('(') + 1, pA.find(',')), nullptr, 0);
    n = stoi(pA.substr(pA.find(',') + 1, pA.find(')')), nullptr, 0);
    std::size_t found = pA.find(",(");
    if(found == std::string::npos) break;
    pA = pA.substr(found + 1);
    arr1[m] = n;
  }
  while(true) {
    m = stoi(pB.substr(pB.find('(') + 1, pB.find(',')), nullptr, 0);
    n = stoi(pB.substr(pB.find(',') + 1, pB.find(')')), nullptr, 0);
    std::size_t found = pB.find(",(");
    if(found == std::string::npos) break;
    pB = pB.substr(found + 1);
    arr2[m] = n;
  }
  cout <<" arr1" <<endl;
  for(int i = 0; i < 1001; i++) {
    if(arr1[i]) {
      cout<<i << "," << arr1[i] << endl;
    }
  }
  cout <<" arr2" <<endl;
  for(int i = 0; i < 1001; i++) {
    if(arr2[i]) {
      cout<<i << "," << arr2[i] << endl;
    }
  }
  vector<int> res = helper(arr1, arr2);
  for(int i = 0; i < 1001; i++) {
    if(res[i]) {
      cout<<i << "," << res[i] << endl;
    }
  }
};

// string helper(vector<pair<int,int>> &pA, vector<pair<int,int>> &pB) {

// }

int main ()
{
  multiplyPloynomial("(-3,5),(87,4),(93,3),(3,0)", "(1,0)");
  multiplyPloynomial("(-3,5),(87,4),(93,3),(3,0)", "(0,0)");
  multiplyPloynomial("(-3,5),(87,4),(93,3),(3,0)", "(2,2),(4,0)");
  // std::cout<<multiplyPloynomial("(-3,5),(87,4),(93,3),(3,0)", "(1,0)")<<std::endl;
  // std::cout<<multiplyPloynomial("(-3,5),(87,4),(93,3),(3,0)", "(0,0)")<<std::endl;
  // std::cout<<multiplyPloynomial("(-3,5),(87,4),(93,3),(3,0)", "(2,2),(4,0)")<<std::endl;
  return 0;
}
