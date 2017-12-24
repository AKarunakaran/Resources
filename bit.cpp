int getSum(vector<int>& bit, int index)
{
    int sum = 0;
    ++index;
    while (index>0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}
 

//assumes global n
void updateBIT(vector<int>& bit, int index, int val)
{
    ++index;
    while (index <= n) {
       bit[index] += val;
       index += index & (-index);
    }
}