#include <bits/stdc++.h>

using namespace std;
using VI = vector<int>;


vector<int> vec[NN], arr[NN];
vector<INT> sumOfSort[NN];

const int NN = 100111;
int a[NN];
int fir[NN];
INT sum[NN];


int main() {
	int T;
	cin >> T;


	for(int i=2; i<NN; i++) if(fir[i] == 0) {
		fir[i] = i;
		for(int j=i*2; j<NN; j+=i) if(fir[j] == 0) fir[j] = i;
	}	
	while(T--) {
		int n;
		cin >> n;
		for(int i=1; i<=n; i++) scanf("%d", a+i), sum[i] = sum[i-1] + a[i];
		for(int i=1; i<NN; i++) vec[i].clear(), arr[i].clear(), sumOfSort[i].clear();
		
		for(int i=1; i<=n; i++) {
			int u = a[i], v = fir[u];
			while(u > 1) {
				vec[v].push_back(i);
				sumOfSort[v].push_back(0);
				arr[v].push_back(a[i]);
				while(u % v == 0) u /= v;
				v = fir[u];
			}
		}
		for(int i=1; i<NN; i++) if(not vec[i].empty()){
			VI temp = arr[i];
			sort(arr[i].begin(), arr[i].end());
			reverse(arr[i].begin(), arr[i].end());
			INT sum = 0;
			for(int j=0; j<arr[i].size(); j++) {
				sum += arr[i][j];
				sum -= temp[j];
				sumOfSort[i][j] = sum;
			}
		}
		int Q;
		cin >> Q;
		while(Q--) {
			int p, k;
			scanf("%d %d", &p, &k);	
			INT ans = sum[k];
			int pos = upper_bound(vec[p].begin(), vec[p].end(), k) - vec[p].begin();
			if(pos > 0) pos--, ans += sumOfSort[p][pos];
			printf("%lld\n", ans);	
		}
	}
	return 0;
}
