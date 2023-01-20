#include <bits/stdc++.h>

using namespace std;


int main() {
	int n, T;
	cin >> n >> T;
	while(T--) {
		int k; scanf("%d", &k);
		if(k < n) {
			if(k & 1) n -= k;
			else n /= k;
		}
		else if(k > n) {
			if(k & 1) n *= k;
			else n += k;
		}
		else n *= 2;
		cout << n << endl;
	}
	cout << n << endl;
}



