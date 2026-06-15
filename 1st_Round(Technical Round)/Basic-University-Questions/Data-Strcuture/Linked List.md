# Linked List (Data Structure in C++ OOP Perspective)

---

## 1. Definition

A **Linked List** is a linear data structure where elements (called **nodes**) are stored in separate memory locations and connected using pointers (references).

Each node contains:

- **Data**
- **Pointer to next node** (and optionally previous node)

Unlike arrays, elements are not stored in contiguous memory.

---

## 2. Why Linked List Exists

Arrays have limitations:

- Fixed size (in static arrays)
    
- Expensive insertions/deletions (O(n))
    
- Memory wastage or overflow
    

A **Linked List solves these problems** by:

- Dynamic memory allocation
    
- Efficient insertion/deletion (O(1) if position is known)
    
- Flexible size
    

---

## 3. Mental Model

Think of a **train system**:

- Each compartment is a node
    
- Each compartment knows only the next one
    
- You can add/remove compartments without rearranging the whole train
    

---

## 4. Types of Linked Lists

- **Singly Linked List** → forward direction only
    
- **Doubly Linked List** → forward + backward
    
- **Circular Linked List** → last node connects back to first
    

---

## 5. Node Structure (Core Concept)

### JavaScript Representation

```javascript
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}
```

---

## 6. Singly Linked List Implementation

---

### 6.1 Basic Structure

```javascript
class LinkedList {
  constructor() {
    this.head = null;
  }
}
```

---

### 6.2 Insertion at End

```javascript
class LinkedList {
  constructor() {
    this.head = null;
  }

  insert(data) {
    const newNode = new Node(data);

    if (this.head === null) {
      this.head = newNode;
      return;
    }

    let current = this.head;

    while (current.next !== null) {
      current = current.next;
    }

    current.next = newNode;
  }
}
```

---

### Step-by-Step Execution

Insert: 10 → 20 → 30

```text
Step 1: head → [10 | null]

Step 2: [10 | next] → [20 | null]

Step 3: [10 | next] → [20 | next] → [30 | null]
```

---

### 6.3 Traversal Example

```javascript
LinkedList.prototype.print = function () {
  let current = this.head;

  while (current !== null) {
    console.log(current.data);
    current = current.next;
  }
};
```

---

## 7. Intermediate Operations

---

### 7.1 Insert at Beginning

```javascript
LinkedList.prototype.insertAtHead = function (data) {
  const newNode = new Node(data);
  newNode.next = this.head;
  this.head = newNode;
};
```

---

### 7.2 Deletion by Value

```javascript
LinkedList.prototype.delete = function (value) {
  if (!this.head) return;

  if (this.head.data === value) {
    this.head = this.head.next;
    return;
  }

  let current = this.head;

  while (current.next && current.next.data !== value) {
    current = current.next;
  }

  if (current.next) {
    current.next = current.next.next;
  }
};
```

---

### Step-by-Step Deletion Example

List: 10 → 20 → 30 → 40  
Delete: 30

```text
Traverse:
10 → 20 → 30 (found in next node)

Update:
20.next = 40

Result:
10 → 20 → 40
```

---

## 8. Real-World Example (Browser History)

```javascript
class BrowserHistory {
  constructor() {
    this.list = new LinkedList();
  }

  visit(page) {
    this.list.insertAtHead(page);
  }

  show() {
    this.list.print();
  }
}
```

---

## 9. Real-World Example (Music Playlist)

```javascript
class Playlist {
  constructor() {
    this.songs = new LinkedList();
  }

  addSong(song) {
    this.songs.insert(song);
  }

  play() {
    this.songs.print();
  }
}
```

---

## 10. Internal Working

A node is stored in **heap memory**, and each node contains:

- Data field
    
- Pointer/reference to next node
    

Unlike arrays:

- No contiguous memory requirement
    
- Nodes are scattered in memory
    

---

## 11. Memory Visualization

```text
Array:
[10][20][30] → contiguous memory

Linked List:
[10|*] → [20|*] → [30|null]
(scattered memory)
```

---

## 12. Comparison with Array

|Feature|Array|Linked List|
|---|---|---|
|Memory|Contiguous|Non-contiguous|
|Size|Fixed/Dynamic (costly)|Fully dynamic|
|Insertion|O(n)|O(1) (if position known)|
|Deletion|O(n)|O(1) (if node known)|
|Access|O(1)|O(n)|

---

## 13. Common Mistakes

### ❌ 1. Losing reference to nodes

```javascript
current = current.next.next; // may skip nodes unintentionally
```

✔ Fix:

```javascript
current.next = current.next.next;
```

---

### ❌ 2. Not handling empty list

```javascript
this.head.data; // crash if head is null
```

✔ Fix:

```javascript
if (!this.head) return;
```

---

### ❌ 3. Infinite loop in traversal

Caused by incorrect pointer updates.

✔ Fix:  
Always ensure:

```javascript
current = current.next;
```

---

## 14. Edge Cases

- Empty list operations
    
- Single node list deletion
    
- Deleting head node
    
- Searching non-existent element
    

---

## 15. Key Points

- Nodes are dynamically allocated
    
- Each node points to next node
    
- Efficient insert/delete (when pointer known)
    
- Sequential access only
    

---

## 16. Mental Model

Think of a **treasure hunt trail**:

- Each clue leads to the next
    
- You cannot jump directly
    
- You must follow the chain
    

---

## 17. Interview Tips

### What interviewers expect:

- Understanding pointer-based structure
    
- Ability to manipulate nodes safely
    
- Handling edge cases
    
- Recursive + iterative solutions
    

### Common Questions:

- Reverse a linked list
    
- Detect cycle (Floyd’s algorithm)
    
- Find middle element
    
- Merge two sorted linked lists
    

---

## 18. Interview Summary

- Linked List = dynamic chain of nodes
    
- Better than arrays for insert/delete-heavy operations
    
- Weakness: slow random access
    
- Core DS for stacks, queues, graphs (adjacency list)
    

---

## 19. Advanced Insight (OOP Perspective)

In real C++ systems:

- Nodes are objects allocated in heap
    
- Destructor handling is critical to avoid memory leaks
    
- Pointer safety is essential (use smart pointers in modern C++)
    

---

## 20. Final Mental Model

A linked list is not a container like an array.

It is a **chain of objects connected by references**, where navigation is sequential, not indexed.