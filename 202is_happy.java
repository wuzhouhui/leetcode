import java.util.*;

class Solution {
	public boolean isHappy(int n) {
		if (n <= 0)
			return false;

		Map<Integer, Integer> hash = new HashMap<Integer, Integer>();
		int	squareSum;

		while (n != 1) {
			squareSum = 0;
			while (n != 0) {
				squareSum += (n % 10) * (n % 10);
				n /= 10;
			}
			if (hash.containsKey(squareSum))
				return false;
			n = squareSum;
			hash.put(n, n);
		}
		return true;
	}
}
