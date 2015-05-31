//// time limit exceed.
//int majorityElement(int num[], int n)
//{
//	int	i, j, k, c;
//
//	for (i = 0; i < n/2 + 1; i++) {
//		k = num[i];
//		for (c = 0, j = 0; j < n; j++) {
//			if (num[j] == k) {
//				if (++c > n/2)
//					break;
//			}
//		}
//	}
//
//	return k;
//}

int majorityElement(int num[], int n)
{
	if (n == 1)
		return num[0];

	int	i, c, ind;

	for (ind = 0, c = 1, i = 1; i < n; i++) {
		if (num[ind] == num[i])
			c++;
		else
			c--;
		if (c == 0) {
			ind = i;
			c = 1;
		}
	}

	return num[ind];
}
