#include <bits/stdc++.h>

using namespace std;

const int NN = 200111;
int a[NN];
int n, K;


struct trie{
	const int alpha = 2;
	struct node{
		int mx;
		node* nxt[alpha];
		
		bool existNode(char c) {
			if(nxt[c] == null) return false;
			return true;
		}
		
		node* getNextNode(char c) {
			if(existNode(c)) return nxt[c];
			nxt[c] = new node();
			nxt[c].init();
		}
		
	}
};


void solve() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i), a[i] ^= a[i-1];
	scanf("%d", &K);
	for(int i=1; i<=n; i++) {
			
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	
}

