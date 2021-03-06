### 剑指 Offer 09. 用两个栈实现队列

常规的想法是用一个栈作辅助栈，然后倒来倒去

但是我们注意到队列**一头只负责进，另一头只负责出**，因此我们可以用两个栈分别承担两个功能

1. s1负责进队列，每次push都进入s1
2. s2负责出队列，每次pop都从s2出
   如果s2为空，则一次性将s1中所有元素倒入s2（出队的顺序是正好的，可以全部倒入），如果两个栈都为空，则删除失败返回-1

```c++
class CQueue {
private:
    // s1代表队尾，s2代表队头
    stack<int> s1, s2;

public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    void mov(stack<int>&from, stack<int>& to){
        while (!from.empty()){
            int temp = from.top();
            from.pop();
            to.push(temp);
        }
    }

    int deleteHead() {
        if (s2.empty()){
            if (s1.empty()) return -1;
            mov(s1, s2);
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
};
```



### 剑指 Offer 07. 重建二叉树

> 根据前序遍历和中序遍历重建二叉树

**根据自己总结**：二叉树题通常三种方法

1. 用数组二叉树，每个叶子标号
2. 用`void dfs();`函数遍历，采用遍历的思想删除或者更改结点
3. 用`TreeNode* build();`函数，返回值是TreeNode*的通常是建立二叉树，内部结构一般为`root->left = build(root->left, ...);`和`root->right = build(root->right, ...);`

前序遍历的特点是在某树所有节点中，根节点一定在第一个；中序遍历的特点是根节点把左右子树区分开来。因此我们想到在前序遍历中获得根节点，再在中序遍历中找到其位置，最后对中序遍历左右两块各自调用build函数建立左右子树
需要注意的是递归时pos（前序遍历下标）的确定（确定右子树root时要根据左子树的节点数量进行右移）

```c++
class Solution {
private:
    size_t len;

public:
    // 根据先序找到每一段的根节点，可以在中序分出左右子树
    TreeNode* build(TreeNode* root, vector<int>& preorder, vector<int>& inorder, int left, int right, int pos){
        if (pos == len || left > right) return root;
        int newRoot = preorder[pos];
        int newPos = find(inorder.begin(), inorder.end(), newRoot) - inorder.begin();

        root = new TreeNode(newRoot);

        root->left = build(root->left, preorder, inorder, left, newPos - 1, pos + 1);
        root->right = build(root->right, preorder, inorder, newPos + 1, right, pos + newPos - left + 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        len = preorder.size();
        TreeNode* root;
        if (!len) return root;
        return build(root, preorder, inorder, 0, len - 1, 0);
    }
};
```



### 剑指 Offer 11. 旋转数组的最小数字

> 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

O(n)的算法很容易想到，但是只能超过40%的人，所以得二分，判断边界点和中间点的大小关系

如果将数组的点在坐标轴上画出来，一定是如下所示：

<img src="https://assets.leetcode-cn.com/solution-static/jianzhi_11/1.png" alt="fig1" style="zoom:20%;" />

因此我们考虑三种情况：

1. `nums[ri] > nums[mid]`如果**右边的比中间的大**，那么**最小值一定在左边**，但是**中间可能是最小值**
2. `nums[ri] < nums[mid]`如果**右边的比中间的小**，那么**最小值一定在右边**，且**中间不是最小值**
3. `nums[ri] == nums[mid]`如果**右边值和中间相等**，那么有两种情况，一是这一串都相等，二是右边先降后升，**左右无法确定**。但是可以确定**最右端点不是最小值（如果这一串都相等，少一个也不影响；如果右边先降后升，降的一定比它小）**

```c++
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int le = 0, ri = numbers.size() - 1;
        while (le < ri){
            int mid = (ri - le) / 2 + le;
            // 如果右边的比中间的大，那么最小值一定在左边，但是中间可能是最小值
            if (numbers[ri] > numbers[mid]){
                ri = mid;
            // 如果右边的比中间的小，那么最小值一定在右边，且中间不是最小值
            } else if (numbers[ri] < numbers[mid]) {
                le = mid + 1;
            // 如果右边值和中间相等，那么有两种情况，一是这一串都相等，二是右边先降后升，左右无法确定
            // 但是可以确定**最右端点不是最小值**
            } else {
                --ri;
            }
        }
        return numbers[ri];
    }
};
```



### 剑指 Offer 12. 矩阵中的路径

> 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
>
> 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

进行的是在较大表中的一次查询，因此不采用前缀树（会超时）

采用dfs的方法，dfs也可以分为两种

1. 修改原表：每次比对完后将字符更改为'\0'，这样就不需要vis数组，临界条件也比较简单，可以放在dfs函数第一行（如果最终表要返回原来状态，可以用值传递）
2. 不修改原表：需要用到vis数组判断一个数是否已经被比对过，但这样需要把i和j跑出边界的条件移到`vis[i][j]`之前，否则可能会发生溢出；或者是在调用函数之前判断，但是这样递归终止条件也要进行相应改变

```c++
class Solution {
private:
    int rows, cols;
    size_t len;
    vector<vector<int>> dirs = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };
public:
    vector<vector<int>> vis;
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int pos){
        char s = board[i][j];
        if (pos == len - 1 && word[pos] == s) return 1;
        if (s != word[pos]) return 0;
        
        vis[i][j] = 1;
        bool flag = 0;
        for (auto& dir : dirs){
            int ii = i + dir[0], jj = j + dir[1];
            if (ii < 0 || jj < 0 || ii == rows || jj == cols) continue;
            if (!vis[ii][jj] && dfs(board, ii, jj, word, pos + 1)){
                flag = 1; break;
            }
        }
        vis[i][j] = 0;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        len = word.size();
        vis.resize(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (board[i][j] == word[0])
                    if (dfs(board, i, j, word, 0)) return 1;
            }
        }
        return 0;
    }
};
```



### 剑指 Offer 13. 机器人的运动范围

> 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

一个简单的搜索问题，要注意的是，机器人不需要往里走（往回走），因为往外走会变小的唯一情况是个位数为9的变成了0，而这种情况要么是由里面的点往外扩张出来的，要么是机器人走不到的（不连续），因此只要往外走即可

另外：判断条件放在递归式前面而不是递归终止的地方运行会快很多

```c++
class Solution {
private:
    int rows, cols, limit;
    vector<vector<int>> vis;
    vector<vector<int>> dirs = {
        {1, 0}, {0, 1}
    };
public:
    int ok(int i, int j){
        int sum = 0;
        while (i){
            sum += i % 10;
            i /= 10;
        }
        while (j){
            sum += j % 10;
            j /= 10;
        }
        if (sum > limit) return 0;
        return 1;
    }

    int dfs(int i, int j){
        if (i < 0 || j < 0 || i == rows || j == cols) return 0;
        if (vis[i][j]) return 0;
        int sum = 1;
        vis[i][j] = 1;
        for (auto& dir : dirs){
            if (ok(i + dir[0], j + dir[1])) sum += dfs(i + dir[0], j + dir[1]);
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        rows = m;
        cols = n;
        vis.resize(m, vector<int>(n));
        limit = k;
        return dfs(0, 0);
    }
};
```



### 剑指 Offer 16. 数值的整数次方

> 实现 pow(x, n)，即计算 x 的 n 次幂函数。不得使用库函数，同时不需要考虑大数问题。

x的n次幂，**x取double，n取long long**。虽然题目中n的限制是int范围，但是取最小负数的绝对值是溢出的，计算负数次幂就会炸

另外，可以特判三种情况`n == 0`、`x == 1`和`x == -1`

```c++
class Solution {
public:
    double myPow(double x, int nn) {
        if (!nn) return 1;
        long long n = nn;
        int flag = n > 0 ? 1 : 0;
        double res = 1;
        n = fabs(n);
        while (n){
            if (n & 1){
                res *= x;
                --n;
            } else {
                x *= x;
                n /= 2;
            }
        }
        return flag ? res : 1 / res;
    }
};
```



### *剑指 Offer 26. 树的子结构

> 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
>
> B是A的子结构， 即 A中有出现和B相同的结构和节点值。

总卡一个样例，换个写法卡一个，再换个卡另一个，要考虑的情况挺多的（因为存在重复数字），一开始有点难考虑全，下面列出几种情况

- 普通的子结构
- B是A中的一部分，例如A的右子树还有东西，而B已经没有了，用`if (!A && !B || A && !B) return 1;`这句代码解决
- 数字与B的根数字相等，但是不构成子结构；后面存在一个重复数字，能构成子结构，用`int fix = 0`解决（fix==1即要求这个根为子结构的根）

```c++
class Solution {
public:
    bool func(TreeNode* A, TreeNode* B, int fix = 0){
        if (!A && !B || A && !B) return 1;
        if (B && !A) return 0;
        bool sub = func(A->left, B) || func(A->right, B);
        if (A->val != B->val){
            if (fix) return 0;
            return sub;
        } else {
            return func(A->left, B->left, 1) && func(A->right, B->right, 1) || sub;
        }
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B) return 0;
        return func(A, B);
    }
};
```



### 剑指 Offer 27. 二叉树的镜像

> 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

- **空间换时间**：定义新的root，在root上进行赋值，这样就不用执行交换了
- **时间换空间**：通过交换操作在原二叉树上进行

```c++
// 时间换空间
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        return root;
    }
};

// 空间换时间
class Solution {
public:
    TreeNode* create(TreeNode* root, TreeNode* newRoot){
        if (!root) return root;
        newRoot = new TreeNode(root->val);
        newRoot->right = create(root->left, newRoot->right);
        newRoot->left = create(root->right, newRoot->left);
        return newRoot;
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* newRoot = new TreeNode(root->val);
        return create(root, newRoot);
    }
};
```



### 剑指 Offer 29. 顺时针打印矩阵

> 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

模拟，但是模拟也容易出错，因为定义上下左右四个变量太多了，而且最后结束的条件不好判断，因此最后应该用pos计数矩阵中所有元素的数量，但是这样要在循环体内增加三个判断语句，暂未找到好方法

```c++
class Solution {
private:
    int urow, lcol, drow, rcol, pos, n;
    vector<int> res;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        drow = matrix.size() - 1;
        if (drow == -1) return res;
        rcol = matrix[0].size() - 1;
        if (rcol == -1) return res;
        urow = lcol = pos = 0;
        n = (drow + 1) * (rcol + 1);
        res.resize(n);
        
        while (pos < n){
            for (int i = lcol; i <= rcol; ++i) res[pos++] = matrix[urow][i];
            if (pos == n) break;
            ++urow;
            for (int i = urow; i <= drow; ++i) res[pos++] = matrix[i][rcol];
            if (pos == n) break;
            --rcol;
            for (int i = rcol; i >= lcol; --i) res[pos++] = matrix[drow][i];
            if (pos == n) break;
            --drow;
            for (int i = drow; i >= urow; --i) res[pos++] = matrix[i][lcol];
            ++lcol;
        }
        return res;
    }
};
```



### 剑指 Offer 59 - II. 队列的最大值

> 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
>
> 若队列为空，pop_front 和 max_value 需要返回 -1

实际上是一个**队列**加上一个**双端队列**完成。
队列用于保存所有元素；双端队列用于保存可能的最大值

双端队列维护的是一个单减序列，因为**位于较大值左边的较小值是没有意义的**，类似于滑动窗口

```c++
class MaxQueue {
private:
    int* head;
    int* tail;
    // 维护单减序列（位于较大值左边的较小值是没有意义的）
    int* maxHead;
    int* maxTail;
public:
    MaxQueue() {
        head = tail = new int[10000];
        maxHead = maxTail = new int[10000];
    }
    
    int max_value() {
        if (maxHead == maxTail) return -1;
        return *maxHead;
    }
    
    void push_back(int value) {
        *tail++ = value;
        while (maxTail != maxHead && value > *(maxTail - 1)){
            maxTail--;
        }
        *maxTail++ = value;
    }
    
    int pop_front() {
        if (head == tail) return -1;
        if (*head == *maxHead) maxHead++;
        return *head++;
    }
};
```



### 剑指 Offer 30. 包含min函数的栈

> 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)

与上一题类似，分析这种**局部max**或者**局部min**值时，最重要的是判断下面一句话：

**位于较X值X边的较X值无意义，所以维护单X序列**

一旦搞清楚这句话，题目就好做了

```c++
class MinStack {
private:
    // 位于较小值右边的较大值无意义，所以维护单减序列
    stack<int> s, mini;

public:
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if (mini.empty() || x <= mini.top()){
            mini.push(x);
        }
    }
    
    void pop() {
        int v = s.top();
        if (v == mini.top()){
            mini.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return mini.top();
    }
};
```



### 剑指 Offer 31. 栈的压入、弹出序列

> 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

模拟便能得到答案，需要注意的一点是：当元素全部push进栈后，如果执行一遍pop操作仍未全弹出，那么就可以得出这个popped无法实现的结论

***// TODO 能不能用数学方法？***

```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pos = 0;
        stack<int> s;
        for (int num : pushed){
            s.push(num);
            while (!s.empty() && s.top() == popped[pos]){
                s.pop(); ++pos;
            }
        }
        return s.empty();
    }
};
```



### 剑指 Offer 32 - II. 从上到下打印二叉树 II

> 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，**每一层打印到一行**。

1. 首先想到的是增加一个辅助队列，每一层将下一层要计数的结点push进辅助队列中，再把辅助队列赋值给原队列，得到结果，但是费时费空间
2. 用**计数**的方法，注意到每次q的大小都是该层的结点数量，所以每层都只需要q.size()次循环即可，这样就只需要一个队列了

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int count = q.size();
            vector<int> level(count);
            for (int i = 0; i < count; ++i){
                TreeNode* t = q.front();
                level[i] = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                q.pop();
            }
            res.emplace_back(level);
        }
        return res;
    }
};
```



### 剑指 Offer 32 - III. 从上到下打印二叉树 III

> 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

使用**双端队列**，每次从前往后遍历时使用push_back，从后往前遍历时使用push_front，否则队头队尾数据可能会被push进来的数据替换，导致输出错误

**误区**：从右到左打印不能简单的反转每次push的顺序，而是整个层队列的反转！

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque<TreeNode*> q;
        q.push_back(root);
        bool flag = 1;
        while (!q.empty()){
            int len = q.size();
            vector<int> level(len);
            if (flag){
                for (int i = 0; i < len; ++i){
                    TreeNode* t = q.front();
                    level[i] = t->val;
                    if (t->left) q.push_back(t->left);
                    if (t->right) q.push_back(t->right);
                    q.pop_front();
                }
            } else {
                for (int i = 0; i < len; ++i){
                    TreeNode* t = q.back();
                    level[i] = t->val;
                    if (t->right) q.push_front(t->right);
                    if (t->left) q.push_front(t->left);
                    q.pop_back();
                }
            }
            flag ^= 1;
            res.emplace_back(level);
        }
        return res;
    }
};
```



### *剑指 Offer 33. 二叉搜索树的后序遍历序列

> 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 `true`，否则返回 `false`。假设输入的数组的任意两个数字都互不相同。

1. 判断是否是后序遍历：使用递归的方法，找到左右子树分界点**（第一个小于根节点的点往左就是左子树，往右除根外就是右子树）**，分别进行递归
2. 判断是否是搜索二叉树：用mini和maxi递归框定每一个结点的取值范围，**左子树为【mini，该根节点大小】，右子树为【该根节点大小，maxi】**

```c++
class Solution {
public:
    bool isPost(vector<int>& postorder, int low, int high, int mini = INT_MIN, int maxi = INT_MAX){
        if (low >= high) return 1;
        for (int i = high; i >= low; --i){
            if (postorder[i] < mini || postorder[i] > maxi) return 0;
            if (postorder[i] < postorder[high]){
                return isPost(postorder, low, i, mini, postorder[high]) && 
                       isPost(postorder, i + 1, high - 1, postorder[high], maxi);
            }
        }
        return isPost(postorder, low, high - 1, postorder[high], maxi);
    }

    bool verifyPostorder(vector<int>& postorder) {
        size_t len = postorder.size();
        if (!len) return 1;
        return isPost(postorder, 0, len - 1);
    }
};
```



### 剑指 Offer 34. 二叉树中和为某一值的路径

> 给你二叉树的根节点 `root` 和一个整数目标和 `targetSum` ，找出所有 **从根节点到叶子节点** 路径总和等于给定目标和的路径。

简单的回溯，需要注意题目要求的终止条件是遇到叶子节点且满足target

```c++
class Solution {
public:
    vector<vector<int>> res;
    void dfs(TreeNode* root, int target, vector<int>& path){
        if (!root) return;
        path.emplace_back(root->val);
        if (target == root->val && !root->left && !root->right){
            res.emplace_back(path);
        }
        dfs(root->left, target - root->val, path);
        dfs(root->right, target - root->val, path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> path;
        dfs(root, target, path);
        return res;
    }
};
```



### 剑指 Offer 35. 复杂链表的复制

> 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

难点在于如何确定新链表和原链表的结点对应关系

可以用一个哈希表创造一一对应，若表中没有，则创建新结点，表中有则用表中的，最后递归求解

```c++
class Solution {
public:
    // 原链表和新链表的结点对应关系
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        if (!mp.count(head)){
            Node* temp = new Node(head->val);
            mp[head] = temp;
            temp->next = copyRandomList(head->next);
            temp->random = copyRandomList(head->random);
        }
        return mp[head];
    }
};
```



### *剑指 Offer 36. 二叉搜索树与双向链表

> 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

中序遍历，把应该输出值的语句换成连接链表的语句，pre和当前root连

注意：不能连right！因为right可能已经改位置了，并不是连续的右子树

```c++
class Solution {
public:
    Node* pre = nullptr;
    Node* first = nullptr;
    void dfs(Node* root){
        if (!root) return;

        dfs(root->left);
        // pre和first只有一开始全为空，first也只需要初始化一次
        if (pre) pre->right = root;
        else first = root;
        // 把pre和root连起来
        root->left = pre;
        // 更新pre
        pre = root;

        dfs(root->right);
        return;
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        dfs(root);
        first->left = pre;
        pre->right = first;
        return first;
    }
};
```



### 剑指 Offer 38. 字符串的排列

> 输入一个字符串，打印出该字符串中字符的所有排列。
>
> 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

解法为回溯，需要注意的是字符串中的**重复元素**，需要保证重复元素**按顺序**计数，这样就不会得到重复结果

1. 对数组排序

2. 设一个vis数组

3. 判断是否重复`i > 0 && s[i] == s[i - 1]`

4. 判断是否按顺序`&& vis[i - 1] == 0`表示前面重复的还没有取，因此是不合理的

注意：

- 由于存在循环，`vis[i] = 1`这句话要放在循环中
- 顺序不对时只需要使用continue，而不是return，因为后面仍然有可能按顺序取前面的，**这是循环，不是单向的！**
- 每次都是再循环中添加temp的值，所以i == pos时不需要特殊考虑

当然，C++里有一个库函数叫做`next_permutation();`，可以直接用这个

```c++
class Solution {
public:
    size_t len;
    int vis[8] = {0};
    vector<string> res;
    string temp;
    void dfs(string& s, int pos){
        if (pos == len){
            res.emplace_back(temp);
            return;
        }
        for (int i = 0; i < len; ++i){
            // 相同的要保证顺序
            if (vis[i] || i > 0 && s[i] == s[i - 1] && vis[i - 1] == 0) continue;

            temp += s[i];
            vis[i] = 1;
            dfs(s, pos + 1);
            vis[i] = 0;
            temp = temp.substr(0, temp.size() - 1);
        }
    }

    vector<string> permutation(string s) {
        len = s.size();
        sort(s.begin(), s.end());
        dfs(s, 0);
        return res;
    }
};
```



### 剑指 Offer 39. 数组中出现次数超过一半的数字

> 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
>
> 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

摩尔投票法，两个不同的数字可以相互抵消，最后剩下的就是出现过半的数字

**如果改为超过三分之一呢？**

那就是每三个不同的数进行一次抵消

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        size_t len = nums.size();
        int fre[2] = {0};
        fre[0] = nums[0];
        fre[1] = 1;
        for (int i = 1; i < len; ++i){
            if (nums[i] == fre[0]){
                fre[1]++;
            } else {
                if (fre[1] == 0){
                    fre[0] = nums[i];
                    fre[1]++;
                } else {
                    fre[1]--;
                }
            }
        }
        return fre[0];
    }
};
```



### *剑指 Offer 40. 最小的k个数

> 输入整数数组 `arr` ，找出其中最小的 `k` 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

**快排还是重要啊！**

1. partition中，`--high`后赋值是`arr[low] = arr[high]`，因为要把low的覆盖
2. 注意pivitloc和k的关系，一定要用`pivotloc - low + 1`和`k`作比较
3. 排序时pivotloc位置的数不需要参与

```c++
class Solution {
public:
    size_t len;

    int partition(vector<int>&arr, int low, int high){
        int temp = arr[low];
        while (low < high){
            while (low < high && arr[high] >= temp) --high;
            arr[low] = arr[high];
            while (low < high && arr[low] <= temp) ++low;
            arr[high] = arr[low];
        }
        arr[low] = temp;
        return low;
    }

    void qsort(vector<int>& arr, int k, int low, int high){
        if (low < high){
            int pivotloc = partition(arr, low, high);
            if (pivotloc < k - 1){
                qsort(arr, k, pivotloc + 1, high);
            } else if (pivotloc > k - 1){
                qsort(arr, k, low, pivotloc - 1);
            } else return;
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        len = arr.size();
        qsort(arr, k, 0, len - 1);
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }
};
```



### 剑指 Offer 45. 把数组排成最小的数

> 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

如何让拼出来的数字最小？如何确定每个字符的优先级？

其实这可以看作是一个子问题，两个数拼成最小字符串，只需要**两个数交换相连比较一下**就好了（cmp的“新”用法！）

实在无法用逻辑来判断的地方，用实践就可以

```c++
class Solution {
public:
    static bool cmp(string& a, string& b){
        return a + b < b + a;
    }

    string minNumber(vector<int>& nums) {
        size_t len = nums.size();
        vector<string> nums2(len);
        for (int i = 0; i < len; ++i){
            nums2[i] = to_string(nums[i]);
        }
        sort(nums2.begin(), nums2.end(), cmp);
        string res;
        for (string s : nums2) res += s;
        return res;
    }
};
```



### 剑指 Offer 46. 把数字翻译成字符串

> 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

动态规划上楼梯，多一个判断的条件，注意不要想得太简单了，动规都得多想想

可以进一步优化掉dp数组，变成3个变量dp0，dp1和dp2

```c++
class Solution {
public:
    int translateNum(int num) {
        int origin = num, len = 0;
        while (origin){
            ++len;
            origin /= 10;
        }
        if (len <= 1) return 1;
        vector<int> nums(len), dp(len);
        int pos = len - 1;
        while (num){
            nums[pos--] = num % 10;
            num /= 10;
        }
        dp[0] = 1;
        if (nums[0] == 0) dp[1] = 1;
        else if (nums[0] * 10 + nums[1] > 25) dp[1] = 1;
        else dp[1] = 2;

        for (int i = 2; i < len; ++i){
            if (nums[i - 1]){
                int temp = nums[i - 1] * 10 + nums[i];
                if (temp >= 10 && temp <= 25) dp[i] = dp[i - 1] + dp[i - 2];
                else dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[len - 1];
    }
};
```



### *剑指 Offer II 004. 只出现一次的数字

> 给你一个整数数组 `nums` ，除某个元素仅出现 **一次** 外，其余每个元素都恰出现 **三次 。**请你找出并返回那个只出现了一次的元素。

**太牛了**

运用到数电的知识

首先我们把题目转化：我们用二进制看待每一个数，**把所有数每个位上的数相加，如果最终得到3的倍数，那么这个数就重复了三次；如果最后得到的数是3的倍数加1，那就是我们求的数**

1. 设定a，b两个变量，用于保存各个位的出现次数（各个位00，01，10循环，因为重复数只出现三次），最后一定是a等于0，b是我们要求的数

2. 列表，找出a和b各位和新来数字x各位之间的关系（因为各位之间独立，所以整个数可以一起操作）

   | $(a_i b_i)$ | $x_i$ | 新的$(a_i b_i)$ |
   | ----------- | ----- | --------------- |
   | 00          | 0     | 00              |
   | 00          | 1     | 01              |
   | 01          | 0     | 01              |
   | 01          | 1     | 10              |
   | 10          | 0     | 10              |
   | 10          | 1     | 00              |

3. 分别得出$a_i$和$b_i$的计算表达式

   a = (~a & b & x) | (a & ~b & ~x)

   b = ~a & (b ˆx)

**注意：a，b同时更新，因此这里使用了tie函数（可以用来把几个不同类型的数据打包成一个tuple，实现批量赋值）**

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num: nums) {
            tie(a, b) = pair{(~a & b & num) | (a & ~b & ~num), ~a & (b ^ num)};
        }
        return b;
    }
};
```



### 剑指 Offer 47. 礼物的最大价值

> 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

左上角走到右下角的动态规划

这里压缩了空间，因为每一个只需要考虑上一行的状态值和左边一位的状态值

**tip：**数组多开一位写起来会方便很多

```c++
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> dp(cols + 1);
        for (int i = 1; i <= cols; ++i) dp[i] = dp[i - 1] + grid[0][i - 1];
        for (int i = 1; i < rows; ++i){
            for (int j = 1; j <= cols; ++j){
                dp[j] = max(dp[j - 1], dp[j]) + grid[i][j - 1];
            }
        }
        return dp[cols];
    }
};
```



### 剑指 Offer 48. 最长不含重复字符的子字符串

> 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

双指针“赛跑”，途中值用vector记录

- $end$指针一直往右移动，将vector中未出现的值均置一
- 遇到重复值后，让$begin$指针向右移动，直到处于与$end$指针指向值相同的后一位，并把途中值置零
- 结束标志是$end$到达末尾，因此**末尾要特判**

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0, end = 0;
        size_t len = s.size();
        if (!len) return 0;
        int fre[256] = {0};
        int maxi = 1;
        while (end != len){
            char e = s[end];
            if (fre[e] == 1){
                maxi = max(maxi, end - begin);
                while (s[begin] != e){
                    fre[s[begin]] = 0;
                    ++begin;
                }
                ++begin;
            }
            fre[e] = 1;
            ++end;
        }
        return max(maxi, end - begin);
    }
};
```



### *剑指 Offer 49. 丑数

> 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

**动态规划真难想**

- 考虑到每一个数字都需要×2、×3、×5，我们用$p2$、$p3$、$p5$三个指针指向还没有乘过这个因数的最小值所在位置
- 每次选取这三个指针指向数产生的最小值
- 更新**所有指针**，如果和最小值相同，则后移一位（避免产生重复数字）

```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        // 第i个丑数
        vector<int> dp(n + 1);
        dp[1] = 1;
        // 每个数都要*2、*3、*5
        int p2, p3, p5;
        p2 = p3 = p5 = 1;
        for (int i = 2; i <= n; ++i){
            // 找到下一个数（最小值）
            int mini = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
            dp[i] = mini;
            // 乘过了或者重复了都要跳下一个
            if (mini == dp[p2] * 2) ++p2;
            if (mini == dp[p3] * 3) ++p3;
            if (mini == dp[p5] * 5) ++p5;
        }
        return dp[n];
    }
};
```



### 剑指 Offer 50. 第一个只出现一次的字符

> 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

- 先找出现一次的字符：由于题目中说明是小写字母，所以可以用数组来存
- 再找第一次出现的：遍历原字符串，一个个找看出现次数是不是1

```c++
class Solution {
public:
    char firstUniqChar(string s) {
        int fre[26] = {0};
        for (char t : s){
            ++fre[t - 97];
        }
        for (char t : s){
            if (fre[t - 97] == 1) return t;
        }
        return ' ';
    }
};
```



### 剑指 Offer 52. 两个链表的第一个公共节点

> 输入两个链表，找出它们的第一个公共节点。

- 两链表长度之和是保持不变的，因此只要一个扫完去另一个的头，最后一定能走到相同结点
- 注意不相交和链表为空的情况

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;
        if (!A || !B) return nullptr;
        while (A != B){
            A = A->next;
            B = B->next;
            if (!A && !B) return nullptr;
            if (!A) A = headB;
            if (!B) B = headA;
        }
        return A;
    }
};
```



### 剑指 Offer 54. 二叉搜索树的第k大节点

> 给定一棵二叉搜索树，请找出其中第k大的节点。

从右往左的“逆序中序遍历”，用$k$来计数

**注：**$k$不能放在递归参数中，因为每统计一个$k$，减了就是减了，不能再回溯

```c++
class Solution {
public:
    int res = -1;
    int num;
    void dfs(TreeNode* root){
        if (!num) return;
        if (!root) return;
        dfs(root->right);
        if (--num == 0){
            res = root->val;
            return;
        }
        dfs(root->left);
    }

    int kthLargest(TreeNode* root, int k) {
        num = k;
        dfs(root);
        return res;
    }
};
```



### *剑指 Offer 55 - II. 平衡二叉树

> 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

妙哇

采用**自底向上**的策略！**计算高度的同时判断是否平衡**！

- 首先和常规递归一样，二叉树会遍历到底，这时我们选取左右两个结点的递归返回值（即高度）进行比较，若不平衡则返回-1

- 在遍历过程中，如果出现$le$或$ri$为-1的现象，则直接返回-1，因为它们的子树不平衡
- 最后返回的是高度，用于平衡的比较

```c++
class Solution {
public:
    int height(TreeNode* root){
        if (!root) return 0;
        int le = height(root->left);
        int ri = height(root->right);
        if (le == -1 || ri == -1) return -1;
        if (abs(le - ri) > 1) return -1;
        return max(le, ri) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
```



### *剑指 Offer 56 - I. 数组中数字出现的次数

> 一个整型数组 `nums` 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

两个非重复数字出现在一群出现两次数的数组中

- 首先我们容易得出这两个数字的异或结果`sum`
- `sum`一定有某一位是1
- 根据这一点，把原数组分为两个部分，**一部分是这位是1的，另一部分是这位不是1的**
- 由于其它数字都能被异或成0，所以两部分会分别出一个数，也就是结果

```c++
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum ^= num;
        // sum一定有至少一位是1，因为存在不同的两数，所以我们找出1
        // 这样就能把nums数组分为两部分，一部分里面只存在一个只出现一次的数
        int border = 1;
        while ((border & sum) == 0){
            border <<= 1;
        }
        int a = 0, b = 0;
        for (int num : nums){
            if (num & border) a ^= num;
            else b ^= num;
        }
        return {a, b};
    }
};
```



### 剑指 Offer 57. 和为s的两个数字

> 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

双指针

从左右往中间夹逼（可以判重复直接掠过，在数据量大的情况下有优势）

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end){
            int sum = nums[begin] + nums[end];
            if (sum == target) return {nums[begin], nums[end]};
            if (sum > target){
                do --end; while (nums[end] == nums[end - 1]);
            } else {
                do ++begin; while (nums[begin] == nums[begin + 1]);
            }
        }
        return {0, 0};
    }
};
```



### 剑指 Offer 57 - II. 和为s的连续正数序列

> 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
>
> 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

本题采用数学方法，设$n$为累加开始的数字，$k$为累加的数字个数，$t$为目标数字，则有下列三个约束式
$$
\begin{cases}
1+2+…+(k-1) \le t \\
n \ge 1\\
t=n+(n+1)+…+(n+k-1)
\end{cases}
$$
由这三个约束式能解出$k$的取值范围，进而得到循环上下界，再用整数这一条件进行$n$的约束，就能得到结果

```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 2n + 1, 3n + 1 + 2, kn + 1 + 2 + ... + k - 1 = kn + k(k - 1) / 2
        vector<vector<int>> res;
        double maxi = min((sqrt(1 + 8 * target) + 1.) / 2, sqrt((-1 + 8 * target) + 1.) / 2);
        int end = ceil(maxi);
        for (int i = end; i >= 2; --i){
            double temp = 1. * target / i - (i - 1) / 2.;
            int itemp = int(temp);
            if (!itemp) continue;
            if (fabs(temp - itemp) < 1e-5){
                vector<int> t(i);
                for (int j = 0; j < i; ++j) t[j] = itemp + j;
                res.emplace_back(t);
            }
        }
        return res;
    }
};
```



### 剑指 Offer 58 - I. 翻转单词顺序

> 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

- 先判断字符串是不是全为空格
- 吃空格
- 吃字符，吃完后push到栈中
- 最后一个需要特判（或者在原字符串末尾加一个空格）

```c++
class Solution {
public:
    string reverseWords(string s) {
        stack<string> res;
        string temp;
        int pos = 0;
        size_t len = s.size();
        while (pos != len && s[pos] == ' ') ++pos;
        if (pos == len) return "";

        while (pos != len){
            while (pos != len && s[pos] == ' ') ++pos;
            while (pos != len && s[pos] != ' '){
                temp += s[pos++];
            }
            if (temp != "") res.push(temp);
            temp = "";
        }
        if (temp != "") res.push(temp);
        string ans;
        while (res.size() != 1){
            ans += res.top() += " ";
            res.pop();
        }
        return ans += res.top();
    }
};
```



### *剑指 Offer 59 - I. 滑动窗口的最大值

> 给定一个数组 `nums` 和滑动窗口的大小 `k`，请找出所有滑动窗口里的最大值。

- deque是用来模拟滑动窗口的，但是由于位于较大值左边的较小值无意义，所以可以维护递增序列，让模拟的滑动窗口变成简化的滑动窗口
- 是否要移除第一个元素需要判断下标（因为下标是定死的）
- 每次的最大值都是队头下标对应的数

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 位于较大值左边的较小值无意义
        vector<int> res;
        deque<int> dq;
        for (int i = 0, len = nums.size(); i < len; ++i){
            while (!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            while (dq.front() < i - k + 1){
                dq.pop_front();
            }
            if (i >= k - 1) res.emplace_back(nums[dq.front()]);
        }
        return res;
    }
};
```



### 剑指 Offer 60. n个骰子的点数

> 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

动态规划

- dp\[i\]\[j\]表示i个骰子扔到j的可能性

- dp\[i\]\[j\] = 【所有可能扔到的数字减去（1~6）】对应的【i - 1个骰子扔到该数字】的【概率乘六分之一】的【和】

```c++
class Solution {
public:
    vector<double> dicesProbability(int n) {
        double dp[12][70] = {0};
        for (int i = 1; i <= 6; ++i) dp[1][i] = 1. / 6;
        for (int dice = 2; dice <= 11; ++dice){
            for (int possibleNum = dice; possibleNum <= dice * 6; ++possibleNum){
                for (int newNum = 1; newNum <= 6; ++newNum){
                    if (possibleNum - newNum >= 0)
                        dp[dice][possibleNum] += dp[dice - 1][possibleNum - newNum] * 1. / 6;
                }
            }
        }
        vector<double> res;
        for (int i = 1; i < 70; ++i){
            if (dp[n][i]) res.emplace_back(dp[n][i]);
        }
        return res;
    }
};
```



### 剑指 Offer 61. 扑克牌中的顺子

> 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

排序 + 去重 + 快速判断

- 如果没有重复元素，那么只要看**非零的最大值和最小值之间相差是否小于四**即可判断
- 如果有重复元素，返回false

```c++
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zeros = 0;
        while (nums[zeros] == 0) ++zeros;
        for (int i = zeros + 1; i < 5; ++i){
            if (nums[i] == nums[i - 1]) return 0;
        }
        return nums[4] - nums[zeros] < 5;
    }
};
```



### 剑指 Offer 68 - II. 二叉树的最近公共祖先

> 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
>
> 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

方法为dfs，重点在如何判断要不要继续往下搜索

- 用全局变量res保存目前的最近公共祖先
- 返回值表示这个子树中有没有p或者q
- **自底向上**
- 第一种情况，左子树和右子树中均含有，那么这个结点一定是所求的
- 第二种情况，本结点是p或q，其中一子树含有，那么这个结点一定是所求的
- 第三种情况，只有一子树含有，那么继续往上走

```c++
class Solution {
public:
    TreeNode* res = nullptr;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root) return 0;
        bool a = dfs(root->left, p, q);
        bool b = dfs(root->right, p, q);
        // p和q分别在左右子树
        if (a && b) res = root;
        // p和q一个是本结点，另一个是在左右子树中
        else if ((p->val == root->val || q->val == root->val) && (a || b)) res = root;
        return a || b || p->val == root->val || q->val == root->val;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};
```



### 剑指 Offer 66. 构建乘积数组

> 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

以i为分界线，左边积 * 右边积 就是结果，所以维护两个数组

- $left$数组从左往右累乘
- $right$数组从右往左累乘
- 不需要引入第三个数组，直接把$right$的元素乘到$left$中，需要注意的是$left[i]$中元素是$left[i - 1] * right[i + 1]$，需要用到左边的元素，因此不能从左往右遍历，要从右往左

```c++
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        size_t len = a.size();
        if (!len) return {};
        vector<int> left = a;
        for (int i = 1; i < len; ++i) left[i] *= left[i - 1];
        vector<int> right = a;
        for (int i = len - 2; i >= 0; --i) right[i] *= right[i + 1];
        int k1 = right[1];
        int k2 = left[len - 2];
        for (int i = len - 2; i >= 1; --i){
            left[i] = left[i - 1] * right[i + 1];
        }
        left[0] = k1;
        left[len - 1] = k2;
        return left;
    }
};
```

### *剑指 Offer 65. 不用加减乘除做加法

> 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

位运算实现加法

- 记录11的情况，记录进位，即$carry=a\&b$，但是要注意因为有负数，需要用无符号数$usigned\ carry=a\&b$
- 由于是进位符号，$carry$需要左移一位
- 除开进位后，实现各个位的变化（10出1、01出1、11出0、00出0），即异或
- 将进位赋值给$b$，判断循环结束的条件就是$b == 0$

```c++
class Solution {
public:
    int add(int a, int b) {
        // 相异得1，相同00不变，11进位
        while (b){
            unsigned carry = unsigned(a & b);
            carry <<= 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
```



### 剑指 Offer II 002. 二进制加法

> 给定两个 01 字符串 `a` 和 `b` ，请计算它们的和，并以二进制字符串的形式输出。
>
> 输入为 **非空** 字符串且只包含数字 `1` 和 `0`。

从右往左计算，还要考虑余下的字符

- 在从右往左计算时，结果都保存在$a$数组中，那么余下字符有两种情况（$a$的或$b$的），用$temp$取出余下字符
- 如果余下字符为空，那么判断$carry$，如果$carry$为1，那么返回加上这一位的$a$
- 如果余下字符不为空，后面有$carry$进位，那么temp还需要进行计算，可以用`add(temp, "1");`进行递归运算
- 最后返回$temp$加上$a$的余下字符

```c++
class Solution {
public:
    string add(string a, string b){
        size_t len1 = a.size(), len2 = b.size();
        int carry = 0;
        int i, j;
        for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; --i, --j){
            if (a[i] == b[j]){
                if (a[i] == '0'){
                    if (carry) a[i] = '1', carry = 0;
                } else {
                    if (!carry) a[i] = '0', carry = 1;
                }
            } else {
                if (carry) a[i] = '0';
                else a[i] = '1';
            }
        }
        string temp;
        if (i == -1 && j == -1) return carry ? "1" + a : a;
        if (i == -1) temp = b.substr(0, j + 1);
        else temp = a.substr(0, i + 1);
        if (carry) return add(temp, "1") + a.substr(i + 1);
        return temp + a.substr(i + 1);
    }

    string addBinary(string a, string b) {
        return add(a, b);
    }
};
```



### *剑指 Offer II 005. 单词长度的最大乘积

> 给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时，它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。

最简单的方法是暴力双层for循环，但是这里使用$bitMap$进行了优化

- $bitmap$，把一个数据用位来表示就可以把二维数组简化为一个$int$变量的$map$，例如对小写字母构成的字符串来说，统计其**是否出现**：`int a[1000][26];`可以简化为`map<int, int> a\[1000\];`，其中每一个$int$数字都是用$26$位二进制数表示对应字符的存在与否
- 本题先创建$bitMap$，$key$是由相同字母组成的字符串表示，$value$是这些字符串中的最大长度
- 用两层循环获得$key$不含相同位的字符串的长度乘积，并更新$maxi$

```c++
class Solution {
public:
    unordered_map<int, int> bitMap;
    int maxProduct(vector<string>& words) {
        size_t len = words.size();
        for (string& word : words){
            int bit = 0;
            for (char s : word){
                bit |= (1 << (s - 97));
            }
            if (bitMap[bit]) bitMap[bit] = fmax(bitMap[bit], word.size());
            else bitMap[bit] = word.size();
        }
        int maxi = 0;
        for (auto& [bit1, value1] : bitMap){
            for (auto& [bit2, value2] : bitMap){
                if (!(bit1 & bit2)){
                    maxi = max(maxi, value1 * value2);
                }
            }
        }
        return maxi;
    }
};
```



### 剑指 Offer II 008. 和大于等于 target 的最短子数组

> 给定一个含有 n 个正整数的数组和一个正整数 target 。
>
> 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

贪心的策略

- 若和大了则start右移一格
- 若和小了则end右移一格

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = 0;
        int sum = nums[0];
        int mini = len + 1;
        while (end < len){
            if (sum >= target){
                mini = min(mini, end - start + 1);
                sum -= nums[start++];
            } else {
                if (end == len - 1) break;
                sum += nums[++end];
            }
        }
        return mini == len + 1 ? 0 : mini;
    }
};
```



### 剑指 Offer II 013. 二维子矩阵的和

> 给定一个二维矩阵 matrix，以下类型的多个请求：
>
> 计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。

和求导一个道理，从原点到右下角的面积，减去原点到右上角上一行，减去原点到左下角左一行，再加上左上角左上点

要注意的是原矩阵下标最小是0，定位上一行可能会溢出，所以要新申请一个vector

```c++
class NumMatrix {
private:
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        size_t rows = matrix.size(), cols = matrix[0].size();
        this->matrix.resize(rows + 1, vector<int>(cols + 1));
        
        for (int i = 0; i < rows; ++i){
            for (int j = 1; j < cols; ++j){
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for (int i = 0; i < cols; ++i){
            for (int j = 1; j < rows; ++j){
                matrix[j][i] += matrix[j - 1][i];
            }
        }

        for (int i = 1; i <= rows; ++i){
            for (int j = 1; j <= cols; ++j){
                this->matrix[i][j] = matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrix[row2 + 1][col2 + 1] - matrix[row1][col2 + 1] - matrix[row2 + 1][col1] + matrix[row1][col1];
    }
};
```
