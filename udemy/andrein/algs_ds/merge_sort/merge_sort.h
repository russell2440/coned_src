/*
 * merge_sort.h
 *
 *  Created on: Oct 24, 2021
 *      Author: russellshahenian
 */

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_


#include <vector>


using namespace std;

namespace rs {

class merge_sort  {
	vector<int> _merge(vector<int> left, vector<int> right);
public:
	merge_sort();
	virtual ~merge_sort();
	vector<int> run (vector<int> array);
	void display(vector<int> &v){
		printf("v-(%lu): ", v.size());
		for(int i = 0; i < v.size(); i++){
			printf(" %d", v[i]);
		}
		printf("\n");
	}
};

} /* namespace rs */

#endif /* MERGE_SORT_H_ */
