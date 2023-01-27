#include<bits/stdc++.h>
using namespace std;
using INT = long long;
const int mod = 1e9 + 7;

long long solve (int N, vector<int> A) {
   // Write your code here
    vector<int> B = A;
    INT sum = 0;
    INT ans = 0;
    for(int i=0; i<N; i++) {
        B[i] -= i;
        sum += B[i];
    }
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    int pos = 0;
    INT now = 0;
    for(int i=0; i<N; i++) {
        while(pos < N and B[pos] <= A[i]) {
            now += B[pos];
            pos++;
        }
        ans += ((INT)A[i] * pos - now + (sum - now) - (INT)A[i] * (N - pos));
        ans %= mod;
    }
    return ans;
}

int main() {

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
        out_ = solve(N, A);
        cout << out_;
        cout << "\n";
    }
}
