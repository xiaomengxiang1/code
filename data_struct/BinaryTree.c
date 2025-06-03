#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode {
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

//创建节点
BTNode* CreatBTNode(char x) {
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->data = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

//树的节点数量
//若节点不为空，则至少有本节点(1)加上左树和右树的节点数
int TreeSize(BTNode* root) {
    if (root == NULL)
        return 0;
    else 
        return 1 + TreeSize(root->left) + TreeSize(root->right);
}

//叶子数量  树的叶子数量为左树和右树的和,是否为叶子取决于树的子节点是否为空
int TreeLeafSize(BTNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//树的深度
//深度较高的左或者右数 + 1
int TreeDepth(BTNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left_tree_depth = TreeDepth(root->left);
    int right_tree_depth = TreeDepth(root->right);
    return (left_tree_depth > right_tree_depth ? left_tree_depth : right_tree_depth) + 1;
}

void PrevOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    printf("%c ", root->data);
    PrevOrder(root->left);
    PrevOrder(root->right);
}

void InOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}

void PostOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);
}

int main() {
    BTNode* A = CreatBTNode('A');
    BTNode* B = CreatBTNode('B');
    BTNode* C = CreatBTNode('C');
    BTNode* D = CreatBTNode('D');
    BTNode* E = CreatBTNode('E');
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    // 先根遍历
    PrevOrder(A);
    printf("\n");
    // 中根遍历
    InOrder(A);
    printf("\n");
    // 后根遍历
    PostOrder(A);
    printf("\n");

    printf("TreeSize:%d\n", TreeSize(A));
    printf("TreeLeafSize:%d\n", TreeLeafSize(A));
    printf("TreeDepth:%d\n", TreeDepth(A));
    getchar();
    return 0;
}