#include <bits/stdc++.h>

using namespace std;

int a[200111];

int ok(int st, int ed) {
	long long sum = 0;
	int cnt = 0;
	for(int i=st; i<ed; i++) {
		sum += a[i];
		if(i < ed and sum < 0) return 0;
	}
	if(sum) return 0;
	if(*max_element(a, a+ed) == *min_element(a, a+ed)) return 1;
	if(a[0] == 0) return 0;
	a[0]--;
	for(int i=ed-1; i>=st; i--) {
		if(a[i] != 0) {
			if(a[i] > 0) return 0;
			a[i] ++;
			break;
		}
	}
	sum = 0;
	for(int i=st; i<ed; i++) {
		sum += a[i];
		if(sum < 0) return 0;	
	}
	return 1;
}

void solve() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n;i ++) scanf("%d", a+i);
	if(ok(0, n)) puts("Yes");
	else puts("No");
	
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

