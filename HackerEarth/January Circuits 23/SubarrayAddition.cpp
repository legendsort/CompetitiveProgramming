#include <bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 200011;
INT a[NN<<2];
INT b[NN<<2];
INT add[NN<<2];
int flag[NN<<2];

int n, q;
#define ls (u<<1)
#define rs ((ls)|1)
#define mid (st+ed>>1)
void push_up(int u) {
	a[u] = a[ls] + a[rs];
	b[u] = b[ls] + b[rs];
}

void push_down(int u, int st, int ed) {
	if(flag[u]) {
		b[ls] += flag[u] * a[ls];
		b[rs] += flag[u] * a[rs];
		flag[ls] += flag[u];
		flag[rs] += flag[u];
		flag[u] = 0;
	}
	if(add[u]) {
		a[ls] += (INT)(mid - st) * add[u];
		a[rs] += (INT)(ed - mid) * add[u];
		add[ls] += add[u];
		add[rs] += add[u];
		add[u] = 0;
	}
}

void Add(int u, int st, int ed, int L, int R, int x) {
	if(ed <= L or st >= R) return ;
	if(L <= st and ed <= R) {
		
		a[u] += (INT)(ed - st) * x;
		add[u] += x;
		return ;
	}
	push_down(u, st, ed);
	Add(ls, st, mid, L, R, x);
	Add(rs, mid, ed, L, R, x);
	push_up(u);
}

void merge(int u, int st, int ed, int L, int R) {
	if(ed <= L or st >= R) return ;
	if(L <= st and ed <= R) {
		b[u] += a[u];
		flag[u] ++;	
		return ;
	}
	push_down(u, st, ed);
	merge(ls, st, mid, L, R);
	merge(rs, mid, ed, L, R);
	push_up(u);
}

INT calc(int u, int st, int ed, int p) {
	if(ed == st + 1) return b[u];
	push_down(u, st, ed);
	if(p < mid) return calc(ls, st, mid, p);
	else return calc(rs, mid, ed, p);
}

void build(int u, int st, int ed) {
	if(ed == st + 1) {
		cin >> a[u];
		return ;
	}
	build(ls, st, mid);
	build(rs, mid, ed);
	push_up(u);
}

int main() {
	freopen("in.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> q;
	build(1, 1, n + 1);
	while(q--) {
		int t, L, R, x;
		cin >> t;
		if(t == 1) {
			cin >> L >> R >> x;
			Add(1, 1, n+1, L, R+1, x);
		}
		else {
			cin >> L >> R;
			merge(1, 1, n+1, L, R+1);
		}
	}
	for(int i=1; i<=n; i++) cout << calc(1, 1, n+1, i) << ' ';
}



