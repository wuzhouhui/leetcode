import java.util.*;

class Solution {

    private List<String> result;
    private StringBuffer sentence;

    public List<String> wordBreak(String s, Set<String> wordDict) {
        result = new LinkedList<>();

        if (s == null || s.length() == 0 || wordDict == null 
                || wordDict.size() == 0)
            return(result);

        sentence = new StringBuffer();
        do_break(s, 0, wordDict);
        return(result);
    }

    private void do_break(String s, int start, Set<String> dict) {
        if (start >= s.length()) {
            if (sentence.length() == 0)
                return;
            result.add(sentence.substring(0, sentence.length() - 1));
            return;
        }

        int del_start = sentence.length();
        for (int i = 1; (start + i) <= s.length(); i++) {
            String substr = s.substring(start, start + i);
            if (dict.contains(substr) == false)
                continue;
            if (breakable(s.substring(start + i), dict) == false)
                continue;
            sentence.append(substr + " ");
            do_break(s, start + i, dict);
            sentence.delete(del_start, sentence.length());
        }
        return;
    }

    private boolean breakable(String s, Set<String> wordDict) {
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
        set.add("cat");
        set.add("cats");
        set.add("and");
        set.add("sand");
        set.add("dog");
        new Solution().wordBreak("catsanddog", set);
    }
}
