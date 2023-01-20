#include <bits/stdc++.h>

using namespace std;

using INT = long long;

const int NN = 100011;
int a[NN];
INT k;
int n;
int L[NN], R[NN];
int ans[NN];
INT mn[NN], mx[NN];

int can(int st, int ed, INT k) {
	if(k > mx[st] or k < mn[st]) return 0;
	return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> L[i];
	for(int i=1; i<=n; i++) cin >> R[i];
	mn[n+1] = mx[n+1] = 0;
	for(int i=n; i>=1; i--) {
		int x ;
		if(a[i] >= L[i] and a[i] <= R[i]) x = 0;
		else if(a[i] < L[i]) x = L[i] - a[i];
		else x = a[i] - R[i];
		mn[i] = mn[i+1] + x;
		x = max(abs(a[i] - L[i]), abs(a[i] - R[i]));
		mx[i] = mx[i+1] + x;
	}
	if(can(1, n, k) == 0) {
		cout << -1  << endl;
		return 0;	
	}
	for(int st = 1; st <= n; st ++) {
		int ed = n;
		assert(can(st, ed, k));
		int s = L[st]-1, e = R[st];
		
		while(e > s + 1) {
			int mid = s + e >> 1;
			int x, y ;
			if(a[st] >= L[st] and a[st] <= mid) x = 0;
			else if(a[st] < L[st]) x = L[st] - a[st];
			else x = a[st] - mid;
			y = max(abs(a[st] - L[st]), abs(a[st] - mid));
			INT A = mn[st+1] + x;
			INT B = mx[st+1] + y;
			if(A <= k and k <= B) e = mid;
			else s = mid;
		}
		ans[st] = e;
		k -= abs(ans[st] - a[st]);
	}
	for(int i=1; i<=n; i++) cout << ans[i] << ' ';
	cout << endl;
}



