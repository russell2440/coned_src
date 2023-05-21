#include "bst_t.h"

#include <cstdio>

int main() {
  printf("Binary Search Tree unit test, and Russell I LOVE you!\n");
  rhs::bst_t tree;
//                  9
//          4               20
//      1       6     15          170
//
  tree.insert(9);
  tree.insert(4);
  tree.insert(6);
  tree.insert(20);
  tree.insert(170);
  tree.insert(15);
  tree.insert(1);
  tree.display();

  int value = 20;
  printf("Is %d in tree? %d\n",value, tree.lookup(value));
  value = 25;
  printf("Is %d in tree? %d\n",value, tree.lookup(value));
  value = 254;
  printf("Is %d in tree? %d\n",value, tree.lookup(value));
  value = 6;
  printf("Is %d in tree? %d\n",value, tree.lookup(value));

  tree.remove(6);
  tree.display();


  return 0;
}

