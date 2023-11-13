/*
 * merge_sort.cpp
 *
 *  Created on: Oct 24, 2021
 *      Author: russellshahenian
 */

#include "merge_sort.h"
#include <cstdio>

namespace rs {

merge_sort::merge_sort() {
	// TODO Auto-generated constructor stub
}

merge_sort::~merge_sort() {
	// TODO Auto-generated destructor stub
}


vector<int> merge_sort::_merge(vector<int> left, vector<int> right){

	unsigned int len = left.size() + right.size();
	vector<int>	merged(len,0);

	// Sorted Merge of left and right
	vector<int>::iterator lit,rit;
	lit = left.begin();
	rit = right.begin();
	for(vector<int>::iterator mit = merged.begin(); mit != merged.end(); mit++){
		// Take from either left or right
		if(lit != left.end() && rit != right.end()){
			if(*lit < *rit){
				*mit = *lit;
				lit++;
			} else {
				*mit = *rit;
				rit++;
			}
		} else {
			if(lit != left.end()){
				// Take from left
				*mit = *lit;
				lit++;
			} else {
				// Take from right
				*mit = *rit;
				rit++;
			}
		}
	}

	return(merged);
}

vector<int> merge_sort::run (vector<int> array){
	// Base case
	if (array.size() == 1) {
	    return array;
	}

	// Split Array in into right and left
	vector<int> left, right;
	unsigned int len = array.size();
	left.resize(len/2,0);
	if (0 == len%2){
	  // Even split
	  right.resize(len/2,0);
	}
	else{
	  // Odd split
		right.resize(len/2+1,0);
	}

	// copy array contents
	for(unsigned int i = 0; i < left.size(); i++){
	  left[i] = array[i];
	}
	for(unsigned int i = 0; i < right.size(); i++){
	  right[i] = array[(len/2)+i];
	}

	return (_merge( run(left), run(right) ) );
}


} /* namespace rs */
