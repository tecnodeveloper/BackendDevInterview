# Key

**Keys in DBMS are attributes (or sets of attributes) used to uniquely identify records (rows)** in a table and **establish relationships** between tables.

---
##  Mental Model

Think of a key like:
- A **CNIC number** (unique per person)
- A **roll number** (unique per student)
- A **product barcode**

Without keys:
 A database is just messy data with no reliable way to find or relate records.

---

##  Types of Keys in DBMS

### 1. Primary Key  
### 2. Candidate Key
### 3. Super Key
### 4. Foreign Key
### 5. Composite Key

---

## Primary Key

A **Primary Key** uniquely identifies each record in a table.

### Rules:

- Must be **unique**
- Cannot be **NULL**
- Only **one primary key per table**
### Example

// SQL representation 
const query = `  
CREATE TABLE Users (  
  id INT PRIMARY KEY,  
  name VARCHAR(50),  
  email VARCHAR(100)  
);  
`

### Mental Model

> Primary Key = "Main identity card of a row"

---

##  2. Candidate Key

All possible attributes that can uniquely identify records.

### Example

|id|email|phone|
|---|---|---|
|1|a@gmail.com|123|

- `id`, `email`, and `phone` can all uniquely identify a row.

 These are **candidate key**
if you pick id as primary key then all others are alternative key

---

##  3. Super Key

A **super key** is any combination of attributes that uniquely identifies a row.
### Example

// Super keys:  
{id}  
{id, name}  
{id, email}  
{id, name, email}

 All are super keys, but not all are minimal.

---

##  4. Foreign Key

### Definition

A **foreign key** is used to link one table to another.
### Example

const query = `  
CREATE TABLE Orders (  
  order_id INT PRIMARY KEY,  
  user_id INT,  
  FOREIGN KEY (user_id) REFERENCES Users(id)  
);  
`

 `user_id` refers to `Users.id`
### Mental Model

> Foreign Key = "Reference to another table's identity"

---
##  5. Composite Key

A key made of **multiple columns**
### Example

const query = `  
CREATE TABLE Enrollments (  
  student_id INT,  
  course_id INT,  
  PRIMARY KEY (student_id, course_id)  
);  
`

 A student can enroll in multiple courses, but combination must be unique.

---

##  Syntax Summary

// Primary Key  
PRIMARY KEY (column_name)  
  
// Foreign Key  
FOREIGN KEY (column_name) REFERENCES table(column)  
  
// Composite Key  
PRIMARY KEY (col1, col2)  
  
// Unique (Candidate/Alternate)  
UNIQUE (column_name)

---

###  Basic Example

const usersTable = `  
CREATE TABLE Users (  
  id INT PRIMARY KEY,  
  name VARCHAR(50)  
);  
`

---

###  Real-World Example: E-commerce

const schema = `  
CREATE TABLE Products (  
  product_id INT PRIMARY KEY,  
  name VARCHAR(100)  
);  
  
CREATE TABLE Orders (  
  order_id INT PRIMARY KEY,  
  product_id INT,  
  FOREIGN KEY (product_id) REFERENCES Products(product_id)  
);  
`
### Step-by-Step:

1. `Products` table stores items
2. `Orders` table references products
3. `product_id` connects both tables
4. Ensures valid product is always used

---

##  Edge Cases

### 1. Duplicate Primary Key

 Wrong:

INSERT INTO Users VALUES (1, 'Ali');  
INSERT INTO Users VALUES (1, 'Ahmed'); //  duplicate

Fix:

INSERT INTO Users VALUES (2, 'Ahmed');

---

### 2. NULL in Primary Key

 Wrong:

INSERT INTO Users (id, name) VALUES (NULL, 'Ali');

 Not allowed

---

### 3. Foreign Key Constraint Failure

 Wrong:

INSERT INTO Orders VALUES (1, 999); // user doesn't exist

Fix:

// First ensure user exists  
INSERT INTO Users VALUES (999, 'Test');

---

##  Comparison Table

| Key Type      | Unique | NULL Allowed | Purpose           |
| ------------- | ------ | ------------ | ----------------- |
| Primary Key   |  Yes   | No           | Main identifier   |
| Candidate Key | Yes    | No           | Possible PKs      |
| Super Key     | Yes    | No           | Any unique combo  |
| Alternate Key | Yes    | No           | Backup unique key |
| Foreign Key   | No     | Yes          | Link tables       |
| Composite Key | Yes    | No           | Multi-column PK   |

---

##  Real-World Usage

### 1. Backend (Node.js + Database)

// Example: fetching user orders  
const userId = 1;  
  
const query = `  
SELECT * FROM Orders  
WHERE user_id = ${userId}  
`;

 Uses **foreign key relationship**

---
##  Key Points

- Keys ensure **uniqueness and integrity**
- Primary key is the **main identifier**
- Foreign key connects **tables together**
- Composite key uses **multiple columns**
- Candidate keys are **all possible unique identifiers**

---

##  Common Mistakes

### Mistake 1: Using non-unique column as primary key

PRIMARY KEY (name)
 Fix:   PRIMARY KEY (id)

---

### Mistake 2: Forgetting Foreign Key Constraints

 Leads to:
- Orphan records
- Broken relationships

 Always define:
-  FOREIGN KEY (...) REFERENCES ...

---

### Mistake 3: Overusing Composite Keys

- Makes queries complex
- Single primary key + unique constraints

---

##  Interview Tips

- Always mention:
    - **Primary Key = unique + not null**
    - **Foreign Key = relationship**
- Be ready to explain:
    - Difference between **candidate vs primary key**
    - Why **indexes matter**
- Common question:
	- "Can a table have multiple primary keys?" 
	- No, only one (can be composite)
   

---

##  Interview Summary

- Keys are fundamental to **database design**
- They enforce:
    - Uniqueness
    - Relationships
    - Data consistency
- Types:
    - Primary, Foreign, Candidate, Super, Alternate, Composite
- Used in:
    - Backend systems
    - APIs
    - Real-world data modeling

---

# SQL Regular Expressions (Regex): The Essential 90% 

## Regular Expression (Regex)

A **Regular Expression (Regex)** is a pattern used to search, validate, extract, or replace text.

Instead of checking for exact text, regex allows you to describe **patterns**.

For example:

- Find all email addresses
- Validate phone numbers    
- Search names starting with "A"    
- Find numbers inside text    
- Extract hashtags    
- Remove special characters    

In SQL, regex is commonly used with functions like:

- `REGEXP`    
- `REGEXP_LIKE()`    
- `REGEXP_REPLACE()`    
- `REGEXP_SUBSTR()`    
- `REGEXP_INSTR()`

The exact function names depend on the database system.

---

# Why Does Regex Exist?

Suppose you have this table:

|name|
|---|
|Alice|
|Bob|
|Alex|
|Anna|
|Charlie|

Finding all names starting with **A** using `LIKE`:

```sql
WHERE name LIKE 'A%'
```

Easy.

But what if you want:

- Starts with A or B    
- Ends with a digit    
- Contains exactly 5 letters    
- Only uppercase letters    
- Valid email addresses    
- Multiple phone number formats   

`LIKE` quickly becomes insufficient.

Regex solves these problems.

---

# Mental Model

Think of Regex as a mini language for describing text.

Instead of saying:

> Find "Alice"

You say:

> Find any word beginning with A and ending with e.

Regex describes **patterns**, not exact values.

---

# Regex vs LIKE

|Feature|LIKE|Regex|
|---|---|---|
|Exact prefix|✅|✅|
|Exact suffix|✅|✅|
|Character ranges|❌|✅|
|Repetition|❌|✅|
|Optional characters|❌|✅|
|Complex validation|❌|✅|
|Email validation|❌|✅|
|Phone validation|❌|✅|

---

# Basic Regex Syntax

Most SQL databases support something similar to:

```sql
SELECT *
FROM Users
WHERE name REGEXP 'pattern';
```

Oracle

```sql
SELECT *
FROM Users
WHERE REGEXP_LIKE(name, 'pattern');
```

PostgreSQL

```sql
SELECT *
FROM Users
WHERE name ~ 'pattern';
```

---

# The Essential 90% Regex Patterns

---

# 1. Dot (.)

## Meaning

Matches **any single character**.

Pattern

```text
.
```

Example

```sql
SELECT *
FROM Employees
WHERE name REGEXP 'A.';
```

Matches

```text
Al
An
Ax
```

Does NOT match

```text
A
```

---

# 2. Begins With (^)

## Meaning

Beginning of a string.

Pattern

```text
^A
```

Example

```sql
SELECT *
FROM Customers
WHERE customer_name REGEXP '^A';
```

Matches

```text
Alice
Alex
Anna
```

---

# 3. Ends With ($)

Pattern

```text
son$
```

Example

```sql
SELECT *
FROM Employees
WHERE name REGEXP 'son$';
```

Matches

```text
Jackson
Anderson
```

---

# 4. Character Set ([])

Match one character from a list.

Pattern

```text
[ABC]
```

Example

```sql
SELECT *
FROM Products
WHERE product_code REGEXP '^[ABC]';
```

Matches

```text
A101
B500
C900
```

---

# 5. Character Range

Pattern

```text
[A-Z]
```

Uppercase letters.

```text
[a-z]
```

Lowercase letters.

```text
[0-9]
```

Digits.

Example

```sql
SELECT *
FROM Employees
WHERE employee_code REGEXP '^[A-Z]';
```

---

# 6. Negated Character Set

Pattern

```text
[^0-9]
```

Meaning

Anything except digits.

Example

```sql
SELECT *
FROM Products
WHERE product_name REGEXP '[^0-9]';
```

---

# 7. Zero or More (*)

Pattern

```text
ab*
```

Means

```text
a
ab
abb
abbb
abbbb
```

Example

```sql
SELECT *
FROM Messages
WHERE message REGEXP 'he*';
```

---

# 8. One or More (+)

Pattern

```text
ab+
```

Matches

```text
ab
abb
abbb
```

Not

```text
a
```

Example

```sql
SELECT *
FROM Logs
WHERE log_text REGEXP 'Error+';
```

---

# 9. Optional (?)

Pattern

```text
colou?r
```

Matches

```text
color
colour
```

Example

```sql
SELECT *
FROM Dictionary
WHERE word REGEXP 'colou?r';
```

---

# 10. Exact Repetition {}

Exactly N times.

Pattern

```text
[0-9]{5}
```

Exactly five digits.

Example

```sql
SELECT *
FROM ZipCodes
WHERE zip_code REGEXP '^[0-9]{5}$';
```

---

# Between Numbers

```text
[0-9]{3,5}
```

Matches

```text
123
1234
12345
```

---

# At Least

```text
[0-9]{3,}
```

Three or more digits.

---

# 11. OR (|)

Pattern

```text
cat|dog
```

Example

```sql
SELECT *
FROM Pets
WHERE pet_name REGEXP 'cat|dog';
```

---

# 12. Groups ()

Groups expressions together.

Pattern

```text
(Mr|Mrs|Miss)
```

Example

```sql
SELECT *
FROM Customers
WHERE full_name REGEXP '^(Mr|Mrs|Miss)';
```

---

# 13. Digits (\d)

Many databases support

```text
\d
```

Equivalent

```text
[0-9]
```

Example

```sql
SELECT *
FROM Orders
WHERE order_code REGEXP '\\d{4}';
```

> Some SQL engines require escaping the backslash (`\\d`), while others use POSIX character classes instead of `\d`.

---

# 14. Word Characters (\w)

Matches

```text
A-Z
a-z
0-9
_
```

Pattern

```text
\w+
```

---

# 15. Whitespace (\s)

Matches

- Space
    
- Tab
    
- Newline
    

Example

```sql
SELECT *
FROM Notes
WHERE note REGEXP '\\s';
```

---

# POSIX Character Classes (Very Common in SQL)

Many SQL databases (especially Oracle, MySQL, MariaDB, PostgreSQL with POSIX regex) support POSIX classes.

|Pattern|Meaning|
|---|---|
|`[[:digit:]]`|Digit|
|`[[:alpha:]]`|Letter|
|`[[:alnum:]]`|Letter or digit|
|`[[:lower:]]`|Lowercase|
|`[[:upper:]]`|Uppercase|
|`[[:space:]]`|Whitespace|

Example

```sql
SELECT *
FROM Employees
WHERE employee_code REGEXP '^[[:upper:]]{3}[[:digit:]]{4}$';
```

---

# Real-World Example 1 — Validate Email

```sql
SELECT *
FROM Users
WHERE email REGEXP
'^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$';
```

Matches

```text
john@gmail.com

admin@yahoo.com

test123@company.org
```

---

# Real-World Example 2 — Phone Number

```sql
SELECT *
FROM Customers
WHERE phone REGEXP
'^[0-9]{10}$';
```

Matches

```text
9876543210
```

---

# Real-World Example 3 — Product Code

Format

```text
ABC-1234
```

Regex

```sql
SELECT *
FROM Products
WHERE product_code REGEXP
'^[A-Z]{3}-[0-9]{4}$';
```

---

# Real-World Example 4 — Employee ID

Format

```text
EMP1001
```

```sql
SELECT *
FROM Employees
WHERE employee_id REGEXP
'^EMP[0-9]{4}$';
```

---

# Real-World Example 5 — Strong Password

At least

- 8 characters
    
- One uppercase
    
- One lowercase
    
- One digit
    

```sql
SELECT *
FROM Users
WHERE password REGEXP
'^(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9]).{8,}$';
```

> **Note:** Lookaheads (`?=`) are **not supported in every SQL database** (for example, older MySQL regex engines). Check your database's regex engine before using advanced constructs.

---

# REGEXP_REPLACE()

Replace matching text.

Example

Remove digits.

```sql
SELECT
REGEXP_REPLACE(
'Phone123',
'[0-9]',
''
);
```

Result

```text
Phone
```

---

# REGEXP_SUBSTR()

Extract matching text.

Example

```sql
SELECT
REGEXP_SUBSTR(
'Invoice-98765',
'[0-9]+'
);
```

Result

```text
98765
```

---

# REGEXP_INSTR()

Return match position.

```sql
SELECT
REGEXP_INSTR(
'Order12345',
'[0-9]'
);
```

Result

```text
6
```

---

# REGEXP_LIKE()

Oracle

```sql
SELECT *
FROM Employees
WHERE REGEXP_LIKE(
employee_name,
'^A'
);
```

---

# Common Mistakes

## Mistake 1

Using `LIKE` for complex validation.

Incorrect

```sql
WHERE email LIKE '%@%'
```

Better

```sql
WHERE email REGEXP
'^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$'
```

---

## Mistake 2

Forgetting `^` and `$`

Incorrect

```sql
WHERE zip_code REGEXP '[0-9]{5}'
```

Matches

```text
12345abc
```

Correct

```sql
WHERE zip_code REGEXP
'^[0-9]{5}$'
```

---

## Mistake 3

Using `*` Instead of `+`

Pattern

```text
A*
```

Matches

```text
(empty string)
A
AA
AAA
```

Sometimes developers actually want

```text
A+
```

---

## Mistake 4

Assuming Every SQL Database Supports the Same Regex

Different databases use different regex engines.

|Database|Common Syntax|
|---|---|
|MySQL|`REGEXP`, `REGEXP_REPLACE()`|
|PostgreSQL|`~`, `~*`, `!~`|
|Oracle|`REGEXP_LIKE()`, `REGEXP_REPLACE()`|
|SQL Server|No native regex operator (typically use `LIKE`, `PATINDEX`, `CLR`, or external processing)|

---

# Performance Considerations

Regex is more expensive than simple string comparisons.

Prefer simpler operations when they meet the requirement:

```sql
WHERE name = 'Alice'
```

is faster than

```sql
WHERE name REGEXP '^Alice$'
```

Similarly,

```sql
WHERE name LIKE 'A%'
```

is generally more efficient than

```sql
WHERE name REGEXP '^A'
```

Use regex only when pattern matching is truly needed.

---

# Quick Reference Cheat Sheet

|Pattern|Meaning|Example Match|
|---|---|---|
|`.`|Any character|`A`, `1`, `#`|
|`^`|Start of string|`^A`|
|`$`|End of string|`son$`|
|`[]`|Character set|`[ABC]`|
|`[^]`|Not in set|`[^0-9]`|
|`*`|Zero or more|`ab*`|
|`+`|One or more|`ab+`|
|`?`|Optional|`colou?r`|
|`{n}`|Exactly `n`|`[0-9]{5}`|
|`{n,m}`|Between `n` and `m`|`[0-9]{3,5}`|
|`|`|OR|
|`()`|Group|`(Mr|
|`\d`*|Digit (engine-dependent)|`123`|
|`\w`*|Word character (engine-dependent)|`User_01`|
|`\s`*|Whitespace (engine-dependent)|`" "`|

* Some SQL databases prefer POSIX character classes instead of these shorthand escapes.

---

# Interview Summary

### What is Regex?

A pattern-matching language used to search, validate, extract, and transform text.

---

### When should you use Regex instead of `LIKE`?

Use regex when you need:

- Character ranges
    
- Exact formats
    
- Validation
    
- Repetition
    
- Optional characters
    
- Alternatives (`OR`)
    
- Complex text matching
    

Use `LIKE` for simple wildcard searches such as prefixes, suffixes, or substring matching.

---

### Most Important Regex Patterns to Remember

|Pattern|Purpose|
|---|---|
|`^`|Start of string|
|`$`|End of string|
|`.`|Any single character|
|`[A-Z]`|Uppercase letter|
|`[0-9]`|Digit|
|`*`|Zero or more|
|`+`|One or more|
|`?`|Optional|
|`{n}`|Exact repetition|
|`{n,m}`|Range of repetitions|
|`|`|
|`()`|Grouping|
|`[[:digit:]]`|POSIX digit class|
|`[[:alpha:]]`|POSIX alphabetic class|

---

# Key Points

- Regex describes **patterns**, not exact text.
    
- SQL regex syntax varies slightly across database systems.
    
- Use anchors (`^` and `$`) to validate an entire string.
    
- Prefer POSIX character classes when supported for better portability across SQL databases.
    
- `LIKE` is faster for simple wildcard searches; use regex for advanced pattern matching.
    
- Common regex functions include `REGEXP`, `REGEXP_LIKE()`, `REGEXP_REPLACE()`, `REGEXP_SUBSTR()`, and `REGEXP_INSTR()`.
    
- Understanding roughly 10–15 core regex constructs is sufficient for the vast majority of SQL pattern-matching tasks encountered in real-world applications.