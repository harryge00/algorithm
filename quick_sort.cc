# include <iostream>
# include <vector>
#include <cmath>
#include <climits>
using namespace::std;

void printArr(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    std::cout<<arr[i];
    if(i != n - 1) {
      std::cout<<",";
    }
  }
  std::cout<<std::endl;
}

int partition(int arr[], int p, int r) {
  cout<<p<<","<<r<<endl;
  int x = arr[r];
  int i = p - 1, j = p;
  for(;j < r; j++) {
    if(arr[j] <= x) {
      i++;
      int tmp = arr[j];
      arr[j] = arr[i];
      arr[i] = tmp;
    }
  }
  i++;
  int tmp = arr[i];
  arr[i] = arr[r];
  arr[r] = tmp;
  printArr(arr, 5);
  cout<<"i:"<<i<<endl;
  return i;
}

void quicksort(int arr[], int p, int r) {
  if(p >= r) return;
  int i = partition(arr, p, r);
  quicksort(arr, p, i - 1);
  quicksort(arr, i + 1, r);
}



// [[1,10],[2,3],[5,8],[4,7]]
int main() {
  int arr[] = {5, 3, 2, 1, 4};
  quicksort(arr, 0, 4);
  printArr(arr, 5);
}
