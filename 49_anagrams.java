import java.util.*;

class Solution {
	public List<String> anagrams(String[] strs) {
		List<String> res = new LinkedList<String>();
		HashMap<String, List<String>> map = 
			new HashMap<String, List<String>>();

		for (int i = 0; i < strs.length; i++) {
			char[] chars = strs[i].toCharArray();
			Arrays.sort(chars);
			String sorted = new String(chars);
			if (map.get(sorted) == null) {
				List<String> list =
					new LinkedList<String>();
				list.add(strs[i]);
				map.put(sorted, list);
			} else {
				map.get(sorted).add(strs[i]);
			}
		}
		for (List<String> l : map.values()) {
			if (l.size() > 1)
				res.addAll(l);
		}
		return(res);
	}
}
