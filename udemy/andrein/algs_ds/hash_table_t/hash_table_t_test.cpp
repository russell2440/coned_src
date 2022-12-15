#include "hash_table_t.h"

int main()
{
  hash_table_t ht(20);
  
  // Set some values with the 'grapes' key.
  ht.set("grapes",1000);
  ht.set("grapes",14000);
  ht.set("grapes",28);
  ht.get("grapes");
  
  ht.set("apples",20000);
  ht.get("apples");

  ht.set("peach",40000);
  ht.get("peach");

  ht.keys();

  return 0;
}
