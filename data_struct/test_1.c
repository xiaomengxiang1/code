// -----------------------时间复杂度---------------------
// 2.2 大 O 的渐进表示法
// 大 O 符号（Big O notation）：是用于描述函数渐进行为的数学符号。
// 推导大 O 阶方法：
// 1、用常数 1 取代运行时间中的所有加法常数。
// 2、在修改后的运行次数函数中，只保留最高阶项。(n^2 和 n 保留n^2)
// 3、如果最高阶项存在且不是 1(2n 3n 4n 0.5n)，则去除与这个项目相乘的常数，得到的结果就是大O 阶(n)。

// 计算Func4的时间复杂度？  复杂度为O(1)
// void Func4(int N)
// {
//     int count = 0;
//     for (int k = 0; k < 100; ++ k)
//     {
//         ++count;
//     }
//     printf("%d\n", count);
// }

// 当一个算法随着输入不同，时间复杂度不同，时间复杂度做悲观预期，看最坏的情况

// 二分查找
// 一个数组    元素个数N
// 查找一次得到N/2
// 最坏的情况 N/2/2/2/2... = 1 (找到了)    (假设查找了X次)
// N / (2^X) = 1
// 由此得到时间复杂度为 X = log N (2为底)

// 递归算法：递归次数*每次递归调用的次数


// 计算斐波那契递归Fib的时间复杂度？    复杂度O(2^N)
// long long Fib(size_t N)
// {
//     if(N < 3)
//         return 1;

//     return Fib(N-1) + Fib(N-2);
// }


// -----------------------空间复杂度---------------------
// 空间复杂度也是一个数学函数表达式，是对一个算法在运行过程中临时占用存储空间大小的量度。
// 空间复杂度不是程序占用了多少 bytes 的空间，因为这个也没太大意义，所以空间复杂度算的是变量的个数。
// 空间复杂度计算规则基本跟时间复杂度类似，也使用大 O 渐进表示法。
// 注意：函数运行时所需要的栈空间 (存储参数、局部变量、一些寄存器信息等) 在编译期间已经确定好了，
// 因此空间复杂度主要通过函数在运行时候显式申请的额外空间来确定。(变量开辟内存的个数)

// 空间可以重复利用，时间是累计的



// 数组 nums 包含从 0 到 n 的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。
// 你有办法在 O (n) 时间内完成吗？

// 示例 1:
// 输入：[3,0,1]
// 输出：2

// 示例 2:
// 输入：[9,6,4,2,3,5,7,0,1]
// 输出：8

// 思路1    qsort
// #include <stdio.h>
// #include <stdlib.h>
// int cmp(const void* e1, const void* e2) {
//     return (*(int*)e1 - *(int*)e2);
// }
// int main() {
//     int arr[] = {9,6,4,2,3,5,7,0,1};
//     //排序
//     qsort(arr, 9, sizeof(int), cmp);

//     int i = 0;
//     //遍历判断是否为前后差1
//     for (i = 0; i < 9 - 1; i++) {
//         if (arr[i] + 1 != arr[i+1]) {
//             printf("找到了：%d\n", i + 1);
//         }
//     }

//     for (i = 0; i < 9; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// 思路2 异或
// int missingNumber(int* nums, int numsSize) {
//     int x = 0;
//     //x和[0,n]异或
//     int i = 0;
//     for(i = 0; i < numsSize + 1; i++) {
//         x ^= i;
//     }
//     //x和nums异或
//     for (i = 0; i < numsSize; i++) {
//         x ^= nums[i];
//     }
//     return x;
// }

// 旋转数组
// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

// 进阶：
// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
// 你可以使用空间复杂度为 O (1) 的 原地 算法解决这个问题吗？

// 方法1 时间复杂度O（n*k）
// 空间复杂度O（1）
// #include <stdio.h>
// void reverse(int *arr, int sz, int n) {
//     n %= sz;
//     //每次移动1步,移动n次
//     int i = 0;
//     for (i = 0; i < n; i++) {
//         //移动1步
//         int tem = arr[sz - 1];
//         int j = 0;
//         for (j = sz - 1; j > 0; j--) {
//             arr[j] = arr[j-1];
//         }
//         arr[0] = tem;
//     }
// }

// int main() {
//     int arr[] = {1,2,3,4,5,6,7};
//     int n = 0;
//     scanf("%d", &n);

//     int sz = sizeof(arr) / sizeof(arr[0]); 
//     reverse(arr, sz, n);

//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// 方法2 空间换时间
// 额外开辟空间，将后k个放到前面，前面n - k个放后面
// O(sz)
// #include <stdio.h>
// #include <string.h>
// void reverse(int *arr, int sz, int n) {
//     if (n != 0) {
//         int arr_tem[sz];
//         n %= sz;
//         int i = 0;
//         int j = 0;
//         //后面n个放到另一个数组
//         for (i = sz-n; i < sz; i++) {
//             arr_tem[j++] = arr[i];
//         }
//         //前面几个
//         for (i = 0; i < sz - n; i++) {
//             arr_tem[j++] = arr[i];
//         }
//         //替换原数组内容
//         for (i = 0; i < sz; i++) {
//             arr[i] = arr_tem[i];
//         }
//     }
// }
// int main() {
//     int arr[] = {1,2,3,4,5,6,7};
//     int n = 0;
//     scanf("%d", &n);

//     int sz = sizeof(arr) / sizeof(arr[0]); 
//     reverse(arr, sz, n);

//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }


// 方法3 3次翻转
// 假设输入3
// 1 2 3 4 5 6 7
//翻转后面3个
// 1 2 3 4 7 6 5
//翻转前面几个
// 4 3 2 1 7 6 5
//整体翻转
// 5 6 7 1 2 3 4

// 时间复杂度：O(n)（每个元素最多被交换一次）
// 空间复杂度：O(1)（原地操作，无额外数组）
// void Reverse(int* nums, int left, int right) {
//     while (left < right) {
//         int tem = nums[left];
//         nums[left] = nums[right];
//         nums[right] = tem;

//         left++;
//         right--;
//     }
// }

// void rotate(int* nums, int num_size, int k) {
//     if (k != 0) {
//         k %= num_size;
//         Reverse(nums, num_size - k, num_size - 1);
//         Reverse(nums, 0, num_size - k - 1);
//         Reverse(nums, 0, num_size - 1);
//     }
// }


// -----------------------------------顺序表---------------------------------
// 顺序表
// 2.1 概念及结构
// 顺序表就是数组，但是在数组的基础上，它还要求数据是连续存储的，不能跳跃间隔
// 顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，
// 一般情况下采用数组存储。在数组上完成数据的增删查改。

// oj的分类和原理
// 1.接口型
// 2.io型

// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O (1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

// 27. 移除元素
// https://leetcode.cn/problems/remove-element/

// int removeElement(int* nums, int numsSize, int val) {
//     int src = 0;
//     int dst = 0;
//     while (src < numsSize) {
//         if (nums[src] != val) {
//             nums[dst] = nums[src];
//             dst++;
//             src++;
//         }
//         else {
//             src++;
//         }
//     }
//     return dst;
// }

// 26. 删除有序数组中的重复项
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
// int removeDuplicates(int* nums, int numsSize) {
//     if (numsSize == 0) {
//         return 0;
//     }
//     int i = 0;
//     int j = 0;
//     int dst = 0;
//     while (j < numsSize) {
//         if (nums[i] == nums[j]) {
//             ++j;
//         }
//         else {
//             nums[dst++] = nums[i];
//             i = j;
//             ++j;
//         }
//     }
//     nums[dst++] = nums[i];
//     return dst;
// }


// 88. 合并两个有序数组
// https://leetcode.cn/problems/merge-sorted-array/description/
// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//     int src_nums1 = m - 1;
//     int src_nums2 = n - 1;
//     int end = m + n - 1;
//     //保证nums2处理完,并且n是大于0的
//     while (src_nums2 >= 0) {
//         //确保src_nums1是大于0的，防止nums1先处理完导致数组越界
//         if (src_nums1 >= 0 && nums1[src_nums1] > nums2[src_nums2]) {
//             nums1[end] = nums1[src_nums1];
//             --end;
//             --src_nums1;            
//         }
//         else {
//             nums1[end] = nums2[src_nums2];
//             --end;
//             --src_nums2;
//         }
//     }
// }

// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//     int end1 = m - 1;
//     int end2 = n - 1;
//     int end = m + n - 1;
//     while (end1 >= 0 && end2 >= 0) {
//         if (nums1[end1] > nums2[end2]) {
//             nums1[end--] = nums1[end1--];
//         }
//         else {
//             nums1[end--] = nums2[end2--];
//         }
//     }
//     while (end2 >= 0) {
//         nums1[end--] = nums2[end2--];
//     }
// }


// -----------------------------------链表---------------------------------
// 顺序表缺陷：
// 1、空间不够了需要增容，增容是要付出代价
// 2、避免频繁扩容，我们满了基本都是扩 2 倍，可能就会导致一定的空间浪费
// 3、顺序表要求数据从开始位置连续存储，那么我们在头部或者中间位置插入删除数据就需要挪动数据，效率不高


// https://leetcode.cn/problems/remove-linked-list-elements/description/
// 203. 移除链表元素

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

// struct ListNode* removeElements(struct ListNode* head, int val) {
//     struct ListNode* prev = NULL;
//     struct ListNode* cur = head;
//     //遍历链表
//     while (cur) {
//         //如果找到val
//         if (cur->val == val) {
//             //头删
//             if (cur == head) {
//                 head = cur->next;
//                 free(cur);
//                 cur = head;
//             }
//             //中间删除
//             else {
//                 //改变两个指针的位置
//                 prev->next = cur->next;
//                 free(cur);
//                 cur = prev->next;
//             }
//         }
//         else {
//             //没有找到val
//             prev = cur;
//             cur = cur->next;
//         }
//     }
//     return head;
// }


// 快速调试
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
// #include <stdio.h>
// int main() {
//     struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     n1->val = 7;
//     n2->val = 7;
//     n3->val = 7;
//     n4->val = 7;
//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     n3->next = NULL;

//     strcut ListNode* head = removeElements(n1. 7);
// }


// 206. 反转链表
// https://leetcode.cn/problems/reverse-linked-list/description/
// 可以看成是对箭头的翻转
// struct ListNode* reverseList(struct ListNode* head) {
//     struct ListNode* prev = NULL;
//     struct ListNode* cur = head;
//     struct ListNode* temp = NULL;
//     while (cur) {
//         //存储cur下一个的地址
//         temp = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = temp;
//     }

//     return prev;
// }


// 876. 链表的中间结点
// https://leetcode.cn/problems/middle-of-the-linked-list/description/

// 时间复杂度为O(N)
// struct ListNode* middleNode(struct ListNode* head) {
//     int count = 0;
//     //记录总共的节点个数
//     struct ListNode* cur = head;
//     while (cur) {
//         count++;
//         cur = cur->next;
//     }
//     //找到中间的位置,并且计算出要走的步数
//     count = count / 2;
//     struct ListNode* pos = head;
//     while (count--) {
//         pos = pos->next;
//     }
//     return pos;
// }

// 只能遍历一次链表
// struct ListNode* middleNode(struct ListNode* head) {
//     //构造快慢指针，一个走一步，一个走两步，快的先走(n2)
//     struct ListNode* n1 = head;
//     struct ListNode* n2 = head;

//     while (n2->next && n2) {
//         n2 = n2->next->next;
//         n1 = n1->next;
//     }
//     return n1;
// }




// 描述
// 输入一个链表，输出该链表中倒数第 k 个结点。

// 示例 1
// 输入: 1,{1,2,3,4,5}
// 返回值: {5}

// 只能遍历一次链表
// 1、fast先走k步。
// 2、slow和fast再一起走，fast == NULL时，slow就是倒数第k个
// struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//     if (pListHead == NULL || k <= 0) {
//         return NULL;
//     }

//     struct ListNode* fast = pListHead;
//     struct ListNode* slow = pListHead;

//     // 快指针先走 k 步
//     for (int i = 0; i < k; i++) {
//         if (fast == NULL) {
//             return NULL;  // k 大于链表长度
//         }
//         fast = fast->next;
//     }

//      // 快慢指针同时前进
//     while (fast) {
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return slow;
// }

// 21. 合并两个有序链表
// https://leetcode.cn/problems/merge-two-sorted-lists/description/
// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//     //创建一个新的头节点new_node
//     struct ListNode new_node;
//     struct ListNode* p_new_node = &new_node;
//     new_node.next = NULL;
//     struct ListNode* cur_1 = list1;
//     struct ListNode* cur_2 = list2;

//     while (cur_2 && cur_1 ) {
//         //第二条小于第一条
//         if (cur_2->val <= cur_1->val) {
//             p_new_node->next = cur_2;
//             cur_2 = cur_2->next;
//         }
//         //反之
//         else {
//             p_new_node->next = cur_1;
//             cur_1 = cur_1->next;
//         }
//         p_new_node = p_new_node->next;
//     }
//     //cur_2没处理完
//     if (cur_2) {
//         p_new_node->next = cur_2;
//     }
//     else {
//         p_new_node->next = cur_1;
//     }
//     return new_node.next;
// }


//带哨兵位的头节点
// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//     if (list1 == NULL) {
//         return list2;
//     }
//     if (list2 == NULL) {
//         return list1;
//     }
//     //注意sizeof(struct ListNode)
//     struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* tail = head;

//     struct ListNode* l1 = list1;
//     struct ListNode* l2 = list2;
//     while (l1 && l2) {
//         if (l1->val < l2->val) {
//             tail->next = l1;
//             l1 = l1->next;
//         }
//         else {
//             tail->next = l2;
//             l2 = l2->next;
//         }
//         tail = tail->next;
//     }

//     if (l1) {
//         tail->next = l1;
//     }
//     else {
//         tail->next = l2;
//     }
//     struct ListNode* list = head->next;
//     free(head);
//     return list;
// }



// 描述
// 现有一链表的头指针 ListNode* pHead，给一定值 x，
// 编写一段代码将所有小于 x 的结点排在其余结点之前，
// 且不能改变原来的数据顺序，返回重新排列后的链表的头指针。


// 我们可以使用两个链表（虚拟头节点）：
// 一个链表存放 < x 的节点
// 另一个链表存放 >= x 的节点
// 最后把两个链表拼接起来，返回新的头结点

// struct ListNode* partition(struct ListNode* pHead, int x) {
//     if (pHead == NULL) {
//         return NULL;
//     }

//     struct ListNode* small_head = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* small_tail = small_head;
//     struct ListNode* big_head = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* big_tail = big_head;

//     struct ListNode* cur = pHead;

//     while (cur) {
//         struct ListNode* next = cur->next;
//         cur->next = NULL;  // ❗断开节点原来的连接，避免环
//         if (cur->val < x) {
//             small_tail->next = cur;
//             small_tail = cur;
//         } else {
//             big_tail->next = cur;
//             big_tail = cur;
//         }
//         cur = next;
//     }

//     // 拼接两个链表
//     small_tail->next = big_head->next;

//     struct ListNode* new_head = small_head->next;
//     free(small_head);
//     free(big_head);
//     return new_head;
// }

//避免死循环还可以在结尾处理big_tail的指向，使其指向NULL
// big_tail->next = NULL；


// 234. 回文链表
// https://leetcode.cn/problems/palindrome-linked-list/description/
// 自己的写法时间O(n)空间复杂度O(n)
// bool isPalindrome(struct ListNode* head) {
//     //倒置链表，使用带有哨兵位的头节点
//     struct ListNode* rev_head = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* cur = head;
//     //头插
//     while (cur) {
//         //直接创建新的节点存储cur节点的值比较方便
//         struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
//         new_node->val = cur->val;
//         new_node->next = rev_head->next;
//         rev_head->next = new_node;
//         cur = cur->next;
//     }
//     //重置节点位置
//     cur = head;
//     struct ListNode* free_rev_head = rev_head;
//     rev_head = rev_head->next;
//     free(free_rev_head);
//     while (cur) {
//         if (cur->val != rev_head->val) {
//             return false;
//         }
//         cur = cur->next;
//         struct ListNode* free_rev_head = rev_head;
//         rev_head = rev_head->next;
//         free(free_rev_head);
//     }
//     return true;
// }

// 时间O(n)空间复杂度O(1)
// 思路2，先找到链表的中间点，然后对链表中间点之后的进行翻转，最后重新从中间和开头进行比较


// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
// 160. 相交链表

// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//     struct ListNode* curA = headA;
//     struct ListNode* curB = headB;
//     //记录节点个数
//     int countA = 0;
//     int countB = 0;
//     //找到尾部节点，对比地址
//     while (curA->next) {
//         countA++;
//         curA = curA->next;
//     }
//     while (curB->next) {
//         countB++;
//         curB = curB->next;
//     }
//     //不相等返回NULL
//     if (curA != curB) {
//         return NULL;
//     }
//     //重置节点
//     curA = headA;
//     curB = headB;
//     //A > B , A先走A - B 步
//     int i = 0;
//     if (countA >= countB) {
//         for (i = 0; i < countA - countB; i++) {
//             curA = curA->next;
//         }
//     }
//     else {
//         for (i = 0; i < countB - countA; i++) {
//             curB = curB->next;
//         }
//     }
//     //同步走
//     while (curA != curB) {
//         curA = curA->next;
//         curB = curB->next;
//     }
//     return curA;
// }

// 141. 环形链表
// https://leetcode.cn/problems/linked-list-cycle/
// bool hasCycle(struct ListNode *head) {
//     if (head == NULL || head->next == NULL) {
//         return false;
//     }
//     //快慢指针,一个一步，一个两步
//     struct ListNode* fast = head;
//     struct ListNode* slow = head;
    
//     while (fast && fast->next) {
//         fast = fast->next->next;
//         slow = slow->next;
//         //两个节点的地址是否相等
//         if (fast == slow) {
//             return true;
//         }
//     }
//     return false;
// }

// 142. 环形链表 II
// https://leetcode.cn/problems/linked-list-cycle-ii/description/

// 从头到入环点为L
// 假设入环点到相遇点为X
// C为环的长度

// 追上相遇的过程中
// 慢指针走的距离：L+X
// 快指针走的距离：L+N*C+X (N>= 1)
// N 是他们相遇之前，fast 在环里面走的圈数

// 快指针走的路程是慢指针的 2 倍
// 2 (L+X) = L+NC+X
// L+X = NC
// L = N*C - X
// L = (N-1)*C + C-X
// 得证从相遇点开始到入环点与L是等长的

// struct ListNode *detectCycle(struct ListNode *head) {
//     //先写出判断有没有环的逻辑
//     struct ListNode* fast = head;
//     struct ListNode* slow = head;
//     struct ListNode* cur = head;
//     while (fast && fast->next) {
//         fast = fast->next->next;
//         slow = slow->next;
//         //相遇
//         if (fast == slow) {
//             //使slow和cur同时开始走，相遇点就是入环点
//             while (cur != slow) {
//                 cur = cur->next;
//                 slow = slow->next;
//             }
//             return cur;
//         }
//     }
//     return NULL;
// }


// struct ListNode *detectCycle(struct ListNode *head) {
//     struct ListNode* fast = head;
//     struct ListNode* slow = head;
//     struct ListNode* cur = head;
//     int cur_d = 0;
//     int slow_d = 0;
//     while (fast && fast->next) {
//         fast = fast->next->next;
//         slow = slow->next;
//         //相遇
//         if (fast == slow) {
//             slow = slow->next;
//             struct ListNode* new_slow = slow;
//             fast->next = NULL;
//             //断开环
//             //分别计算两条路的长度，然后求交点
//             while (cur) {
//                 cur_d++;
//                 cur = cur->next;
//             }
//             while (slow) {
//                 slow_d++;
//                 slow = slow->next;
//             }

//             int len = abs(cur_d - slow_d);
//             //重置节点到原来的位置
//             cur = head;
//             //比较长度,长度大的先走
//             slow = new_slow;
//             if (cur_d > slow_d) {
//                 while (len--) {
//                     cur = cur->next;
//                 }
//             }
//             else {
//                 while (len--) {
//                     slow = slow->next;
//                 }
//             }
//             //同步走，地址相同点为交点
//             while (cur != slow) {
//                 cur = cur->next;
//                 slow = slow->next;
//             }
//             return cur;
//         }
//     }
//     return NULL;
// }

//计算完长度一定要重置节点
// 也可以不剪断环来计算长度，在cur和slowc再次遇到meetpoint的过程计算长度就好了，这样不用直接剪断了


// 138. 随机链表的复制
// https://leetcode.cn/problems/copy-list-with-random-pointer/description/
// 因为现在你知道 A' 在 A 后面，A.random 是 R，那 A'.random 就是 R.next(A.random.next)
// struct Node* copyRandomList(struct Node* head) {
//     if (head == NULL) return NULL;
//     struct Node* cur = head;
// 	//1.复制节点到原来的节点和下一个节点之间
//     while (cur) {
//         //开辟新的节点,与原来的链表链接
//         struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//         new_node->val = cur->val;
//         new_node->next = cur->next;
//         cur->next = new_node;

//         cur = new_node->next;
//     }
// 	//2.复制random的指向
//     cur = head;
//     while (cur) {
//         if (cur->random) {
//             cur->next->random = cur->random->next;
//         }
//         else {
//             cur->next->random = NULL;
//         }
//         cur = cur->next->next;
//     }
// 	//3.将原链表进行拆分
//     cur = head;
//     struct Node* new_head = cur->next;
//     struct Node* tail = new_head;
//     while (cur) {
//         cur->next = tail->next;
//         cur = cur->next;
//         //先跟新cur的位置cur为NULL,则改变tail的指向
//         if (cur) {
//             tail->next = cur->next;
//             tail = tail->next;
//         }
//         else {
//             tail->next = NULL;
//         }
//     }
//     return new_head;
// }



// -----------------------------------双向链表---------------------------------
// 双向链表Doubly Linked List
// 双向链表是一种比单向链表更灵活的链表结构，
// 每个节点除了有一个 next 指针指向下一个节点之外，还有一个 prev 指针指向前一个节点
// NULL ← A ⇄ B ⇄ C → NULL(也可以前后链接变成环)






