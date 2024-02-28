#include<iostream>
#include <chrono>
#include <random>
using namespace std;
unsigned const N = 5'000;
int a[N];
int func(int a[], unsigned N, int x)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			if (a[i] + a[j] == x)
			{
				return i, j;
			}
		}
	}
	return -1;
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
	for (int i = 0; i < 10; ++i)
	{
		int x = (rand() * rand()) % N;
		int y = (rand() * rand()) % N;
		nabiv_massivchika(a, N, 1'000'000'000);
		auto begin = chrono::steady_clock::now();
		for (unsigned cnt = 100'000; cnt != 0; --cnt)
		{
			int x = (rand() * rand()) % N;
			int y = (rand() * rand()) % N;
			func(a, N, a[x] + a[y]);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);
		cout << time_span.count() << "," << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << N << "," << " ";
	}
}