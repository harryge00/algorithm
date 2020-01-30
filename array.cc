#include <iostream>
#include <string>
#include <vector>


using namespace std;

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
	string str = "(-3,5),(87,4),(93,3),(3,0)";
	cout<<str.substr(str.find('(') + 1, str.find(","));
	int* arr = new int[10];
	cout<<arr[0]<<","<<arr[1]<<","<<arr[2]<<","<<arr[3];
	cout<<endl;
	
}