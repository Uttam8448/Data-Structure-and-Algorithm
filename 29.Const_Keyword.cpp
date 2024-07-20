// C++ program to demonstrate the
// above concept
//#include <iostream>
//using namespace std;
//
//// Driver Code
//int main()
//{
//	int x=10 ;
//	int z=8;
//	char y='M';
//
//	const int* i = &x;
//	const char* j = &y;
//	i=&z;
//	// Value of x and y can be altered,
//	// they are not constant variables
//	x = 9;
//	y = 'A';
//	
//	// Change of constant values because,
//	// i and j are pointing to const-int
//	// & const-char type value
//	// *i = 6;
//	// *j = 7;
//
//	cout << *i << " " << *j;
//}
// C++ program to demonstrate the
// above concept
//#include <iostream>
//using namespace std;
//
//// Driver Code
//int main()
//{
//	// x and z non-const var
//	int x = 5;
//	int z = 6;
//
//	// y and p non-const var
//	char y = 'A';
//	char p = 'C';
//
//	// const pointer(i) pointing
//	// to the var x's location
//	int* const i = &x;
//
//	// const pointer(j) pointing
//	// to the var y's location
//	char* const j = &y;
//
//
//	// The values that is stored at the memory location can modified
//	// even if we modify it through the pointer itself
//	// No CTE error
//	*i = 10;
//	*j = 'D';
//
//	// CTE because pointer variable
//	// is const type so the address
//	// pointed by the pointer variables
//	// can't be changed
//	// i = &z;
//	// j = &p;
//
//	cout << *i << " and " << *j
//		<< endl;
//	cout << i << " and " << j;
//
//	return 0;
//}
// C++ program to demonstrate the
// above approach
#include <iostream>
using namespace std;

// Function foo() with variable
// const int
void foo(const int y)
{
	y = 6; const value
	// can't be change
	cout << y;
}

// Function foo() with variable int
void foo1(int y)
{
	// Non-const value can be change
	y = 5;
	cout << '\n'
		<< y;
}

// Driver Code
int main()
{
	int x = 9;
	const int z = 10;

	foo(z);
	foo1(z);

	return 0;
}

