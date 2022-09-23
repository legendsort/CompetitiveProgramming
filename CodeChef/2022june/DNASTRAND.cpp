#include <bits/stdc++.h>

using namespace std;

char s[111];
char A[] = "ATCG";
char B[] = "TAGC";

void solve() {
	int n;
	cin >> n >> s;
	map<char, char> mp;
	for(int i=0; i<4; i++) mp[A[i]] = B[i];
	for(int i=0; s[i]; i++) putchar(mp[s[i]]);
	puts("");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) solve();
}

