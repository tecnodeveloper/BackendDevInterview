# Indexing in DBMS

---

##  Definition 

**Indexing** is a technique used in databases to **speed up data retrieval** by creating a separate data structure that allows the database to find rows quickly—without scanning the entire table.

Think of it like the **index of a book**: instead of reading every page to find a topic, you jump directly to the page number listed in the index.

---

##  Why Indexing Exists

Without indexing:

- The database performs a **full table scan** (checking every row)
- Slow performance, especially with large datasets

With indexing:

- The database can **locate data quickly**
- Improves **read/query performance**

---

##  Mental Model

Imagine a phone book:

- **Without index** → You check every name manually
    
- **With index (sorted)** → You jump directly to the right section (A, B, C…)

In DBMS:

- The table = phone book data
- The index = sorted lookup structure (often a **B-Tree**)

---

##  How Indexing Works Internally

Most databases use **B-Trees** (or variants like B+ Trees):

- Data is stored in a **balanced tree structure**
- Each node contains keys and pointers
- Searching is done in **O(log n)** time

### Internal Steps:

1. Query is executed
2. Database checks if an index exists
3. Traverses the index tree
4. Finds matching pointer(s)
5. Fetches actual data rows

---

##  Basic Syntax

### SQL Syntax (Generic)

```sql
-- Create an index
CREATE INDEX index_name
ON table_name (column_name);

-- Create a unique index
CREATE UNIQUE INDEX index_name
ON table_name (column_name);

-- Drop an index
DROP INDEX index_name;
```

---

##  JavaScript Example (Using a Database)

### Basic Query Without Index

```javascript
// Simulating a slow query (no index)
const users = await db.collection("users").find({ email: "test@example.com" });
```

 This may scan all records.

---

### Adding Index

```javascript
// Create index on email field
await db.collection("users").createIndex({ email: 1 });
```

---

### Query After Index

```javascript
const users = await db.collection("users").find({ email: "test@example.com" });
```

 Now the query is much faster.

---

###  Basic Example

```sql
CREATE INDEX idx_name ON employees (name);
```

Query:

```sql
SELECT * FROM employees WHERE name = 'Ali';
```

---

### Real-World Example (E-commerce)

```javascript
// Searching products by category
await db.collection("products").createIndex({ category: 1 });

const products = await db.collection("products")
  .find({ category: "electronics" });
```

---

###  Step-by-Step Breakdown

Query:

```sql
SELECT * FROM orders WHERE order_id = 101;
```

Without Index:

1. Scan row 1
2. Scan row 2
3. Continue...
4. Find match → slow

With Index:

1. Go to index tree
2. Locate `order_id = 101`
3. Jump to row location
4. Fetch data → fast

---

##  Edge Cases & Pitfalls

###  Over-Indexing

- Too many indexes = slower **INSERT/UPDATE**
- Each index must be updated

---

###  Low Cardinality Columns

Bad example:

```sql
CREATE INDEX idx_gender ON users (gender);
```

Why bad?

- Only few values (M/F)
- Not selective → poor performance gain

---

###  Index Not Used

```sql
SELECT * FROM users WHERE LOWER(name) = 'ali';
```

Fix:

```sql
CREATE INDEX idx_lower_name ON users ((LOWER(name)));
```

---

###  Incorrect

```javascript
// No index on frequently queried field
await db.collection("orders").find({ status: "pending" });
```

---

### Correct

```javascript
await db.collection("orders").createIndex({ status: 1 });

await db.collection("orders").find({ status: "pending" });
```

---

##  Comparison: Indexed vs Non-Indexed

| Feature      | Indexed          | Non-Indexed    |
| ------------ | ---------------- | -------------- |
| Search Speed | Fast (O(log n))  | Slow (O(n))    |
| Insert Speed | Slower           | Faster         |
| Storage      | Extra space      | No extra space |
| Use Case     | Frequent queries | Rare queries   |

---

###  Backend API Optimization

```javascript
// Login system
await db.collection("users").createIndex({ email: 1 });

const user = await db.collection("users")
  .findOne({ email: "user@example.com" });
```

✔ Fast authentication lookup

---

###  Search Feature (Frontend + Backend)

```javascript
// Search posts by title
await db.collection("posts").createIndex({ title: "text" });

const results = await db.collection("posts")
  .find({ $text: { $search: "database indexing" } });
```

✔ Enables fast text search

---

##  Advanced Insights

- Indexes can be **covering indexes** (contain all needed data)
- Query optimizer decides **whether to use index**
- Composite index order matters:
    
    - `(name, age)` ≠ `(age, name)`
    
---

##  Key Points

- Indexing improves **read performance**
- Uses structures like **B-Trees**
- Costs extra **storage and write overhead**
- Must be used **strategically**
- Not all columns should be indexed

---

##  Common Mistakes

| Mistake                  | Fix                                  |
| ------------------------ | ------------------------------------ |
| Indexing every column    | Index only frequently queried fields |
| Ignoring query patterns  | Analyze real queries                 |
| Wrong composite order    | Match query filter order             |
| Using functions in WHERE | Use functional indexes               |

---

##  Interview Tips

- Always mention **trade-off (read vs write)**
- Explain **B-Tree concept simply**
- Give real-world analogy (book index)
- Know **composite index behavior**
- Mention **query optimization**

---

##  Interview Summary

- Index = **data structure for fast lookup**
- Improves **SELECT performance**
- Slows down **INSERT/UPDATE**
- Implemented using **B-Trees**

---

## Final Thoughts

Indexing is essential for building **scalable and high-performance systems**. Proper use of indexes can turn slow queries into fast operations, but misuse can degrade performance.