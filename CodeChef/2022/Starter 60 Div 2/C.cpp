#include <bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 300011;
int a[NN];
int b[NN];
int solve() {
	int n, k;
	cin >> n;
	
	for(int i=1; i<=n; i++) cin >> a[i];
	b[0] = 1e9+3;
	for(int i=1; i<=n; i++) {
		int j=n-i+1;
		if(i<j) b[i] = a[j] - a[i];
		else b[i] = 0;
		if(b[i-1] < b[i]) return -1;
	}
	return b[1];
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--) cout << solve() << endl;

}



