int dijkstra(vector<vector<int>>& g, int src, int tgt) {
    vector<int> dist(graph.size(), INF);
    dist[src] = 0;
    set<pair<int,int>> next;
    next.insert({0, src});
        
    while(!next.empty()) {
        int cur = next.begin()->second;
        if(cur == tgt) return dist[cur];
        next.erase(next.begin());
        REP(i, g[cur].size()) {
            if (dist[cur] + 1 < dist[g[cur][i]]) {
                next.erase({dist[g[cur][i]], g[cur][i]});
                dist[g[cur][i]] = dist[cur] + 1;
                next.insert({dist[g[cur][i]], g[cur][i]});
            }
        }
    }
    return INF;
}