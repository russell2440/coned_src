/*
 * insertionsort.h
 *
 *  Created on: Nov 5, 2021
 *      Author: russellshahenian
 */

#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include <vector>
#include <list>

namespace rs {

class insertion_sort  {
public:
	insertion_sort();
	virtual ~insertion_sort();
	insertion_sort(const insertion_sort &other);
	insertion_sort(insertion_sort &&other);
	insertion_sort& operator=(const insertion_sort &other);
	insertion_sort& operator=(insertion_sort &&other);
	void display_list(std::list<int> &l, std::list<int>::iterator &cwit);
	void display_list(std::list<int> &l);
	void exec(const int *pinput, const int *pend, int *poutput);

};

} /* namespace rs */

#endif /* INSERTION_SORT_H_ */
