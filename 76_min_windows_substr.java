import java.util.*;

class Solution {
		public String minWindow(String s, String t) {
				if (s.length() == 0 || t.length() == 0)
						return "";

				Map<Character, Integer> mapt = new HashMap<>();
				Map<Character, Integer> maps = new HashMap<>();

				for (int i = 0; i < t.length(); i++) {
						Integer n = mapt.get(t.charAt(i));
						if (n == null)
								mapt.put(t.charAt(i), 1);
						else
								mapt.put(t.charAt(i), n + 1);
				}

				int start = 0, end = 0;
				int resStart = -1, resEnd = -1;
				int total = 0;
				while (end < s.length()) {
						for (; end < s.length(); end++) {
								Integer nt = mapt.get(s.charAt(end));
								if (nt == null)
										continue;
								Integer ns = maps.get(s.charAt(end));
								if (ns == null)
										ns = 1;
								else
										ns++;
								if (ns <= nt)
										total++;
								maps.put(s.charAt(end), ns);
								if (total >= t.length())
										break;
						}
						if (end >= s.length())
								break;
						int tmp = 0;
						while (total == t.length() && start <= end) {
								tmp = start++;
								Integer nt = mapt.get(s.charAt(tmp));
								if (nt == null)
										continue;
								Integer ns = maps.get(s.charAt(tmp));
								ns--;
								if (ns < nt)
										total--;
								maps.put(s.charAt(tmp), ns);
						}
						if (resStart < 0 || (end - tmp + 1) < (resEnd - resStart + 1)) {
								resStart = tmp;
								resEnd	= end;
								if ((resEnd - resStart + 1) == t.length())
										break;
						}
						if (start > end)
								break;
						end++;
				}

				if (resStart < 0)
						return "";
				return(s.substring(resStart, resEnd + 1));
		}
		public static void main(String[] args) {
				Solution sol = new Solution();
				System.out.println(sol.minWindow(args[0], args[1]));
		}
}
