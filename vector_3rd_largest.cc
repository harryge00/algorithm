// vector::emplace
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int thirdMax(vector<int>& nums) {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        long tmp;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= c || nums[i] == b || nums[i] == a) continue;
            if(nums[i] > a) {
                tmp = a;
                a = nums[i];
                b = tmp;
            } else if(nums[i] > b) {
                tmp = b;
                b = nums[i];
                c = tmp;
                
            } else {
                c = nums[i];
            }
        }
        return c == LONG_MIN? a: c;
    }

int main ()
{
  std::vector<int> myvector = {10,20, 90, 20, 10, 30};

  std::cout << thirdMax(myvector) << '\n';

  return 0;
}