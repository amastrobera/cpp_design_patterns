#ifndef strategy_h
#define strategy_h

#include <functional>
#include <vector>

namespace design_patterns
{

void merge_sort(std::vector<int>& arr);

void quick_sort(std::vector<int>& arr);

void print_arr(std::vector<int> const& arr);

class Client
{
public:
    Client(std::function<void(std::vector<int>&)> injSorter);
    void sort(std::vector<int>& arr);
    
private:
    std::function<void(std::vector<int>&)> mrSorter;
};


}

#endif
