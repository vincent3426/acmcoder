#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string sum(string a, string b) {
	string tmp, s;
	int len = a.length() - b.length();
	if (len < 0) {
		tmp = a;
		a = b;
		b = tmp;
	}
	int num = 0;
	for (int i = b.length() - 1; i >= 0; i--) {
		int p, q;
		p = b[i] - '0';
		q = a[abs(len) + i] - '0';
		s = to_string((p + q + num) % 10) + s;
		num = (p + q + num) / 10;
	}
	for (int i = abs(len) - 1; i >= 0; i--) {
		int p;
		p = a[i] - '0';
		s = to_string((p + num) % 10) + s;
		num = (p + num) / 10;
	}
	if (num == 1) // 最高位进位
		s = '1' + s;
	return s;
}

int main() {
	int T, cnt = 0;
	cin >> T;
	string a, b;
	while (T--) {
		cnt++;
		cin >> a >> b;
		cout << "Case " << cnt << ":" << endl;
		cout << a << " + " << b << " = " << sum(a, b);
		if(T == 0)
			cout<< endl;
		else
			cout << endl << endl;
	}
	return 0;
}
