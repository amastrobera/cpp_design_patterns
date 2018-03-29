#include <strategy.hpp>

#include <algorithm>
#include <iostream>

namespace design_patterns
{

void merge_sort(std::vector<int>& arr)
{
  std::cout << "using merge_sort" << std::endl;
  std::sort(arr.begin(), arr.end());
}

void quick_sort(std::vector<int>& arr)
{
  std::cout << "using quick_sort" << std::endl;
  std::sort(arr.begin(), arr.end());
}

void print_arr(std::vector<int> const& arr)
{
  for (size_t i = 0; i < arr.size(); ++i)
    std::cout << arr[i] << ' ';
  std::cout << std::endl;
}

Client::Client(std::function<void(std::vector<int>&)> injSorter)
  : mrSorter(injSorter)
{
}

void Client::sort(std::vector<int>& arr)
{
  mrSorter(arr);
}
}
