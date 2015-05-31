///* wrong answer */
//#define ROBBED	 -1
//#define UNROBBED -2
//
//static int find_maxidx(int *, int);
//
//int rob(int num[], int n)
//{
//	if (!num || !n)
//		return 0;
//	if (n == 1)
//		return num[0];
//	if (n == 2)
//		return (num[0] > num[1] ? num[0] : num[1]);
//
//	int maxidx, amount = 0;
//
//	while (1) {
//		maxidx = find_maxidx(num, n);
//		if (num[maxidx] < 0)
//			break;
//
//		if ((maxidx == 0 && num[1] == ROBBED)
//			|| (maxidx == (n - 1) && num[n - 2] == ROBBED)
//			|| ((maxidx > 0 && maxidx < n)
//				&& (num[n - 1] == ROBBED
//					|| num[n + 1] == ROBBED))) {
//			num[maxidx] = UNROBBED;
//		} else {
//			amount += num[maxidx];
//			num[maxidx] = ROBBED;
//		}
//	}
//	return amount;
//}
//
//static int find_maxidx(int *num, int n)
//{
//	int	maxidx = 0;
//
//	while (n-- > 0) {
//		if (num[n] > num[maxidx])
//			maxidx = n;
//	}
//
//	return maxidx;
//}

int rob(int num[], int n)
{
	if (!num || !n)
		return 0;
	if (n == 1)
		return num[0];
	if (n == 2)
		return (num[0] > num[1] ? num[0] : num[1]);

	int	buf[n];
	int	i, a;

	buf[0]	= num[0];
	buf[1]	= num[0] > num[1] ? num[0] : num[1];

	for (i = 2; i < n; i++) {
		a = num[i] + buf[i - 2];
		buf[i] = a > buf[i - 1] ? a : buf[i - 1];
	}

	return buf[n - 1];
}
