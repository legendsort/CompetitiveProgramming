#include <bits/stdc++.h>

using namespace std;
int n, k;
const int NN = 10011;
int a[111];
int g[NN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> k;
	for(int i=0; i<k; i++) {
		cin >> a[i];	
	}
	g[0] = 0;
	int p=0;
	for(int i=1; i<=n; i++) {
		while(p<k and a[p]<=i) p++;
		if(p==0) g[i] = 0;
		else {
			for(int j=0; j<p; j++) {
				g[i] = max(g[i], a[j] + (i - a[j] - g[i - a[j]]));
			}
		}
	
	}
	cout << g[n] << endl;
	
}



