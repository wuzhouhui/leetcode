import java.util.*;

class TreeNode {
	int	val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
	public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> res = new LinkedList<Integer>();

		if (root == null)
			return res;
		if (root.left == null && root.right == null) {
			res.add(root.val);
			return res;
		}

		pre_trav(root, res);

		return res;
	}

	private void pre_trav(TreeNode root, List<Integer> res) {
		if (root == null)
			return;
		res.add(root.val);
		pre_trav(root.left, res);
		pre_trav(root.right, res);
	}
}
