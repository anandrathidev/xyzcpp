#include "VectorSlice.h"

void test_VectorSlice() {
	std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	VectorSlice<int> vs(v);
}