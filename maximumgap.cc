class Solution {
    // 1 5 10 12 15 / 15 - 1 / 5 - 1 = 3 
    //1 4 7 10 13 16
    class Bucket {        
    public:
        int min;
        int max;
        Bucket() {
            min = INT_MAX;
            max = INT_MIN;
        }
    }
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        int min = INT_MAX, max = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < min) {
                min = nums[i];
            }
            if(nums[i] > max) {
                max = nums[i];
            }
        }
        int bucketLen = (max - min) / (nums.size() - 1);
        vector<Bucket> buckets(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            int curIndex = (nums[i] - min) / bucketLen;
            if(buckets[i].max < nums[i]) {
                buckets[i].max = nums[i];
            }
            if(buckets[i].min > nums[i]) {
                buckets[i].min = nums[i];
            }
        }
        int maximumGap = 0;
        for(int i = 1; i < buckets.size(); i++) {
            if(buckets[i].min - buckets[i - 1].max > maximumGap) {
                maximumGap = buckets[i].min - buckets[i - 1].max;
            }
        }

        return maximumGap;
    }
};