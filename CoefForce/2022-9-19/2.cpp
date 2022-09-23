#include <bits/stdc++.h>

using namespace std;

int solve(int n, int x, int y) {
	if(x > 0) return puts("-1");
	if(y == 0) return puts("-1");
	if((n-1) % y) return puts("-1");
	int pre = 0;
	for(int i=0; i<n-1; i++) {
		if(i%y == 0) {
			if(pre == 1) pre += y + 1;
			else if(pre) pre += y;
			else pre = 1;
		}
		printf("%d ", pre);
	}
	puts("");
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		if(x > y) swap(x, y);
		solve(n, x, y);	
	}
}
