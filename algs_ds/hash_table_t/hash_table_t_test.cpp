#include "hash_table_t.h"
#include <iostream>

int main()
{
  hash_table_t ht(20);
  
  // Set some values with the 'grapes' key.
  ht.set("grapes",1000);
  ht.display();
  ht.set("grapes",14000);
  ht.display();
  ht.set("grapes",28);
  ht.display();
  std::cout << ht.get("grapes") << std::endl;
  std::cout << std::endl;
  
  ht.set("apples",20000);
  ht.display();
  ht.get("apples");
  ht.display();
  std::cout << ht.get("apples") << std::endl;
  std::cout << std::endl;

  ht.set("peach",40000);
  ht.display();
  ht.get("peach");
  ht.display();
  std::cout << ht.get("peach") << std::endl;
  std::cout << std::endl;

  return 0;
}
