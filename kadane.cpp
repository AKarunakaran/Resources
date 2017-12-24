int kadane(vector<int>& v)
{
    int res = 0, tempMax = 0;
    for(int num : v) {
        tempMax += num;
        res = max(res, tempMax);
        tempMax = max(tempMax, 0);
    }
    return res;
}