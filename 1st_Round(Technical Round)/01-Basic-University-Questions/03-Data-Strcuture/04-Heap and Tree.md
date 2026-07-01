# Heap and Tree

---

# 1. Heap

---

## 1.1 Definition

A **Heap** is a **complete binary tree** that satisfies the **Heap Property**.

There are two types of heaps:

- **Max Heap** → Every parent is **greater than or equal to** its children.
    
- **Min Heap** → Every parent is **less than or equal to** its children.
    

> Unlike a Binary Search Tree (BST), heaps do **not** maintain sorted order.

---

## 1.2 Why Heap Exists

A heap is designed to efficiently retrieve the **highest-priority** or **lowest-priority** element.

Without a heap, repeatedly finding the largest or smallest element would take **O(n)** time.

Heaps reduce this to:

- Insert → **O(log n)**
    
- Remove Highest/Lowest Priority → **O(log n)**
    
- Access Highest/Lowest Priority → **O(1)**
    

Common applications:

- Priority Queue
    
- CPU Scheduling
    
- Dijkstra's Algorithm
    
- Prim's Algorithm
    
- Heap Sort
    
- Task Scheduling
    
- Event Simulation
    

---

## 1.3 Mental Model

Imagine a company where every manager earns more than their employees.

```
          100
         /   \
       80     70
      / \     / \
    60 50   40 30
```

The CEO (root) always has the highest salary.

Every manager earns more than their direct employees.

This is exactly how a **Max Heap** works.

---

## 1.4 Types of Heap

### Max Heap

```
          90
         /  \
       70    60
      / \   / \
    50 40 30 20
```

Largest element is always at the root.

---

### Min Heap

```
          10
         /  \
       20    30
      / \   / \
    40 50 60 70
```

Smallest element is always at the root.

---

## 1.5 Heap Properties

A heap satisfies two conditions:

### 1. Complete Binary Tree

Every level is completely filled except possibly the last.

Last level is filled from **left to right**.

```
Correct

        1
      /   \
     2     3
    / \   /
   4  5  6
```

---

### 2. Heap Order Property

For Max Heap:

```
Parent ≥ Children
```

For Min Heap:

```
Parent ≤ Children
```

---

## 1.6 Array Representation

A heap is usually stored in an array.

```
          100
         /   \
       90     80
      / \     / \
    70 60   50 40
```

Array:

```
Index : 0 1 2 3 4 5 6

Value :100 90 80 70 60 50 40
```

Relationships:

```
Left Child  = 2*i + 1

Right Child = 2*i + 2

Parent = (i-1)/2
```

---

## 1.7 Basic Operations

|Operation|Description|
|---|---|
|Insert|Add new element|
|Delete|Remove root|
|Top|Access root|
|Heapify|Restore heap property|
|Build Heap|Convert array into heap|

---

## 1.8 C++ Syntax (Max Heap)

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> pq;

    pq.push(50);
    pq.push(80);
    pq.push(30);
    pq.push(90);

    cout << pq.top() << endl;

    pq.pop();

    cout << pq.top();

    return 0;
}
```

Output

```
90
80
```

---

## 1.9 Min Heap Syntax

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int,
                   vector<int>,
                   greater<int>> pq;

    pq.push(40);
    pq.push(20);
    pq.push(80);

    cout << pq.top();

    return 0;
}
```

Output

```
20
```

---

## 1.10 Basic Example

```cpp
priority_queue<int> pq;

pq.push(100);
pq.push(50);
pq.push(200);

cout << pq.top();

pq.pop();

cout << pq.top();
```

Output

```
200
100
```

---

## 1.11 Step-by-Step Heap Insertion

Insert:

```
40
```

```
40
```

---

Insert:

```
20
```

```
    40
   /
 20
```

---

Insert:

```
60
```

```
    40
   /  \
 20   60
```

Swap with parent

```
    60
   /  \
 20   40
```

---

## 1.12 Internal Behavior (Heapify Up)

Insert:

```
10
40
30
80
```

```
       10
      /
     40
    /
   30
  /
80
```

80 compares with parent.

Swap.

Continue until heap property is restored.

---

## 1.13 Real-World Example (Task Scheduler)

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> tasks;

    tasks.push(3);
    tasks.push(8);
    tasks.push(5);

    while(!tasks.empty()) {

        cout << "Execute Priority "
             << tasks.top() << endl;

        tasks.pop();
    }

    return 0;
}
```

---

## 1.14 Real-World Usage

### Backend

- Job scheduling
    
- Process scheduling
    
- Event simulation
    
- Load balancing
    
- Database query optimization
    

### Frontend

- Animation priority
    
- Task prioritization
    
- Notification priority
    

---

## 1.15 Incorrect Example

### ❌ Wrong

```cpp
priority_queue<int> pq;

cout << pq.top();
```

---

### ✅ Correct

```cpp
priority_queue<int> pq;

if(!pq.empty())
    cout << pq.top();
```

---

## 1.16 Edge Cases

- Empty heap
    
- Duplicate values
    
- Single node
    
- Large insertions
    
- Deleting until empty
    

---

## 1.17 Time Complexity

|Operation|Complexity|
|---|---|
|Insert|O(log n)|
|Delete Root|O(log n)|
|Peek|O(1)|
|Build Heap|O(n)|
|Heapify|O(log n)|

---

## 1.18 Heap vs Binary Search Tree

|Feature|Heap|BST|
|---|---|---|
|Sorted|❌|✅ (Inorder)|
|Root|Highest/Lowest|Depends|
|Search|O(n)|O(log n) Average|
|Insert|O(log n)|O(log n) Average|
|Delete|O(log n)|O(log n) Average|
|Main Use|Priority Queue|Searching|

---

## 1.19 Key Points

- Complete Binary Tree
    
- Priority-based structure
    
- Stored using arrays
    
- Root contains highest/lowest priority
    
- Used in Priority Queue
    
- Excellent for scheduling problems
    

---

## 1.20 Common Mistakes

|Mistake|Fix|
|---|---|
|Expecting sorted traversal|Heap is **not** sorted|
|Accessing arbitrary element|Only root is guaranteed|
|Calling `top()` on empty heap|Check `empty()` first|

---

## 1.21 Interview Tips

Common questions:

- Difference between Heap and BST?
    
- Why heap uses arrays?
    
- Explain Heapify.
    
- What is Build Heap?
    
- Why Build Heap is O(n)?
    
- Difference between Max Heap and Min Heap?
    

---

## 1.22 Interview Summary

- Complete Binary Tree
    
- Heap Property
    
- Used for Priority Queue
    
- Root stores highest/lowest priority
    
- Insert/Delete → O(log n)
    

---

# 2. Tree

---

## 2.1 Definition

A **Tree** is a **non-linear hierarchical data structure** made up of **nodes** connected by **edges**.

Unlike arrays or linked lists, a tree represents **parent-child relationships**.

A tree starts with a **Root** node and branches into child nodes.

---

## 2.2 Why Trees Exist

Trees are used when data naturally forms a hierarchy.

Examples include:

- File systems
    
- Organization charts
    
- HTML DOM
    
- Database indexes
    
- Decision trees
    
- Routing tables
    

---

## 2.3 Mental Model

Think of a family tree.

```
          Grandfather
          /         \
      Father       Uncle
      /     \
   You    Sister
```

Each person has a parent and may have children.

---

## 2.4 Terminology

```
          A
         / \
        B   C
       / \
      D   E
```

|Term|Meaning|
|---|---|
|Root|A|
|Parent|A is parent of B|
|Child|B is child of A|
|Leaf|C, D, E|
|Edge|Connection between nodes|
|Height|Longest path from root to leaf|
|Depth|Distance from root|

---

## 2.5 Types of Trees

- Binary Tree
    
- Binary Search Tree (BST)
    
- AVL Tree
    
- Red-Black Tree
    
- Heap
    
- Trie
    
- B-Tree
    
- Segment Tree
    

---

## 2.6 Binary Tree

Each node has **at most two children**.

```
       10
      /  \
     5   20
```

---

## 2.7 Binary Search Tree (BST)

Property:

```
Left < Root < Right
```

Example

```
        50
      /    \
    30      70
   /  \    /  \
 20  40 60 80
```

---

## 2.8 Tree Node in C++

```cpp
#include <iostream>
using namespace std;

struct Node {

    int data;

    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};
```

---

## 2.9 Basic Example

```cpp
#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {

    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(20);

    cout << root->left->data;

    return 0;
}
```

---

## 2.10 Tree Traversals

### Inorder

```
Left → Root → Right
```

### Preorder

```
Root → Left → Right
```

### Postorder

```
Left → Right → Root
```

### Level Order

```
Level by Level
```

---

## 2.11 Inorder Traversal

```cpp
#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

void inorder(Node* root){

    if(root==nullptr)
        return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

int main(){

    Node* root=new Node(2);

    root->left=new Node(1);
    root->right=new Node(3);

    inorder(root);
}
```

Output

```
1 2 3
```

---

## 2.12 Step-by-Step Traversal

Tree

```
      2
     / \
    1   3
```

Inorder:

```
Visit Left

1

Visit Root

2

Visit Right

3
```

Output

```
1 2 3
```

---

## 2.13 Real-World Usage

### Backend

- Database indexing (B-Tree)
    
- File systems
    
- DNS
    
- Search engines
    

### Frontend

- HTML DOM
    
- React Component Tree
    
- Vue Component Tree
    
- Menu hierarchy
    

---

## 2.14 Incorrect Example

### ❌ Wrong

```cpp
cout << root->left->data;
```

when `root` is `nullptr`.

---

### ✅ Correct

```cpp
if(root != nullptr && root->left != nullptr)
    cout << root->left->data;
```

---

## 2.15 Edge Cases

- Empty tree
    
- Single node
    
- Skewed tree
    
- Duplicate values (depends on implementation)
    
- Very deep recursion
    

---

## 2.16 Time Complexity

|Operation|BST Average|BST Worst|
|---|---|---|
|Search|O(log n)|O(n)|
|Insert|O(log n)|O(n)|
|Delete|O(log n)|O(n)|
|Traversal|O(n)|O(n)|

---

## 2.17 Heap vs Tree

|Feature|Heap|Tree|
|---|---|---|
|Structure|Complete Binary Tree|General Hierarchical Structure|
|Ordering|Heap Property|Depends on Tree Type|
|Search|O(n)|O(log n) in BST|
|Storage|Usually Array|Usually Nodes & Pointers|
|Main Use|Priority Queue|Searching & Hierarchies|

---

## 2.18 Key Points

- Non-linear data structure
    
- Hierarchical organization
    
- Root-parent-child relationship
    
- Many specialized tree types
    
- BST enables efficient searching
    
- Traversals are fundamental operations
    

---

## 2.19 Common Mistakes

|Mistake|Fix|
|---|---|
|Confusing Binary Tree with BST|BST has ordering rules|
|Forgetting base case in recursion|Check `root == nullptr`|
|Assuming all trees are balanced|Many trees become skewed|

---

## 2.20 Interview Tips

Frequently asked questions:

- Difference between Tree and Graph?
    
- What is a BST?
    
- Explain tree traversals.
    
- Difference between Heap and BST.
    
- What is a balanced tree?
    
- Why are B-Trees used in databases?
    

---

## 2.21 Interview Summary

- Trees represent hierarchical data.
    
- Binary Trees allow up to two children.
    
- BST maintains sorted order.
    
- Traversals include Inorder, Preorder, Postorder, and Level Order.
    
- Average BST operations are **O(log n)** but degrade to **O(n)** in skewed trees.
    
- Trees are widely used in databases, file systems, DOM structures, and search algorithms.