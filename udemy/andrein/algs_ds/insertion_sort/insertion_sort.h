/*
 * insertionsort.h
 *
 *  Created on: Nov 5, 2021
 *      Author: russellshahenian
 */
#pragma once

#include <vector>
#include <list>

namespace rs
{

  class insertion_sort
  {
  public:
  	insertion_sort();
  	void display_list(std::list<int> &l, std::list<int>::iterator &cwit);
  	void display_list(std::list<int> &l);
  	void exec(const int *pinput, const int *pend, int *poutput);
  };

} /* namespace rs */

