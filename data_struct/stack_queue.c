// -----------------------------------栈---------------------------------
// 栈的定义：栈是一种特殊的线性表 ，它限定仅在固定的一端进行插入和删除元素操作。
// 进行插入（压栈）和删除（出栈）操作的一端是栈顶，另一端是栈底 。
// 数据元素遵循后进先出（LIFO，Last In First Out ）原则，就像往弹夹里压子弹，最后压进去的子弹会最先被打出来。

// 压栈：也叫进栈、入栈 ，是将数据存入栈的操作，新数据存入栈顶位置 。

// 出栈：是从栈中取出数据的操作，从栈顶取出数据 。 栈在程序设计中应用广泛，
// 比如函数调用栈，用于管理函数调用时的局部变量、返回地址等信息 。

// ------------------------
// |       栈
// -------------------------

// 20. 有效的括号
// https://leetcode.cn/problems/valid-parentheses/description/
// 每当遇到左括号，就压栈；
// 遇到右括号，就检查栈顶是否是对应的左括号
// 是就弹出
// 不是就是非法
// 最终如果栈为空，说明全部匹配成功！

// bool isValid(char* s) {
//     ST st;
//     StackInit(&st);
//     //压栈
//     while (*s) {
//         //左括号
//         if (*s == '(' || *s == '[' || *s == '{') {
//             StackPush(&st, *s);
//             s++;
//         }
//         else {
//             //遇到右括号,但是栈内没有数据
//             if (StackEmpty(&st)) {
//                 StackDestory(&st);
//                 return false;
//             }
//             STDataType top = StackTop(&st);
//             StackPop(&st);
//             if ((*s == '}' && top != '{')
//              || (*s == ']' && top != '[')
//              || (*s == ')' && top != '(')) {
//                 StackDestory(&st);
//                 return false;
//             }
//             else {
//                 ++s;
//             }
//         }
//     }
//     bool ret = StackEmpty(&st);
//     StackDestory(&st);
//     return ret;
// }

// 232. 用栈实现队列
// https://leetcode.cn/problems/implement-queue-using-stacks/description/

// typedef struct {
//     //st1为push栈
//     //st2为pop栈
//     ST st1;
//     ST st2;
// } MyQueue;


// MyQueue* myQueueCreate() {
//     MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
//     StackInit(&queue->st1);
//     StackInit(&queue->st2);

//     return queue;
// }

// void myQueuePush(MyQueue* obj, int x) {
//     //进入push栈
//     StackPush(&obj->st1, x);
// }

// int myQueuePop(MyQueue* obj) {
//     //直接将pop栈里的数据pop出来，如果没有数据，则从push栈中转移数据
//     if (StackEmpty(&obj->st2)) {
//         while (!StackEmpty(&obj->st1)) {
//             StackPush(&obj->st2, StackTop(&obj->st1));
//             StackPop(&obj->st1);
//         }
//         STDataType ret = StackTop(&obj->st2);
//         StackPop(&obj->st2);
//         return ret;
//     }
//     else {
//         STDataType ret = StackTop(&obj->st2);
//         StackPop(&obj->st2);
//         return ret;
//     }

// }

// int myQueuePeek(MyQueue* obj) {
//     //如果pop栈中没有数据，先移动数据然后返回栈顶数据，如果有数据直接返回栈顶数据
//     if (StackEmpty(&obj->st2)) {
//         while (!StackEmpty(&obj->st1)) {
//             StackPush(&obj->st2, StackTop(&obj->st1));
//             StackPop(&obj->st1);
//         }
//         return StackTop(&obj->st2);
//     }
//     else {
//         return StackTop(&obj->st2);
//     }
// }

// bool myQueueEmpty(MyQueue* obj) {
//     return (StackEmpty(&obj->st1) && StackEmpty(&obj->st2)) == true;
// }

// void myQueueFree(MyQueue* obj) {
//     StackDestory(&obj->st1);
//     StackDestory(&obj->st2);
//     free(obj);
// }


// -----------------------------------队列---------------------------------
// 队列
// 2.1 队列的概念及结构
// 队列：只允许在一端进行插入数据操作，在另一端进行删除数据操作的特殊线性表，
// 队列具有先进先出 FIFO (First In First Out)
// 入队列：进行插入操作的一端称为队尾
// 出队列：进行删除操作的一端称为队头

//              ------------------------
// <-------出队列                          <----------入队列
//              -------------------------

// 225. 用队列实现栈
// https://leetcode.cn/problems/implement-stack-using-queues/description/

// typedef struct {
//     Queue q1;
//     Queue q2;
// } MyStack;

// MyStack* myStackCreate() {
//     //要使用具有全局属性的方法，否则返回的结构体指针会无效
//     MyStack* st = (MyStack*)malloc(sizeof(MyStack));
//     QueueInit(&st->q1);
//     QueueInit(&st->q2);

//     return st;
// }

// void myStackPush(MyStack* obj, int x) {
//     //如果第一个队列不为为空，直接放入
//     if (!QueueEmpty(&(obj->q1))) {
//         QueuePush(&(obj->q1), x);
//     }
//     else {
//         QueuePush(&(obj->q2), x);
//     }
// }

// int myStackPop(MyStack* obj) {
//     //如果第一个队列不为为空,将数据除了最后一个转移至第二个队列，然后最后再pop掉
//     if (!QueueEmpty(&(obj->q1))) {
//         while (QueueSize(&(obj->q1)) != 1) {
//             QDataType head = QueueFront(&(obj->q1));
//             QueuePop(&(obj->q1));
//             QueuePush(&(obj->q2), head);
//         }
//         QDataType ret = QueueBack(&(obj->q1));
//         QueuePop(&(obj->q1));
//         //返回被移除的栈顶元素
//         return ret;
//     }
//     else {
//         while (QueueSize(&(obj->q2)) != 1) {
//             QDataType head = QueueFront(&(obj->q2));
//             QueuePop(&(obj->q2));
//             QueuePush(&(obj->q1), head);
//         }
//         QDataType ret = QueueBack(&(obj->q2));
//         QueuePop(&(obj->q2));

//         return ret;
//     }
// }

// int myStackTop(MyStack* obj) {
//     //栈顶，队尾
//     if (!QueueEmpty(&(obj->q1))) {
//         return QueueBack(&(obj->q1));
//     }
//     else {
//         return QueueBack(&(obj->q2));
//     }
// }

// bool myStackEmpty(MyStack* obj) {
//     return ((QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2)))) == true;
// }

// void myStackFree(MyStack* obj) {
//     QueueDestory(&(obj->q1));
//     QueueDestory(&(obj->q2));
// }


// 622. 设计循环队列
// https://leetcode.cn/problems/design-circular-queue/description/

// 重点：循环队列，无论使用数组实现还是链表实现，都要多开一个空间，
// 也就意味着，要是一个存 k 个数据的循环队列，要开 k + 1 个空间，否则无法实现判空和判满。

// 数组实现方法

// typedef struct {
//     int* a;
//     int head;
//     int tail;
//     int k;
// } MyCircularQueue;

// bool myCircularQueueIsFull(MyCircularQueue* obj);
// bool myCircularQueueIsEmpty(MyCircularQueue* obj);

// MyCircularQueue* myCircularQueueCreate(int k) {
//     //开辟k + 1个空间 
//     MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//     cq->a = (int*)malloc(sizeof(int) * (k + 1));
//     cq->head = 0;
//     cq->tail = 0;
//     cq->k = k;

//     return cq;
// }

// bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//     //先判断是否为满，不为满则正常放
//     if (myCircularQueueIsFull(obj)) {
//         return false;
//     }
//     obj->a[obj->tail] = value;
//     ++obj->tail;
//     obj->tail %= (obj->k + 1);
//     return true;
// }

// bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//     if (myCircularQueueIsEmpty(obj)) {
//         return false;
//     }
//     ++obj->head;
//     obj->head %= (obj->k + 1);
//     return true;
// }

// int myCircularQueueFront(MyCircularQueue* obj) {
//     //返回队头就是head的对应的值
//     if (myCircularQueueIsEmpty(obj)) {
//         return -1;
//     }
//     return obj->a[obj->head];
// }

// int myCircularQueueRear(MyCircularQueue* obj) {
//     //返回队列的尾部的值，是tail的前一个，所以要处理tail在边界的问题
//     if (myCircularQueueIsEmpty(obj)) {
//         return -1;
//     }
//     if (obj->tail == 0) {
//         return obj->a[obj->k];
//     }
//     else {
//         return obj->a[obj->tail - 1];
//     }
// }

// bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//     //两个指针在同一个位置，是开始或者满
//     return obj->head == obj->tail;
// }

// bool myCircularQueueIsFull(MyCircularQueue* obj) {
//     return (obj->tail + 1) % (obj->k + 1) == obj->head;
// }

// void myCircularQueueFree(MyCircularQueue* obj) {
//     free(obj->a);
//     free(obj);
// }



//队列的方法，定义结构体包含head和tail指向节点，入队开辟节点，
// 出队删除节点，头尾的节点不是相连接的，虚拟的环形

// typedef struct queue_node {
//     int val;
//     struct queue_node* next;
// } QueueNode;

// typedef struct {
//     QueueNode* head;
//     QueueNode* tail;
//     int size; //元素个数
//     int capacity; //容量
// } MyCircularQueue;

// bool myCircularQueueIsFull(MyCircularQueue* obj);
// bool myCircularQueueIsEmpty(MyCircularQueue* obj);

// MyCircularQueue* myCircularQueueCreate(int k) {
//     MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//     q->size = 0;
//     q->capacity = k;
//     q->head = q->tail = NULL;

//     return q;
// }

// bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//     if (myCircularQueueIsFull(obj)) return false;

//     QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
//     new_node->val = value;
//     new_node->next = NULL;
    
//     //区分tail为空或者不为空,不为空连接到新的node，为空说明没有节点
//     if (obj->tail) {
//         obj->tail->next = new_node;
//     }
//     else {
//         obj->head = new_node;
//     }
//     obj->tail = new_node;
//     obj->size++;

//     return true;
// }

// bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//     if (myCircularQueueIsEmpty(obj)) return false;
//     //入队删除节点
//     QueueNode* tem = obj->head;
//     obj->head = obj->head->next;
//     free(tem);
    
//     obj->size--;
//     if (obj->size == 0) {
//         //只有一个节点，然后进行删除，将tail重新至空
//         obj->tail = NULL;
//     }
//     return true;
// }

// int myCircularQueueFront(MyCircularQueue* obj) {
//     if (myCircularQueueIsEmpty(obj)) return -1;
//     return obj->head->val;
// }

// int myCircularQueueRear(MyCircularQueue* obj) {
//     if (myCircularQueueIsEmpty(obj)) return -1;
//     return obj->tail->val;
// }

// bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//     return obj->size == 0;
// }

// bool myCircularQueueIsFull(MyCircularQueue* obj) {
//     return obj->size == obj->capacity;
// }

// void myCircularQueueFree(MyCircularQueue* obj) {
//     QueueNode* cur = obj->head;
//     while (cur) {
//         QueueNode* next = cur->next;
//         free(cur);
//         cur = next;
//     }
//     free(obj);
// }