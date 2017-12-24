int bs(int item, vector<int>& arr) {
	int l = 0, r = arr.size()-1;
	while(l <= r) {
		int m = l + (r-l)/2;
		if(arr[m] == item) return m;
		if(arr[m] > item) r = m;
		else l = m+1;
	}
	return -1;
}