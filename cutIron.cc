#include <iostream>
#include <string>
#include <vector>


using namespace std;

int x[] = {0,1,5,8,9,10,17,17,20,24,30};

int findElem(vector<int> &nums, int lo, int hi, int k) {
	if(lo >= hi) return nums[lo];
	int pivot = nums[hi];
	int i = lo;
	for(int j = hi - 1; j > lo; j--) {
		if(nums[j] < pivot) {
			int tmp = nums[i];
			nums[i++] = nums[j];
			nums[j] = tmp;
		}
	}
	if(k == i) {
		return pivot;
	}
	nums[hi] = nums[i];
	nums[i] = pivot;
	if(k < i) {
		return findElem(nums, lo, i - 1, k);
	} else {
		return findElem(nums, i + 1, hi, k);
	}
}

int main() {
	
	
}