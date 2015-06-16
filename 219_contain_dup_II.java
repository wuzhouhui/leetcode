import java.util.*;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (nums.length <= 1)
            return(false);
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            List<Integer> list = map.get(nums[i]);
            if (list == null) {
                list = new LinkedList<Integer>();
                list.add(i);
                map.put(nums[i], list);
                continue;
            }

            for (int j = 0; j < list.size(); j++) {
                if (Math.abs(list.get(j) - i) <= k)
                    return(true);
            }
            list.add(i);
        }
        return(false);
    }
}
