// Сортировка слиянием.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector <long long> mas;

void sort_(int l, int r)
{
	if (r == l)
	{
		return;
	}

	int m = (l + r) / 2;

	sort_(l, m);
	sort_(m + 1, r);

	vector <long long> a = mas;
	int l1 = l, l2 = m + 1;
	for (int i = l; i <= r; i++)
	{
		if (l1 > m)
		{
			mas[i] = a[l2];
			l2++;
		}
		else
			if (l2>r)
			{
				mas[i] = a[l1];
				l1++;
			}
			else
			{
				if (a[l1]<a[l2])
				{
					mas[i] = a[l1];
					l1++;
				}
				else
				{
					mas[i] = a[l2];
					l2++;
				}
			}

	}
	return;
}


int main()
{
	int n;
	cin >> n;
	long long a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		mas.push_back(a);
	}

	sort_(0, mas.size() - 1);

	for (auto u : mas)//вывод элементов вектора
	{
		cout << u << ' ';
	}
	return 0;
}