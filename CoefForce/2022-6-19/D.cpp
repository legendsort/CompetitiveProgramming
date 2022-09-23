#include <bits/stdc++.h>

using namespace std;
using INT = long long ;
int n;
int a[200111];

int ok(int mid) {
	INT s = 0;
	for(int i=1; i<=n; i++) {
		s += a[i];
		if((INT)i * mid < s) return 0;
	}
	return 1;
}

int main() {

	cin >> n;
	INT s = 0;
	for(int i=1; i<=n; i++) scanf("%d", a+i), s+= a[i];
	int st = 0, ed = 1e9 + 3;
	while(ed > st + 1) {
		int mid = st + ed >> 1;
		if(ok(mid)) ed = mid;
		else st = mid;
	}
	int q;
	cin >> q;
	while(q--) {
		int t;
		scanf("%d", &t);
		if(t<ed) puts("-1");
		else printf("%d\n", (s+t-1)/t);
	}
	

}

