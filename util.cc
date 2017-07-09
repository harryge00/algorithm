void swap(int arr[], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void printArr(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		std::cout<<arr[i];
		if(i != n - 1) {
			std::cout<<","
		}
	}
	std::cout<<std::endl;
}