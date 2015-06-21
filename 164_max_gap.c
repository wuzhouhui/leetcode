/*
 * too slow, but too accepted
 */
#include <stdlib.h>

static int intcmp(const void *a, const void *b)
{
    return(*(int *)a - *(int *)b);
}

int maximumGap(int *nums, int numsSize)
{
    int i, max, t;

    if (numsSize < 2)
        return(0);

    qsort(nums, numsSize, sizeof(int), intcmp);
    max = 0;
    for (i = 1; i < numsSize; i++)
        if ((t = nums[i] - nums[i - 1]) > max)
            max = t;
    return(max);
}

int main(void)
{

}
