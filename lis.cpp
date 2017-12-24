int lis(vector<int>& a) {
    int n = a.size(), ans = 1, high, low;
    vector<int> dp(n+1, INF);
    dp[1] = a[0];
    FOR(i, 1, n-1) {
        high = ans;
        low = 1;
        while(low <= high) {
            int mid = (high+low)/2;
            if(dp[mid] >= a[i]) high = mid-1;
            else low = mid+1;
        }
        if(dp[low] > a[i]) dp[low] = a[i];
        ans = max(ans, low);
    }
    return ans;
}