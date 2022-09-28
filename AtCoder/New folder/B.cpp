#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y, int z) {
	if(x<0) {
		x=-x; y=-y; z=-z;
	}
	if(y > x) return x;
	if(y < 0) return x;
	if(z > y) return -1;
	return abs(z) + abs(x - z);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int x, y, z;
	cin >> x >> y >> z;
	cout << solve(x, y, z) << endl;
}



