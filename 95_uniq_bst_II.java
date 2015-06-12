/*
 * vim: ts=4 sts=4 sw=4 et
 */
import java.util.*;

class TreeNode {
    int	val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<TreeNode> generateTrees(int n) {
        return do_gen(1, n);
    }

    private List<TreeNode> do_gen(int start, int end) {
        List<TreeNode> roots = new LinkedList<>();

        if (start > end) {
            roots.add(null);
            return roots;
        }

        for (int i = start; i <= end; i++) {
            List<TreeNode> left = do_gen(start, i - 1);
            List<TreeNode> right = do_gen(i + 1, end);
            Iterator<TreeNode> iterL = left.iterator();
            while (iterL.hasNext()) {
                TreeNode nodeL = iterL.next();
                Iterator<TreeNode> iterR = right.iterator();
                while (iterR.hasNext()) {
                    TreeNode node = new TreeNode(i);
                    node.left = nodeL;
                    node.right = iterR.next();
                    roots.add(node);
                }
            }
        }

        return roots;
    }
}
