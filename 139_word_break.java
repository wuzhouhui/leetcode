// Time limit exceeded
// import java.util.*;
// 
// class Solution {
// 	public boolean wordBreak(String s, Set<String> wordDict) {
// 		if (s == null || wordDict == null
// 				|| s.length() == 0
// 				|| wordDict.size() == 0)
// 			return false;
// 
// 		return recursive(s, wordDict);
// 	}
// 
// 	private boolean recursive(String s, Set<String> dict) {
// 		Iterator<String> iter = dict.iterator();
// 
// 		while (iter.hasNext()) {
// 			String word = iter.next();
// 			if (s.startsWith(word) == false)
// 				continue;
// 			/* s.startWith(word) == true */
// 			String sub = s.substring(word.length());
// 			if (sub.length() == 0)
// 				return true;
// 			if (recursive(sub, dict) == true)
// 				return true;
// 		}
// 
// 		return false;
// 	}
// }

import java.util.*;

class Solution {
	public boolean wordBreak(String s, Set<String> wordDict) {
		if (s == null || wordDict == null
				|| s.length() == 0
				|| wordDict.size() == 0)
			return false;

	}
}
