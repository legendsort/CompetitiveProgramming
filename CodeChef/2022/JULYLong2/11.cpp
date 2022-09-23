#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
    	int x, y;
    	cin >> x >> y;
    	cout << x * 4 + y << endl;
    }
}


