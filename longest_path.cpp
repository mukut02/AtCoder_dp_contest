#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin >> n >> m;
	vector<vector<int>> adj(n+1);
	vector<int> indegree(n+1,0);
    
    for(int i=0;i<m;++i){
    	int a,b;cin >> a >> b;
    	adj[a].push_back(b);
    	indegree[b]++;
    }
    
    queue<int> q;
    vector<int> dist(n+1,0);

    for(int i=1;i<=n;++i){
    	if(indegree[i]==0){
    		q.push(i);
    	}
    }
    int ans=0;
    while(!q.empty()){
    	int node=q.front();
    	q.pop();

    	for(auto &nxt : adj[node]){
    		dist[nxt]=max(dist[nxt], dist[node]+1);
    		indegree[nxt]--;
    		if(indegree[nxt]==0) q.push(nxt);
    		ans=max(ans,dist[nxt]);
    	}
    }
    cout << ans;

}