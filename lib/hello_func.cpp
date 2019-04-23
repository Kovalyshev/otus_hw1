#include "hello_func.h"
#include "version.h"

using namespace std;

string fullVersion() {
	return to_string(PROJECT_VERSION_MAJOR) + "." + to_string(PROJECT_VERSION_MINOR) + "." + to_string(PROJECT_VERSION_PATCH);
}