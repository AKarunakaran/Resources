/************************************************          Max flow, FFA for adj. list                     ********************************************/

const int MAXN = 200100;
const int INF = 1000000000;

// destination, capacity
vector<pair<int, int> > g[MAXN];

int max_flow(int s, int t, int n) {
    vector<int> ff(n + 1, 0);
    vector<int> fa(n + 1, 0);
    vector<int> fi(n + 1, 0);
    vector<bool> z(n + 1, 0);
    
    int i = 0, now, ans = 0;
    
    i = s;
    now = INF;
    
    while (true) {
        z[i] = true;
        ff[i] = now;
        bool flag = false;
        auto p = g[i].begin();
        while (p != g[i].end()) {
             if (p->second > 0 && !z[p->first]) {
                flag = true;
                if (p->second < now) now = p->second;
                fa[p->first] = i;
                fi[p->first] = p - g[i].begin();
                i = p->first;
                if (i == t) {
                    ans += now;
                    while (i != s) {
                        int tmp = i;
                        i = fa[i];
                        p = g[i].begin() + fi[tmp];
                        p->second -=now;
                        g[tmp].push_back(make_pair(i, now));
                    }
                    now = INF;
                    z = vector<bool> (n + 1, false);
                }
                break;
            }
            ++p;
        }
        if (flag) continue;
        if (!flag && i == s) break;
        
        if (i != s) {
            i = fa[i];
            now = ff[i];
        }
    }
    
    return ans;
}

/************************************************                       end                                ********************************************/









/************************************************          Min cost flow for adj. list                     ********************************************/

const int MAXN = 1100;
const int INF = 1000000000;

class node {
public:
    int v, w, f, couple;
    node(int V, int W, int F, int CC) {v = V; w = W; f = F; couple = CC;};
};

int fa[MAXN], ff[MAXN];
vector<node> g[MAXN];

// s, t, capacity, cost
void newnode(int a, int b, int c, int d) {
    node p(b, d, c, g[b].size());
    node q(a, -d, 0, g[a].size());
    g[a].push_back(p);
    g[b].push_back(q);
}

int SPFA(int s, int t, int n) {
    vector<int> d(n + 1, INF);
    vector<bool> z(n + 1, false);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    z[s] = true;
    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        for (auto p = g[i].begin(); p != g[i].end(); ++p) {
            if (p->f > 0 && d[p->v] > d[i] + p->w) {
                d[p->v] = d[i] + p->w;
                fa[p->v] = i;
                ff[p->v] = p - g[i].begin();
                if (!z[p->v]) {
                    z[p->v] = true;
                    Q.push(p->v);
                }
            }
        }
        z[i] = false;
    }
    return d[t];
}

int min_cost(int s, int t, int n) {
    int flow = 0, cost = 0;
    while (SPFA(s, t, n) < INF) { //if using negative cost, replace INF with 0
        int i = t, now = INF;
        while (i != s) {
            node &p = g[fa[i]][ff[i]];
            i = fa[i];
            if (p.f < now) now = p.f;
        }
        flow += now;
        
        i = t;
        while (i != s) {
            g[fa[i]][ff[i]].f -= now;
            cost += now * g[fa[i]][ff[i]].w;
            g[i][g[fa[i]][ff[i]].couple].f += now;
            i = fa[i];
        }
    }
    return cost;
}

/************************************************                       end                                ********************************************/