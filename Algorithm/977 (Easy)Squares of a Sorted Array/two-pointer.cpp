class Solution {
public:
   vector<int> sortedSquares(vector<int>& A) {
	vector<int>ans(A.size(), 0);
	int i = 0;
	int j = A.size() - 1;
	int k = A.size() - 1;
	while (i<j) {
		int val1 = pow(A[i], 2);
		int val2 = pow(A[j], 2);
		if (val1>val2) {
			ans[k--] = val1;
			i++;
		}
		else {
			ans[k--] = val2;
			j--;
		}
	}
	ans[k] = pow(A[i], 2);
	return ans;
}
};
