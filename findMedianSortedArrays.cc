class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	/*
    		1 4 5 6
    		8 19 22 24 25

    		1 2 3  8  14
    		5 6 10 20 30

			1 	2 3  8  14
    		15 16 18 20 30

			
    		50
    		50

    		1	2	3
			2	4	6	8
			3	6	9	12
			4	8	12	16
			5	10	12	16
			6
			7

			11	22

    		s1/2
    		s2/2
    		nums1 always short
    	*/

    	int s1, s2 = nums1.size(), nums2.size();
    	int m1, m2;
    	if(s1 % 2 == 0 & s2 % 2 == 0) {
    		m1 = s1/2;
    		m2 = s2/2 - 1;
    	} else {
    		m1 = s1/2;
    		m2 = s2/2;
    	}
    	
    	int leftMax, rightMin;

    	while(true) {
    		if(m1 == s1 - 1) {
    			rightMin = nums[m2 + 1];
    		} else {
    			rightMin = min(nums[m2 + 1], nums[m1 + 1]);
    		}

    		if(m1 == 0) {
    			leftMax = max(nums[m2 - 1])
    		} else {
    			leftMax = max(nums[m1 - 1], nums[m2 - 1])
    		}
    		if(leftMax <= rightMin) {
    			break;
    		} else {


    		}

    	}

    }
    double find(vector<int>& nums1, vector<int>& nums2, int m1, int m2) {
    	if(m1 + m2 )
    }
};