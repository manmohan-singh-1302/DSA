#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a;
	char b;
	cin >> a;
	cin >> b;
	int m = a - '0';
	int n = b - '0';
	int z = m * n;
	string s;
	ostringstream iss;
	iss << z;
	s = iss.str();
	cout << s << endl;
}