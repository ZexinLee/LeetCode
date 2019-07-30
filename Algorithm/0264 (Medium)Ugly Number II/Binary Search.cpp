class Solution {
public:
	int nthUglyNumber(int n) {
		int pow[40] = {1};
		for (int i = 1; i <= 30; ++i) pow[i] = pow[i - 1] * 2;
		int l = 1, r = 2147483647;
		while (l < r) {
			int mid = l + ((r - l) >> 1), cnt = 0;
			for (long long i = 1; i <= mid; i *= 5) {
				for (long long j = 1; j * i <= mid; j *= 3) {
					cnt += upper_bound(pow, pow + 31, mid / i / j) - pow;
				}
			}
			if (cnt < n) l = mid + 1;
			else r = mid;
		}
		return l;
	}
};