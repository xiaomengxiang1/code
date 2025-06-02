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


