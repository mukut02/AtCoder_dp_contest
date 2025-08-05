 #include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<double> p;
vector<vector<double>> dp;

double f(int i,int h){
	if(dp[i][h]!=-1) return dp[i][h];
     if(i==0){
     	if(h>(n-h)){
     		return dp[i][h]=(double)1;
     	}
     	else{
     		return dp[i][h]=(double)0;
     	}
     }

	double head=f(i-1,h+1)*(p[i-1]);
	double tail=f(i-1,h)*(1-p[i-1]);

	return dp[i][h]=head+tail;
}

void solve(){
    cin >> n;
    p.resize(n);
    dp.resize(n+1,vector<double>(n+1,-1));
    for(auto &x : p) cin >> x;
    cout << fixed << setprecision(16) <<  f(n,0) << '\n';	
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
