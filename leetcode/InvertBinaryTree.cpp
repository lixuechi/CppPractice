/* Invert a binary tree. 
     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *lChild, TreeNode *rChild):val(x), left(lChild), right(rChild) {}
};

TreeNode* invertTree(TreeNode* root) {
	if(root == NULL) return NULL;

	TreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;

	invertTree(root->left);
	invertTree(root->right);

	return root;
}

void testInvertTree(TreeNode *root) {
	cout << root->val;
	if(root->left != NULL) {
		cout << "left: " << root->left->val << endl;
		testInvertTree(root->left);
	} 
	if(root->right != NULL) {
		cout << "right: " << root->right->val << endl;
		testInvertTree(root->right);
	}
}

int main() {
	TreeNode t1(1);
	TreeNode t3(3);
	TreeNode t6(6);
	TreeNode t9(9);
	TreeNode t2(2, &t1, &t3);
	TreeNode t7(7, &t6, &t9);
	TreeNode t4(4, &t2, &t7);

	invertTree(&t4);
	testInvertTree(&t4);

	return 0;
}
