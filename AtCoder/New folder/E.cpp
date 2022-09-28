#include <bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 100011;
int n;
INT k;
INT a[NN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> k;
	vector<INT> vec;
	vector<INT> sum;
	for(int i=1; i<=n; i++) cin >> a[i], vec.push_back(a[i]);
	sort(vec.begin(), vec.end());
	INT p = 0;
	for(auto u : vec) {
		p += u;
		sum.push_back(p);
	}
	INT st=0, ed=1e13, mid, re;
	while(ed>st+1) {
		mid = st + ed >> 1;
		p = upper_bound(vec.begin(), vec.end(), mid) - vec.begin();
		p--;
		re = k;
		if(p >= 0) re -= sum[p];
		re -= (n - p - 1) * mid;
		if(re < 0) ed = mid;
		else if(n - p - 1 >= re) st = mid;
		else ed = mid;
	}
	cout << st << endl;
	p = upper_bound(vec.begin(), vec.end(), st) - vec.begin();
	p--;
	re = k;
	if(p >= 0) re -= sum[p];
	 re -= (n - p - 1) * st;
	for(int i=1; i<=n; i++) {
		a[i] = max(0ll, a[i] - st);
		if(a[i] and re) {
			a[i]--;
			re--;
		}
		cout << a[i]<<' ';
	}
	cout << endl;
	
}



