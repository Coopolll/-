#include<iostream>
using namespace std;
unsigned const N = 1'000;
int a[N];
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
void Pusyrechek(int a[], unsigned N)
{
	for (unsigned i = 0; i < N - 1; ++i)
	{
		for (unsigned j = 0; j < N - i - 1; ++j)
		{
			if (a[j] > a[j + 1]) 
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void Vybor(int a[], unsigned N)
{
	unsigned minim = 0;
	for (unsigned i = 0; i < N - 1; ++i)
	{
		minim = i;
		for (unsigned j = i + 1; j < N; ++j)
		{
			if (a[j] < a[minim])
			{
				minim = j;
			}
		}
		if (minim != i)
		{
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
	}
}
void Vstavka(int a[], unsigned N)
{
	for (unsigned i = 0; i < N - 1; ++i)
	{
		for (unsigned j = i; j > 0 and a[j - 1] > a[j]; --j)
		{
			if (a[j] > a[j - 1]) 
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	nabiv_massivchika(a, N, 1'000'000);
	Bystraya(a, N);
	for (unsigned 1 = 0; i < N; ++i)
	{
		cout << i << " " << a[i] << " ";
	}
}
