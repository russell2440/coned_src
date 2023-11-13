#include <iostream>
#include "double_linked_list.h"

int main() {
  std::cout << "Hello World!\n";

  double_linked_list dll;

  dll.append(10);
  dll.print();
  dll.print_rev();
  dll.append(15);
  dll.print();
  dll.print_rev();
  dll.append(16);
  dll.print();
  dll.print_rev();
  dll.prepend(1);
  dll.print();
  dll.print_rev();
  dll.insert(2,99);
  dll.print();
  dll.print_rev();
  dll.insert(1,98);
  dll.print();
  dll.print_rev();
  dll.insert(0,97);
  dll.print();
  dll.print_rev();
  dll.insert(100,96);
  dll.print();
  dll.print_rev();
  dll.remove(2);
  dll.print();
  dll.print_rev();
  dll.remove(2);
  dll.print();
  dll.print_rev();


  dll.remove(2);
  dll.print();
  dll.print_rev();


}