#include<iostream>
#include <chrono>
#include <random>
using namespace std;
unsigned const N = 700'000;
int a[N];
int func(int a[], unsigned N, int x)
{
	bool flag = false;
	int l = 0;
	int r = N - 1;
	int m=0;
	while ((l <= r) and (flag == false))
	{
		m = (l + r) / 2;
		if (a[m] == x)
		{
			flag = true;
		}
		if (a[m] > x)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}

	}
	return m;
}
void Sortirovochka(int a[], unsigned N)
{
	for (unsigned i = 0; i < N - 1; ++i)
	{
		for (unsigned j = 0; j < N - i - 1; ++j)
		{
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
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
	for (int i = 0; i < 10; ++i)
	{
		nabiv_massivchika(a, N, 1'000'000'000);
		Sortirovochka(a, N);
		auto begin = chrono::steady_clock::now();
		for (unsigned cnt = 100'000; cnt != 0; --cnt)
		{
			int x = (rand() * rand()) % N;
			func(a, N, a[x]);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);
		cout << time_span.count() << "," << " ";
	}
}