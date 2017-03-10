/**
 Given two binary trees, write a function to check if they are equal or not.
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <list>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
	/* my solution
	if(p == NULL && q == NULL) {
		return true;
	} else if(p == NULL || q == NULL) {
		return false;
	}
	if((*p).val == (*q).val) {
		isSameTree((*p).left, (*q).left);
		isSameTree((*p).right, (*q).right);
	}
	*/
	/* better solution */
	if(p == NULL || q == NULL) return (p == q);
	return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main() {

	return 0;
} 
