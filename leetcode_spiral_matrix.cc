# include <iostream>
# include <vector>
using namespace::std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res (n, vector<int>(n));
        int t= 1;
        // if(n == 1) {
        //     res[0][0] = t; 
        //     return res;
        // }
        int a = -1, b = -1;
        for(int i = 0; i < (n+1)/2; i++) {
            int len = n - 2 * i;
            a++;b++;
            if(len == 1) {
                cout<<a<<","<<b<<":"<<t<<endl;
                res[a][b] = t++;
            }
            for(int j = 0; j <len - 1; j++) {
                cout<<a<<","<<b<<":"<<t<<endl;
                res[a][b++] = t++;
            }
            for(int j = 0; j < len - 1; j++) {
                cout<<a<<","<<b<<":"<<t<<endl;
                res[a++][b] = t++;
            }
            for(int j = 0; j < len - 1; j++) {
                cout<<a<<","<<b<<":"<<t<<endl;
                res[a][b--] = t++;
            }
            for(int j = 0; j < len - 1; j++) {
                cout<<a<<","<<b<<":"<<t<<endl;
                res[a--][b] = t++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    s.generateMatrix(4);
}