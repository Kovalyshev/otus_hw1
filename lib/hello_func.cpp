#include "hello_func.h"
#include "version.h"

using namespace std;

string fullVersion() {
	return str(PROJECT_VERSION_MAJOR) + "." + str(PROJECT_VERSION_MINOR) + "." + str(PROJECT_VERSION_PATCH);
}