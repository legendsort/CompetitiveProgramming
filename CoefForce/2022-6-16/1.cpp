#include <bits/stdc++.h>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
//#endif
	int T;
	cin >> T;
	while(T--) {
		int a, b ;
		scanf("%d %d", &a, &b);
		while(a+b>0) {
			if(a) putchar('0'), a--;
			if(b) putchar('1'), b--;	
		}
		puts("");
	}

}

