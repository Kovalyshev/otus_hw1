#include <iostream>
#include "../lib/hello_func.h"

using namespace std;

int main() {
	cout << "Hello, world!" << endl << endl;

	cout << "Version is " << fullVersion() << endl;
	
	return 0;
}