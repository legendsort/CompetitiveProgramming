#include <bits/stdc++.h>

using namespace std;

string name[3] = {"Alice", "Bob", "Charlie"};
int val[3];

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
    	for(int i=0; i<3; i++) cin >> val[i];
    	cout << name[max_element(val, val+3) - val] << endl;
    }
}


