// files.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "fstream"
#include "conio.h"

using namespace std;

int f(const char *fname) {
	ifstream FS;
	FS.open(fname,ios_base::in|ios_base::binary);
	if (!FS.is_open()) {
		cout << "Can't open file for reading" << endl;
	}
	else {
		char c;
		int k = 0;
		while (true) {
			c = FS.get();
			if (FS.eof()) break;
			else {
				cout << c << endl;
				k++;
			}
		}
		return k;
	}
	FS.close();
}
void g( int e, const char* gname= "D:\\1 курс\\Основы программирования\\files\\S3.txt"){
	ofstream FS;
	FS.open(gname, ios_base::trunc);
	for (int i = 0; i < e; i++) {
		FS.put('*');
	}
}

void copy(const char* a, const char*b= "D:\\1 курс\\Основы программирования\\files\\S4.jpg") {
	ifstream iFS;
	iFS.open(a,ios_base::in| ios_base::binary);
	ofstream oFS;
	oFS.open(b,ios_base::out|ios_base::trunc| ios_base::binary);
	while (true) {
		char c;
		c = iFS.get();
		if (iFS.eof()) break;
		else {
			oFS.put(c);
		}
	}
	iFS.close();
	oFS.close();
}

void shift(char*s, int n, char k) {
	for (int i = 0; i < n - 1; i++) {
		s[i] = s[i + 1];
	}
	s[n - 1] = k;
}

void find(const char* file, char* s, int n) {
	ifstream iFS;
	iFS.open(file, ios_base::in | ios_base::binary);
	int now = 0;
	char* c=new char[n];
	for (int i = 0; i < n; i++) {
		c[i]= iFS.get();
		if (iFS.eof()) cout<<"no", return ;
	}
	int k = 0;
	for (int j = 0; j < n-1; j++) {
		if (c[j] != s[j]) {
			shift(s, n, iFS.get());
			k++;
			break;
		}
		if (k==n) cout << "yes";
		else k = 0;
	}
	
	if(k!=n)  cout << "no";
	iFS.close();
}



int main()
{
	/*const int n=10;
	char s[n+1];*/
	int n;
	cin >> n;
	char*s = new char[n];
	cin.getline(s,n);
	find("D:\\1 курс\\Основы программирования\\files\\S1.txt", s, n);
	/*

	cout << f("D:\\1 курс\\Основы программирования\\files\\S1.txt");
	copy("D:\\1 курс\\Основы программирования\\files\\102_Garden.jpg");
	g(7);
	*/
	_getch();
	return 0;
}