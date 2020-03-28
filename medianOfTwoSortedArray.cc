class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int halfLen = (m + n + 1) / 2;
        int iMin = 0, iMax = m;
        int i, j;
        while(true) {
        	i = (iMin + iMax)/ 2;
        	j = halfLen - i;
        	if(i > 0 && j < n && nums2[j] < nums1[i - 1]) {
                iMax = i - 1;
                continue;
        	}
        	if(j > 0 && i < m && nums1[i] < nums2[j - 1]) {
        		iMin = i + 1;
        		continue;
        	}
        	break;
        }
        if((m + n) % 2) {
        	if(i == 0) {
        		return nums2[j - 1];
        	}
        	if(j == 0) {
        		return nums1[i - 1];
        	}
        	return max(nums1[i - 1], nums2[j - 1]);
        }
        int leftMax, rightMin;
        if(j == 0) {
        	leftMax = nums1[i - 1];
        } else if(i == 0) {
        	leftMax = nums2[j - 1];
        } else {
        	leftMax = max(nums2[j - 1], nums1[i - 1]);
        }
        if(i == m) {
        	rightMin = nums2[j];
        } else if(j == n) {
        	rightMin = nums1[i];
        } else {
        	rightMin = min(nums1[i], nums2[j]);
        }
        return (leftMax + rightMin)/ 2.0;

    }
};