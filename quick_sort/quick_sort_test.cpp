#include "quick_sort_t.h"

int
main(int argc, char **argv)
{
  // TODO use these for something.
  (void) argc;
  (void) argv;

  rs::quick_sort_t::perform(std::vector<int>({99, 23, 45, 424, 8, 0, 1022, 3, 434, 72}));

  rs::quick_sort_t::perform(std::vector<int>({424, 8, 0}));

  rs::quick_sort_t::perform(std::vector<int>({424, 8}));
}






