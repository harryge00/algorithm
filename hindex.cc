class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> papers(n, 0);
        // 计数
        for (int c: citations)
            papers[Math.min(n, c)]++;
        // 找出最大的 k
        int k = n;
        for (int s = papers[n]; k > s; s += papers[k])
            k--;
        return k;
    }
};