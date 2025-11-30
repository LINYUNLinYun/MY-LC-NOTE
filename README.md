# MY-LC-NOTE
This reposity is used to recoed my LeetCode practice code(including C++ and other programing languages), as well as my thinking processes and study notes. There may alse be some addtional content included. 

## 代码随想录
| 题单 | 已完成 | 总计 |
| :-----| ----: | :----: |
| 代码随想录-数组 | 1-7 | 8 |
| 代码随想录-链表 | 0 | 8 |

## 数据结构实现

### 单链表
C++实现：实现构造函数的好处在于，可以在初始化的时候赋值，比如ListNode* head = new ListNode(5);
```C++
// 单链表
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};
```

## 59_generate_spiral_matrix.cpp
注意get_direction要首尾相连，检查的时候可以注意 一下，rdlur循环。然后没了，没什么需要注意的

## 707_design_linked_list.cpp
这道题需要注意的是单链表的数据结构：
1. 在最开头有一个哨兵节点作为头节点。
`sentinel -> 下标0 -> 下标1 -> ... -> 下标n-1 -> nullptr` 
2. 需要有一个数n来保存当前的节点个数，方便做越界判断等。
3. 在做题的时候只需要实现一个addAtIndex函数，也就是在下标index前插入的函数，然后就可以通过该函数在head和tail进行插入。