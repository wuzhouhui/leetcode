int trap(int *height, int heightSize)
{
	if (heightSize < 3)
		return(0);

	int	i, j, t;
	int	sum, leftmax[heightSize], rightmax[heightSize];

	t = height[0];
	for (i = 1; i <= (heightSize - 2); i++) {
		leftmax[i] = t;
		if (height[i] > t)
			t = height[i];
	}
	t = height[heightSize - 1];
	for (i = heightSize - 2; i >= 1; i--) {
		rightmax[i] = t;
		if (height[i] > t)
			t = height[i];
	}
	sum = 0;
	for (i = 1; i <= (heightSize - 2); i++) {
		t = (leftmax[i] < rightmax[i] ? leftmax[i] : rightmax[i])
			- height[i];
		if (t > 0)
			sum += t;
	}
	return(sum);
}

#include <stdio.h>

int main(void)
{
	int	x[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	printf("%d\n", trap(x, sizeof(x) / sizeof(int)));
	return(0);
}
