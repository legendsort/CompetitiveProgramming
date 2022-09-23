#include <bits/stdc++.h>

using namespace std;

char s[200111];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	long long ans = 0;
	for(int i=0; s[i]; i++) {
		ans ++;
		if(i and s[i]!=s[i-1]) ans += i;
	}
	printf("%I64d\n", ans);
}
int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
//#endif
	int T;
	cin>>T;
	while(T--) solve();
	
}

