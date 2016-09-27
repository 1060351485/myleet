// need to pratice more on this kind of problem

vector<TreeNode*> generateTrees(int n) {
	if (n == 0) return generateTrees(1, 0);
	return generateTrees(1, n);
}

vector<TreeNode*> generateTrees(int start, int end) {
	vector<TreeNode*> subtree;
	if (start > end){
		subtree.push_back(NULL);
		return subtree;
	}
	for (int k = start; k <= end; k++){
		vector<TreeNode*> leftTree = generateTrees(start, k-1);
		vector<TreeNode*> rightTree = generateTrees(k+1, end);
		for (int i = 0; i < leftTree.size(); i++){
			for (int j = 0; j < rightTree.size(); j++) {
				TreeNode *node = new TreeNode(k);
				node->left = leftTree[i];
				node->right = rightTree[j];
				subtree.push_back(node);
			}
		}
	}
	return subtree;
}
