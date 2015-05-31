int maxArea(int *height, int heightSize)
{
	if (heightSize <= 1)
		return(0);
	int	left, right, tmp, max;

	left = max = 0;
	right = heightSize - 1;
	while (left < right) {
		if (height[left] < height[right]) {
			tmp = height[left] * (right - left);
			if (tmp > max)
				max = tmp;
			tmp = height[left++];
			while (left < right && height[left] <= tmp)
				left++;
			continue;
		}
		tmp = height[right] * (right - left);
		if (tmp > max)
			max = tmp;
		tmp = height[right--];
		while (left < right && height[right] < tmp)
			right--;
	}
	return(max);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 2, 4, 7, 3 };
	printf("%d\n", maxArea(x, 4));
	return(0);
}
