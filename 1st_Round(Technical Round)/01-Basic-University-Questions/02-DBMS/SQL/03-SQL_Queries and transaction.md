
# SQL  

**SQL (Structured Query Language)** is a language used to **communicate with relational databases**. It allows you to **store, retrieve, update, and delete data**.  
  
> SQL is how you **ask questions** and **give instructions** to a database.  
  
---  
  
## 2. Why SQL Exists  
  
Databases store large amounts of structured data. SQL exists to:  
  
- Provide a **standard way to interact with data**  
- Enable **efficient data retrieval**  
- Support **data integrity and consistency**  
- Allow multiple users/applications to work with data safely  
  
---  
  
## 3. Mental Model  
  
Think of SQL like:  
  
- A **conversation with a database**  
- You say: _"Give me all users named Ali"_  
- Database responds with matching data  
  
---  
  
## 4. Basic Syntax  
  
```sql  
-- Retrieve data  
SELECT column1, column2  
FROM table_name  
WHERE condition;  
  
-- Insert data  
INSERT INTO table_name (column1, column2)  
VALUES (value1, value2);  
  
-- Update data  
UPDATE table_name  
SET column1 = value  
WHERE condition;  
  
-- Delete data  
DELETE FROM table_name  
WHERE condition;  
```  
  
---  
  
## 5. JavaScript Integration  
  
```javascript  
const result = await db.query(`  
SELECT * FROM users WHERE age > 18  
`);  
```  
  
---  
  
## 6. Basic SELECT Query  
  
### SQL  
  
```sql  
SELECT name, age FROM users;  
```  
  
### JavaScript  
  
```javascript  
const users = await db.query(`  
SELECT name, age FROM users  
`);  
```  
  
---  
  
## 7. Filtering Data (WHERE)  
  
```sql  
SELECT *  
FROM users  
WHERE age > 18;  
```  
  
---  
  
## 8. Sorting Data (ORDER BY)  
  
```sql  
SELECT *  
FROM users  
ORDER BY age DESC;  
```  
  
---  
  
## 9. Aggregation (GROUP BY)  
  
```sql  
SELECT city, COUNT(*) AS total  
FROM users  
GROUP BY city;  
```  
  
---  
  
## 10. JOIN Example  
  
```sql  
SELECT users.name, orders.total  
FROM users  
JOIN orders  
ON users.id = orders.user_id;  
```  
  
---  
  
## 11. Step-by-Step Breakdown (Complex Query)  
  
Query:  
  
```sql  
SELECT city,  
COUNT(*) AS total_users  
FROM users  
WHERE age > 18  
GROUP BY city  
ORDER BY total_users DESC;  
```  
  
### Execution Order  
  
1. **FROM users**  
- Load the table.  
  
2. **WHERE age > 18**  
- Filter rows.  
  
3. **GROUP BY city**  
- Group rows by city.  
  
4. **COUNT(*)**  
- Count records in each group.  
  
5. **SELECT**  
- Return requested columns.  
  
6. **ORDER BY**  
- Sort the final result.  
  
---  
  
## 12. Edge Cases & Pitfalls  
  
### Missing WHERE in DELETE  
  
```sql  
DELETE FROM users;  
```  
  
 Deletes every record.  
  
### Correct  
  
```sql  
DELETE FROM users  
WHERE id = 1;  
```  
  
---  
  
### NULL Comparison  
  
Incorrect  
  
```sql  
SELECT *  
FROM users  
WHERE name = NULL;  
```  
  
Correct  
  
```sql  
SELECT *  
FROM users  
WHERE name IS NULL;  
```  
  
---  
  
### Duplicate Results (JOIN)  
  
Improper joins may duplicate rows.  
  
Use:  
  
```sql  
SELECT DISTINCT users.name  
FROM users  
JOIN orders  
ON users.id = orders.user_id;  
```  
  
when appropriate.  
  
---  
  
## 13. SQL Injection  
  
### Incorrect  
  
```javascript  
const query = `  
SELECT *  
FROM users  
WHERE email='${email}'  
`;  
  
await db.query(query);  
```  
  
 Vulnerable to SQL Injection.  
  
---  
  
### Correct  
  
```javascript  
const query = `  
SELECT *  
FROM users  
WHERE email = ?  
`;  
  
await db.query(query, [email]);  
```  
  
✔ Uses parameterized queries.  
  
---  
  
## 14. Comparison: SQL vs NoSQL  
  
| Feature | SQL (Relational) | NoSQL (Non-Relational) |  
|----------|------------------|------------------------|  
| Structure | Fixed Schema | Flexible Schema |  
| Query Language | SQL | JSON/API Based |  
| Relationships | Strong (JOINs) | Usually Manual |  
| Scalability | Vertical | Horizontal |  
| Best For | Structured Data | Semi/Unstructured Data |  
  
---  
  
# 15. Real-World Use Cases  
  
---  
  
## User Authentication System  
  
```javascript  
const user = await db.query(  
`  
SELECT *  
FROM users  
WHERE email = ?  
AND password = ?  
`,  
[email, password]  
);  
```  
  
Used in login systems.  
  
---  
  
## Dashboard Analytics  
  
```javascript  
const stats = await db.query(`  
SELECT status,  
COUNT(*) AS total  
FROM orders  
GROUP BY status  
`);  
```  
  
Used in:  
  
- Admin dashboards  
- Reports  
- Business analytics  
  
---  
  
# 16. Advanced Insights  
  
SQL is much more than CRUD.  
  
Modern relational databases include:  
  
- Query Optimizer  
- Execution Plans  
- Indexes  
- Transactions  
- Views  
- Stored Procedures  
- Triggers  
  
### Query Optimizer  
  
Before executing a query, the database creates an execution plan.  
  
Example  
  
```sql  
SELECT *  
FROM users  
WHERE email = 'john@gmail.com';  
```  
  
Instead of scanning every row, the optimizer may use an index.  
  
---  
  
### Indexes  
  
Indexes improve search performance.  
  
Without index:  
  
```  
Database  
  
↓  
  
Reads every row  
```  
  
With index:  
  
```  
Database  
  
↓  
  
Uses lookup structure  
  
↓  
  
Returns result quickly  
```  
  
---  
  
### Execution Plans  
  
Execution plans determine:  
  
- Which indexes to use  
- Join order  
- Scan type  
- Estimated cost  
  
---  
  
### Transactions  
  
Multiple SQL statements can execute as one unit.  
  
If one fails,  
  
everything rolls back.  
  
(We'll cover this in the MySQL Transactions section.)  
  
---  
  
### Views  
  
Views simplify complex queries.  
  
```sql  
CREATE VIEW adult_users AS  
  
SELECT *  
FROM users  
WHERE age >= 18;  
```  
  
Now:  
  
```sql  
SELECT *  
FROM adult_users;  
```  
  
---  
  
# 17. Key Points  
  
- SQL communicates with relational databases.  
- SQL performs CRUD operations.  
- SELECT retrieves data.  
- INSERT adds data.  
- UPDATE modifies data.  
- DELETE removes data.  
- WHERE filters rows.  
- ORDER BY sorts results.  
- GROUP BY performs aggregation.  
- JOIN combines related tables.  
- Parameterized queries prevent SQL injection.  
- Indexes improve query performance.  
  
---  
  
# 18. Common Mistakes  
  
| Mistake | Fix |  
|----------|-----|  
| Forgetting WHERE in UPDATE | Always specify conditions |  
| Forgetting WHERE in DELETE | Prevent accidental data loss |  
| Using = NULL | Use IS NULL |  
| SQL Injection | Use prepared statements |  
| Selecting unnecessary columns | Fetch only required data |  
| Ignoring indexes | Add indexes for frequent searches |  
  
---  
  
# 19. Interview Tips  
  
Know these SQL categories:  
  
| Category | Purpose |  
|----------|---------|  
| DDL | CREATE, ALTER, DROP |  
| DML | INSERT, UPDATE, DELETE |  
| DQL | SELECT |  
| DCL | GRANT, REVOKE |  
| TCL | COMMIT, ROLLBACK |  
  
Also remember:  
  
- Execution order  
- Joins  
- GROUP BY  
- Aggregations  
- Indexes  
- SQL Injection prevention  
  
---  
  
# 20. Interview Summary  
  
### What is SQL?  
  
A language used to communicate with relational databases.  
  
---  
  
### What can SQL do?  
  
- Create data  
- Read data  
- Update data  
- Delete data  
  
---  
  
### Why is SQL declarative?  
  
You describe **what** data you want, not **how** the database should retrieve it.  
  
---  
  
### What is SQL Injection?  
  
A security vulnerability caused by building SQL queries using string concatenation.  
  
Prevent it using parameterized queries.  
  
---  
  
### What are JOINs?  
  
JOINs combine related rows from multiple tables.  
  
---  
  
### Why are indexes important?  
  
Indexes reduce the amount of data scanned and significantly improve query performance.  
  
---  
  
# 21. Final Summary  
  
SQL is the standard language for interacting with relational databases. It enables developers to perform CRUD operations, filter, sort, aggregate, and join data efficiently. SQL is declarative, meaning you specify the desired result while the database determines the optimal execution strategy. Features such as indexes, query optimization, views, and transactions make SQL suitable for building reliable and high-performance applications. Secure SQL development also requires using parameterized queries to prevent SQL injection attacks.  
  
---

# MySQL Transactions  
  
---  
  
## 1. Definition  
  
A **transaction** is a sequence of one or more SQL statements that are executed as a **single unit of work**.  
  
A transaction ensures that **either all operations succeed or none of them are applied**.  
  
> **Mental Model**  
>  
> Imagine transferring money from one bank account to another.  
>  
> - Money should be deducted from Account A.  
> - Money should be added to Account B.  
>  
> If either operation fails, both operations should be canceled.  
>  
> This guarantees data consistency.  
  
---  
  
# 2. Why Transactions Exist  
  
Without transactions:  
  
- Partial updates can occur.  
- Data may become inconsistent.  
- Failures can leave the database in an invalid state.  
  
Transactions ensure:  
  
- Data consistency  
- Reliable operations  
- Recovery from failures  
- Safe execution of multiple SQL statements  
  
---  
  
# 3. ACID Properties  
  
Transactions follow the **ACID** principles.  
  
| Property | Description |  
|----------|-------------|  
| **Atomicity** | Either all operations succeed or none do. |  
| **Consistency** | Database remains in a valid state before and after the transaction. |  
| **Isolation** | Transactions do not interfere with each other. |  
| **Durability** | Once committed, changes are permanently stored. |  
  
---  
  
## Mental Model  
  
Think of ordering food online.  
  
1. Payment succeeds.  
2. Order is created.  
3. Restaurant receives the order.  
  
If payment fails:  
  
- The order should not be created.  
  
Everything succeeds together or fails together.  
  
---  
  
# 4. Transaction Syntax  
  
## Start a Transaction  
  
```sql  
START TRANSACTION;  
```  
  
or  
  
```sql  
BEGIN;  
```  
  
---  
  
## Commit a Transaction  
  
```sql  
COMMIT;  
```  
  
Saves all changes permanently.  
  
---  
  
## Rollback a Transaction  
  
```sql  
ROLLBACK;  
```  
  
Undoes all changes made during the transaction.  
  
---  
  
# 5. Basic Example  
  
Suppose we have an `accounts` table.  
  
```sql  
CREATE TABLE accounts (  
id INT PRIMARY KEY,  
name VARCHAR(50),  
balance DECIMAL(10,2)  
);  
```  
  
Initial Data  
  
| ID | Name | Balance |  
|----|------|---------|  
| 1 | Alice | 5000 |  
| 2 | Bob | 3000 |  
  
---  
  
## Money Transfer  
  
```sql  
START TRANSACTION;  
  
UPDATE accounts  
SET balance = balance - 1000  
WHERE id = 1;  
  
UPDATE accounts  
SET balance = balance + 1000  
WHERE id = 2;  
  
COMMIT;  
```  
  
Result  
  
| Name | Balance |  
|------|---------|  
| Alice | 4000 |  
| Bob | 4000 |  
  
Both updates succeed together.  
  
---  
  
# 6. Rollback Example  
  
Suppose an error occurs after deducting money.  
  
```sql  
START TRANSACTION;  
  
UPDATE accounts  
SET balance = balance - 1000  
WHERE id = 1;  
  
-- Error occurs here  
  
ROLLBACK;  
```  
  
Result  
  
Alice's balance remains unchanged.  
  
The deduction is canceled.  
  
---  
  
# 7. Step-by-Step Transaction Flow  
  
```text  
START TRANSACTION  
│  
▼  
Execute SQL Statement 1  
│  
▼  
Execute SQL Statement 2  
│  
▼  
Any Error?  
/ \  
Yes No  
│ │  
ROLLBACK COMMIT  
```  
  
---  
  
# 8. Savepoints  
  
A **Savepoint** allows rolling back part of a transaction instead of the entire transaction.  
  
## Syntax  
  
```sql  
SAVEPOINT savepoint_name;  
```  
  
Rollback to a savepoint  
  
```sql  
ROLLBACK TO savepoint_name;  
```  
  
---  
  
## Example  
  
```sql  
START TRANSACTION;  
  
UPDATE products  
SET stock = stock - 1  
WHERE id = 10;  
  
SAVEPOINT after_stock;  
  
UPDATE orders  
SET total = total + 100  
WHERE id = 1;  
  
ROLLBACK TO after_stock;  
  
COMMIT;  
```  
  
Only the second update is undone.  
  
The stock update remains.  
  
---  
  
# 9. Auto Commit  
  
MySQL enables **Auto Commit** by default.  
  
This means every SQL statement is automatically committed.  
  
```sql  
UPDATE users  
SET name = 'John'  
WHERE id = 1;  
```  
  
This change is saved immediately.  
  
---  
  
## Disable Auto Commit  
  
```sql  
SET autocommit = 0;  
```  
  
Now changes are not permanent until:  
  
```sql  
COMMIT;  
```  
  
or  
  
```sql  
ROLLBACK;  
```  
  
---  
  
# 10. Transaction Isolation Levels  
  
Isolation levels control how transactions interact with each other.  
  
| Isolation Level | Dirty Read | Non-Repeatable Read | Phantom Read |  
|-----------------|------------|---------------------|--------------|  
| Read Uncommitted | Yes | Yes | Yes |  
| Read Committed | No | Yes | Yes |  
| Repeatable Read (MySQL Default) | No | No | Yes |  
| Serializable | No | No | No |  
  
---  
  
## Set Isolation Level  
  
```sql  
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;  
```  
  
---  
  
# 11. Common Transaction Problems  
  
## Dirty Read  
  
A transaction reads data that hasn't been committed yet.  
  
Transaction A  
  
```sql  
UPDATE accounts  
SET balance = 1000;  
```  
  
(No commit yet)  
  
Transaction B  
  
```sql  
SELECT balance FROM accounts;  
```  
  
If Transaction A rolls back later,  
  
Transaction B has read invalid data.  
  
---  
  
## Non-Repeatable Read  
  
Reading the same row twice gives different results.  
  
Transaction A  
  
```sql  
SELECT balance FROM accounts;  
```  
  
Transaction B  
  
```sql  
UPDATE accounts  
SET balance = 2000;  
  
COMMIT;  
```  
  
Transaction A reads again.  
  
The value has changed.  
  
---  
  
## Phantom Read  
  
Rows appear or disappear during a transaction.  
  
Transaction A  
  
```sql  
SELECT *  
FROM orders  
WHERE amount > 500;  
```  
  
Transaction B  
  
```sql  
INSERT INTO orders VALUES (...);  
```  
  
Transaction A runs the same query again.  
  
A new row appears.  
  
---  
  
# 12. Real-World Usage  
  
## Banking System  
  
```sql  
START TRANSACTION;  
  
UPDATE accounts  
SET balance = balance - 1000  
WHERE id = 1;  
  
UPDATE accounts  
SET balance = balance + 1000  
WHERE id = 2;  
  
COMMIT;  
```  
  
Both operations succeed together.  
  
---  
  
## E-Commerce Website  
  
Customer purchases a product.  
  
```sql  
START TRANSACTION;  
  
UPDATE products  
SET stock = stock - 1  
WHERE id = 101;  
  
INSERT INTO orders(user_id, product_id)  
VALUES (5, 101);  
  
COMMIT;  
```  
  
If order creation fails,  
  
```sql  
ROLLBACK;  
```  
  
Stock is restored.  
  
---  
  
# 13. Transactions in Node.js (mysql2)  
  
```javascript  
import mysql from "mysql2/promise";  
  
const connection = await mysql.createConnection({  
host: "localhost",  
user: "root",  
password: "",  
database: "shop"  
});  
  
try {  
await connection.beginTransaction();  
  
await connection.query(  
"UPDATE accounts SET balance = balance - 1000 WHERE id = ?",  
[1]  
);  
  
await connection.query(  
"UPDATE accounts SET balance = balance + 1000 WHERE id = ?",  
[2]  
);  
  
await connection.commit();  
  
console.log("Transaction Successful");  
  
} catch (error) {  
  
await connection.rollback();  
  
console.log("Transaction Failed");  
  
} finally {  
  
await connection.end();  
  
}  
```  
  
---  
  
# 14. Internal Behavior  
  
```text  
Client  
│  
▼  
START TRANSACTION  
│  
▼  
Execute SQL Statements  
│  
▼  
Temporary Changes  
│  
▼  
COMMIT?  
/ \  
Yes No  
│ │  
▼ ▼  
Save ROLLBACK  
Changes Undo Changes  
```  
  
---  
  
# 15. Edge Cases and Pitfalls  
  
## Forgetting to Commit  
  
```sql  
START TRANSACTION;  
  
UPDATE users  
SET name = 'John';  
```  
  
Without  
  
```sql  
COMMIT;  
```  
  
The changes may never become permanent.  
  
---  
  
## Forgetting to Rollback  
  
If an error occurs but `ROLLBACK` isn't called,  
  
The transaction may remain open and lock rows.  
  
---  
  
## Long Transactions  
  
Keeping transactions open for a long time can:  
  
- Lock tables or rows  
- Reduce performance  
- Block other users  
  
Keep transactions as short as possible.  
  
---  
  
# 16. Common Mistakes  
  
| Mistake | Problem | Solution |  
|----------|---------|----------|  
| Forgetting `COMMIT` | Changes are not saved | Always commit successful transactions |  
| Forgetting `ROLLBACK` | Database may stay locked | Rollback on errors |  
| Long-running transactions | Poor performance | Keep transactions short |  
| Mixing unrelated operations | Difficult recovery | Keep transactions focused |  
| Using transactions for read-only queries | Unnecessary overhead | Use transactions only when needed |  
  
---  
  
# 17. Key Points  
  
- A transaction is a group of SQL statements executed as one unit.  
- Transactions guarantee data consistency.  
- Use `START TRANSACTION` to begin.  
- Use `COMMIT` to save changes.  
- Use `ROLLBACK` to undo changes.  
- MySQL follows ACID properties.  
- MySQL uses **Repeatable Read** as the default isolation level.  
- Keep transactions short to avoid locking issues.  
  
---  
  
# 18. Interview Summary  
  
## What is a transaction?  
  
A transaction is a sequence of SQL operations treated as a single unit of work where either all operations succeed or all fail.  
  
---  
  
## What does ACID stand for?  
  
- **A** → Atomicity  
- **C** → Consistency  
- **I** → Isolation  
- **D** → Durability  
  
---  
  
## Difference Between COMMIT and ROLLBACK  
  
| COMMIT | ROLLBACK |  
|----------|-----------|  
| Saves changes permanently | Undoes all changes |  
| Used after success | Used after failure |  
  
---  
  
## Why are transactions important?  
  
- Prevent partial updates  
- Maintain data integrity  
- Handle failures safely  
- Ensure reliable database operations  
  
---  
  
# 19. Final Summary  
  
A **MySQL transaction** groups multiple SQL statements into a single logical unit of work. By following the **ACID** principles, transactions ensure that data remains accurate and consistent even when errors occur. Commands such as `START TRANSACTION`, `COMMIT`, and `ROLLBACK` allow developers to control whether changes are permanently saved or completely undone. Transactions are widely used in banking systems, e-commerce applications, inventory management, and any scenario where multiple related database operations must either all succeed or all fail.