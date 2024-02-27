#include<iostream>
#include <chrono>
#include <random>
using namespace std;
unsigned const N = 50'000;
int a[N];
int func1(int a[], unsigned N, int x)
{
	bool flag = false;
	int l = 0;
	int r = N - 1;
	int m = 0;
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
	if (flag == true)
	{
		return m;
	}
	else
	{
		return -1;
	}
}
int func(int a[], unsigned N, int x)
{
	int flag_1 = -1;
	int l = 0;
	int r = N - 1;
	int m = 0;
	while ((l <= r) and (flag_1 == -1))
	{
		m = (l + r) / 2;
		if (a[m] <= x)
		{
			if (a[m + 1] > x)
			{
				flag_1 = m;
			}
			else
			{
				l = m + 1;
			}
		}
		if (a[m] > x)
		{
			if (a[m - 1] > x)
			{
				r = m;
			}
			else
			{
				flag_1 = m - 1;
			}
		}
	}
	if (flag_1 == -1 and a[0] > x)
	{
		return -1;
	}
	if (flag_1 == -1 and a[0] <= x)
	{
		flag_1 = N - 1;
	}
	m = flag_1;
	while (m >= 0)
	{
		if (func1(a, m, x - a[m]) != -1)
		{
			return m;
		}
		else
		{
			--m;
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