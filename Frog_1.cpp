 #include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n;cin >> n;
	vector<int> v(n);
	for(auto &x : v) cin >> x;

	// vector<int> dp(n,0);

    // for(int ind=1;ind<n;++ind){
    // 	int onestep=dp[ind-1]+abs(v[ind]-v[ind-1]);
    // 	int twostep=LLONG_MAX;
    // 	if(ind>1){
    // 		twostep=dp[ind-2]+abs(v[ind]-v[ind-2]);
    // 	}
    // 	dp[ind]=min(onestep,twostep);
    // }
    // cout << dp[n-1] << '\n';
	int t1=0,t2=0,cur=0;
    
    for(int ind=1;ind<n;++ind){
    	int onestep=t1+abs(v[ind]-v[ind-1]);
    	int twostep=LLONG_MAX;
    	if(ind>1){
    		twostep=t2+abs(v[ind]-v[ind-2]);
    	}
        cur=min(onestep,twostep);
        t2=t1;
        t1=cur;
    }
    cout << cur << '\n';
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
