/*
 * too slow, but too accepted.
 */
import java.util.*;

class Solution {
    public int maximumGap(int[] nums) {
        if (nums.length < 2)
            return(0);
        Set<Integer> set = new TreeSet<>();
        int i;
        for (i = 0; i < nums.length; i++) {
            if (set.contains(nums[i]))
                continue;
            set.add(nums[i]);
        }
        nums = new int[set.size()];
        i = 0;
        for (Integer n : set)
            nums[i++] = n;

        int max = 0;
        for (i = 1; i < nums.length; i++)
            if ((nums[i] - nums[i - 1]) > max)
                max = nums[i] - nums[i - 1];
        return(max);
    }
    public static void main(String[] args) {
        int[] nums = new int[]{ 1, 10000000};
        System.out.println(new Solution().maximumGap(nums));
    }
}
