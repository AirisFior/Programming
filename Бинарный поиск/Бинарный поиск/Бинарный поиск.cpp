// Бинарный поиск.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using  namespace std;

int main()
{
	const int n=20;
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 51;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (auto now : a)
		cout << now << " ";
	cout << endl;


	int num;
	cin >> num;
	int left = 0, right = n-1;
	bool find = false;
	int middle = n / 2;
	while (left <= right && find!=true) {
		if ((num < a[left]) && (num > a[right])) {
				cout << "not found";
				find = true;
		}
		if (a[middle] == num) {
				cout << middle;
				find = true;
		}
		else if (num ==a[left]) {
				cout << left;
				find = true;
		}
			else if (num == a[right]) {
				cout << right;
				find = true;
			}
			else if (num < a[middle]) {
				right = middle-1;
				middle = (right+left)/2;
			}
			else if (num > a[middle]) {
				left = middle+1;
				middle = (right + left) / 2;
			}
		}
	
	if (find == false)
		cout << "not found";
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
