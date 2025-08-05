//
// Created by mE on 05/08/2025.
//

#ifndef BST_H
#define BST_H

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr);
};

class BST {
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value);
    TreeNode* findMin(TreeNode* node);

    TreeNode* deleteNode(TreeNode* node, int value);

    void inorder(TreeNode* node);
    void preorder(TreeNode *node);
    void postorder(TreeNode* node);

public:
    BST();

    void insert(int value);
    void remove(int value);
    void display_inorder();
    void display_preorder();
    void display_postorder();

};

#endif //BST_H
