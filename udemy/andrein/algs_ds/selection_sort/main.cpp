#include <iostream>

int passes = 0;

 unsigned int numbers[] 
//= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
= {19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};

const unsigned int len = sizeof (numbers) /sizeof *numbers;
unsigned int *input = numbers;

// Their is one major pass over array, each current index, ci, 
// will end up being greater than previous.
// The innter logic uses the ci to start scanning for the next
// largest element.
void selection_sort(void) {
  // Sort input by running buble sort 
  // passes until all sorting us done
  unsigned int *pi = input;
  for(int i = 0; i < len; i++, pi++){
    unsigned int *pm = pi;
    unsigned int *pj = pi;
    for(int j = i; j < len; j++, pj++){
      if(*pm > *pj){
        pm = pj;
       }
    }
    unsigned int tmp = *pi;
    *pi = *pm;
    *pm = tmp;
  }
  return;
}

int main() {
  std::cout << "Hello World!\n";
  void buble_sort(void);
  for (int i = 0; i < len; i++){
    printf("%d,",numbers[i]);
  }
  selection_sort();
  printf("\n%d\n",passes);
  for (int i = 0; i < len; i++){
    printf("%d,",numbers[i]);
  }
  printf("\n%d\n",passes);

}