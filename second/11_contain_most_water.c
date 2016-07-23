int maxArea(int *height, int heightSize)
{
	if (heightSize < 2)
		return(0);
	int max = 0;
	int left = 0, right = heightSize - 1;
	while (left < right) {
		if (height[left] < height[right]) {
			int t = height[left] * (right - left);
			if (t > max)
				max = t;
			t = height[left++];
			while (left < right && height[left] <= t)
				left++;
			continue;
		}
		int t = height[right] * (right - left);
		if (t > max)
			max = t;
		t = height[right--];
		while (left < right && height[right] < t)
			right--;
	}
	return(max);
}

int main(void)
{
	return(0);
}
