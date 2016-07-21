#ifndef bool
#define bool int
#endif

bool isPalindrome(int x)
{
	if (x < 0 || (x && x % 10 == 0))
		return(0);
	int half = 0;
	while (x > half) {
		half = half * 10 + x % 10;
		x /= 10;
	}
	return(x == half || x == half / 10);
}
main(){}
