#include <iostream>
#include <vector>
using namespace std;

void insert_sorted(vector<int>& vec, int num)
{

}

void task_1()
{
	vector<int> sortedVec { 1, 2, 3, 4, 5, 6 };
	insert_sorted(sortedVec, 4);
	ostream_iterator<int> osIt{ cout, " " };
	copy(sortedVec.begin(), sortedVec.end(), osIt);
}



int main()
{
	task_1();
}

