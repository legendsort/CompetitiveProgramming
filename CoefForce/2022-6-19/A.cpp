#include <bits/stdc++.h>

using namespace std;

int main() {

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		long long ans = 1ll * m * (m-1) / 2 + 1ll * m * n * (n + 1) / 2;
		printf("%I64d\n", ans);	
	}

}

