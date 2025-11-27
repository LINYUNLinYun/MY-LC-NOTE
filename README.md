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
