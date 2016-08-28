#include <cmath>
class Solution {
public:
    int numSquares(int n) {
        if(n == 1)
        return 1;
        if(n == 2)
        return 2;
        if(n == 3)
        return 3;
        int k = std::sqrt(n);
        if(n % k == 0 && n/k == k)
            return 1;
        int min = n;
        for(int i=k; i > 1; i--) {
            int num = 1;
            int limit = i * i;
            int remain = n - limit;
            for(int j = i; remain > 4; j--) {
                    
            }
            while(remain > 4) {
                int sq = sqrt(remain);
                remain -= sq*sq;
                                
            }
        }
        
    }
};
