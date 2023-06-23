/*
 * insertionsort_test.cpp
 *
 *  Created on: Nov 5, 2021
 *      Author: russellshahenian
 */

#include "insertion_sort.h"

using namespace rs;


#include <iostream>

#include <cstdio>



int main() {
  int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  unsigned int numbers_len = (sizeof(numbers)/sizeof(*numbers));

  std::cout << "Hello Russ! insert_sort() test\n";

  for (int *p = numbers; p < numbers+numbers_len; p++)
  {
    printf(" %d", *p);
  }
  printf("\n");

  insertion_sort is;
  is.exec(numbers, numbers+numbers_len, numbers);

  for (int *p = numbers; p < numbers+numbers_len; p++)
  {
    printf(" %d", *p);
  }

  printf("\n");
}
