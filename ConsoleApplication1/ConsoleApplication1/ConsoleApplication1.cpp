#include<iostream>
#include <chrono>
#include <random>
using namespace std;
unsigned const N = 100000;
int a[N];
int x[1];
int func(int a[], unsigned N, int x)
{
	for (unsigned i = 0; i < N; ++i)
	{
		if (a[i] == x)
		{
			return i;
		}
	}
}
void nabiv_massivchika(int a[], int N, int M)
{
	unsigned seed = 1001;
	default_random_engine rng(seed);
	uniform_int_distribution <unsigned> dstr(1, M);
	for (unsigned i = 0; i < N; ++i)
	{
		a[i] = dstr(rng);
	}
}
int main()
{
	nabiv_massivchika(a, N, 1'000'000);
	//for (unsigned i = 0; i < N; ++i)
	//{
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	//cout << a[x[0]];
	nabiv_massivchika(x, 1, N);
	auto begin = chrono :: steady_clock :: now();
	for (unsigned cnt = 100000; cnt != 0; --cnt)
	{
		func(a, N, a[x[0]]);
	}
	auto end = chrono :: steady_clock :: now();
	auto time_span =
	chrono :: duration_cast< chrono :: milliseconds >(end - begin);
	cout << "\n\n";
	cout << time_span.count() << endl;
}