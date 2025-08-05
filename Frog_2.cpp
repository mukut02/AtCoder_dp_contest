 #include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n,k;cin >> n >> k;
	vector<int> v(n);

	for(auto &x : v) cin >> x;
	vector<int> dp(n+1,LLONG_MAX);
    dp[0]=0;
    for(int i=1;i<n;++i){
    	for(int j=i-1;j>=(i-k) && j>=0;j--){
    		int jump=dp[j]+abs(v[j]-v[i]);
    		dp[i]=min(jump,dp[i]);
    	}
    }
    cout << dp[n-1] << '\n';
}

signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    while(t--){
     	solve();
     }
}
