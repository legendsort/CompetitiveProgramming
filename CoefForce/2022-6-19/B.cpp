#include <bits/stdc++.h>

using namespace std;

char s[200111];
char t[200111];
int n;
void get(int c, int len) {
	if(len == n) {
		for(int i=0; i<n; i++) t[i] = 9 - (s[i] - '0') + '0';
	} else {
		for(int i=0; i<n; i++) t[i] = '1';
		for(int i=n-1; i>=0; i--) {
			if(t[i] < s[i]) {
				t[i] = (t[i] + 10 - s[i]) + '0';
				if(i) t[i-1] --;
			}
			else t[i] = (t[i] - s[i]) + '0';
		}
	}
}

void solve() {
	cin >> n;
	scanf("%s", s);
	if(s[0] == '9') get(1, n+1);
	else get(9, n);
	t[n] = 0;
	puts(t);
}

int main() {
	int T;
	cin >> T;
	while(T--) solve();

}

