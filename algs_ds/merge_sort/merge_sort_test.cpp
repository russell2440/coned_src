//============================================================================
// Name        : mege_sort_test.cpp
// Author      : rhs
// Version     :
// Copyright   : 
// Description : 
//============================================================================

#include <iostream>
using namespace std;
#include "merge_sort.h"
using namespace rs;


int main() {
	int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
	vector<int> vn(numbers, numbers+(sizeof(numbers)/sizeof(*numbers)));

	cout<< __PRETTY_FUNCTION__ << endl;

	merge_sort ms;

	ms.display(vn);
	vn = ms.run(vn);
	ms.display(vn);

	return 0;

}
