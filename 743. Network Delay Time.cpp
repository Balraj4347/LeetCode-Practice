class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int k) {
        
        vector<pair<int,int>> g[N+1];
        for(int i=0;i<times.size();i++){
            g[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        vector<int> dist(N+1,1e9);
        dist[k]=0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<bool> visited(N+1,false);
        q.push(make_pair(dist[k],k));
        pair<int,int> temp;
        
        while(!q.empty()){
            temp=q.top();
            q.pop();
            int u=temp.second;
            visited[u]=true;
            for(int i=0;i<g[u].size();i++){
                    int v =g[u][i].first;
                    int w =g[u][i].second;
                    if(visited[v]==false && dist[v] > dist[u]+w)
                    {
                        dist[v]= dist[u]+w;
                        q.push(make_pair(dist[v],v));
                    }
            }
        }
        
        int result=0;
        for(int i=1;i<dist.size();i++){
            cout<<i<<" "<<dist[i]<<endl;
            result= max(result,dist[i]);
            
        }
        if(result == 1e9)
            return -1;
        
        return result;
        
        
    }
};
