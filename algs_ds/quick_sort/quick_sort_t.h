#include <vector>
#include <iterator>
#include <iostream>


namespace rs
{
  // Userful alias.
  using iter_t = std::vector<int>::iterator;

  /**
   * This is the quick sort class.
   */
  class quick_sort_t
  {
  public:
    /**
     * This method is responsible for getting the quicksort done.
     *
     * @return This method returns the sorted data.
     */
    static std::vector<int> perform(std::vector<int> input);


  private:

    //---------------------
    // Private methods.
    //---------------------

    /**
     * Constructor.
     */
    quick_sort_t(std::vector<int> input) ;

    /**
     * This method is responsible for the performing
     * the sort algorithm.
     * 
     * If there's a segment that's two or more elements, then we
     * assign the pivot and sort it to the best spot.
     * Then we perform the same algorithm on the segments to the
     * left and to the right of the pivot.
     * This is done in a recursive manner until this all is done.
     *
     * @param begin the iterator that define's the segments start.
     * 
     * @param begin the iterator that define's the segments end.
     */
    void do_sort( rs::iter_t begin, rs::iter_t end);

    rs::iter_t do_swap( rs::iter_t start, rs::iter_t pivot);

    std::vector<int> get_output();

    /**
     * This method displays the contents of the supplied vector.
     *
     * @param location is the caller supplied string.
     *
     * @param vector is the vector to display.
     */
    void inline display(std::vector<int> vector)
    {
      for(auto it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << " ";
      std::cout << std::endl;
    }

    //---------------------
    // Private data.
    //---------------------

    // Local input copy.
    std::vector<int> input_;
  };
}
//end namespace rs
