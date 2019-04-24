#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include "hello_func.h"
#include "version.h"

using namespace std;

string fullVersion() {
	ostringstream stream;
	stream << PROJECT_VERSION_MAJOR << "." << PROJECT_VERSION_MINOR << "." << PROJECT_VERSION_PATCH;
	return stream.str();
}