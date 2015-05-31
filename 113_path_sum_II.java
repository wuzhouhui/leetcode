import java.util.*;

class TreeNode {
	int	val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
	private List<List<Integer>> pathList = new LinkedList<List<Integer>>();

	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		if (root == null)
			return pathList;
		List<Integer> list = new LinkedList<Integer>();
		privatePathSum(root, sum, 0, list);
		return pathList;
	}

	private void privatePathSum(TreeNode root, int sum, int curr_sum,
			List<Integer> list) {
		if (root == null)
			return;
		if (isLeaf(root)) {
			if (sum == (curr_sum + root.val)) {
				List<Integer> l = new LinkedList<Integer>(list);
				l.add(root.val);
				pathList.add(l);
			}
			return;
		}
		list.add(root.val);
		curr_sum += root.val;
		if (root.left != null)
			privatePathSum(root.left, sum, curr_sum, list);
		if (root.right != null)
			privatePathSum(root.right, sum, curr_sum, list);
		list.remove(list.size() - 1);
	}

	private boolean isLeaf(TreeNode node) {
		if (node.left == null && node.right == null)
			return true;
		else
			return false;
	}
}
