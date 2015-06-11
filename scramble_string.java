/*
 * time limit exceeded
 * s1 = "tqxpxeknttgwoppemjkivrulaflayn"
 * s2 = "afaylnlurvikjmeppowgttnkexpxqt"
 */

import java.util.*;

class Solution {
	public boolean isScramble(String s1, String s2) {
		if (s1.length() != s2.length())
			return false;
		Map<Character, Integer> map = new HashMap<>();
		for (int i = 0; i < s1.length(); i++) {
			Integer n = map.get(s1.charAt(i));
			if (n == null)
				map.put(s1.charAt(i), 1);
			else 
				map.put(s1.charAt(i), n + 1);
			n = map.get(s2.charAt(i));
			if (n == null)
				map.put(s2.charAt(i), -1);
			else 
				map.put(s2.charAt(i), n - 1);
		}
		for (Integer n : map.values())
			if (n != 0)
				return false;
		int len = s1.length();
		for (int i = 1; i < len; i++) {
			String s11 = s1.substring(0, i);
			String s12 = s1.substring(i, len);
			String s21 = s2.substring(0, i);
			String s22 = s2.substring(i, len);
			if (isScramble(s11, s21) && isScramble(s12, s22))
				return true;
			s21 = s2.substring(0, len - i);
			s22 = s2.substring(len - i, len);
			if (isScramble(s11, s22) && isScramble(s12, s21))
				return true;
		}
		return false;
	}

	public static void main(String[] args) {
		Solution s = new Solution();
		String s1 = "tqxpxeknttgwoppemjkivrulaflayn";
		String s2 = "afaylnlurvikjmeppowgttnkexpxqt";
		System.out.println(s.isScramble(s1, s2));
	}
}
