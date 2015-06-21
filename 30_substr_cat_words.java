import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new LinkedList<>();
        if (s.length() == 0 || words.length == 0 || words[0].length() == 0)
            return(result);

        HashMap<String, Integer> map = new HashMap<>();
        for (String word : words) {
            Integer n = map.get(word);
            if (n == null)
                map.put(word, 1);
            else 
                map.put(word, n + 1);
        }

        int wordlen = words[0].length();
        int totallen = words.length * wordlen;
        for (int i = 0; (s.length() - i) >= totallen; i++) {
            int j = i;
            HashMap<String, Integer> mapcpy = (HashMap<String, Integer>)map.clone();
            for (; (j + wordlen) <= (i + totallen); j += wordlen) {
                Integer n = mapcpy.get(s.substring(j, j + wordlen));
                if (n == null || n == 0)
                    break;
                mapcpy.put(s.substring(j, j + wordlen), n - 1);
            }
            if ((j + wordlen) > (i + totallen))
                result.add(i);
        }
        return(result);
    }
    public static void main(String[] args) {
        String[] words = new String[]{ "bar", "foo" };
        System.out.println(new Solution().findSubstring("barfoothefoobarmanbarfoofoobar",words));
    }
}
