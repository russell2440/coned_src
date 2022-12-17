#include "hash_table_t.h"

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
  ht.get("grapes");
  
  ht.set("apples",20000);
  ht.display();
  ht.get("apples");
  ht.display();

  ht.set("peach",40000);
  ht.display();
  ht.get("peach");
  ht.display();

  ht.display();

  return 0;
}
