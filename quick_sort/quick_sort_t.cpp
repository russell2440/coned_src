#include <vector>
#include <iterator>
#include "quick_sort_t.h"


//=============================================================================
//=============================================================================
std::vector<int>
rs::quick_sort_t::perform(std::vector<int> input)
{
  // Create the quicksort instance.  Supply input vector.
  quick_sort_t qs(input);

  return qs.get_output();
}


//=============================================================================
//=============================================================================
rs::quick_sort_t::quick_sort_t(std::vector<int> input)
: input_(input)
{
  this->display(this->input_);
  this->do_sort(input_.begin(), input_.end()-1);
  this->display(this->input_);
}


//=============================================================================
//=============================================================================
void
rs::quick_sort_t::do_sort(rs::iter_t first, rs::iter_t last)
{
  // Do the swap if its has the length.
  iter_t pivot = do_swap(first, last);

  // Do the left segment if its has the length.
  if (first < (pivot - 1))
    { do_sort(first, pivot - 1); }

  // Do the right segment if its has the length.
  if ((pivot + 1) < last)
    { do_sort(pivot + 1, last); }
}


//=============================================================================
//=============================================================================
rs::iter_t
rs::quick_sort_t::do_swap(rs::iter_t first, rs::iter_t last)
{
  // Setup pivot.
  iter_t scan = first;
  iter_t pivot = last;

  while (scan < pivot)
  {
    if (*pivot < *scan)
    {
      int scan_element = *scan;
      *scan = *(pivot - 1);
      *(pivot - 1) = *pivot;
      *pivot = scan_element;
      --pivot;
    }
    else
    {
      ++scan;
    }
  }

  return pivot;
}


//=============================================================================
//=============================================================================
std::vector<int>
rs::quick_sort_t::get_output()
{
  return input_;
}
