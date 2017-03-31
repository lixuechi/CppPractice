/* Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
   According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
   between two nodes v and w as the lowest node in T that has both v and w as descendants 
   (where we allow a node to be a descendant of itself).”   */
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int pDiff = p->val - root->val;
	int qDiff = q->val - root->val;

	if(pDiff == 0 || qDiff == 0 || pDiff * qDiff < 0) return root;
	if(pDiff > 0 && qDiff > 0) return lowestCommonAncestor(root->right, p, q); 
	else if(pDiff < 0 && qDiff < 0) return lowestCommonAncestor(root->left, p, q);
}

int main() {
	TreeNode t3(3);
	TreeNode t5(5);
	TreeNode t4(4, &t3, &t5);
	TreeNode t0(0);
	TreeNode t2(2, &t4, &t3);
	TreeNode t7(7);
	TreeNode t9(9);
	TreeNode t8(8, &t7, &t9);
	TreeNode t6(6, &t2, &t8);

	cout << lowestCommonAncestor(&t6, &t2, &t8)->val << endl;
	cout << lowestCommonAncestor(&t6, &t2, &t4)->val << endl;
	cout << lowestCommonAncestor(&t6, &t0, &t4)->val << endl;
	cout << lowestCommonAncestor(&t6, &t2, &t3)->val << endl;
	cout << lowestCommonAncestor(&t6, &t5, &t2)->val << endl;

	return 0;
}
