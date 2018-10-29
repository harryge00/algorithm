#include <iostream>
#include <vector>

using namespace std;
int longestPalindromeSubseq(string s) {
    int dp1[1000];
    int dp2[1000];
    bool useDP1 = true;
    for(int i = s.length() - 1; i >= 0; i--) {
      dp1[i][i] = 1;
      for(int j = i + 1; j < s.length(); j++) {
        if(useDP1) {
          if(s[i] == s[j]) {
            dp1[j] = dp2[j - 1] + 2;
          } else {
            dp1[j] = dp1[j - 1] > dp2[j] ? dp1[j - 1] : dp2[j];
          }
        } else {
          if(s[i] == s[j]) {
            dp2[j] = dp2[j - 1] + 2;
          } else {
            dp2[j] = dp1[j - 1] > dp2[j] ? dp1[j - 1] : dp2[j];
          }
        }
        useDP1 = !useDP1;
      }
    }
    return dp[0][s.length() - 1];
}
  
int main ()
{
  cout<<"abxcybaz " << longestPalindromeSubseq("abxcybaz")<<endl;
  cout<<"123abxcybaz321 " << longestPalindromeSubseq("123abxcybaz321")<<endl;
  cout<<"bbbab " << longestPalindromeSubseq("bbbab")<<endl;
  return 0;
}
