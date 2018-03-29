#### Strategy Pattern ###

A strategy is a pattern that allows to achieve the same goal, using one of many different ways. For example, sorting an array using one of the (classic) algorithms such as *merge-sort* or *quick-sort*. I would like to test this pattern in this way:

    Algo merge_sort;
    Client my_class(&merge_sort); // inject dependency
    my_class.Algo.sort();		  // then use it


This can be achieved with polymorphism, in one of the following ways:

* **C Function Pointers**

In C, it would be something like this:

    #include <stdio.h>
    void merge_sort(int** array, int size)
    {
	    printf("merge_sort\n");
    }
    void quick_sort(int** array, int size)
    {
	    //just to leave a footprint of the function call
	    *(array)[0] = 1; 
	    printf("quick_sort: a[0]=%d\n", *(array)[0]);
    }
    void do_something(int** array, int size, void*(*sorting_algo)(int**, int))
    {
	    printf("do_something called: a[0]=%d\n", array[0]);
	    sorting_algo(&array, size);
    }
    int main()
    {
	    int myarray[10] = {21,34,54,12,54,92,3,71,48,63};
	    do_something(&myarray, 10, &quick_sort);
	    printf("terminating: a[0]=%d\n", myarray[0]);
	    return 0;
    }
    
    
And would result in this:

    ubuntu: ~/development/c++/test/c_sorting
    $ ./a.out 
    do_something called: a[0]=21
    quick_sort: a[0]=1
    terminating: a[0]=1

 * **C++11 function**
[std::function](http://www.cplusplus.com/reference/functional/function/)  can wrap any *callable element* into a copyable object. It can wrap a function, a function pointer, a pointer to member, or any kind of function object (i.e., an object whose class defines operator(), including _closures_).  In code terms, it can be used in either of these ways:
```
//function, function 
int half(int x) {return x/2;}
struct third_t { int operator()(int x) {return x/3;} };
struct MyValue { int value; int fifth() {return value/5;}};

std::function<int(int)> fn1 = half;  // function
std::function<int(int)> fn2 = &half; // function pointer
std::function<int(int)> fn3 = third_t(); // function object
std::function<int(int)> fn4 = [](int x){return x/4;}; // lambda 
std::function<int(int)> fn5 = std::negate<int>(); // standard function object
```
**I want to use this approach**. The code is in the repo. The result is the following:

```
ubuntu: ~/development/c++/design_patterns/build
$ ./strategy/strategy 
21 43 54 12 43 65 93 82 
using merge_sort
12 21 43 43 54 65 82 93 
```

* **C++ Inheritance**
A `Sorter` base class, and `MergeSort`, `QuickSort` derived classes to override the method `void sort(container&)`.  I have already done this with the [factory pattern](/../master/factory) so I will just describe the idea. 
```
// main.cpp
// build : g++ --std=c++11 main.cpp
#include <algorithm>
#include <iostream>
#include <vector>
class Sorter
{
public: 
	virtual ~Sorter() {}
	virtual void sort(std::vector<int>& rArray) = 0;
};
class MergeSorter : public Sorter
{
public: 
	virtual void sort(std::vector<int>& rArray)
	{
		std::cout << "merge-sorting array" << std::endl;
		std::sort(rArray.begin(), rArray.end());
	}
};
class Client
{
public:
	Client(Sorter* injSorter) : pSorter(injSorter) {}
	void doSomething(std::vector<int>& arr)
	{
		// stuff
		pSorter->sort(arr);
	}
	void print(std::vector<int> const& arr)
    {
        for (size_t i = 0; i < arr.size(); ++i) 
            std::cout << arr[i] << ' '; 
        std::cout << std::endl;
    }
private:
	Sorter* pSorter;
};

int main()
{
	std::vector<int> arr = {21,43,12,54,65,23,24};
    MergeSorter sorter;
	Client myclass(&sorter);
	myclass.print(arr);
	
	myclass.doSomething(arr);
	
	myclass.print(arr);	
	return 0;
}
```
Which eventually results in this:
```
ubuntu: ~/development/c++/test/cpp_sorting
$ ./a.out 
21 43 12 54 65 23 24 
merge-sorting array
12 21 23 24 43 54 65 
```


* **C++ Functors**
A `Sorter`base class, and other two+ deverived classes, overloading the `void operator()(container&)`.  In this example, to use over the whole container of items, rather than one by one in a loop (as usual for functors). 



