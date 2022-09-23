#include <bits/stdc++.h>

using namespace std;

int x, y, n, r;

long long solve() {
	int n;
	cin >> n;
	long long ans = 0;
	int pre = 0;
	for(int i=0; i<n; i++) {
		int a; cin >> a;
		if(a) pre++;
		else pre = 0;
		ans += pre;
	}
	return pre;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) cout << solve() << endl;
}


