import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord,
            Set<String> wordDict) {
        if (beginWord.length() == 0)
            return(0);
        LinkedList<String> wordQ = new LinkedList<>();
        LinkedList<Integer> distQ = new LinkedList<>();
        wordDict.add(beginWord);
        wordDict.add(endWord);
        wordQ.offer(beginWord);
        distQ.add(1);
        while (wordQ.size() > 0) {
            String word = wordQ.poll();
            Integer dist = distQ.poll();
            if (word.equals(endWord))
                return(dist);
            for (int i = 0; i < word.length(); i++) {
                char[] chars = word.toCharArray();
                for (char c = 'a'; c <= 'z'; c++) {
                    chars[i] = c;
                    String tmpWord = new String(chars);
                    if (wordDict.contains(tmpWord)) {
                        wordQ.offer(tmpWord);
                        distQ.offer(dist + 1);
                        wordDict.remove(tmpWord);
                    }
                }
            }
        }
        return(0);
    }
    public static void main(String[] args) {
        Set<String> set = new HashSet<String>();
        set.add("hot");
        set.add("dot");
        set.add("dog");
        set.add("lot");
        set.add("log");
        System.out.println(new Solution().ladderLength("hit", "cog", set));
    }
}
