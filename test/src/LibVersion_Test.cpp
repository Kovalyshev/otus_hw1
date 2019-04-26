#include <limits.h>
#include <string>

#include "gtest/gtest.h"
#include "../../lib/hello_func.h"

using namespace std;

TEST(LibVerstion, VersionNotEmpty) {
	string version = fullVersion();
	ASSERT_FALSE(version.empty());
};

TEST(LibVersion, ContainsThreeDigits) {
	string version = fullVersion();

	int countDigits = 0;
	int pos = 0;
		
	while (pos != string::npos) {
		countDigits++;
		pos = version.find(".", pos + 1);
	}
		
	ASSERT_EQ(countDigits, 3);
}