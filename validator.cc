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

bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
          sum += nums[i];
        }
        if(sum % 2 == 1) {
          return false;
        }
        int target = sum/2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for(int i = 0; i < nums.size(); i++) {
          for(int j = target; j >= nums[i]; j--) {
            if(dp[j - nums[i]]) {
              dp[j] = true;
            }
          }
          if(dp[target]) {
            return true;
          }
        }
        return false;
    }

int main ()
{
  vector<int> myvect = { 1, 2, 5};
  cout<<canPartition(myvect) << endl;
  vector<int> myvect2 = { 1, 2, 5, 2};
  cout<<canPartition(myvect2) << endl;

  vector<int> myvect3 = {100,100,100,100,100,100,100,100};
  cout<<canPartition(myvect3) << endl;
  return 0; 
}
