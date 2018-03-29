#include <strategy.hpp>

using namespace design_patterns;

int main()
{
  std::vector<int> arr = {21,43,54,12,43,65,93,82};
  
  Client myclass(&merge_sort); // injected as a function pointer

  print_arr(arr);
  
  myclass.sort(arr);
  
  print_arr(arr);

  return 0;
}
