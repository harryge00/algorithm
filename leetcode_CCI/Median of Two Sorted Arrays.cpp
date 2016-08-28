#include <iostream>
#include <unordered_set>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
    int l1 = 0, l2=0, r1= nums1.size()-1, r2 = nums2.size() -1;
    int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
    if(m1+m2 < (m+n)/2)
    	m1++;
    while(1) {
    	if(m2 > 0 && nums[m1] > nums[m2-1] && nums[] )
    }
}
int main() {
	int arr[] = {2, 7, 13, 19};
	vector<int> nums1(arr, arr+3);
	int arr2[] = {1, 7, 13, 19};
	vector<int> nums2(arr2, arr2+3);
	cout<<findMedianSortedArrays(nums1, nums2)<<endl;
}
