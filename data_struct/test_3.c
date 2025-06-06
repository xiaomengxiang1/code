// 节点的度：一个节点含有的子树的个数称为该节点的度；如上图：A 的为 6 
// 叶节点或终端节点：度为 0 的节点称为叶节点；如上图：B、C、H、I… 等节点为叶节点 
// 非终端节点或分支节点：度不为 0 的节点；如上图：D、E、F、G… 等节点为分支节点
// 双亲节点或父节点：若一个节点含有子节点，则这个节点称为其子节点的父节点；如上图：A 是 B 的父节点
// 孩子节点或子节点：一个节点含有的子树的根节点称为该节点的子节点；如上图：B 是 A 的孩子节点 
// 兄弟节点：具有相同父节点的节点互称为兄弟节点；如上图：B、C 是兄弟节点 
// 树的度：一棵树中，最大的节点的度称为树的度；如上图：树的度为 6
// 节点的层次：从根开始定义起，根为第 1 层，根的子节点为第 2 层，以此类推；
// 树的高度或深度：树中节点的最大层次；如上图：树的高度为 4 


// 完全二叉树:
// 前 k - 1 层都是满的，最后可以不满
// 必须左到右连续

// 树
// 二叉树
// 完全二叉树
// 满二叉树

// 若规定根节点的层数为 1，则一棵非空二叉树的第 i 层上最多有 2^(i - 1) 个结点.
// 若规定根节点的层数为 1，则深度为 h 的二叉树的最大结点数是 2^h - 1(总的节点数)
// 对任何一棵二叉树，如果度为 0 其叶结点个数为 n0，度为 2 的分支结点个数为 n2，则有 n0 = n2 + 1

// 完全二叉树:
// 度为0的节点 x
// 度为2的节点 x - 1
// 度为1的节点 只能是1或者0

// 所以x + x - 1 (加1或者0) = 总的节点数

    // 满二叉树有 n 个节点，那它的深度 d 为：
    // d=log 2 (n + 1)

    // 完全二叉树的深度
    // d=⌊log 2(n)⌋+1

// ----------------------------------堆-----------------------------
// 大堆：
// 1、完全二叉树
// 2、每个父亲都大于等于孩子

// 小堆：
// 1、完全二叉树
// 2、每个父亲都小等于孩子

// 选数
// 大堆特点：根 (堆顶) 就是最大值
// 选数
// 大堆特点：根 (堆顶) 就是最大值

// 父节点下标：parent(i) = (i - 1) / 2
// 左孩子下标：left(i) = 2 * i + 1
// 右孩子下标：right(i) = 2 * i + 2

//向下调整算法
// void Swap(HpDataType* e1, HpDataType* e2) {
//     HpDataType tmp = *e1;
//     *e1 = *e2;
//     *e2 = tmp;
// }

// void adjust(HpDataType* a, int n, int root) {
//     int parent = root;
//     int child = parent * 2 + 1; 
//     //找出最小的孩子
//     while (child < n) {
//         if (child + 1 < n && [child + 1] < a[child]) {
//             ++child;
//         }
//         //如果孩子小于父亲就交换,大于就说明完成
//         if (a[child] < a[parent]) {
//             Swap(&a[child], &a[parent]);
//             parent = child;
//             child = parent * 2 + 1;
//         }
//         else {
//             break;
//         }
//     }
// }

// 小堆选出最小的，和数组的最后的值进行互换，然后再次建堆，数据个数为n - 1，就可以选出次小的值
// 排完序就可以得到降序的数组，排升序相反就可以采用大堆，时间复杂度为 N * logN

// 排列升序：使用大堆
// 排列降序：使用小堆

// TOPK问题

// 在 N 个数中找出最大的或最小的前 K 个，用什么方法？
// 正确答案：建小堆！
// 原理：
// 建一个 K 个元素的小堆（最小堆）。
// 堆顶是当前 K 个数中最小的那个。
// 遍历后面数据时：
// 如果比堆顶大，就把堆顶踢出去，换新数据进来；
// 否则不变。
// 这样：
// 最终堆里就保留了 最大的 K 个数，而且堆顶是 K 个里最小的，方便下一轮判断！

// 最小k个数
// https://leetcode.cn/problems/smallest-k-lcci/description/
// void Swap(int* e1, int* e2) {
//     int tmp = *e1;
//     *e1 = *e2;
//     *e2 = tmp;
// }

// void AdjustDown(int* a, int n, int root) {
//     int parent = root;
//     int child = parent * 2 + 1; // 左孩子
//     while (child < n) {
//         //找大的孩子
//         if (child + 1 < n && a[child + 1] > a[child]) {
//             ++child;
//         }
//         if (a[child] > a[parent]) {
//             Swap(&a[child], &a[parent]);
//             parent = child;
//             child = parent * 2 + 1;
//         }
//         else {
//             break;
//         }
//     }
// }

// int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
//     if (k == 0 || arrSize == 0) {
//         *returnSize = 0;
//         return NULL;
//     }
//     //建堆(以前k个为大堆)
//     int* a = (int*)malloc(sizeof(int) * k);
//     int i = 0;
//     for (i = 0; i < k; i++) {
//         a[i] = arr[i];
//     }
//     for (i = (k - 1 - 1) / 2; i >= 0; i--) {
//         AdjustDown(a, k, i);
//     }
//     //遍历剩下的数据,若小于堆顶则替换堆顶，并进行向下调整
//     for (i = k; i < arrSize; i++) {
//         if (arr[i] < a[0]) {
//             a[0] = arr[i];
//             AdjustDown(a, k, 0);
//         }
//     }
//     *returnSize = k;
//     return a;
// }



// ----------------------------------链式二叉树-----------------------------

        //     A  
        //    / \  
        //   B   C
        //  / \    
        // D   E 
// 遍历二叉树有4种遍历：前序，中序，后序，层序
// 前序，中序，后序为深度优先   层序为广度优先

// 将任何一颗一颗二叉树看成3个部分(分析的时候要以树为一个单位)
// 1.根节点     2.左子树    3.右子树

// 前序：(先根遍历) 根 左子树 右子树
// A B D NULL NULL E NULL NULL C NULL NULL 
// 中序：(中根遍历) 左子树 根 右子树
// NULL D NULL B NULL E NULL A NULL C NULL
// 后序：(后根) 左子树 右子树 根
// NULL NULL D NULL NULL E B NULL NULL C A
// 层序：
// A B C D E NULL NULL NULL NULL NULL NULL

// int TreeDepth(BTNode* root) {
//     if (root == NULL)
//         return 0;

//     int leftDepth = TreeDepth(root->left);
//     int rightDepth = TreeDepth(root->right);

//     return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
// }


// 二叉树的思路还是递归
// 1.将大问题化为子问题
// 2.返回条件（子问题不能继续缩小了）

// 144. 二叉树的前序遍历
// https://leetcode.cn/problems/binary-tree-preorder-traversal/

//先求出树的大小并开辟空间，然后再写一个函数前序遍历，可以用returnSize控制数组的下标,
//或者用新的i传入

// int TreeSize(struct TreeNode* root) {
//     if (root == NULL) 
//         return 0;
//     else
//         return 1 + TreeSize(root->left) + TreeSize(root->right);
// }

// void PrevOrder(struct TreeNode* root, int* returnSize, int* a) {
//     if (root == NULL) return;
//     a[(*returnSize)++] = root->val;
//     PrevOrder(root->left, returnSize, a);
//     PrevOrder(root->right, returnSize, a);
// }

// int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//     int size = TreeSize(root);
//     int* a = malloc(sizeof(int) * size);
//     //returnSize初始值手动赋值为0
//     *returnSize = 0;
//     PrevOrder(root, returnSize, a);
//     return a;
// }


// 965. 单值二叉树
// https://leetcode.cn/problems/univalued-binary-tree/description/

// void prev_order(struct TreeNode* root, int val, int* i) {
//     if (root == NULL) {
//         return;
//     }
//     //比较值是否不一样
//     if (root->val != val) {
//        *i = 0;
//        return;
//     }
//     prev_order(root->left, val, i);
//     prev_order(root->right, val, i);
// }

// bool isUnivalTree(struct TreeNode* root) {
//     //记录根的值，传入一个值记录是否是单值二叉树，开始时为1默认是
//     //然后前序遍历二叉树,若和根不同直接改变i的值
//     int val = root->val;
//     int i = 1;
//     prev_order(root, val, &i);

//     return i;
// }


//写法2
// bool isUnivalTree(struct TreeNode* root) {
//     if (root == NULL)
//         return true;

//     // 判断当前节点是否与左子节点相等
//     if (root->left && root->val != root->left->val)
//         return false;

//     // 判断当前节点是否与右子节点相等
//     if (root->right && root->val != root->right->val)
//         return false;

//     // 递归判断左右子树是否满足单值要求
//     return isUnivalTree(root->left) && isUnivalTree(root->right);
// }


// 将问题分解成左右树，左右树最小单位来看

// 104. 二叉树的最大深度
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
// int maxDepth(struct TreeNode* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     int left_depth = maxDepth(root->left);
//     int right_depth = maxDepth(root->right);
//     return 1 + (left_depth > right_depth ? left_depth : right_depth);
// }

// 226. 翻转二叉树
// https://leetcode.cn/problems/invert-binary-tree/description/

// struct TreeNode* invertTree(struct TreeNode* root) {
//     //分别翻转左右树的分支，直接改变分支的指向，不该从值入手
//     if (root == NULL) {
//         return NULL;
//     }

//     struct TreeNode* left_next = invertTree(root->left);
//     struct TreeNode* right_next = invertTree(root->right);
//     root->left = right_next;
//     root->right = left_next;

//     return root;
// }

// 100. 相同的树
// https://leetcode.cn/problems/same-tree/description/

// bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//     //同时遍历两颗树，判断值是否相等,值相当就向下递归
//     if (p == NULL && q == NULL) {
//         return true;
//     }
//     //判断两个根是否都存在
//     if (p == NULL && q != NULL) {
//         return false;
//     }
//     if (p != NULL && q == NULL) {
//         return false;
//     }
//     if (p->val == q->val) {
//         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//     }
//     else {
//         return false;
//     }
// }


// 101. 对称二叉树
// bool IsMirror(struct TreeNode* q, struct TreeNode* p) {
//     if (q == NULL && p == NULL) {
//         return true;
//     }
//     if (q == NULL || p == NULL) {
//         return false;
//     }
//     if (q->val == p->val) {
//         return IsMirror(q->left, p->right) && IsMirror(q->right, p->left);
//     }
//     else {
//         return false;
//     }
// }
// bool isSymmetric(struct TreeNode* root) {
//     if (root == NULL) {
//         return true;
//     }
//     return IsMirror(root->left, root->right);
// }

// 572. 另一棵树的子树
// https://leetcode.cn/problems/subtree-of-another-tree/
// bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//     //前序遍历节点,比较每一颗树,如果一棵树相等，则返回true
//     if (root == NULL) {
//         return false;
//     }
//     if (is_same_tree(root, subRoot)) {
//         return true;
//     }
//     return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
// }


// 110. 平衡二叉树
// https://leetcode.cn/problems/balanced-binary-tree/description/

// 时间复杂度O(N * N)
//一颗树的高度
// int Treehigh(struct TreeNode* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     int tree_left = Treehigh(root->left);
//     int tree_right = Treehigh(root->right);
//     return (tree_left > tree_right ? tree_left : tree_right) + 1;
// }

// bool isBalanced(struct TreeNode* root) {
//     if (root == NULL) {
//         return true;
//     }
//     if (abs(Treehigh(root->left) - Treehigh(root->right)) <= 1) {
//         return isBalanced(root->left) && isBalanced(root->right);
//     }
//     else {
//         return false;
//     }
// }

// 时间复杂度O(N)
// int check_heigh(struct TreeNode* root) {
//     if (root == NULL) 
//         return 0;
    
//     int left_heigh = check_heigh(root->left);
//     if (left_heigh == -1) 
//         return -1;

//     int right_heigh = check_heigh(root->right);
//     if (right_heigh == -1) 
//         return -1;

//     if (abs(left_heigh - right_heigh) > 1)
//         return -1;

//     return (left_heigh > right_heigh ? left_heigh : right_heigh) + 1;
// }

// bool isBalanced(struct TreeNode* root) {
//     return check_heigh(root) != -1;
// }


// 二叉树遍历
// https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpl=60&&tqId=294838&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
// #include <stdio.h>

// typedef struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// }TreeNode;

// TreeNode* CreatTree(char* str, int* i) {
//     if (str[*i] == '#') {
//         (*i)++;
//         return NULL;
//     }
//     else {
//         TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
//         root->val = str[*i];

//         (*i)++;
//         root->left = CreatTree(str, i);
//         root->right = CreatTree(str, i);

//         return root;
//     }
// }

// void Inorder(TreeNode* root) {
//     if (root == NULL)
//         return;

//     Inorder(root->left);
//     printf("%c ", root->val);
//     Inorder(root->right);
// }

// int main() {
//     char str[100];
//     scanf("%s", str);
//     int i = 0;
//     TreeNode* root = CreatTree(str, &i);
//     Inorder(root);

//     return 0;
// }


