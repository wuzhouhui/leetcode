import java.util.*;

class Solution {
	public static boolean isIsomorphic(String s, String t) {
		if (s == null && t == null)
			return true;
		if (s == null || t == null)
			return false;
		if (s.length() != t.length())
			return false;

		char[] chars = new char[s.length()];
		Map<Character, Character> map = new HashMap<>();
		Map<Character, Character> usedMap = new HashMap<>();
		for (int i = 0; i < s.length(); i++) {
			Character c = map.get(s.charAt(i));
			if (c == null) {
				c = t.charAt(i);
				if (usedMap.get(c) != null)
					return false;
				map.put(s.charAt(i), t.charAt(i));
				usedMap.put(c, c);
			}
			chars[i] = c;
		}
		
		if (t.equals(new String(chars)))
			return true;
		return false;
	}
	
	public static void main(String[] args) {
		System.out.println(Solution.isIsomorphic(args[0], args[1]));
	}
}
