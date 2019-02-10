#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

typedef struct rubble { // need tag name for self-reference int betty;
  char barney[4];
  struct rubble *bammbamm;
} rubble;

typedef struct {
  short *wilma[2];
  short fred[2];
  rubble dino;
} flintstone;

typedef struct { int a, b; } IntPair;

int main() {
	rubble *simpsons;
	flintstone jetsons[4];
	simpsons = &jetsons[0].dino;
	jetsons[1].wilma[3] = (short *) &simpsons; 
	strcpy(simpsons[2].barney, "Bugs Bunny");
	((flintstone *)(jetsons->fred))->dino.bammbamm = simpsons; 
	*(char **)jetsons[4].fred = simpsons->barney + 4;
	cout<<"sss"<<endl;

	// unique_ptr<int> x(new int(5));
	// int *ptr = x.get();
	// // Return a reference to the pointed-to object
	// int val = *x;
	// cout<<val<<endl;
	// // Access a field or function of a pointed-to object
	// unique_ptr<IntPair> ip(new IntPair); 
	// ip->a = 100;
	// // Deallocate the pointed-to object and reset the unique_ptr with // a new heap-allocated object.
	// x.reset(new int(1));
	// cout<<val<<","<<*x<<endl;

	// // Release responsibility for freeing the pointed-to object.
	// ptr = x.release(); 
	// delete ptr;


	unique_ptr<int> x(new int(5)); 
	cout << "x: " << x.get() << endl;
	unique_ptr<int> y(x.release()); // y takes ownership, x abdicates it cout << "x: " << x.get() << endl;
	cout << "y: " << y.get() << endl;
	cout << "x: " << x.get() << endl;

	unique_ptr<int> z(new int(10));
	cout << "z: " << *z << endl;
	// z delete's its old pointer and takes ownership of y's pointer. // y abdicates its ownership.
	z.reset(y.release());
	cout << "z: " << *z << endl;


}