# Database and API Basics

## Definition

This file covers the fundamental concepts required to connect Python applications with **databases** and **APIs**. It focuses on how data is stored, retrieved, manipulated, and exchanged between systems.

You will learn:

- SQL Fundamentals
    
- CRUD Operations
    
- Python Database Connectivity
    
- Working with JSON
    
- REST API Basics
    
- Requests Library
    
- API Authentication Concepts
    

---

# Why This Topic Exists

Modern applications are data-driven:

```text
User → API → Server → Database → Response → User
```

Without databases and APIs:

- No persistent data storage
    
- No communication between systems
    
- No scalable backend architecture
    

---

# Mental Model

```text
Frontend (Client)
      |
      V
REST API (Communication Layer)
      |
      V
Backend (Python)
      |
      V
Database (Storage Layer)
```

---

# SQL Fundamentals

## Definition

SQL (Structured Query Language) is used to interact with relational databases.

---

# Common SQL Commands

|Command|Purpose|
|---|---|
|SELECT|Read data|
|INSERT|Add data|
|UPDATE|Modify data|
|DELETE|Remove data|

---

## Example Table: employees

```sql
CREATE TABLE employees (
    id INT,
    name VARCHAR(100),
    salary INT
);
```

---

## Insert Data

```sql
INSERT INTO employees (id, name, salary)
VALUES (1, 'Ali', 50000);
```

---

## Select Data

```sql
SELECT * FROM employees;
```

---

## Update Data

```sql
UPDATE employees
SET salary = 60000
WHERE id = 1;
```

---

## Delete Data

```sql
DELETE FROM employees
WHERE id = 1;
```

---

# CRUD Operations

## Definition

CRUD stands for:

```text
Create
Read
Update
Delete
```

---

## Mapping SQL to CRUD

|CRUD|SQL|
|---|---|
|Create|INSERT|
|Read|SELECT|
|Update|UPDATE|
|Delete|DELETE|

---

# Python Database Connectivity

## Definition

Python connects to databases using drivers or ORMs.

---

# SQLite Example (Built-in)

## Connect to Database

```python
import sqlite3

conn = sqlite3.connect("employees.db")
cursor = conn.cursor()
```

---

## Create Table

```python
cursor.execute("""
CREATE TABLE IF NOT EXISTS employees (
    id INTEGER,
    name TEXT,
    salary INTEGER
)
""")
```

---

## Insert Data

```python
cursor.execute("""
INSERT INTO employees (id, name, salary)
VALUES (1, 'Ali', 50000)
""")

conn.commit()
```

---

## Fetch Data

```python
cursor.execute("SELECT * FROM employees")

print(cursor.fetchall())
```

---

## Close Connection

```python
conn.close()
```

---

# Internal Behavior

```text
Python Code
    |
Database Driver
    |
SQL Query
    |
Database Engine
    |
Data Storage
```

---

# Working with JSON

## Definition

JSON (JavaScript Object Notation) is a lightweight format for data exchange.

---

# JSON Structure

```json
{
    "id": 1,
    "name": "Ali",
    "salary": 50000
}
```

---

# Python JSON Handling

## Convert Python → JSON

```python
import json

employee = {
    "id": 1,
    "name": "Ali"
}

json_data = json.dumps(employee)

print(json_data)
```

---

## Convert JSON → Python

```python
data = '{"id":1,"name":"Ali"}'

python_data = json.loads(data)

print(python_data["name"])
```

---

# Common Use Case

```text
API Response → JSON → Python Dictionary
```

---

# REST API Basics

## Definition

REST APIs allow communication between client and server over HTTP.

---

# REST Methods

|Method|Purpose|
|---|---|
|GET|Retrieve data|
|POST|Create data|
|PUT|Update data|
|DELETE|Remove data|

---

# Example API Flow

```text
Client → GET /employees → Server → Database → Response JSON
```

---

# REST Example (Conceptual)

```python
GET /employees
POST /employees
PUT /employees/1
DELETE /employees/1
```

---

# Requests Library

## Definition

`requests` is a Python library used to interact with APIs.

---

# Install

```bash
pip install requests
```

---

# GET Request

```python
import requests

response = requests.get(
    "https://api.example.com/employees"
)

print(response.status_code)
print(response.json())
```

---

# POST Request

```python
import requests

data = {
    "name": "Ali",
    "salary": 50000
}

response = requests.post(
    "https://api.example.com/employees",
    json=data
)

print(response.status_code)
```

---

# PUT Request

```python
requests.put(
    "https://api.example.com/employees/1",
    json={"salary": 60000}
)
```

---

# DELETE Request

```python
requests.delete(
    "https://api.example.com/employees/1"
)
```

---

# Internal Flow

```text
Python → HTTP Request → API Server → Database → Response → Python
```

---

# API Authentication Concepts

## Definition

Authentication ensures only authorized users can access APIs.

---

# Types of Authentication

|Type|Description|
|---|---|
|API Key|Simple key-based access|
|Basic Auth|Username + Password|
|Token Auth|Secure token-based|
|OAuth|Third-party login system|

---

# API Key Example

```python
headers = {
    "Authorization": "API_KEY_123"
}

requests.get(
    "https://api.example.com/data",
    headers=headers
)
```

---

# Token Authentication Example

```python
headers = {
    "Authorization": "Bearer TOKEN123"
}

requests.get(
    "https://api.example.com/data",
    headers=headers
)
```

---

# OAuth Concept

```text
User → Login with Google → Token → Access API
```

---

# Database + API Integration Example

```python
import requests
import sqlite3

conn = sqlite3.connect("employees.db")
cursor = conn.cursor()

response = requests.get(
    "https://api.example.com/employees"
)

employees = response.json()

for emp in employees:

    cursor.execute("""
    INSERT INTO employees
    VALUES (?, ?, ?)
    """, (
        emp["id"],
        emp["name"],
        emp["salary"]
    ))

conn.commit()
conn.close()
```

---

# Real-World Use Case 1: Employee Management System

- Store employee data in SQL database
    
- Fetch data using REST APIs
    
- Display in frontend dashboard
    

---

# Real-World Use Case 2: E-Commerce System

- Products stored in database
    
- APIs serve product data
    
- JSON used for frontend communication
    

---

# Common Mistakes

## Mistake 1: Not Using Commit

```python
cursor.execute("INSERT INTO employees ...")
# Missing conn.commit()
```

Fix:

```python
conn.commit()
```

---

## Mistake 2: Ignoring API Status Codes

```python
response = requests.get(url)
print(response.json())
```

Fix:

```python
if response.status_code == 200:
    print(response.json())
```

---

## Mistake 3: Hardcoding Credentials

```python
api_key = "123456"
```

Fix:

```text
Use environment variables
```

---

# Edge Cases

## Invalid JSON

```python
json.loads("{invalid json}")
```

Raises error.

---

## Database Locking

Multiple writes may lock SQLite database.

---

## API Timeout

```python
requests.get(url, timeout=5)
```

Prevents hanging requests.

---

# Key Points

- SQL is used for relational databases.
    
- CRUD represents basic data operations.
    
- Python connects to databases using drivers.
    
- JSON is the standard API data format.
    
- REST APIs enable system communication.
    
- Requests library handles HTTP operations.
    
- Authentication secures API access.
    

---

# Interview Summary

```text
CRUD → Create, Read, Update, Delete
SQL → Database language
JSON → Data exchange format
REST → API architecture style
Requests → HTTP client library
Auth → Security layer
```

---

# Conclusion

Databases and APIs form the backbone of modern applications. SQL handles structured data storage, Python enables database interaction, JSON ensures lightweight data exchange, and REST APIs connect systems. Mastering these concepts is essential for backend development, full-stack engineering, and real-world production systems.