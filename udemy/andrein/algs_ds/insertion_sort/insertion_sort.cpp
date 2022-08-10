/*
 * insertionsort.cpp
 *
 *  Created on: Nov 5, 2021
 *      Author: russellshahenian
 */

#include "insertion_sort.h"


namespace rs {

insertion_sort::insertion_sort() {
	// TODO Auto-generated constructor stub

}

insertion_sort::~insertion_sort() {
	// TODO Auto-generated destructor stub
}

insertion_sort::insertion_sort(const insertion_sort &other) {
	// TODO Auto-generated constructor stub

}

insertion_sort::insertion_sort(insertion_sort &&other) {
	// TODO Auto-generated constructor stub

}

insertion_sort& insertion_sort::operator=(const insertion_sort &other) {
	// TODO Auto-generated method stub
}

insertion_sort& insertion_sort::operator=(insertion_sort &&other) {
	// TODO Auto-generated method stub
}



void insertion_sort::display_list(std::list<int> &l, std::list<int>::iterator &cwit){
  for(std::list<int>::iterator it = l.begin(); it != l.end(); it++){
    if(cwit == it){
      printf(" (%d)", *it);
    }else{
      printf(" %d", *it);
    }
  }
  printf("\n");
}

void insertion_sort::display_list(std::list<int> &l){
  for(std::list<int>::iterator it = l.begin(); it != l.end(); it++){
      printf(" %d", *it);
  }
  printf("\n");
}


//
// Insertion sort:
// Using std list, initializing with pointers to input array
// ends and output array start.
// Algorithm uses outer loop for the current working element
// and innter loop for search/insertion loop.
//
void insertion_sort::exec(const int *pinput, const int *pend, int *poutput){

  // Construct list from input
  std::list<int> input(pinput, pend);

  // current working element loop
  for (std::list<int>::iterator cwit = input.begin(); cwit != input.end();){
    // Insertion loop
    bool spliced = false;
    for (std::list<int>::iterator sit = input.begin(); sit != cwit; sit++){
      if(*cwit < *sit){
        // Keep cw iteration continuity
        std::list<int>::iterator tmpit =  cwit; cwit++;
        // Transfer lesser in
        input.splice(sit, input, tmpit);
        spliced = true;
        break;
      }
    }
    if(!spliced){
      cwit++;
    }
  }

  // Store sorted list into output
  for (std::list<int>::iterator it = input.begin(); it != input.end(); it++){
    *(poutput++) = *it;
  }
}



} /* namespace rs */
