#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
using namespace std;

int a=33,b,c;

void choice(int& x) { x=a; }

int main()
{
	int x;

	choice(x);

	cout<<x<<endl;

	return 0;
}