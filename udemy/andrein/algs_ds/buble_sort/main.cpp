#include <iostream>



int passes = 0;

 unsigned int numbers[] 
//= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
= {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};

const unsigned int len = sizeof (numbers) /sizeof *numbers;
unsigned int *input = numbers;


bool buble_pass(void){
  bool bubbled = false;
  // Each passs does the bubbling
  unsigned int *p = input;
  unsigned int *pp = p+1;
  for(int i = 0; i < len-1; i++, p++, pp++){
    if(*p > *pp){
      unsigned int tmp = *pp;
      *pp = *p;
      *p = tmp;
      bubbled = true;
    }
  }

  return bubbled;
}

void buble_sort1(void) {
  // Sort input by running buble sort 
  // passes until all sorting us done
  if(len < 2) { // nothing to sort
    return;
  }
  bool bubbled = buble_pass();
  while(bubbled){
    bubbled = buble_pass();
  }
  return;
}

void buble_sort(void) {
  // Sort input by running buble sort 
  // passes until all sorting us done
  for(int i = 0; i < len; i++){
    unsigned int *p = input;
    unsigned int *pp = p+1;
    for(int j = 0; j < len-1; j++, p++, pp++){
      if(*p > *pp){
        unsigned int tmp = *pp;
        *pp = *p;
        *p = tmp;
      }
    }
  }
  return;
}

int main() {
  std::cout << "Hello World!\n";
  void buble_sort(void);
  for (int i = 0; i < len; i++){
    printf("%d,",numbers[i]);
  }
  buble_sort();
  printf("\n%d\n",passes);
  for (int i = 0; i < len; i++){
    printf("%d,",numbers[i]);
  }

}