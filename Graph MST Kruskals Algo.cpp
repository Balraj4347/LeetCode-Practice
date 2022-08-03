class Solution
{   
	public:
  //find operation disjoint set . Path compression
	int find(vector<int>& par,int x){
	    if(par[x]==x)
	        return x;
	     return par[x]= find(par,par[x]);
	}
  // connneecting two sets if nodes in different set
  // making the higher rank parent as the parent of both the nodes set
  // if ranks are equal make any one set parent as parent and increse rank of it.
	void connect(vector<int>& rank,vector<int>& par, int u, int v){
	    
	    int pU= find(par,u);
	    int pV= find(par,v);
	    
	    if(rank[pU]!=rank[pV]){
	        if(rank[pU]>rank[pV]){
	            par[pV]=pU;
	        }else{
	            par[pU]=pV;
	        }
	    }else{
	        rank[pU]++;
	        par[pV]=pU;
	    }
	}
  // checking if the two nodes with the minimum weight from the priorty queue
  // belong to the same set on no .
  // if both are from the same set including this edge in the MST will result in a cycle . So we will not include it.
    bool isConnected(vector<int>& rank,vector<int>& par, int u, int v){
        u = find(par,u);
        v = find(par,v);
        
        if(u==v)
        return true;
        
        return false;
    }
  // Spanning tree minimum weight calculation using greedy approch 
  //implemented through minimum heap (priority queue);
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>> pq;
        
        //priority queue item of format { dist(u,v), { u , v } }
      //thus the top always return the dist that is minimum in the graph;
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++)
                pq.push({adj[i][j][1],{i,adj[i][j][0]}});
        }
      
        // arrays for disjoint set implenetation
        // par keeping track of the parent of the set to which the node belong to 
        vector<int> par(V);
      // rank keep track of the depth of the set to implement a optimum connection to two sets
        vector<int> rank(V,0);
        
        for(int i=0;i<V;i++)
            par[i]=i;
            
        int ans=0;
        
      // for each edge we take the minimum edge from the PQ and check for cycle 
      //if no cycle we consider the edge to be part of MST
        while(!pq.empty()){
            auto item = pq.top();
            int u = item.second.first;
            int v = item.second.second;
            if(!isConnected(rank,par,u,v) ){
                ans += item.first;
                connect(rank,par,u,v);
            }
            pq.pop();
        }
        return ans;
        
    }
};
