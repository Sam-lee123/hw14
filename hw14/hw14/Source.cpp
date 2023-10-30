#include <algorithm>
#include <iostream>
#include <list>



//Create a function called PrintList() that will print out all the elements of a list in a space - separated manner
//Use this function to prove you have correctly completed your activities!
void PrintList(char X, const std::list<int>& L)
{
	std::cout << X << ":  ";
	for (int i : L)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}


	//“Customize” and create your own custom STL std::sort() operation to sort first by even / odd status, and then sort values high to low
	//All even numbers move to the left of the list
	//All odd numbers move to the right of the list
	//Even grouping is sorted from high to low
	//Odd grouping is sorted from high to low
bool SortTwoWays(int a, int b)
{
	bool IsAEven = ((a & 1) == 0);
	bool IsBEven = ((b & 1) == 0);

	if (IsAEven && !IsBEven)
		return true;
	if (!IsAEven && IsBEven)
		return false;
	return a > b;

}


int main()
{
	//Create list a which is initialized to 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
	std::list<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	PrintList('A', a);
 
	//Create list b which is initialized to 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
	std::list<int> b{ 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintList('B', b);

	//Reverse list b
	b.reverse();
	PrintList('B', b);

	//Create list k which initializes with a copy of every element of a, using the copy constructor
	std::list<int> k(a);
	PrintList('K', k);

	//Create list m which initializes with a copy of every element of b, using iterators of b
	std::list<int> m(b.begin(), b.end());
	PrintList('M', m);
	
	
	//Merge list m into list k
	k.merge(m);
	PrintList('K', k);
	PrintList('M', m);

	//Remove all duplicates of consecutive elements from k
	k.unique();
	PrintList('K', k);


	//Create list d which initializes with a copy of every element of a, using the copy constructor
	std::list<int> d(a);
	PrintList('D', d);

	//Create list c which initializes with a copy of every element of b, using iterators of b
	std::list<int> c(b.begin(), b.end());
	PrintList('C', c);

	//Create list e as a list of 7 elements all initialized to 9
	std::list<int> e(7, 9);
	PrintList('E', e);

	//Create list f which uses a loop to set up the list into the squares of the first 30 numbers
	//1, 4, 9, 25, 36, 49, 64, 81, 100, ...
	std::list<int> f;
	for (int i = 1; i <= 30; ++i)
	{
		f.insert(f.end(), i * i);
	}
	PrintList('F', f);
			
	//Use std::stable_partition() and std::erase() to eliminate all odd values from linked list f
	std::list<int>::iterator iter = std::stable_partition(f.begin(), f.end(), [](int x) {return (x & 1) == 1; });
	PrintList('F', f);
	f.erase(f.begin(), iter);
	PrintList('F', f);


	//Create list h which uses a loop to initialize the list to the squares of the first 50 numbers
	// //1, 4, 9, 25, 36, 49, 64, 81, 100, ...
	std::list<int> h;
	for (int i = 1; i <= 20; ++i)
	{
		int x = 1 + (rand() % 100);
		h.insert(h.end(), x * x);
	}
	PrintList('H', h);
	
	h.sort(SortTwoWays);
	PrintList('H', h);




	//Find a way to use std::erase() to eliminate all odd values from linked list h
	iter = std::find_if(h.begin(), h.end(), [](int x) {return (x & 1) == 1; });
	h.erase(iter, h.end());
	PrintList('H', h);

	system("Pause");
	return 0;

}






