vector<int> topSort() {
	vector<int> t, d(n, 0);
	queue<int> next;
	REP(i, n) for(int v : g[i]) ++d[v];
	REP(i, n) if(d[i] == 0) next.push(i);
	while(!next.empty()) {
		int cur = next.front();
		next.pop();
		t.push_back(cur);
		for(int v : g[cur]) {
			--d[v];
			if(d[v] == 0) next.push(v);
		}
	}
	return t;
}