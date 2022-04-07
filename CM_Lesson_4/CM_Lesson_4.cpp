#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <numeric>
using namespace std;

template <class T>
void insert_sorted(vector<T>& inVec, T elem)
{
	auto it = find_if(inVec.begin(), inVec.end(), [elem](T x) { return x >= elem; });
	inVec.insert(it, elem);
}

void task_1()
{
	cout << "==============================================================" << endl;
	cout << "                         TASK 1" << endl;
	cout << "==============================================================" << endl;
	vector<int> vec{ 1, 2, 3, 7, 8, 11 };
	ostream_iterator<int> it{ cout, " " };
	copy(vec.begin(), vec.end(), it); cout << endl;

	insert_sorted<int>(vec, 4);
	copy(vec.begin(), vec.end(), it); cout << endl;

	insert_sorted<int>(vec, 5);
	copy(vec.begin(), vec.end(), it); cout << endl;

	insert_sorted<int>(vec, 10);
	copy(vec.begin(), vec.end(), it); cout << endl;

	vector<double> vec2{ 1.1, 2.23, 3.16, 7.9, 8.3, 11.09 };
	ostream_iterator<double> it2{ cout, " " };
	copy(vec2.begin(), vec2.end(), it2); cout << endl;

	insert_sorted<double>(vec2, 2.25);
	copy(vec2.begin(), vec2.end(), it2); cout << endl;

	vector<char> vec3{ 'a', 'b', 'd', 'e', 'h' };
	ostream_iterator<char> it3{ cout, " " };
	copy(vec3.begin(), vec3.end(), it3); cout << endl;

	insert_sorted<char>(vec3, 'f');
	copy(vec3.begin(), vec3.end(), it3); cout << endl;
	cout << "==============================================================" << endl;

}

void task_2()
{
	cout << "==============================================================" << endl;
	cout << "                         TASK 2" << endl;
	cout << "==============================================================" << endl;
	const size_t VECTOR_SIZE = 100;
	vector<double> analog(VECTOR_SIZE);
	random_device rd;
	mt19937 gen{ rd() };
	normal_distribution<double> d{ 10, 3 };

	generate(analog.begin(), analog.end(), [&]() { return d(gen); });
	ostream_iterator<double> it{ cout, " " };
	cout << "                     Analog vector:" << endl;
	copy(analog.begin(), analog.end(), it); cout << endl << endl;

	vector<int> digital;
	transform(analog.begin(), analog.end(), back_inserter(digital), [](double x) { return floor(x); });
	ostream_iterator<int> it2{ cout, " " };
	cout << "                     Digital vector:" << endl;
	copy(digital.begin(), digital.end(), it2); cout << endl << endl;


	vector<double> out(VECTOR_SIZE);

	transform(analog.begin(), analog.end(), digital.begin(), out.begin(),
		[](const double& a, const double& b)->double { return (a - b) * (a - b); });

	double sum = accumulate(out.begin(), out.end(), 0.0);
	cout << "==============================================================" << endl;
	cout << "Result = " << sum << endl;
	cout << "==============================================================" << endl;
}

int main()
{
	task_1();
	task_2();
}
