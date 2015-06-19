import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length <= 1)
            return(nums.length);

        Set<Integer> set = new HashSet<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            if (set.contains(nums[i]))
                continue;
            set.add(nums[i]);
        }
        int max = 1;
        for (int i = 0; i < nums.length; i++) {
            int count = 1;
            for (int left = nums[i] - 1; set.contains(left); left--) {
                set.remove(left);
                count++;
            }

            for (int right = nums[i] + 1; set.contains(right); right++) {
                set.remove(right);
                count++;
            }
            set.remove(nums[i]);
            if (count > max)
                max = count;
        }
        return(max);
    }
    public static void main(String[] args) {
        int[] x = new int[] { 1, 2, 0, 1 };
        System.out.println(new Solution().longestConsecutive(x));
    }
}
