class Solution {
private:
    void dfs(string src, vector<string>& res, unordered_map<string, deque<string>>& adjList){
        while(!adjList[src].empty()){
            string dst = adjList[src].back();
            adjList[src].pop_back();
            dfs(dst, res, adjList);
        }

        res.push_back(src);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adjList;
        for(auto ticket : tickets){
            adjList[ticket[0]].push_back(ticket[1]);
        }

        for(auto& it : adjList){
            sort(it.second.rbegin(), it.second.rend());
        }

        vector<string> res;
        dfs("JFK", res, adjList);
        reverse(res.begin(), res.end());

        return res;
    }
};
