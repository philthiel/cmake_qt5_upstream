#include <mylib.h>
#include <iostream>


using namespace std;
using namespace MYLIB;


int main()
{
	MyLIB m;
	m.set_string("Hello world :)");

	cout << m.get_string() << endl;

	return 0;
}
