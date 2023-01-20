#include <bits/stdc++.h>

#define sz(a) ((int)a.size())
#define pb push_back
#define x first
#define y second
using namespace std;
using pii = pair<int, int>;
using VI = vector<int>;
using VP = vector<pii>;
using INT = long long;

const int NN = 555;
const int MM = 17;
const int inf = 1e9 + 8;
int N, M;
int C[NN];
int D[NN][NN], B[NN][MM];
int testG, testK;
int testType;
int totScore;

#define TIME_LIMIT 4.8

int HAP;



void INPUT() {
	cin >> N >> M;
	for(int i = 1; i <= N + 2; i ++) scanf("%d", C + i);
	testG = testK = 0;
	for(int i = 1; i <= N; i ++) for(int j = 1; j <= N; j ++) {
		scanf("%d", D[i] + j);
		testK += (D[i][j] > 0);
	}
	for(int i = 1; i <= N; i ++) for(int j = 1; j <= M; j ++) {
		scanf("%d", B[i] + j);
		if(B[i][j] == B[i][1]) testG ++;
	}
	
	if(testK >= N * (N - 1) / 2) testK = 0;
	else if(testK >= N * (N - 1) / 10) testK = 1;
	else if(testK >= N * (N - 1) / 30) testK = 2;
	else testK = 3;
	if(testG >= 5800) testG = 0;
	else if(testG >= 4500) testG = 1;
	else if(testG >= 2000) testG = 2;
	else testG = 3;
	testType = testK * 4 + testG;
	
}

struct Answer {
	
	VI reverseOper;
	VP pourOper;
	int cost;
	VI tubes[NN];
	int mxH[NN];
	VP his;
	VI col[NN];
	int tmp[NN];
	int up(int s) {
		assert(checkValid());
		int bk = 0;
		for(int i = 1; i <= N + 2; i ++) {
			if(tubes[i].empty()) bk = i;
		}
		for(int i = 1; i <= N + 2; i ++) if(tubes[i].size()) {
			for(int j = i + 1; j <= N + 2; j ++) if(tubes[j].size()) {
				if(D[tubes[i].back()][tubes[j].back()] == 1) {
					while(s --) {
						pour(i, bk); pour(j, bk);
						pour(bk, j); pour(bk, i);
					}
					return 1;
				}
			}
		}
		assert(0);
	}
	void init() {
		his.clear();
		his.pb({0, 0});
		cost = 0;
		reverseOper.clear();
		pourOper.clear();
		for(int i = 1; i <= N + 2; i ++) tubes[i].clear();
		for(int i = 1; i <= N + 2; i ++) {
			col[i].clear();
			tmp[i] = 0;
		}
		
		for(int i = 1; i <= N; i ++) {
			for(int j = 1; j <= M; j ++) {
				tubes[i].pb(B[i][j]);
			}
		}
		for(int i = 1; i <= N + 2; i ++) mxH[i] = M;
	}
	

	void makePoint() {
		int n = sz(pourOper);
		his.pb({n, cost});
	}
	
	int top(int x) {
		if(sz(tubes[x]) == 0) return 0;
		return tubes[x].back();
	}
	
	void back(pii now) {
		int x = now.x, y = now.y;
		if(x == 0) {
			mxH[y] --;
			cost -= C[y];
		} else{
			int t = top(y);
			tubes[y].pop_back();
			tubes[x].pb(t);
			cost -= D[top(x)][top(y)];
		}
		pourOper.pop_back();
	}
	
	void back() {
		if(his.empty()) return ;
		while(sz(pourOper) > his.back().x) {
			back(pourOper.back());
		}
		his.pop_back();
	}
	
	bool operator < (Answer a) {
		return cost < a.cost;
	}
	
	int numOpers() {
		return sz(pourOper);
	}
	void rever(int x) {
		reverseOper.pb(x);
		reverse(tubes[x].begin(), tubes[x].end());
	}
	
	void extend(int x) {
		mxH[x] ++;
		pourOper.pb({0, x});
		cost += C[x];
	}
	
	void dispState() {
		cout << "DISP"<<endl;
		for(int i = 1; i <= N + 2; i ++) {
			for(auto x : tubes[i]) printf("%3d ", x);
			puts("");
		}
	}
	
	int pour(int u, int v) {
		int ans = 0;
		
		assert(not tubes[u].empty());
		assert(sz(tubes[v]) < mxH[v]);
		pourOper.pb({u, v});
		int x = tubes[u].back();
		
		if(not tubes[v].empty()) {
			int y = tubes[v].back();
			assert(D[x][y] != -1);
			
			cost += D[x][y];	
			ans = D[x][y];
		}
		tubes[u].pop_back();
		tubes[v].pb(x);
		return ans;
	}
	
	bool checkValid() {
		for(int i = 1; i <= N + 2; i ++) if(not tubes[i].empty()) {
			int u = tubes[i][0];
			for(auto v : tubes[i]) if(u != v) return false;
			if(sz(tubes[i]) != M) return false;
		}
		return true;
	}
	
	void print() {
		assert(checkValid());
		cout << sz(reverseOper) << ' ' << sz(pourOper) << endl;
		for(auto x : reverseOper) {
			printf("%d ", x);
		}
		puts("");
		for(auto p : pourOper) {
			if(p.x) {
				int x = p.x, y = p.y;
				printf("1 %d %d\n", p.x, p.y);
			} else {
				printf("2 %d\n", p.y);
			}
		}
	}
	
};

int LUK = 1;

namespace ZACH {
	Answer ans;
	VI tubes[NN];
	VI adj[NN];
	VI col[NN];
	
	int mxH[NN];
	int deg[NN];
	int sav[NN];
	int unq[NN];
	int tmp[NN];
	
	void init() {
		for(int i = 1; i <= N + 2; i ++) mxH[i] = M, unq[i] = 0;
		for(int i = 1; i <= N + 2; i++) {
			tubes[i].clear();
			adj[i].clear();
			col[i].clear();
			tmp[i] = sav[i] = 0;
			deg[i] = 0;
		}
		for(int i = 1; i <= N; i ++) {
			for(int j = 1; j <= M; j ++) {
				tubes[i].pb(B[i][j]);
			}
		}
		for(int i = 1; i <= N; i ++) {
			for(int j = 1; j < i; j ++) if(D[i][j] != -1) {
				deg[i] ++;
				deg[j] ++;
			}
		}
	}
	
	int extend(int x) {
		ans.extend(x);
		mxH[x] ++;
		return C[x];
	}
	
	
	void rever(int x) {
		reverse(tubes[x].begin(), tubes[x].end());
		ans.rever(x);
	}
	
	int hei(int r) {
		return sz(tubes[r]);
	}
	
	
	int top(int r) {
		if(hei(r) == 0) return 0;
		return tubes[r].back();
	}
	
	int pour(int x, int y) {
		
		assert(x != y);
		assert(!tubes[x].empty());
		int res = 0;
		if(sz(tubes[y]) == mxH[y]) res = extend(y);
		assert(sz(tubes[y]) < mxH[y]);
		
		int u = tubes[x].back();
		tubes[x].pop_back();
		
		if(top(x) != u) unq[x]--;
		if(top(y) != u) unq[y]++;
		
		tubes[y].pb(u);
		return ans.pour(x, y) + res;
	
	}
	
	
	bool isFilled(int r, int c) {
		if(M != sz(tubes[r])) return false;
		for(auto u : tubes[r]) if(u != c) return false;
		return true;
	}
	
	
	bool hasColor(int r, int c) {
		for(auto x : tubes[r]) if(x == c) return true;
		return false;
	}
	
	int mt;
	
	void countTime() {
		mt = clock();
	}
	
	void dispTime() {
		double ans = (clock() - mt) * 1.0 / CLOCKS_PER_SEC;
		cerr << ans << endl;		
	}
	
	void back(pii now) {
		int x = now.x, y = now.y;
		if(x == 0) {
			mxH[y] --;
		} else{
			int t = top(y);
			tubes[y].pop_back();
			if(t != top(y)) unq[y]--;
			if(t != top(x)) unq[x]++;
			tubes[x].pb(t);
		}
	}
	
	void back() {
		if(ans.his.empty()) return ;
		while(sz(ans.pourOper) > ans.his.back().x) {
			back(ans.pourOper.back());
			ans.back(ans.pourOper.back());
		}
		ans.his.pop_back();
	}
	
	int cost(int u, int v) {
		assert(u != v);
		int x = top(u);
		int y = top(v);
		if(D[x][y] == -1) return inf; 
		ans.makePoint();
		assert(top(u));
		int res = pour(u, v);
		back();
		return res;
	}
	
	
	int getUnique(int u) {
		return unq[u];
	}
	
	bool ok() {
		int ans = 0;
		for(int i = 1; i <= N + 2; i ++) {
			if(getUnique(i) > 1) ans ++;
		}
		return ans <= 1;
	}
	
	
	int getTops(int r) {
		if(top(r) == 0) return 0;
		int ans = 0;
		for(int i=hei(r)-1; i>=0; i--) {
			if(tubes[r][i] != top(r)) return ans;
			ans++;
		}
		return ans;
	}
	void greedyReverse(Answer &ans) {
		VI deg = VI(N+1); VI vec;
		
		for(int i = 1; i <= N; i ++) {
			for(int j = 1; j <= N; j ++) if(D[i][j] != -1) deg[i]++;
			vec.pb(i);
		}
		while(not vec.empty()) {
			VI cnt = VI(N+1);
			for(auto i : vec) {
				int u = tubes[i].back();
				int v = tubes[i].front();
				cnt[u]++;
				cnt[v]++;
			}
			int sel = 0;
			auto good = [&](int u, int v) {
				if(cnt[u] == cnt[v]) return deg[u] > deg[v];
				return cnt[u] < cnt[v];	
			};
			for(int i = 1; i <= N; i ++) if(good(sel, i)) {
				sel = i;
			}
			VI nvec;
			for(auto i : vec) {
				int u = tubes[i].back();
				int v = tubes[i].front();
				if(u == sel) continue;
				if(v == sel) {
					rever(i);
					continue;
				}
				nvec.pb(i);
			}
			vec = nvec;
		}
	}	
		
	pii myFind(VI &vec) {
		VI col = VI(N + 2);
		for(int i = 1; i <= N + 2; i ++) if(top(i)) col[top(i)] += getTops(i);
		for(auto u : vec) {
			
		}
	}
	
	VI sec[NN];
	
	pii findGood(VI &vec) {
		
		for(auto u : vec) {
			int mn = inf - 1;
			int cnt = 0;
			int sel = 0;
			for(int i = 0; i <= N; i ++) sav[i] = 0;
			for(int i = 1; i <= N + 2; i ++) sav[top(i)] += getTops(i);
			for(int i = 1; i <= N + 2; i ++) if(i != u and top(i)) {
				if(C[i] < C[u]) continue;
				int co = cost(i, u);
				int cc = sav[top(i)];
				if(co == inf) continue;
				int g = 1;
				
				co = (co + (C[u] + C[u])  * (cc-1)) / 2 * 3;
				co /= cc;
				if(co < mn) {
					mn = co;
					sel = i;
					cnt = cc;
				} else if(abs(co - mn) < 1e-6 and cc > cnt) {
					sel = i;
					cnt = cc;
				}
			}
			if(sel) {
				return pii(top(sel), u);
			}
		}
		assert(0);
	}
	
	
	
	
	int freeze(VI &vec) {
		for(int i = 1; i <= N; i ++) col[i].clear();
		for(int i = 1; i <= N + 2; i ++) if(top(i)) {
			col[top(i)].pb(i);
			tmp[i] = getUnique(i);
		}
		int ok = 0;
		for(int c = 1; c <= N; c ++) {
			
			sort(col[c].begin(), col[c].end(), [&](int u, int v) {
				if(tmp[u] == tmp[v]) {
					if(hei(u) == hei(v)) return u > v;
					return hei(u) < hei(v);
				}
				return tmp[u] < tmp[v];	
			});
			
			for(int u : col[c]) if(top(u) == c) {
				for(int i = sz(col[c]) - 1; i >= 0; i --) {
					int v = col[c][i];
					if(u == v) continue;
					if(top(v) != c) continue;
					if(getTops(u) + hei(v) <= mxH[v]) {
						assert(top(u) == c);
						assert(top(v) == c);
						while(top(u) == c) {
							pour(u, v);
						}
						ok = 1;
						break;
					}
				}
			}
		}
		if(ok) return 1;
		auto kth = [&](int u, int k) {
			int c=0;
			int pre = 0;
			int cnt = 0;
			pii ans = pii(0, 0);
			for(int i = hei(u) - 1; i >= 0; i --) {
				if(tubes[u][i] != pre) c++, cnt=0;
				cnt++;
				pre = tubes[u][i];
				if(c == k) ans =  pii(pre, cnt);
				if(c > k) break;
			}
			return ans;
		};
		
		auto dump = [&](int u, int nt, int L = LUK) {
			int c = top(u);
			assert(c);
			int mn = inf;
			int sel = 0;
			for(int cc : adj[c]) {
				int d = D[c][cc];
				if(d > mn) continue;
				if(d >= L) continue;
				assert(c != cc);
				int ok = 0;
				for(int v : col[cc]) if(v != nt and u != v and top(v) == cc) {
					if(getTops(u) + hei(v) <= mxH[v]) {
						ok = 1;
						break;
					}
				}	
				if(ok) {
					mn = d;
					sel = cc;
				}
			}
			if(mn == inf) return inf;
			for(int v : col[sel]) if(v != nt and u != v and top(v) == sel) {
				assert(u != v);
				if(getTops(u) + hei(v) <= mxH[v]) {
					while(top(u) == c) pour(u, v);
					assert(top(u) != c);
					return mn;
				}
			}
			return inf;	
		};
			
		
		if(ok == 0) {
			for(int i = 1; i <= N + 2; i ++) if(i != vec[0]) {
				auto now  = kth(i, 2);
				int c = now.x;
				int cnt = now.y;
				
				if(c == 0) continue;
				for(int v : col[c]) if(i != v and cnt + hei(v) <= mxH[v]) {
							
					int co;
					co = dump(i, v);
					if(co == inf) continue;						
					assert(top(i) == c);
					while(top(i) == c) pour(i, v);
					assert(top(i) !=c);
					ok = 1;
					return 1;
				}
			}
			for(int i = 1; i <= N; i ++) sec[i].clear();
			for(int i = 1; i <= N + 2; i ++) if(i != vec[0]) {
				int c = kth(i, 2).x;
				if(c == 0) continue;
				sec[c].pb(i);
			}
			for(int i = 1; i <= N; i ++) {
				sort(sec[i].begin(), sec[i].end(), [&](int u, int v) {
					return tmp[u] <tmp[v];
				});
				for(int u : sec[i]) {
					for(int v : sec[i]) if(u != v) {
						ans.makePoint();
						int co;
						double coef = (rand()/(double)RAND_MAX*0.5+0.5);
						co = dump(u, v, LUK*coef);
						if(co == inf) continue;
						co = dump(v, u, coef*LUK);
						if(co == inf) {
							back();
							continue;
						}
						
						assert(top(u) == top(v));
						if(getTops(u) + hei(v) <= mxH[v]) {
							while(top(u) == top(v)) {
								pour(u, v);
							}
						} else {
							back();
							continue;
						}
						return 1;
					}
				}
			}
			
			for(int i = 1; i <= N + 2; i ++) {
				auto now  = kth(i, 2);
				int c = now.x;
				int cnt = now.y;
				
				if(c == 0) continue;
				for(int j = sz(col[c]) - 1; j >=0; j--) {
					int v = col[c][j];
					if(i != v and getTops(v) + hei(i) - getTops(i) <= mxH[i]) {
							
						int co;
						co = dump(i, v);
						if(co == inf) continue;						
						while(top(v) == c) pour(v, i);
						ok = 1;
						return 1;
					}
				}
			}
			
		}
		if(ok == 0 and 0) {
			for(int i = 1; i <= N + 2; i ++) if(getUnique(i) == 2) {
				auto now  = kth(i, 2);
				int c = now.x;
				int cnt = now.y;
				
				if(c == 0) continue;
				for(int j = sz(col[c]) - 1; j >=0; j--) {
					int v = col[c][j];
					if(i != v and getTops(v) + hei(i) - getTops(i) <= mxH[i]) {
							
						int co;
						co = dump(i, v);
						if(co == inf) continue;						
						while(top(v) == c) pour(v, i);
						ok = 1;
						return 1;
					}
				}
			}
		}
		if(ok == 0) {
			int mx = 1;
			int em = 0;
			for(int i = 1; i <= N + 2; i ++) if(top(i) == 0) {
				em = i;
				break;
			}
			if(em) {
				VI qwe(N+1);
				VI qwer(N+1);
				VI asd(N+1);
				VI id;
				for(int i = 1; i <= N + 2; i ++) if(i != vec[0] and top(i) and getUnique(i) > 1) {
					qwer[top(i)] += getTops(i);
					qwe[top(i)] ++;
					id.pb(top(i));
					asd[top(i)] += getUnique(i);
				}
				
				sort(id.begin(), id.end(), [&](int u, int v) {
					if(qwe[u] == qwe[v]) {
						if(qwer[u] == qwer[v]) {
							return deg[u] > deg[v];
							return u < v;
							if(testType % 4 < 2) return asd[u] > asd[v];
							return asd[u] < asd[v];
						}
						return qwer[u] > qwer[v];
					}
					return qwe[u] > qwe[v];	
				});
				if(sz(id)) {
					mx = id[0];
					for(auto u : col[mx]) {
						int c = top(u);
						while(top(u) == c) pour(u, em);
						ok = 1;
					}
				}
				else for(auto u : vec) if(getUnique(u) > 1) {
					int c = top(u);
					while(top(u) == c) pour(u, em);
					ok = 1;
					break;
				}
			}
		}
		return ok;
	}
	
	
	void makeEmpty(int u) {
		if(getUnique(u) <= 1) return ;		
		while(top(u)) {
			int x = top(u);
			int ok = 0;
			for(int i = 1; i <= N + 2; i ++) if(i != u) {
				if(x == top(i)) {
					pour(u, i);
					ok = 1;
					break;
				}
			}
			if(ok) continue;
		
			for(int i = 1; i <= N + 2; i ++) if(i != u) {
				if(top(i)) continue;
				pour(u, i);
				ok = 1;
				break;
			}
			assert(ok);
		}
	}
	
	void spread(VI &vec) {
		while(freeze(vec));
		for(auto u : vec) makeEmpty(u);
	}
	
	void info(Answer &ans) {
		VI ext, pou;
		map<int, int> mp;
		for(auto now : ans.pourOper) {
			int x = now.x;
			int y = now.y;
			if(x == 0) {
				ext.pb(C[y]);
				mp[C[y]]++;
			}
		}
		sort(ext.begin(), ext.end());
	}
	
	Answer main(int REV) {
		init(); 
		ans.init();
		
		VI vec;
		for(int i = 1; i <= N+2; i ++) vec.pb(i);
		sort(vec.begin(), vec.end(), [](int u, int v) {
			return C[u] < C[v];	
		});
		if(REV) for(int i=1;i<=N;i++) rever(i);
		else if(testType % 4 >= 3 or testType >= 9) greedyReverse(ans);
		for(int i = 1; i <= N; i ++) for(int j = 1; j <= N; j ++) if(i != j and D[i][j] != -1) adj[i].pb(j);
		for(int u = 1; u <= N + 2; u ++) {
			int ans = hei(u) > 0;
			for(int i = 1; i < sz(tubes[u]); i ++) {
				ans += tubes[u][i] != tubes[u][i-1];
			}
			unq[u] = ans;
		}
		
		int step = 20000;
		
		while(1) {
			if(clock() > CLOCKS_PER_SEC * TIME_LIMIT) {
				ans.cost = inf;
				return ans;
			}
			if(ok()) break;
			auto sel = findGood(vec);
			int u = sel.x;
			int v = sel.y;
			for(int i = 1; i <= N + 2; i ++) if(i != v) {
				while(top(i) == u) {
					pour(i, v);
					if(clock() > CLOCKS_PER_SEC * TIME_LIMIT) {
						ans.cost = inf;
						return ans;
					}
				}
			}
			while(freeze(vec)) {
				if(clock() > CLOCKS_PER_SEC * TIME_LIMIT) {
					ans.cost = inf;
					return ans;
				}
			}
		}
		spread(vec);
		return ans;
	}
};

int solve(int i = 0) {
	INPUT();
	int REV=0;
	if(testType>11) REV=1;
	int st, ed;
	st = 1; ed = 50;
	
	Answer ans;
	ans.cost=1e9;
	for(int i=st; i<=ed; i++) {
		LUK = i;
		Answer tmp = ZACH :: main(REV);
		if(tmp < ans) ans = tmp;
	}
	
	ans.print();
}

int main () {
	srand(time(0));
	solve();
}