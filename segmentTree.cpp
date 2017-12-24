const int maxn = 4e5+1;
const int maxlog = 20;
int st[maxn][maxlog];
int lg2[maxn];

int rmq(int l, int r) {
    int len = lg2[r-l+1];
    int ret = max(st[l][len], st[r-(1<<len)+1][len]);
    return ret;
}

{
	for (int i = 0; i < n; ++i) {
        scanf("%d", &st[i][0]);
        st[i+n][0] = st[i][0];
    }
    lg2[1] = 0;
    for (int i = 2; i < maxn; ++i) lg2[i] = lg2[i>>1]+1;
    for (int len = 1; len <= lg2[2*n]; ++len) for (int i = 0; i+(1<<len) <= 2*n; ++i) st[i][len] = max(st[i][len-1], st[i+(1<<(len-1))][len-1]);
}