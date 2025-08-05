 #include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> v;
vector<vector<int>> dp;
int n;

int helper(int x,int y){
	if(dp[x][y]!=-1) return dp[x][y];
   if(x==0 || y==0){
   	  return dp[x][y]=0;
   }

   int path1=0;
   int path2=0;
   
   if(y==1){
   	 path1=helper(x-1,y+1);
   	 path2=helper(x-1,y+2);
   }
   else if(y==2){
   	path1=helper(x-1,y-1);
   	 path2=helper(x-1,y+1);
   }
   else if(y==3){
   	path1=helper(x-1,y-1);
   	 path2=helper(x-1,y-2);
   }
   return dp[x][y]=max(path1,path2)+v[x][y];
}

void solve(){
	cin >> n;
	v.resize(n+1,vector<int>(4));
    dp.resize(n+2,vector<int>(4,-1));

	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			cin >> v[i][j];
		}
	}
    int ans=0;
	for(int j=0;j<3;++j){
		ans=max(ans,helper(n,j+1));
	}
	cout << ans << '\n';
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
