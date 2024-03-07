#include<iostream>
using namespace std;
unsigned const N = 1'000;
int a[N];
int b[N];
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
void Bystraya(int a[], unsigned end, int start)
{
	int N = end - start + 1;
	if (N != 1)
	{
		int i = start;
		int j = end;
		int m = N / 2 + start;
		int M = a[m];
		while (i < j and (a[i] != M or a[j] != M))
		{
			while (a[i] < M)
			{
				++i;
			}
			while (a[j] > M)
			{
				--j;
			}
			if (i < j)
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
		if (j > 0 and j != end - 1 and j != end)
		{
			Bystraya(a, j + 1, start);
		}
		if (i < N - 1)
		{
			Bystraya(a, end, i);
		}
	}
}
void Sliyanie(int a[], unsigned end, unsigned start)
{
	unsigned N = end - start + 1;
	if (N != 1)
	{
		Sliyanie(a, N / 2 + start - 1, start);
		Sliyanie(a, end, N / 2 + start);
		unsigned i = start;
		unsigned j = N / 2 + start;
		unsigned k = start;
		while (i < N / 2 + start and j <= end)
		{
			if (a[i] <= a[j] )
			{
				b[k] = a[i];
				++i;
				++k;
			}
			else
			{
				b[k] = a[j];
				++j;
				++k;
			}
		}
		while (j <= end)
		{
			b[k] = a[j];
			++j;
			++k;
		}
		while (i < N / 2 + start)
		{
			b[k] = a[i];
			++i;
			++k;
		}
		for (int c = start; c <= end; ++c)
		{
			a[c] = b[c];
		}
	}
}
int main()
{
	nabiv_massivchika(a, N, 1'000'000);
	Bystraya(a, N - 1);
	for (unsigned 1 = 0; i < N; ++i)
	{
		cout << i << " " << a[i] << " ";
	}
}
