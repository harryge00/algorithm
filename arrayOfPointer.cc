#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main () {
   int  var[MAX] = {10, 100, 200};
   int *ptr[MAX];
 
   for (int i = 0; i < MAX; i++) {
      ptr[i] = &var[i]; // assign the address of integer.
   }
   
   for (int i = 0; i < MAX; i++) {
      cout << "Value of var[" << i << "] = ";
      cout << *ptr[i] << endl;
   }

   // Pointer to an array of five numbers 
    int(*a)[5]; 
  
    int b[5] = { 1, 2, 3, 4, 5 }; 
  
    int i = 0; 
  
    // Points to the whole array b 
  
    a = &b; 
  
    for (i = 0; i < 5; i++)
        printf("%d\n", *(*a + i));
   
   return 0;
}