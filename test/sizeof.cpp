#include <iostream>
using namespace std;

struct person{
	char ch;
	int i;
};

class A{
	char ch;
	int i;
};

int main()
{
	person a;
	A b;
	cout << sizeof(a) <<endl;
	cout << sizeof(b) <<endl;
	
	return 0;
}
