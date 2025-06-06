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

//销毁一颗树
void DestoryTree(BTNode* root) {
    if (root == NULL) {
        return;
    }
    DestoryTree(root->left);
    DestoryTree(root->right);
    free(root);
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


//二叉树第k层的节点的个数
//如第三层的节点个数，可以看(成以第二层为根节点)的第二层,可以看(成以第三层为根节点)的第一层
//如果一直递归下去直到第一层，就可以判断第一层是不是为空，如果为空，则返回0，否则返回1
int BinaryTreeLevelKSize(BTNode* root, int k) {
    if (root == NULL) {
        return 0;
    }
    if (k == 1) {
        return 1;
    }
    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//查找二叉树中值为x的节点
BTNode* BinaryTreeFind(BTNode* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == x) {
        return root;
    }
    // 递归查找左子树
    BTNode* left = BinaryTreeFind(root->left, x);
    if (left) return left;

    BTNode* right = BinaryTreeFind(root->right, x);
    if (right) return right;

    return NULL;
}

// 先根遍历
void PrevOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    printf("%c ", root->data);
    PrevOrder(root->left);
    PrevOrder(root->right);
}

// 中根遍历
void InOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}

// 后根遍历
void PostOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);
}

//层序遍历
//采用队列,根节点入队，出队的同时带入左右孩子，左右孩子重复改操作
//直到队列为空
// void BinaryTreeLevelOrder(BTNode* root) {
//     Queue q;
//     QueueInit(&q);
//     if (root == NULL) {
//         return;
//     }
//     QueuePush(&q, root);
//     while (!QueueEmpty(&q)) {
//         BTNode* front = QueueFront(&q);
//         QueuePop(&q);
//         printf("%c ", front->data);

//         if (front->left) {
//             QueuePush(&q, front->left);
//         }
//         if (front->right) {
//             QueuePush(&q, front->right);
//         }
//     }
//     QueueDestory(&q);
//     printf("\n");
// }


//判断一棵树是否是完全二叉树
//使用队列,当出队的数据不为空的时候进行另一个判断，若果还有不为空的数据就直接返回0
// int BinaryTreeComplete(BTNode* root) {
//     Queue q;
//     QueueInit(&q);
//     if (root == NULL) {
//         return 1;
//     }
//     QueuePush(&q, root);
//     while (!QueueEmpty(&q)) {
//         BTNode* front = QueueFront(&q);
//         QueuePop(&q);

//         if (front == NULL)
//             break; 
//         QueuePush(&q, front->left);
//         QueuePush(&q, front->right);

//     }
//     // 一旦遇到 NULL 节点，后续必须全是 NULL，才能算完全二叉树
//     while (!QueueEmpty(&q)) {
//         BTNode* front = QueueFront(&q);
//         QueuePop(&q);

//         if (front != NULL) {
//             QueueDestory(&q);
//             return 0;
//         }
//     }
    
//     QueueDestory(&q);
//     return 1;
// }

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
    printf("KTreeSize:%d\n", BinaryTreeLevelKSize(A, 2));

    getchar();
    return 0;
}