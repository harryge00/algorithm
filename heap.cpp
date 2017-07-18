// my first program in C++
#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int i) {
  int left = 2 * i + 1, right = 2 * i + 2, largest = i;
  if(left < arr.size()) {
    largest = arr[i] < arr[left] ? i : left;
  }
  if(right < arr.size()) {
    largest = arr[largest] < arr[right] ? largest: right;
  }
  if(i != largest) {
    swap(arr[i], arr[largest]);
    heapify(arr, largest);
  }
}
void heap_sort(vector<int>& arr) {
  int m = arr.size() / 2;
  for(int i = m; i >= 0; i--) {
    heapify(arr, i);
  }
}
int main()
{
  vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  heap_sort(arr);
  for(int i = 0; i < arr.size(); i++) {
    cout<< arr[i] <<",";
  }
  cout<<endl;
}
