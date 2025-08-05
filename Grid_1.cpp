 #include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int h,w;
vector<vector<char>> v;
vector<vector<int>> dp;

int f(int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(v[i][j]=='#') return dp[i][j]=0;
    if(i==h-1 && j==w-1) return dp[i][j]=1;
	int path1=0,path2=0;
	if(j!=w-1){
		path1=f(i,j+1)%MOD;
	}
	if(i!=h-1){
		path2=f(i+1,j)%MOD;
	}

	return dp[i][j]=(path1+path2)%MOD;
}

void solve(){
	cin >> h >> w;
    v.resize(h,vector<char>(w));
    dp.resize(h+1,vector<int>(w+1,-1));
    for(int i=0;i<h;++i){
    	for(int j=0;j<w;++j){
    		cin >> v[i][j];
    	}
    }
    cout << f(0,0) << '\n';
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
