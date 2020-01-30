#include <iostream>
#include <algorithm>
#include <vector>

# 3 2 1 5 6 4 
# 2 1 3 5 6 4

using namespace std;

// We need this function to define how to sort
// the vector. We will pass this function into the
// third parameter and it will tell it to sort descendingly.
bool wayToSort(int i, int j) {
	return i > j;
}

int main()
{
    int intVec[8] = {56, 32, -43, 23, 12, 93, 132, -154};
    
    // Do not include the () when you call wayToSort
    // It must be passed as a function pointer or function object
    sort(intVec, intVec + 8, wayToSort);

    for (int i = 0; i < 8; i++)
        cout << intVec[i] << " ";
    
    return 0;
}
