/*
 * time limit exceeded
 */
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
