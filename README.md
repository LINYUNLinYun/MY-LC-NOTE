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

## 19_remove_nth_node_from_end_of_list.cpp
我的做法是：创建一个dummy node（就不需要对头节点进行特殊的判断了），先遍历一遍list，记录长度的同时，把node ptr存在容器里。后续只需要对容器的第length - n个结点后的进行删除即可。
时间复杂度和空间复杂度都是O(L)
还有个很妙的做法，遍历的过程中将node入栈，完事后第n个出栈的node就是要删除的节点，此时的栈顶node就是它的前驱节点，就可以删除了
还有个最妙的做法，双指针，first比second超前n个节点，这样first到末尾的时候，second刚刚好就是倒数第n个，如此一来就解决了

## 59_generate_spiral_matrix.cpp
注意get_direction要首尾相连，检查的时候可以注意 一下，rdlur循环。然后没了，没什么需要注意的

## 124_linked_list_cycle_ii
方法一：哈希表，常规思路，空间复杂度O(N)

方法二：快慢指针，这到底谁想出来的，空间复杂度O(1)
推导如下，刚开始fast和slow指向head，然后fast以两倍slow的速度前进，slow一次前进一步。可想而知，fast会先进环（如果有的话），然后再环里面跑直到slow也进来最后二者相遇。
无图，图看官方题解去。
设，slow进入环内跑了b距离后和fast相遇（这个b一定小于等于环的长度，因为即使在最极端的情况下，也就是slow进来的时候fast刚好从入口离开的情况下，fast也只需两圈就可以追上），c是环的长度l - b
那么有，fast在环内走了n圈和b相遇：
$$ a + b + n(b + c) = 2(a+b) \\
a+ b + nb+nc = 2a+2b \\
a = (n-1)b + nc = c + (n - 1)(b+c)
$$
也就是说，a的距离刚好就等于，环剩下的距离加上n-1圈的环。那么在俩个指针相遇的时刻，设计一个指针ptr从head开始走，当ptr和slow相遇的时候，slow刚好走了c+(n-1)圈和ptr相遇，ptr走过的路程就是就是head到入环点的路程
## 160_intersection_of_two_linked_list_node
方法一，哈希表建表A，轮到B遍历的时候查询一下B中的节点是否在A中出现，出现就返回。时间复杂度O(m+n)，空间复杂度O(m)。
**方法二，双指针**，这是个很妙的方法。首先，记录下pA和pB，如果他们俩有一个为空就返回nullptr。下面分类讨论，假设AB有相交，长度分别为m、n，公共部分长度为c。令指针pA和pB遍历A和B，当pA遍历完A就跳转到B的head继续遍历，当pB遍历完B就跳转到A的head继续遍历，两个指针最后走的长度是一样的，都是m+n -c（a+c +b = b + c +a），最后一定会汇聚到那个相交节点。如果两个相等且不为空，即为相交节点。

## 206_reverse_linked_lists.cpp
我采用的做法是迭代，用变量存储上一个和下一个节点，然后交换就可以了；
**比较需要注意的地方大概是，我采用了currNode为空时跳出循环，这本身没任何问题，问题出在我选择了返回currNode作为结果。你知道问题出在哪里了吗？——对的，跳出循环的时候curr已经是空的了，这么返回的一定是空指针，所以应该返回curr的上一个结果pre**

## 242_valid_anagram
方法一、排序后，依次比较元素是否相同，没什么特别的，时间复杂度是排序的复杂度

方法二、哈希表，与题解不同的是我用了库，他没有，他直接用了一个26的整数数组充当哈希表，还要注意char - 'a'才能访问数组下标，其他没什么特别的。

## 707_design_linked_list.cpp
这道题需要注意的是单链表的数据结构：
1. 在最开头有一个哨兵节点作为头节点。
`sentinel -> 下标0 -> 下标1 -> ... -> 下标n-1 -> nullptr` 
2. 需要有一个数n来保存当前的节点个数，方便做越界判断等。
3. 在做题的时候只需要实现一个addAtIndex函数，也就是在下标index前插入的函数，然后就可以通过该函数在head和tail进行插入。