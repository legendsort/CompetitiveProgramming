#include <bits/stdc++.h>

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 300011;
int n, q;
int a[NN];
int nxt[NN];

INT sum[NN<<2];
int flag[NN<<2];

vector<pii> query[NN];
INT ans[NN];

#define ls (u<<1)
#define rs ((ls)|1)
#define mid (st+ed>>1)

void push_up(int u) {
	sum[u] = sum[ls] + sum[rs];
}

void push_down(int u, int st, int ed) {
	if(flag[u]) {
		sum[ls] = (INT)(mid - st) * flag[u];
		sum[rs] = (INT)(ed - mid) * flag[u];
		flag[ls] = flag[rs] = flag[u];
		flag[u] = 0;
	}
}

void modify(int u, int st, int ed, int L, int R, int x) {
	if(ed <= L or st >= R) return ;
	if(L <= st and ed <= R) {
		sum[u] = (INT)(ed - st) * x;
		flag[u] = x;
		return ;
	}
	push_down(u, st, ed);
	modify(ls, st, mid, L, R, x);
	modify(rs, mid, ed, L, R, x);
	push_up(u);
}

INT calc(int u, int st, int ed, int L, int R) {
	if(ed <= L or st >= R) return 0;
	if(L <= st and ed <= R) return sum[u];
	push_down(u, st, ed);
	return calc(ls, st, mid, L, R) + calc(rs, mid, ed, L, R);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> q;
	for(int i=1; i<=n; i++) cin >> a[i];
	reverse(a+1, a+n+1);
	for(int i=0; i<q; i++) {
		int L, R;
		cin >> L >> R;
		L = n+1-L;
		R = n+1-R;
		swap(L, R);
		query[R].push_back({L, i});
	}
	for(int i=1; i<=n; i++) {
		int p = i-1;
		while(a[p] > a[i]) p = nxt[p];
		nxt[i] = p;
		modify(1, 1, n+1, p+1, i+1, a[i]);
		for(auto qu : query[i]) {
			int L = qu.first, id = qu.second;
			ans[id] = calc(1, 1, n+1, L, i+1);
		}
	}
	for(int i=0; i<q; i++) cout << ans[i] << endl;
}



