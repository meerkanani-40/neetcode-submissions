class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        vector<pair<int, int>> adjList[n+1];
        for(auto it : times){
            adjList[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > dist[node]){
                continue;
            }

            for(auto neighbors : adjList[node]){
                int adjNode = neighbors.first;
                int edW = neighbors.second;

                if(dis+edW < dist[adjNode]){
                    dist[adjNode] = dis+edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int time = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9){
                return -1;
            }

            time = max(time, dist[i]);
        }

        return time;
    }
};
