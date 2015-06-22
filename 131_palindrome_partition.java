/*
 * wrong answer because of misunderstanding of problem
 *
import java.util.*;

class Solution {
    private List<List<String>>  result;
    private Collection<String>  a_part;
    private List<Node>          partitions;

    private class Node {
        public int start;
        public int length;
        public Node(int start, int length) {
            this.start = start;
            this.length = length;
        }
    }

    public List<List<String>> partition(String s) {
        result = new LinkedList<>();
        if (s.length() == 0)
            return(result);

        partitions = new LinkedList<>();
        Node node = new Node(0, 1);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i -1)) {
                node.length++;
            } else {
                partitions.add(node);
                node = new Node(i, 1);
            }
        }
        partitions.add(node);

        a_part = new LinkedList<String>();
        do_partitioning(s, 0);
        return(result);
    }
    private void do_partitioning(String s, int part_num) {
        if (part_num >= partitions.size()) {
            result.add(new LinkedList<String>(a_part));
            return;
        }

        Node node = partitions.get(part_num);

        if (node.length == 0) {
            do_partitioning(s, part_num + 1);
            return;
        }

        int length = node.length;
        for (int i = 1; i <= length; i++) {
            String substr = s.substring(node.start, node.start + i);
            a_part.add(substr);
            node.length -= i;
            do_partitioning(s, part_num);
            a_part.remove(substr);
            node.length += i;
        }
        return;
    }

    public static void main(String[] args) {
        List<List<String>> list = new Solution().partition("aab");
    }
}
*/

import java.util.*;

class Solution {
    private LinkedList<List<String>>  result;
    private LinkedList<String>        partitions;
    public List<List<String>> partition(String s) {
        result = new LinkedList<>();
        if (s.length() == 0)
            return(result);

        partitions = new LinkedList<>();
        do_partitioning(s, 0);
        return(result);
    }

    private void do_partitioning(String s, int start) {
        if (start >= s.length()) {
            List<String> list = new LinkedList<>();
            for (int i = 0; i < partitions.size(); i++)
                list.add(partitions.get(i));
            result.add(list);
            return;
        }

        for (int i = 1; (start + i) <= s.length(); i++) {
            if (is_palind(s, start, i)) {
                String substr = s.substring(start, start + i);
                partitions.add(substr);
                do_partitioning(s, start + i);
                partitions.removeLast();
            }
        }
    }

    private boolean is_palind(String s, int start, int length) {
        for (int i = start; i < (start + length / 2); i++)
            if (s.charAt(i) != s.charAt(2 * start + length - i - 1))
                    return(false);
        return(true);
    }

    public static void main(String[] args) {
        List<List<String>> list = new Solution().partition("cbbbcc");
        for (int i = 0; i < list.size(); i++)
            System.out.println(list.get(i));

    }
}
