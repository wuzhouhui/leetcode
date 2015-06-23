/*
 * time limit exceeded
import java.util.*;

class Solution {
	public boolean wordBreak(String s, Set<String> wordDict) {
		if (s.length() == 0)
			return true;

		// s.len > 0
		if (wordDict.size() == 0)
			return false;

		return do_break(s, wordDict);
	}

	private boolean do_break(String s, Set<String> wordDict) {
		if (s.length() == 0)
			return true;

		Iterator<String> iter = wordDict.iterator();
		while (iter.hasNext()) {
			String word = iter.next();
			if (word.length() > s.length() ||
				word.compareTo(s.substring(0, word.length())) != 0)
				continue;
			if (do_break(s.substring(word.length()), wordDict))
				return true;
		}
		return false;
	}
}
*/

import java.util.*;

class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {

        if (s.length() == 0)
            return(true);

		// s.len > 0
		if (wordDict.size() == 0)
			return(false);

        boolean[]   arr = new boolean[s.length() + 1];
        for (int i = 0; i <= s.length(); i++) {
            if (i == 0) {
                arr[i] = true;
                continue;
            }
            if (wordDict.contains(s.substring(0, i))) {
                arr[i] = true;
                continue;
            }
            int j;
            for (j = i - 1; j > 0; j--) {
                if (arr[j] == true
                        && wordDict.contains(s.substring(j, i))) {
                    arr[i] = true;
                    break;
                }
            }
            if (j == 0)
                arr[i] = false;
        }
        return(arr[s.length()]);
    }

    public static void main(String[] args) {
        Set<String> set = new HashSet<>();
        set.add("leet");
        set.add("code");
        set.add("abc");
        System.out.println(new Solution().wordBreak("leetabccode", set));
    }
}
