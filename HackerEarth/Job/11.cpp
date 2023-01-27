#include<bits/stdc++.h>
using namespace std;

long long maxCost (int N, vector<int> A) {

   /*
   Input - N, A 
   Output - X
   */
    map<int, int> mp;
    long long ans = 0;
    int mx = A[0];
    for(auto a : A) {
        mp[a]++;
        ans += a;
        if(mp[a] > mp[mx]) mx = a;
    }
    int mn = (*mp.begin()).first;
    if(mp[mx] <= N/2) {
        if(N & 1) ans -= mn;
        return ans;
    }
    int remain = N - mp[mx];
    ans -= 1LL * mx * (mp[mx] - remain);
    return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }

        long long out_;
        out_ = maxCost(N, A);
        cout << out_;
        cout << "\n";
    }
}
