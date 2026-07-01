# Stack and Queue

---

# 1. Stack

---

## 1.1 Definition

A **Stack** is a **linear data structure** that follows the **LIFO (Last In, First Out)** principle.

> The **last element inserted** into the stack is the **first element removed**.

A stack allows insertion and deletion from **only one end**, called the **Top**.

---

## 1.2 Why Stack Exists

A stack exists to efficiently solve problems where the **most recently added item should be processed first**.

Without a stack, implementing many common programming tasks would be difficult or inefficient.

Typical applications include:

- Function call management
    
- Recursion
    
- Undo/Redo operations
    
- Browser history
    
- Expression evaluation
    
- Backtracking algorithms
    
- Syntax parsing
    
- Depth First Search (DFS)
    

---

## 1.3 Mental Model

Imagine a stack of plates.

```
        Top
         │
     ┌───────┐
     │  30   │
     ├───────┤
     │  20   │
     ├───────┤
     │  10   │
     └───────┘
```

- Add a plate to the top.
    
- Remove the top plate first.
    
- You cannot remove the middle plate directly.
    

---

## 1.4 Internal Behavior

A stack maintains a single pointer called **Top**.

```
Push(10)

Top
 │
 ▼
[10]

Push(20)

     Top
      │
      ▼
[10][20]

Push(30)

         Top
          │
          ▼
[10][20][30]
```

Every new element becomes the new top.

---

## 1.5 Basic Operations

|Operation|Description|STL Function|
|---|---|---|
|Push|Insert element at top|`push()`|
|Pop|Remove top element|`pop()`|
|Top|Access top element|`top()`|
|Empty|Check if stack is empty|`empty()`|
|Size|Number of elements|`size()`|

---

## 1.6 C++ Syntax

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    st.pop();

    cout << "Top after pop: " << st.top() << endl;

    cout << "Size: " << st.size() << endl;

    if(st.empty())
        cout << "Empty";
    else
        cout << "Not Empty";

    return 0;
}
```

---

## 1.7 Basic Example

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> st;

    st.push(5);
    st.push(15);
    st.push(25);

    cout << st.top() << endl;

    st.pop();

    cout << st.top();

    return 0;
}
```

**Output**

```
25
15
```

---

## 1.8 Intermediate Example

Reverse a string using a stack.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {

    string str = "STACK";
    stack<char> st;

    for(char ch : str)
        st.push(ch);

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}
```

**Output**

```
KCATS
```

---

## 1.9 Real-World Example (Balanced Parentheses)

```cpp
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s) {

    stack<char> st;

    for(char ch : s) {

        if(ch == '(')
            st.push(ch);

        else if(ch == ')') {

            if(st.empty())
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main() {

    cout << isBalanced("(())") << endl;
    cout << isBalanced("(()");

    return 0;
}
```

**Output**

```
1
0
```

---

## 1.10 Step-by-Step Breakdown

Suppose we execute:

```cpp
st.push(10);
st.push(20);
st.push(30);
st.pop();
```

### Step 1

```
[10]
```

---

### Step 2

```
[10]
[20]
```

---

### Step 3

```
[10]
[20]
[30]
```

---

### Step 4

```
Pop()

Removed 30

Remaining

[10]
[20]
```

Top becomes **20**.

---

## 1.11 Incorrect Example

### ❌ Wrong

Calling `top()` on an empty stack.

```cpp
stack<int> st;

cout << st.top();
```

This causes **undefined behavior**.

---

### ✅ Correct

```cpp
stack<int> st;

if(!st.empty())
    cout << st.top();
```

---

## 1.12 Edge Cases

### Empty Stack

```cpp
stack<int> st;

cout << st.empty();
```

Output

```
1
```

---

### Single Element

```cpp
stack<int> st;

st.push(100);

cout << st.top();

st.pop();

cout << st.empty();
```

---

### Multiple Pops

Always verify the stack is not empty.

```cpp
while(!st.empty())
    st.pop();
```

---

## 1.13 Time Complexity

|Operation|Complexity|
|---|---|
|Push|O(1)|
|Pop|O(1)|
|Top|O(1)|
|Empty|O(1)|
|Size|O(1)|

---

## 1.14 Real-World Usage

### Backend

- Function call stack
    
- Recursive algorithms
    
- Compiler parsing
    
- Expression evaluation
    
- Undo operations in editors
    

### Frontend

- Browser back navigation
    
- Undo/Redo functionality
    
- Navigation history
    
- Component state rollback
    

---

## 1.15 Key Points

- Linear data structure
    
- Follows LIFO
    
- One insertion/deletion point
    
- Fast O(1) operations
    
- Used heavily in recursion
    
- Does not support random access
    

---

## 1.16 Common Mistakes

|Mistake|Fix|
|---|---|
|Calling `top()` on empty stack|Check `empty()` first|
|Forgetting `pop()`|Remove elements after processing|
|Expecting random access|Use `vector` instead|

---

## 1.17 Interview Tips

Common questions:

- What is LIFO?
    
- Why recursion uses a stack?
    
- Difference between stack and heap?
    
- Implement stack using arrays.
    
- Implement stack using linked lists.
    
- How does browser back button work?
    

---

## 1.18 Interview Summary

- LIFO structure
    
- Single access point
    
- Push and Pop are O(1)
    
- Used in recursion, DFS, parsing, undo systems
    

---

# 2. Queue

---

## 2.1 Definition

A **Queue** is a **linear data structure** that follows the **FIFO (First In, First Out)** principle.

> The **first element inserted** is the **first element removed**.

Insertion happens at the **Rear**, while deletion happens from the **Front**.

---

## 2.2 Why Queue Exists

Queues are designed for situations where tasks must be processed **in the exact order they arrive**.

Common applications include:

- CPU scheduling
    
- Printer jobs
    
- Ticket booking
    
- Task scheduling
    
- Request handling
    
- Messaging systems
    
- Breadth First Search (BFS)
    

---

## 2.3 Mental Model

Think of people waiting in a line.

```
Front

[A] [B] [C] [D]

              Rear
```

- New people join at the rear.
    
- First person leaves first.
    

---

## 2.4 Internal Behavior

```
Front

10 20 30 40

          Rear
```

When dequeue occurs:

```
Removed 10

Front

20 30 40
```

---

## 2.5 Basic Operations

|Operation|Description|STL Function|
|---|---|---|
|Enqueue|Insert element|`push()`|
|Dequeue|Remove front|`pop()`|
|Front|Access first element|`front()`|
|Back|Access last element|`back()`|
|Empty|Check empty|`empty()`|
|Size|Number of elements|`size()`|

---

## 2.6 C++ Syntax

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();

    cout << q.front();

    return 0;
}
```

---

## 2.7 Basic Example

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(100);
    q.push(200);
    q.push(300);

    cout << q.front() << endl;

    q.pop();

    cout << q.front();

    return 0;
}
```

---

## 2.8 Intermediate Example

Processing customer IDs.

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> customers;

    customers.push(101);
    customers.push(102);
    customers.push(103);

    while(!customers.empty()) {

        cout << "Serving Customer "
             << customers.front() << endl;

        customers.pop();
    }

    return 0;
}
```

---

## 2.9 Real-World Example (BFS)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    vector<vector<int>> graph = {
        {1,2},
        {0,3},
        {0},
        {1}
    };

    vector<bool> visited(4,false);

    queue<int> q;

    q.push(0);
    visited[0]=true;

    while(!q.empty()) {

        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int next:graph[node]){

            if(!visited[next]){

                visited[next]=true;
                q.push(next);

            }
        }
    }
}
```

---

## 2.10 Step-by-Step Breakdown

```
Queue Empty
```

---

Enqueue 10

```
10
```

---

Enqueue 20

```
10 20
```

---

Enqueue 30

```
10 20 30
```

---

Dequeue

```
Removed 10

Remaining

20 30
```

---

## 2.11 Incorrect Example

### ❌ Wrong

```cpp
queue<int> q;

cout << q.front();
```

---

### ✅ Correct

```cpp
queue<int> q;

if(!q.empty())
    cout << q.front();
```

---

## 2.12 Edge Cases

### Empty Queue

```cpp
queue<int> q;

cout << q.empty();
```

---

### One Element

```cpp
queue<int> q;

q.push(50);

q.pop();

cout << q.empty();
```

---

### Processing Until Empty

```cpp
while(!q.empty())
    q.pop();
```

---

## 2.13 Time Complexity

|Operation|Complexity|
|---|---|
|Enqueue|O(1)|
|Dequeue|O(1)|
|Front|O(1)|
|Back|O(1)|
|Empty|O(1)|
|Size|O(1)|

---

## 2.14 Real-World Usage

### Backend

- API request queue
    
- Background job scheduling
    
- Message brokers
    
- CPU scheduling
    
- Task execution pipelines
    

### Frontend

- Notification queue
    
- Upload queue
    
- Animation queue
    
- Event handling
    

---

## 2.15 Key Points

- Linear data structure
    
- FIFO order
    
- Front for deletion
    
- Rear for insertion
    
- Constant time operations
    
- Ideal for scheduling systems
    

---

## 2.16 Common Mistakes

|Mistake|Fix|
|---|---|
|Accessing `front()` on empty queue|Check `empty()`|
|Using queue for undo feature|Use stack instead|
|Expecting random access|Use `deque` or `vector`|

---

## 2.17 Interview Tips

Frequently asked questions:

- What is FIFO?
    
- Difference between queue and deque?
    
- Why BFS uses queue?
    
- Implement queue using arrays.
    
- Implement queue using stacks.
    

---

## 2.18 Interview Summary

- FIFO structure
    
- Front removes
    
- Rear inserts
    
- Used in BFS, scheduling, buffering and request handling
    

---

# 3. Stack vs Queue

---

|Feature|Stack|Queue|
|---|---|---|
|Principle|LIFO|FIFO|
|Insert|Top|Rear|
|Remove|Top|Front|
|Accessible Element|Top|Front|
|STL Container|`stack`|`queue`|
|Primary Use|Undo, DFS, Recursion|Scheduling, BFS, Requests|

---

## Visual Comparison

### Stack

```
Push

30
20
10

↓

Pop

30
```

---

### Queue

```
Front

10 20 30

       Rear

↓

Dequeue

10
```

---

# 4. Stack vs Queue Use Cases

---

|Scenario|Stack|Queue|
|---|---|---|
|Browser Back Button|✅|❌|
|Undo/Redo|✅|❌|
|Function Calls|✅|❌|
|Printer Jobs|❌|✅|
|CPU Scheduling|❌|✅|
|BFS Traversal|❌|✅|
|DFS Traversal|✅|❌|
|Message Queue|❌|✅|

---

# 5. Common Mistakes

---

### Mistake 1

Using a queue for recursion.

**Fix:** Recursion naturally uses a **stack**.

---

### Mistake 2

Using a stack for request scheduling.

**Fix:** Scheduling requires a **queue**.

---

### Mistake 3

Calling `top()` or `front()` without checking emptiness.

**Fix**

```cpp
if(!st.empty())
    cout << st.top();

if(!q.empty())
    cout << q.front();
```

---

### Mistake 4

Trying to access the middle element.

```cpp
// Invalid

st[2];
q[1];
```

Neither `std::stack` nor `std::queue` supports random access.

---

# 6. Interview Summary

---

|Topic|Stack|Queue|
|---|---|---|
|Data Structure Type|Linear|Linear|
|Processing Order|LIFO|FIFO|
|Insertion|Top|Rear|
|Deletion|Top|Front|
|Access|Top Only|Front and Back|
|Time Complexity|O(1)|O(1)|
|Common Algorithms|DFS, Backtracking|BFS, Scheduling|
|STL Header|`<stack>`|`<queue>`|

---

# 7. Final Mental Model

---

### Stack

Think of a **stack of plates**.

- Put a new plate on the top.
    
- Remove the top plate first.
    

```
Last In
   ↓
[30]
[20]
[10]
   ↑
First Out
```

**Rule:** **LIFO (Last In, First Out)**

---

### Queue

Think of a **line of people waiting for service**.

```
Front

A → B → C → D

             Rear
```

- New people join at the rear.
    
- The person at the front leaves first.
    

**Rule:** **FIFO (First In, First Out)**

---

# 8. Key Takeaways

- **Stack** processes the most recently added element first (**LIFO**).
    
- **Queue** processes the earliest added element first (**FIFO**).
    
- Both provide **O(1)** insertion and deletion at their designated ends.
    
- **Stacks** are ideal for recursion, undo systems, expression evaluation, and DFS.
    
- **Queues** are ideal for scheduling, buffering, BFS, and request processing.
    
- Always check `empty()` before calling `top()`, `front()`, or `back()`.
    
- Neither `std::stack` nor `std::queue` supports random access to middle elements.