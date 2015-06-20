/*
 * I	1
 * V	5
 * X	10
 * L	50
 * C	100
 * D	500
 * M	1000
 */
#include <stdlib.h>
#include <string.h>
static char *romans[] = {
	"M",	/* 1000 */
	"CM",	/* 900 */
	"D",	/* 500 */
	"CD",	/* 400 */
	"C",	/* 100 */
	"XC",	/* 90 */
	"L",	/* 50 */
	"XL",	/* 40 */
	"X",	/* 10 */
	"IX",	/* 9 */
	"V",	/* 5 */
	"IV",	/* 4 */
	"I",	/* 1 */
};

static int nums[] = {
	1000,
	900,
	500,
	400,
	100,
	90,
	50,
	40,
	10,
	9, 
	5, 
	4,
	1,
};

#define N (sizeof(nums) / sizeof(nums[0]))

char *intToRoman(int num)
{
	char	*res;
	int	i;

	res = calloc(512, 1);
	for (i = 0; i < N; i++) {
		while (num >= nums[i]) {
			strcat(res, romans[i]);
			num -= nums[i];
		}
	}
	return(res);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	printf("%s\n",	intToRoman(atoi(argv[1])));
	return(0);
}
