#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;cin >> n >> k;
	vector<int> v(n);
	vector<bool> dp(k+1,false);
    dp[0]=true;
	for(int i=0;i<n;++i){
		cin >> v[i];
		dp[v[i]]=true;
	}
    for(int j=1;j<=k;++j){
    	for(int i=0;i<n;++i){
    		if(j<v[i]) break;
    		dp[j]= dp[j] or !dp[j-v[i]];
    		if(dp[j]==true) break;
    	}
    }
    if(dp[k]){
    	cout << "First";
    }
    else{
    	cout << "Second";
    }
} 
