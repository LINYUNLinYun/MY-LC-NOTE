# MY-LC-NOTE
This reposity is used to recoed my LeetCode practice code(including C++ and other programing languages), as well as my thinking processes and study notes. There may alse be some addtional content included. 

## 代码随想录
考虑到200+确实太多了，所以从贪心开始，只做hot100里相关的题，剩下的题以后有时间再说了。

| 题单 | 已完成 | 未完成 | 总计 | 备注 |
| :-----| ----: | :----: | :----: | |
| 代码随想录-数组 | 1-7 | 1 | 8| |
| 代码随想录-链表 | 1-8 | 0 | 8 | |
| 代码随想录-哈希表 | 1-9 | 9 | 9 | |
| 代码随想录-字符串 | 7 | 0 | 7 | |
| 代码随想录-双指针法 | 10 | 0 | 10 | |
| 代码随想录-栈与队列 | 8 | 0 | 8 | |
| 代码随想录-二叉树 | 33 |  | 33 | |
| 代码随想录-回溯算法 | 1-19 | 2 | 21 |最后两道hard不写了（不在hot100里日后再说） |
| 代码随想录-贪心算法 | 1-8, 11,18,20 | 12 | 23 | 只做hot100相关|
| 代码随想录-动态规划 | 0 | 53 | 53 | |
| 代码随想录-单调栈 | 0 | 5 | 5 | 只做hot100相关 |
| 代码随想录-图论 | 0 | 30 | 30 | |
| 总计 | 101 | 114 | 215 | | 

动态规划hot100:爬楼梯，最小花费爬楼梯，不同路径，不同路径 II，分割等和子集，目标和，完全平方数，零钱兑换，单词拆分

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
## 15_3sum

**好难的题！！！给我整不会了！！！！！！**

首先，这道题需要对数组进行一个排序（我发现排序真是个好东西）。这个是为了去除重复的数组。
按照一般情况，直接进行枚举的话，一共是n*(n-1)*(n-2)种情况，这会导致个什么？假设有a+b+c = 0 满足条件，
直接这么枚举还会有b+a+c = 0和c+b+a = 0一共六种情况，大大的重复了。如果改进一下枚举，采用下述的枚举可以吗？
```C++
for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
        for(int k = j+1;k<n;k++){
            if(nums[i]+nums[j]+nums[k] == 0){
                result.push_back({nums[i],nums[j],nums[k]});
            }
        }
    }
}
```
答案是依旧不可以。为什么？因为这样只消除了枚举顺序带来的重复（下标ijk和下标jik不会重复）。数值上的重复依旧是不可避免地。
也就是说，如果三个数a+b+c = 0，还能找到下标不一样的数也满足a+b+c = 0。如[-1,0,1,2,-1,-4]就有{0,1,2}和{1，2，4}。
所以说我们要排序，将数组按小到大先排序了，再在枚举的时候跳过相等的数字。这样可以确保枚举的时候一定是$a<=b<=c$的。

这样子就避免了下标带来的重复，和数值上的重复，因为输出的三元组是递增的，满足这个顺序的三元组有且仅有一个。也就是排除了{-1,0,1}的重复解{0,1，-1}


然后他用了一个双指针，就是说，在second递增的时候，指针third递减。因为三数之和为0，second对应的数值变大了，third对应的数值一定就要变小。

直到second和third相遇了，都没找到就结束。
这样子时间复杂度只有O(n^2)。还有就是，因为会出现相邻元素相同的问题，为了避免所以对于重复元素一律跳过，即nums[ptr] == nums[ptr-1]时ptr跳过。

## 18_4sum
刚开始做没想到怎么做，直接用的一层哈希表企图降低复杂度到O(N^3)，但是事实证明这个题他就不该用哈希表
他和三数之和是一样的做法，只多了一点点特性——剪枝
妙就妙在用了两种剪枝：
1. 确定第一个数之后，如果`(long)nums[first]+nums[first+1]+nums[first+2]+nums[first+3] > (long)target`那么说明此题无解，直接break;
2. 确定第一个数之后，如果`(long)nums[first]+nums[n-1]+nums[n-2]+nums[n-3] < (long)target`那么说明这个数这一轮无解了，直接continue;

但是官方题解只在外面两层循环做了剪枝，大概是觉得里面两层复杂度（虽然两层但是复杂度O(N)）不需要剪枝吧，所以三数之和为什么不剪枝。

还有一个就是，四数之和竟然越界了然后要改用long类型去操作。

## 17_letter_combinations_of_a_phone_number
官方题解是维护了个哈希表，然后递归加循环。我是直接人工写表，然后递归。

## 19_remove_nth_node_from_end_of_list.cpp
我的做法是：创建一个dummy node（就不需要对头节点进行特殊的判断了），先遍历一遍list，记录长度的同时，把node ptr存在容器里。后续只需要对容器的第length - n个结点后的进行删除即可。
时间复杂度和空间复杂度都是O(L)
还有个很妙的做法，遍历的过程中将node入栈，完事后第n个出栈的node就是要删除的节点，此时的栈顶node就是它的前驱节点，就可以删除了
还有个最妙的做法，双指针，first比second超前n个节点，这样first到末尾的时候，second刚刚好就是倒数第n个，如此一来就解决了

## 20_valid_parentheses
没啥特别的，就是每碰到一个左括号就入栈，每碰到一个右括号就出栈一个左括号匹配下——利用先进后出的特性验证了括号的闭合性。因为外层括号一定是左括号先进然后里面的括号出完了才出外层括号的右括号

## 28_find_the_index_of_the_first_occurrence_in_a_string
方法一：暴力法，但是这个没什么特别的所以我们额外拿出一天来研究KMP算法

方法二：KMP。

## 39_combination_sum.cpp
要注意一个问题：只有入栈没有出栈！！！！！！

事情就是我用了一个临时变量存储当前path的sum，但是我忘记在循环末尾回溯这个变量了。。。

这是个值得注意的地方——对于回溯算法来说，每次递归调用结束后都要通过栈把相关的变量全部恢复到之前的状态。

## 40_combination_sum_ii.cpp
开始我套用39的做法，失败了，因为我处理不了相同组合重复的问题（当某个元素出现多次的时候，比如说30个1，无论target是啥，可以随便组合出一堆重复的组合）。

后面参照官方题解采用了两层循环，第一层循环控制递归的起点元素，第二层循环控制当前位置参与递归的元素个数，如此一来就解决了重复问题——因为相同元素参与到递归中的个数的每种可能只出现一次。

## 45_jump_game_ii
我的做法是从尾部开始寻找，每次寻找一个能跳到当前节点的最左边的节点，直到找到头节点为止。时间复杂度O(N^2)，空间复杂度O(1)。

有时间复杂度为O(N)的做法：贪心做法的本质——有点像按层序遍历，每次我们都要找到当前可达的节点里能跳的最远的那个节点，这样就可以保证每次跳跃都能跳的尽可能远，从而减少跳跃次数。那么问题来了，每次都寻求局部的最大值能不能保证全局的最优解呢？答案是肯定的，因为如果某个跳的一般远的节点可以达成目标，那么跳的更远的节点也一定可以达成目标，所以说每次都跳的最远的那个节点是不会错的。

## 53_maximum_subarray
这题可以用贪心+dp写：这题的关键在于，因为是最大**连续**子序列的和，说明了一件事：如果当前的子序列和是负数了，那么这个子序列就没有意义了，因为它不但不能增加后续元素的和，反而会减少后续元素的和，所以说一旦当前子序列和变成负数了，就直接丢弃掉这个子序列，重新开始一个新的子序列。

所以对于每个元素nums[i]，如果nums[i]和前一个或几个元素的和小于nums[i]了，说明前一个或几个元素的和已经没有意义了，直接丢弃掉，从nums[i]开始一个新的子序列；如果nums[i]和前一个或几个元素的和大于nums[i]了，说明前一个或几个元素的和还有意义，可以继续保留在当前子序列中。

也可以用分治写，分治我还不懂

## 55_jump_game
运用可达的思想秒了
```C++
bool canJump(vector<int>& nums) {
        int right_reach = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] > right_reach){
                right_reach = nums[i];
            }
            if(right_reach>0){
                right_reach--;
            }else{
                return (i==nums.size()-1) ||false; 
            }
        }
        return true;
    }
```

## 59_generate_spiral_matrix.cpp
注意get_direction要首尾相连，检查的时候可以注意 一下，rdlur循环。然后没了，没什么需要注意的

## 70_climbing_stairs
我用了一种矩阵快速幂的做法，时间复杂度O(logN)，空间复杂度O(1)，感觉挺妙的。其实这个规律和斐波那契数列一样，都是第N等于前两项之和。

## 77_combinations
我的做法是：递归+循环啊+回溯，~~感觉没什么特别~~（错误的，我们这个做法好像是最优做法，每层递归都有个循环，且循环的元素都用上了，不需要剪枝），主要是要注意回溯的时候要把之前添加的元素删除掉。我用循环递归的起点。

官方题解依旧比我的更好：直接通过栈控制当前答案的深度，递归的起点就是当前元素的下一个元素，这样就不需要在递归函数里进行循环了。
```C++
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {
        // ……
        // 前面省略
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};

```

## 78_subsets
这道题不难，就是n个元素的nums总子集是2^n个，时间复杂度O(n*2^n)，空间复杂度O(n)（递归栈的深度）。

## 90_subsets_ii
这道题和上一道题的区别在于，nums中可能存在重复元素，所以参考第40题的做法，在递归的时候加一层循环，控制当前元素参与递归的个数，这样就可以避免重复了。就是78题和40题的结合体。

## 93_restore_ip_addresses
思路倒是会，但是错在两个地方：
1. 没有处理好先导零。我用的判断是`if(stoi(num) > 0 && temp[0] == '0')`，但是这个判断是错误的，因为00和000也是不合法的，所以应该改成`if(temp[0] == '0' && temp.size() > 1)`。根本在于stoi函数会把00和000都转换成0，所以无法通过这个函数来判断先导零的问题了。
2. 忽略了char字符的比较问题，我直接用`if(temp[0] == 0)`来判断这个字符串是否是0，结果发现这个条件永远不成立，因为temp[0]是个char类型的字符，而不是数字0，所以应该改成`if(temp[0] == '0')`。

## 98_validate_binary_search_tree
第一遍写，错了。我的写法：
```C++
bool isValidBST(TreeNode* root) {
        bool res = true;
        if(root){
            if(root->left && root->left->val >= root->val){
                res = false;
                return res;
            }else{
                res = isValidBST(root->left);
            }
            if(root->right && root->right->val <= root->val){
                res = false;
                return res;
            }else{
                res = isValidBST(root->right);
            }
        }else{
            return res;
        }
        return res;
    }
```
错在这个么写其实只验证了当前的一个小子树是严格符合左儿子小于父节点，右儿子大于父节点，只确保了局部正确性，全局的树可能是错的；因此正确的写法应该是在递归之间传递全局信息。

第二遍，对了……他妈的算法题也太恶心了。这一次我先尝试用pair来传递子树的上下界，如果有违法的我会把pair设置为{INT_MAX,INT_MIN}，如果合法的话就返回子树的最大值和最小值。这样子就可以在递归的过程中验证全局的正确性了……吗？由于树节点的值可能是INT_MAX或者INT_MIN，所以有些案例是过不了的，回炉重造！也很简单，我直接在函数参数加了个引用的bool变量来记录是否合法，完美解决只利用pair传递上下界可能出现的边界值问题了。

或者也可以不加这个变量，学习官方题解，把边界设置为long long类型的LONG_MAX和LONG_MIN，这样就不会出现边界值问题了，

但是官方的思路更好，我是真没没想到啊！！！！！！！！！！！！！！！！！！！！！！！！！：
思路1：递归，传递上下界，验证全局正确性，但是它是自顶向下的，和我的一层一层往上传递最大最小值的思路不一样，感觉这个思路更妙，强烈推荐复盘学习，思路其实很简单但是很妙——自顶向下的好处是每一轮只用传递这个根节点带来的范围约束即可，也就是只需传递局部信息。因为自顶向下确保了，如果递归能走到这个位置说明前面的是对的了，保证了全局的正确性。

反观我们的自底向上的做法，无论底下的错误发生与否，信息都要传递到根节点才知道，一点也不优雅。
```C++
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper){
        if(root == nullptr){
            return true;
        }
        if(root->val <= lower || root->val >= upper){
            return false;
        }
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
        

    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
```

思路2：中序遍历，二叉搜索树的中序遍历是一个递增序列，所以只要验证中序遍历的结果是递增的就行了，这个思路最简单。

## 101_symmetric_tree
我的错误思路：刚开始随便瞄了眼，发现对称的树它的中序遍历序列是个回文序列即对称，于是就开始用这个方法写了。结果发现很bad有几个测试用例过不了，即使给叶子节点使用特殊的标记也依然存在某个除了根节点两边节点都只有一个子节点的树中序遍历完了是对称的。

！！！说白了用中序遍历是不行的，他只是充分条件。把二维树结构压缩成一维序列实际上已经丢失了树的左右信息，所以还是要用常规方法做，明天再写一遍。

方法1：递归。
方法2：层序遍历，每层都判断一下是否是回文序列。

## 106_construct_binary_tree_from_inorder_and_postorder_traversal
我尝试使用递归做，但不知道为什么失败了，猜测是没处理好边界条件，导致创建子容器出错了？？？？或许用下标管理是对的吧。。

v1.0更新 使用子容器加递归成功了，之前递归失败是因为我把边界条件搞错了，加上我在递归的时候传的是`root->left`和`root->right`，看似把左右子树的根节点传进去了，实际上传的只是他们的值，随后在递归函数里进行修改父节点也是没有变化的。所以说，递归的时候应该传入指针的引用`TreeNode* &root`，或者指向该指针的指针`TreeNode** root`，这样在递归函数里修改父节点的左右子树才会生效。

v2.0 

## 110_balanced_binary_tree
> 平衡二叉树是指该树所有节点的左右子树的高度相差不超过 1。
因此这题可以用递归来做，对于每个根节点都要满足左右子树高差不过1；

## 112_path_sum
递归+回溯秒了，感觉没什么难的

## 122_best_time_to_buy_and_sell_stock_ii
emmmmm dp有点难度 贪心秒了

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

## 131_palindrome_partitioning
时间复杂度时O(N*2^N)，空间复杂度O(N)，不过不知道为什么我的时间复杂度只战胜了9%的人，可能是因为我用了子串函数，好像只用左右指针也能做。

## 160_intersection_of_two_linked_list_node
方法一，哈希表建表A，轮到B遍历的时候查询一下B中的节点是否在A中出现，出现就返回。时间复杂度O(m+n)，空间复杂度O(m)。
**方法二，双指针**，这是个很妙的方法。首先，记录下pA和pB，如果他们俩有一个为空就返回nullptr。下面分类讨论，假设AB有相交，长度分别为m、n，公共部分长度为c。令指针pA和pB遍历A和B，当pA遍历完A就跳转到B的head继续遍历，当pB遍历完B就跳转到A的head继续遍历，两个指针最后走的长度是一样的，都是m+n -c（a+c +b = b + c +a），最后一定会汇聚到那个相交节点。如果两个相等且不为空，即为相交节点。

## 169_majority_element
这道题有很多方法：
1. 暴力法，时间复杂度O(N^2)，空间复杂度O(1)
2. 哈希表，时间复杂度O(N)，空间复杂度O(N)
3. 排序，时间复杂度O(NlogN)，空间复杂度O(1)（如果排序算法是原地的）
4. Boyer-Moore 投票算法，时间复杂度O(N)，空间复杂度O(1)
今天来试试投票


## 202_happy_number
快乐数（lc easy?????）
在做题之前首先要回答一个问题——就是一个数的各位置数字平方和是个什么数？
简单画个表格看看每个数的next是什么情况：
| 位数 | 最大数 | next | 
| :-----| ----: | :----: | 
| 1 | 9 | 81 |
| 2 | 99 | 162 |
| 3 | 999 | 243 |
| 4 | 9999 | 324 |
| ... | ... | ... |
| 10 | 9999999999 | 810 |

不难看出，3位数的数next最大不超过243，这说明了什么呢？也就是说，只要是个三位数，next一定是个三位数而且是小于243的，对于其他位数的情况以此类推即可。

所以对一个数循环提取各位置数平方加和的结果，一直做下去，有三种可能：
1. 7-49-97-130-10-1 收敛到1，也就是快乐数
2. 在某个地方开始产生环，无法收敛到1，不是快乐数
3. 一直变大变大直到正无穷？错！

事实证明这是不可能的，因为根据next的性质可知，平方和之后它是会不断缩小的，所以不会出现这种情况。那么问题就简单多了，我们只需判断这个数它一直做下去是第一还是第二种情况即可，第二种情况用快慢指针即可检测（具体请看lc124判断链表的环）。



## 206_reverse_linked_lists.cpp
我采用的做法是迭代，用变量存储上一个和下一个节点，然后交换就可以了；
**比较需要注意的地方大概是，我采用了currNode为空时跳出循环，这本身没任何问题，问题出在我选择了返回currNode作为结果。你知道问题出在哪里了吗？——对的，跳出循环的时候curr已经是空的了，这么返回的一定是空指针，所以应该返回curr的上一个结果pre**

### 216_combination_sum_iii
我们的做法就是再题77的基础上加了一个三元素和判断，没做什么改进。理论上还可以进行一些剪枝，这样可以降低时间复杂度。

## 222_count_complete_tree_nodes.cpp
这道题的难点在于，如何利用完全二叉树的性质来降低时间复杂度。
> 在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。

普通方法：递归或者迭代，复杂为O(N)，空间复杂度O(H)
方法一：二分法，复杂度O(logN*logN)  已实现，很妙的一个思路。也有其他的思路。本质差不多
方法二：位运算法，复杂度O(logN*logN)

## 232_implement_queue_using_stack
这题没什么难的就是难在怎么用两个栈构造一个队列上想清楚就很简单了。一个尾栈负责记录push，要pop的时候在全推到另一个头栈，再进行pop就可以了。

## 236_lowest_common_ancestor_of_a_binary_tree
简单题 可以学习下官方题解的做法。

## 239_sliding_window_maximum.cpp
好像是我的第一道hard题，第一遍用的思路是双重循环暴力枚举，结果超时间；然后改进了下对出和入的元素以及最大值做一个比较进行剪枝但依旧过不了某些用例；最后看题解用了优先队列priority_queue，最大堆，轻松解决了……没啥好说的，学习人家的做法就行了

## 242_valid_anagram
方法一、排序后，依次比较元素是否相同，没什么特别的，时间复杂度是排序的复杂度

方法二、哈希表，与题解不同的是我用了库，他没有，他直接用了一个26的整数数组充当哈希表，还要注意char - 'a'才能访问数组下标，其他没什么特别的。

## 257_binary_tree_paths
这道题毫无疑问是递归；但是我用了vector来模拟栈，去用出栈入栈找路径，结果是比较复杂，因为要处理出栈入栈的问题，同时还要使得输出的格式符合要求的。

官方题解是更简单的做法，递归+回溯，可以看一下我们的第二次提交的代码，那个是回溯的写法，比较简单。

## 347_top_k_frequent_elements
这道题依旧考察优先队列的用法，使用小顶堆可以提取前k个最大的元素；这个小顶堆有个抽象构造方法，要传入比较函数的可以学习下。没了，感觉这道题也不难，难在优先队列吧，最大堆最小堆的处理上。

此外这题的常规做法时间复杂度O(NlogN)，空间复杂度O(N)，优先队列的做法时间复杂度O(NlogK)，空间复杂度O(N)，**还有快速排序做法可以补充学习一下。**

## 376_wiggle_subsequence
摆动序列，这题可以dp可以贪心。dp的思路是，分为up和down标记，如果up说明第i-1个元素是处在一个上升序列的末尾，down同理；所以判断当前元素和上一个元素的大小就知道当前元素能不能让上升序列或者下降序列继续增大。

贪心：涉及到峰和谷的概念，本质思想在于，一个摆动序列一定是由峰和谷交替组成的，过渡元素没有意义；所以比较下符号就可以，如果当前元素和上一个元素的差值是正的，且摆动序列的尾是下降的，那么当前元素就可以加入到摆动序列中；如果当前元素和上一个元素的差值是负的，且摆动序列的尾是上升的，那么当前元素也可以加入到摆动序列中；如果符号相等说明是过渡元素没有意义，如果差值为零也没意义

## 383_ransom_note
这道题没什么好注意的，主要是提一个点，就是如果hashTable[a]++对一个没出现过的元素a进行自增，那么是把value初始化为0后进行自增。相应的后续对这个键的值进行--，这个键也不会消失，所以用count判断会出问题，虽然值是0意味着某种程度上它已经不可用了但键还是在的。

## 450_delete_node_in_a_bst
虽然是中等题，但是感觉挺简单。重要的在于删除掉一个节点后，要保证这个节点的左右子树（如果有的话）能成为一个合法的bst。所以问题转化为，如果在删除根节点的情况下让左右子树连接起来——也很简单，要么把左子树接到右子树的最左节点上；要么把右子树接到左子树的最右节点上。这样就保证了连接起来的树依然是合法的bst了。

随后递归整个树，对于目标节点，把以它为根的树进行删除操作，其他节点不变。

## 455_assign_cookies
这道题是贪心应该不难看出。我原先的做法时间复杂度是O(m*n)，空间复杂度O(1)。

正确做法:先对两个数组进行排序，然后用双指针分别指向两个数组的开头，。这样时间复杂度是O(mlogm + nlogn)，空间复杂度O(1)。

## 461_hamming_distance
用异或更简单

## 491_non_decreasing_subsequences
我们的思路（经gpt完善后）如下。主要的改动点：path改为引用、去重检查在递归的过程中进行

主要讲讲为什么去重检查要在递归的过程中进行，而不是在push答案的时候进行。因为如果在push答案的时候进行去重检查，等于每种情况都要遍历一遍，时间复杂度最坏是是O(2^N * N )，可以想象一个[1,2,...,15]你会发现每轮递归都是答案，而每个答案都要做一遍检查 。

如果在递归的过程中进行去重检查（利用unordered_set或者其他的哈希方法），那么每种情况只需要检查一次，时间复杂度是O(2^N)，大大降低了时间复杂度。
```C++
class Solution {
public:
    void helper(vector<int>& nums, vector<int> &path, vector<vector<int>> &res, int start){
        if(path.size()>=2){
            res.push_back(path);
            if(start == nums.size()){
                return;
            }
        }
        unordered_set<int> used;
        for(int i = start;i<nums.size();i++){
            // 不应该在push答案的时候再检查是否重复
            if((!path.empty() && nums[i] < path.back()) || used.count(nums[i])){
                continue;
            }
            used.insert(nums[i]);
            path.push_back(nums[i]);
            helper(nums,path,res,i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(nums,path,res,0);
        return res;

    }
};
```

## 513_find_bottom_left_tree_value
这道题我用的是一个dfs获取深度，然后bfs获取最底层的第一个节点的值的方法，感觉有点麻烦了。

官方题解是直接在dfs的过程中记录当前的最大深度和对应的节点值，这样就不需要两次遍历了，比较简单。可以试试。

## 530_minimum_absolute_difference_in_bst
我的做法，我又又又想复杂了，**这题用中序遍历好像能秒（O(N)）**。我这个做法的复杂度是O(NlogN)，因为每个节点都要调用一次getEdgeNodeVal函数，而这个函数的复杂度是O(logN)。
```C++
int getEdgeNodeVal(TreeNode* root, int direction) {
        if(root == nullptr){
            return INT_MAX;
        }
        if(direction){
            while(root->right){
                root = root->right;
            }
            return root->val;
        }
        else{
            while(root->left){
                root = root->left;
            }
            return root->val;
        }
    }
    int helper(TreeNode* root){
        int abs_res = INT_MAX;
        if(root == nullptr){
            return abs_res;
        }
        if(root->left){
            int left_max = getEdgeNodeVal(root->left, 1);
            left_max = abs(left_max - root->val);
            abs_res = left_max < abs_res ? left_max : abs_res;
        }
        if(root->right){
            int right_min = getEdgeNodeVal(root->right, 0);
            right_min = abs(right_min - root->val);
            abs_res = right_min < abs_res ? right_min : abs_res;
        }
        int left_res = helper(root->left);
        int right_res = helper(root->right);
        abs_res = left_res < abs_res ? left_res : abs_res;
        abs_res = right_res < abs_res ? right_res : abs_res;
        return abs_res;
    }
    int getMinimumDifference(TreeNode* root) {
        // 如果bst的某个根节点存在最小差值 一定是它的左右子树的最右/左节点产生
        return helper(root);
    }
```

## 538_convert_bst_to_greater_tree
我的做法是：先中序遍历获取一个递增的序列，然后从后往前遍历这个序列，依次累加并更新到树节点上。

官方答案比我的更简单，是直接在中序遍历的过程中就把这个累加完成了。

还有另一种做法，Morris遍历，可以实现O(1)空间复杂度的中序遍历，日后再说。

## 617_merge_two_binary_trees
简单题，如果开新的树的话会很简单，一直递归就行；我选择原地修改一棵树，花了很久……看了下lc上讨论区，发现别人写的简洁多了，学习：
```C++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }
        return root1 ? root1 : root2;
    }

    //等价于
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr){
            return nullptr;
        }
        else if(root1 && root2 == nullptr){
            return root1;
        }
        else if(root1 == nullptr && root2){
            return root2;
        }
        else{
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
    }
};
```

## 654_maximum_binary_tree
左右指针+递归秒了，和那个106题差不多。

## 669_trim_a_binary_search_tree
一道中等题。。。。没思路，试着用剪枝根节点的左右子树并递归写一下，发现很复杂，失败，~~明天再试~~下午想了想还是今天就试试吧！看了下官方题解，非常的简单，还真是到中等题……递归几行就写完了：
```C++
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 空返回空
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < low) {
            // 说明根节点和左子树都不合法，对右树递归
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            // 说明根节点和右子树都不合法，对左树递归
            return trimBST(root->left, low, high);
        } else {
            // 说明根节点合法，对左右子树递归
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }
};
``` 
所以为什么这道题这么简单呢？对于修剪一棵树来说，根节点只有三种情况：
1. 根节点小于low，那么根节点和左子树可以扔掉，我们返回右子树的合法结果，所以对右子树继续递归。
2. 根节点大于high同理。
3. 精髓就在根节点合法。对于前两种情况，我们总是遇到根节点太小or太大，那么由于bst的性质，递归倾向于往不那么小/大的方向走，也就是说这么走下去一定能遇到一个合法的根节点（搜索树收敛到这个范围里）或者遇到空节点。那么接着对合法的节点的左右子树继续递归修剪就好了。

可以想象一下三角形的的树，low和high的范围构成一个狭窄的长方形。最后返回的root是这个范围内的最高的节点。

## 701_insert_into_a_binary_search_tree
中等题？？感觉很简单。

## 707_design_linked_list.cpp
这道题需要注意的是单链表的数据结构：
1. 在最开头有一个哨兵节点作为头节点。
`sentinel -> 下标0 -> 下标1 -> ... -> 下标n-1 -> nullptr` 
2. 需要有一个数n来保存当前的节点个数，方便做越界判断等。
3. 在做题的时候只需要实现一个addAtIndex函数，也就是在下标index前插入的函数，然后就可以通过该函数在head和tail进行插入。

## 746_min_cost_climbing_stairs
典型的动态规划，先建立一个最小代价数组，dp[i]表示到达第i阶的最小代价。然后最小代价数组的前二个都是0，因为可以从第0阶或者第1阶开始。给定了初始条件，然后就可以开始递推了。对于第i阶的最小代价来说（i >= 2），可以从第i-1阶或者第i-2阶上来，所以dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])

## 1047_remove_all_adjacent_duplicates_in_string.cpp
这道题不难，但是最优解是利用string类自身的栈特性解决，即通过pop_back和push_back来实现