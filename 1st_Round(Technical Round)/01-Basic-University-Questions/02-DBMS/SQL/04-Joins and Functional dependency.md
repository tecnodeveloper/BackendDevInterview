# Joins in DBMS

---

##  Definition

A **JOIN** is used to **combine rows from two or more tables** based on a related column between them.

 joins allow you to **connect data stored in separate tables** and view it as a single result.

---
##  Why Joins Exist

Databases are designed using **normalization**, meaning:

- Data is split into multiple tables
- Reduces duplication
- Improves consistency

 Joins solve this by linking tables using **common keys**.

---
## Mental Model

Think of two spreadsheets:

**Customers Table**

|id|name|
|---|---|
|1|Ali|

**Orders Table**

| id  | customer_id | product |
| --- | ----------- | ------- |
| 101 | 1           | Laptop  |

A JOIN:

- Matches `customers.id` with `orders.customer_id`
- Combines rows into one view

---

##  Basic Syntax

```sql
SELECT columns
FROM table1
JOIN table2
ON table1.column = table2.column;
```

---
##  Types of Joins

| Join Type  | Description                   |
| ---------- | ----------------------------- |
| INNER JOIN | Returns matching rows only    |
| LEFT JOIN  | All rows from left + matches  |
| RIGHT JOIN | All rows from right + matches |
| FULL JOIN  | All rows from both tables     |
| CROSS JOIN | Cartesian product             |

---

##  Visual Understanding

| A (Left) | B (Right) | INNER | LEFT | RIGHT | FULL |
| -------- | --------- | ----- | ---- | ----- | ---- |
| Match    | Match     | ✔     | ✔    | ✔     | ✔    |
| No Match | Match     |       |      | ✔     | ✔    |
| Match    | No Match  |       | ✔    |       | ✔    |

---
### Basic INNER JOIN

```sql
SELECT users.name, orders.product
FROM users
INNER JOIN orders
ON users.id = orders.user_id;
```

---

### JavaScript (Node.js Example)

```javascript
const result = await db.query(`
  SELECT users.name, orders.product
  FROM users
  INNER JOIN orders
  ON users.id = orders.user_id
`);
```

---

###  LEFT JOIN

```sql
SELECT users.name, orders.product
FROM users
LEFT JOIN orders
ON users.id = orders.user_id;
```

✔ Includes users even if they have no orders

---

###  RIGHT JOIN

```sql
SELECT users.name, orders.product
FROM users
RIGHT JOIN orders
ON users.id = orders.user_id;
```

---

###  FULL JOIN

```sql
SELECT users.name, orders.product
FROM users
FULL OUTER JOIN orders
ON users.id = orders.user_id;
```

---

###  CROSS JOIN

```sql
SELECT users.name, products.name
FROM users
CROSS JOIN products;
```

 Produces all combinations (can be huge)

---

##  Step-by-Step Breakdown (INNER JOIN)

Query:

```sql
SELECT u.name, o.product
FROM users u
INNER JOIN orders o
ON u.id = o.user_id;
```

### Execution Steps:

1. Take table `users`
2. Take table `orders`
3. Compare `u.id` with `o.user_id`
4. Find matching rows
5. Merge selected columns

---

##  Edge Cases & Pitfalls

###  Duplicate Rows

If multiple matches exist:

```sql
-- One user, multiple orders
```

 Result will duplicate user data

---

###  Missing ON Condition

```sql
SELECT * FROM users JOIN orders;
```

 Creates unintended CROSS JOIN

---

###  NULL Values

```sql
SELECT * FROM users
LEFT JOIN orders ON users.id = orders.user_id;
```

 Unmatched rows return NULL values

---
### Incorrect

```javascript
// Missing join condition
await db.query(`
  SELECT * FROM users JOIN orders
`);
```

---

###  Correct

```javascript
await db.query(`
  SELECT * FROM users
  INNER JOIN orders
  ON users.id = orders.user_id
`);
```

---

##  Comparison: JOIN vs Subquery

|Feature|JOIN|Subquery|
|---|---|---|
|Performance|Usually faster|Can be slower|
|Readability|Clear for relationships|Can be nested/complex|
|Use Case|Combining tables|Filtering/aggregation|
|Optimization|Better optimized|Depends on DB engine|

---

##  Real-World Use Cases

---

###  E-commerce Order System

```javascript
// Fetch user orders with details
const orders = await db.query(`
  SELECT users.name, orders.total, orders.status
  FROM users
  INNER JOIN orders
  ON users.id = orders.user_id
`);
```

✔ Combines customer and order data

---

###  Social Media Feed

```javascript
// Posts with user info
const posts = await db.query(`
  SELECT posts.content, users.username
  FROM posts
  JOIN users
  ON posts.user_id = users.id
`);
```

✔ Displays post with author name

---

##  Advanced Insights

- Joins rely heavily on **indexes**
- Query planner chooses join strategy:
    
    - Nested Loop Join
        
    - Hash Join
        
    - Merge Join
        
- Join order can affect performance
    
- Filtering early improves efficiency

---

##  Mental Model (Advanced)

Think of joins as:

- **Matching keys**
- Then **merging rows**

Like merging two sorted lists using a common identifier.

---

## 🧠 Key Points

- Joins combine data from multiple tables
- Use **ON condition** to define relationship
- INNER JOIN = only matches
- LEFT JOIN = preserve left table
- Be careful with duplicates and NULLs


---

##  Common Mistakes (With Fixes)

| Mistake                      | Fix                          |
| ---------------------------- | ---------------------------- |
| Missing ON clause            | Always define join condition |
| Using wrong join type        | Choose based on requirement  |
| Ignoring duplicates          | Use DISTINCT or GROUP BY     |
| Joining large tables blindly | Use filters and indexes      |

---

##  Interview Tips

- Clearly explain **difference between JOIN types**
- Use real-world examples (users/orders)
- Mention performance implications
- Understand LEFT vs INNER deeply

## what is diff b/w joins and foreign key

---

##  Interview Summary

- JOIN = combine tables using related columns
- Types: INNER, LEFT, RIGHT, FULL, CROSS
- ON clause defines relationship
- Impacts performance significantly
- Essential for normalized databases

---

#  Functional Dependency in DBMS

---

##  Definition

A **Functional Dependency** in a database is a relationship between **two sets of attributes** in a table such that the value of one attribute **determines the value of another attribute**.

> If you know `A`, you can uniquely determine `B`.

A → B

If you know the student id then you can get student name, student numbers.

---

##  Why Functional Dependency Exists

Functional dependencies are crucial for:

- **Ensuring data integrity**
- **Avoiding anomalies** like insertion, deletion, and update anomalies

Without functional dependencies, databases can have **duplicate or inconsistent data**, making maintenance difficult.

---

##  Mental Model

Think of FD as a **cause-and-effect relationship**:

- `StudentID → StudentName`  
    Knowing the `StudentID` guarantees you know the `StudentName`.
- `EmployeeID → Department`  
    EmployeeID uniquely identifies the department of the employee.

---

##  Types of Functional Dependency

1. **Trivial FD**:
    - Right-hand side (RHS) is a subset of left-hand side (LHS)
    - Example: `A, B → A`
2. **Non-Trivial FD**:
    - RHS is **not** a subset of LHS
    - Example: `StudentID → StudentName`
3. **Fully Functional Dependency**:
    - Attribute depends on the **whole set** of attributes, not just part of it
    - Example: `(CourseID, StudentID) → Grade`
4. **Partial Dependency**:
    - Attribute depends on **part** of a composite key
    - Example: `(StudentID, CourseID) → StudentName` (StudentName depends only on StudentID)
5. **Transitive Dependency**:
    - A → B and B → C ⇒ A → C
    - Example: `StudentID → DepartmentID` and `DepartmentID → DepartmentName` ⇒ `StudentID → DepartmentName`

---

###  Real-World Example: E-commerce

~~~javascript
const orders = [  
  { orderId: 1001, customerId: 200, shippingAddress: 'NY' },  
  { orderId: 1002, customerId: 201, shippingAddress: 'LA' },  
];  
  
// Functional dependency:  
// orderId → customerId, shippingAddress
~~~
- Each `orderId` uniquely determines the customer and address.

---
##  Comparison Table

| Concept               | Determines       | Notes                          |
| --------------------- | ---------------- | ------------------------------ |
| Functional Dependency | RHS by LHS       | Basis for normalization        |
| Primary Key           | Unique row       | Special FD where LHS is PK     |
| Foreign Key           | References table | Enforces referential integrity |

---

##  Key Points

- Functional dependency = "knowledge of A gives B"
- Basis for **1NF, 2NF, 3NF normalization**
- Types:
    - Trivial, Non-Trivial
    - Full, Partial, Transitive
- Helps **eliminate redundancy and anomalies**

---

##  Interview Tips

- Be ready to:
    - Define FD clearly
    - Identify FDs in a table
    - Explain how FDs relate to **normal forms**
- Common question:

> "Is `A → B` a full functional dependency?"

---

##  Interview Summary

- Functional Dependency is foundational for **database normalization**
- Ensures:
    - Data integrity
    - No redundancy
    - Predictable relationships
- Recognize:
    - Trivial / Non-Trivial
    - Full / Partial / Transitive
- Used in **design, query optimization, and front/backend mapping**