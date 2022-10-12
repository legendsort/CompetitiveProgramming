#include <bits/stdc++.h>

using namespace std;

char s[100111];
int cnt[2];

int main() {
    int T;
	cin >> T;
	while(T--) {
		int n; scanf("%d %s", &n, s);
		cnt[0]=cnt[1]=0;
		for(int i=0; i<n; i++) cnt[s[i]-'0']++;
		if((cnt[0]&1) & (cnt[1]&1)) puts("NO");
		else puts("YES");
	}
}



