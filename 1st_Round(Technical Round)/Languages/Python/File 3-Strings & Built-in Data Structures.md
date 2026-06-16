# File 3: Strings & Built-in Data Structures

## Definition

**Strings** are sequences of characters used to store and manipulate text.

**Built-in Data Structures** are Python's native containers that help organize, store, and manage data efficiently.

Python provides four primary built-in data structures:

- Lists
    
- Tuples
    
- Sets
    
- Dictionaries
    

This file covers:

- Strings and String Methods
    
- Lists
    
- Tuples
    
- Sets
    
- Dictionaries
    
- List/Dict/Set Comprehensions
    
- Common Interview Questions
    

---

# Why Strings and Data Structures Exist

Real-world applications constantly manage data:

- Employee records
    
- Product catalogs
    
- Customer information
    
- API responses
    
- Database query results
    

Without data structures:

```python
employee1 = "Ali"
employee2 = "Sara"
employee3 = "Ahmed"
employee4 = "Usman"
```

Managing data becomes difficult and inefficient.

Built-in data structures solve this problem by organizing data into manageable collections.

---

# Mental Model

Think of Python data structures as containers.

```text
Python Data Structures
        |
        ├── List
        ├── Tuple
        ├── Set
        └── Dictionary
```

Think of strings as text documents.

```text
"Python"

P → Index 0
y → Index 1
t → Index 2
h → Index 3
o → Index 4
n → Index 5
```

---

# Strings

## Definition

A string is a sequence of characters enclosed in quotes.

---

## Creating Strings

```python
employee_name = "Ali Khan"
department = 'IT'
```

---

## Accessing Characters

```python
employee_name = "Ali"

print(employee_name[0])
```

Output:

```text
A
```

---

## String Length

```python
employee_name = "Ali Khan"

print(len(employee_name))
```

Output:

```text
8
```

---

## String Slicing

### Syntax

```python
string[start:end]
```

---

### Example

```python
employee_name = "Ali Khan"

print(employee_name[0:3])
```

Output:

```text
Ali
```

---

# Common String Methods

---

## upper()

```python
department = "it"

print(department.upper())
```

Output:

```text
IT
```

---

## lower()

```python
department = "IT"

print(department.lower())
```

Output:

```text
it
```

---

## strip()

Removes leading and trailing spaces.

```python
email = "  ali@company.com  "

print(email.strip())
```

Output:

```text
ali@company.com
```

---

## replace()

```python
department = "IT Department"

print(
    department.replace(
        "IT",
        "Engineering"
    )
)
```

Output:

```text
Engineering Department
```

---

## split()

```python
skills = "Python,SQL,MongoDB"

print(skills.split(","))
```

Output:

```python
['Python', 'SQL', 'MongoDB']
```

---

## join()

```python
skills = [
    "Python",
    "SQL",
    "MongoDB"
]

print(", ".join(skills))
```

Output:

```text
Python, SQL, MongoDB
```

---

## find()

```python
employee_name = "Ali Khan"

print(
    employee_name.find("Khan")
)
```

Output:

```text
4
```

---

## startswith()

```python
employee_name = "Ali Khan"

print(
    employee_name.startswith("Ali")
)
```

Output:

```text
True
```

---

# Lists

## Definition

Lists store ordered collections of items.

Lists are mutable.

---

## Creating Lists

```python
employees = [
    "Ali",
    "Sara",
    "Ahmed"
]
```

---

## Database Record Example

```python
employees = [
    {
        "employee_id": 101,
        "name": "Ali"
    },
    {
        "employee_id": 102,
        "name": "Sara"
    }
]
```

---

## Access Elements

```python
print(employees[0])
```

---

## Add Elements

```python
employees.append(
    {
        "employee_id": 103,
        "name": "Ahmed"
    }
)
```

---

## Remove Elements

```python
employees.pop()
```

---

## Common List Methods

```python
employees.append(employee)
employees.remove(employee)
employees.insert(0, employee)
employees.sort()
employees.reverse()
```

---

# Tuples

## Definition

Tuples are ordered, immutable collections.

---

## Creating Tuples

```python
employee = (
    101,
    "Ali",
    "IT"
)
```

---

## Access Values

```python
print(employee[1])
```

Output:

```text
Ali
```

---

## Why Use Tuples?

- Faster than lists
    
- Protects data from modification
    
- Useful for fixed records
    

---

## Database Example

```python
employee_record = (
    101,
    "Ali",
    75000
)
```

---

# Sets

## Definition

Sets store unique values.

Duplicates are automatically removed.

---

## Creating Sets

```python
departments = {
    "IT",
    "HR",
    "Finance"
}
```

---

## Duplicate Removal

```python
departments = {
    "IT",
    "IT",
    "HR"
}

print(departments)
```

Output:

```python
{'IT', 'HR'}
```

---

## Add Value

```python
departments.add("Marketing")
```

---

## Remove Value

```python
departments.remove("HR")
```

---

## Set Operations

### Union

```python
team_a = {"IT", "HR"}
team_b = {"Finance", "HR"}

print(team_a | team_b)
```

---

### Intersection

```python
print(team_a & team_b)
```

Output:

```python
{'HR'}
```

---

### Difference

```python
print(team_a - team_b)
```

Output:

```python
{'IT'}
```

---

# Dictionaries

## Definition

Dictionaries store data as key-value pairs.

---

## Creating Dictionary

```python
employee = {
    "employee_id": 101,
    "name": "Ali",
    "department": "IT"
}
```

---

## Database Record Example

```python
employee = {
    "employee_id": 101,
    "name": "Ali",
    "salary": 75000,
    "email": "ali@company.com"
}
```

---

## Access Value

```python
print(employee["name"])
```

Output:

```text
Ali
```

---

## Add Field

```python
employee["city"] = "Lahore"
```

---

## Update Field

```python
employee["salary"] = 85000
```

---

## Delete Field

```python
del employee["email"]
```

---

## Common Dictionary Methods

```python
employee.keys()
employee.values()
employee.items()
employee.get("name")
```

---

# Nested Data Structures

Real-world systems combine multiple structures.

---

## Example

```python
company = {
    "company_name": "Tech Corp",
    "employees": [
        {
            "employee_id": 101,
            "name": "Ali"
        },
        {
            "employee_id": 102,
            "name": "Sara"
        }
    ]
}
```

---

## Access Nested Data

```python
print(
    company["employees"][0]["name"]
)
```

Output:

```text
Ali
```

---

# List Comprehensions

## Definition

A concise way to create lists.

---

## Traditional Approach

```python
employee_ids = []

for employee_id in range(1, 6):
    employee_ids.append(employee_id)
```

---

## List Comprehension

```python
employee_ids = [
    employee_id
    for employee_id in range(1, 6)
]
```

Output:

```python
[1, 2, 3, 4, 5]
```

---

## Database Example

```python
employees = [
    {"employee_id": 101},
    {"employee_id": 102},
    {"employee_id": 103}
]

ids = [
    employee["employee_id"]
    for employee in employees
]
```

Output:

```python
[101, 102, 103]
```

---

# Dictionary Comprehensions

## Syntax

```python
{
    key: value
    for item in iterable
}
```

---

## Example

```python
employee_salary = {
    employee_id: 50000
    for employee_id in range(1, 4)
}
```

Output:

```python
{
    1: 50000,
    2: 50000,
    3: 50000
}
```

---

# Set Comprehensions

## Syntax

```python
{
    expression
    for item in iterable
}
```

---

## Example

```python
departments = [
    "IT",
    "IT",
    "HR",
    "Finance"
]

unique_departments = {
    department
    for department in departments
}
```

Output:

```python
{
    'IT',
    'HR',
    'Finance'
}
```

---

# Step-by-Step Example

## Employee Processing System

### Employee Records

```python
employees = [
    {
        "employee_id": 101,
        "name": "Ali",
        "salary": 90000
    },
    {
        "employee_id": 102,
        "name": "Sara",
        "salary": 70000
    }
]
```

---

### Extract Names

```python
employee_names = [
    employee["name"]
    for employee in employees
]
```

Output:

```python
['Ali', 'Sara']
```

---

### Extract High Salary Employees

```python
high_salary = [
    employee
    for employee in employees
    if employee["salary"] > 80000
]
```

Output:

```python
[
    {
        'employee_id': 101,
        'name': 'Ali',
        'salary': 90000
    }
]
```

---

# Real-World Use Case 1: Employee Management System

```python
employees = [
    {
        "employee_id": 101,
        "name": "Ali"
    }
]

for employee in employees:
    print(employee["name"])
```

Used in:

- HR Applications
    
- Payroll Systems
    
- Employee Portals
    

---

# Real-World Use Case 2: Product Catalog System

```python
products = [
    {
        "product_id": 1,
        "name": "Laptop",
        "price": 1200
    }
]
```

Used in:

- E-Commerce Platforms
    
- Inventory Management
    
- ERP Systems
    

---

# Comparison Table

|Structure|Ordered|Mutable|Duplicates|Access Speed|
|---|---|---|---|---|
|List|Yes|Yes|Yes|Fast|
|Tuple|Yes|No|Yes|Very Fast|
|Set|No|Yes|No|Very Fast|
|Dictionary|Yes|Yes|Keys Unique|Extremely Fast|

---

# Common Mistakes

## Mistake 1: Index Out of Range

### Wrong

```python
employees = ["Ali"]

print(employees[5])
```

Error:

```text
IndexError
```

---

### Fix

```python
if len(employees) > 5:
    print(employees[5])
```

---

## Mistake 2: Modifying Tuple

### Wrong

```python
employee = (
    101,
    "Ali"
)

employee[0] = 102
```

Error:

```text
TypeError
```

---

### Fix

Use a list when modifications are needed.

```python
employee = [
    101,
    "Ali"
]
```

---

## Mistake 3: Accessing Missing Dictionary Key

### Wrong

```python
employee = {
    "name": "Ali"
}

print(employee["salary"])
```

Error:

```text
KeyError
```

---

### Fix

```python
print(
    employee.get(
        "salary",
        0
    )
)
```

---

## Mistake 4: Assuming Set Order

### Wrong

```python
departments = {
    "IT",
    "HR",
    "Finance"
}

print(departments[0])
```

Error:

```text
TypeError
```

---

### Fix

Convert to list if indexing is required.

```python
departments_list = list(departments)
```

---

# Edge Cases and Pitfalls

---

## Empty List

```python
employees = []

print(len(employees))
```

Output:

```text
0
```

---

## Empty Dictionary

```python
employee = {}

print(employee)
```

Output:

```python
{}
```

---

## Empty String

```python
name = ""

print(len(name))
```

Output:

```text
0
```

---

## Duplicate Values in Set

```python
departments = {
    "IT",
    "IT",
    "HR"
}
```

Output:

```python
{'IT', 'HR'}
```

---

# Internal Behavior

## List Storage

```text
Index     Value
----------------
0         Ali
1         Sara
2         Ahmed
```

---

## Dictionary Hash Table

```text
Key
 |
Hash Function
 |
Memory Address
 |
Value
```

Dictionary lookups are generally O(1).

---

## String Memory Model

```text
String: "Python"

Index:
0 1 2 3 4 5
P y t h o n
```

Strings are immutable.

---

# Key Points

- Strings are immutable sequences of characters.
    
- Lists are ordered and mutable.
    
- Tuples are ordered and immutable.
    
- Sets store unique values.
    
- Dictionaries store key-value pairs.
    
- Comprehensions provide concise data creation.
    
- Dictionaries are commonly used to represent database records.
    
- Nested data structures are heavily used in APIs and databases.
    

---

# Common Interview Questions

## Q1: Difference Between List and Tuple?

|List|Tuple|
|---|---|
|Mutable|Immutable|
|Slower|Faster|
|Dynamic|Fixed|

---

## Q2: Why Use a Set?

To:

- Remove duplicates
    
- Perform set operations
    
- Fast membership checks
    

Example:

```python
departments = {
    "IT",
    "IT",
    "HR"
}
```

Output:

```python
{'IT', 'HR'}
```

---

## Q3: Difference Between `remove()` and `pop()` in Lists?

|remove()|pop()|
|---|---|
|Removes by Value|Removes by Index|
|No Return|Returns Removed Item|

---

## Q4: Difference Between `[]`, `{}`, and `()`?

|Symbol|Structure|
|---|---|
|[]|List|
|{}|Dictionary / Set|
|()|Tuple|

---

## Q5: What is a Dictionary Lookup Complexity?

Average case:

```text
O(1)
```

Because dictionaries use hash tables.

---

## Q6: Are Strings Mutable?

```text
No
```

Strings cannot be modified after creation.

---

## Q7: What is a List Comprehension?

A concise way to create lists.

Example:

```python
numbers = [
    number
    for number in range(5)
]
```

---

# Interview Summary

### Most Commonly Used Data Structure?

```text
Dictionary
```

Especially for API responses and database records.

---

### Fastest Lookup?

```text
Dictionary
```

Average complexity:

```text
O(1)
```

---

### Which Structure Removes Duplicates?

```text
Set
```

---

### Which Structure Cannot Be Modified?

```text
Tuple
```

---

### Which Data Type Is Used Most in APIs?

```python
{
    "id": 101,
    "name": "Ali"
}
```

Dictionary.

---

# Conclusion

Strings and Python's built-in data structures are fundamental tools for organizing and processing data. Lists, Tuples, Sets, and Dictionaries each serve specific purposes, while comprehensions provide concise and efficient ways to create collections. Mastering these concepts is essential for working with databases, APIs, backend systems, automation scripts, data processing pipelines, and technical interviews.