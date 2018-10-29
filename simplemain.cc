#include <iostream>
#include <vector>

using namespace std;
int longestPalindromeSubseq(string s) {
    vector<int> dp(s.length());
    for(int i = s.length() - 1; i >= 0; i--) {
      dp[i] = 1;
      for(int j = i + 1; j < s.length(); j++) {
        // if(s[i])
      }
    }
    return dp[s.length() - 1];
}

int main ()
{
  cout<<"abxcybaz " << longestPalindromeSubseq("abxcybaz")<<endl;
  cout<< (4||7) <<","<< (5||3) << endl;
  return 0; 
}
