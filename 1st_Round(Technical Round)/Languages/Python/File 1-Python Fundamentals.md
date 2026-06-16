# File 1: Python Fundamentals

## Definition

**Python Fundamentals** are the core concepts that form the foundation of Python programming. These concepts help developers understand how data is stored, manipulated, processed, and managed within a Python application.

This file covers:

- Variables and Data Types
    
- Type Conversion
    
- Operators
    
- Input/Output
    
- Python Keywords
    
- Memory Management Basics
    

---

# Why Python Fundamentals Matter

Every Python application, from a simple script to a large-scale backend system, relies on these concepts.

Without understanding fundamentals:

- Data cannot be stored properly
    
- Calculations become difficult
    
- User interaction is impossible
    
- Memory usage becomes inefficient
    
- Code becomes difficult to debug
    

Understanding these concepts creates a strong foundation for advanced topics such as:

- Object-Oriented Programming
    
- Data Structures
    
- APIs
    
- Databases
    
- Machine Learning
    

---

# Mental Model

Think of Python as an office.

```text
Memory (Storage Room)
       |
       V
Variables (Labels)
       |
       V
Data (Files)
```

Example:

```python
employee_name = "Ali"
```

```text
Variable Name  -> employee_name
Stored Value   -> "Ali"
Memory Address -> Internal Location
```

---

# Variables and Data Types

---

## What is a Variable?

A variable is a named location that stores data.

### Syntax

```python
variable_name = value
```

### Example

```python
employee_name = "Ali"
salary = 75000
is_active = True
```

---

## Variable Naming Rules

### Valid

```python
employee_name = "Ali"
salary_2025 = 75000
user1 = "Ahmed"
```

### Invalid

```python
1employee = "Ali"
class = "Python"
employee-name = "Ali"
```

---

## Common Data Types

|Data Type|Description|Example|
|---|---|---|
|int|Integer|100|
|float|Decimal Number|99.5|
|str|Text|"Ali"|
|bool|True/False|True|
|list|Collection|[1,2,3]|
|tuple|Immutable Collection|(1,2,3)|
|set|Unique Values|{1,2,3}|
|dict|Key-Value Data|{"name":"Ali"}|

---

## Integer

```python
employee_id = 101
salary = 75000
```

---

## Float

```python
product_price = 1200.50
rating = 4.8
```

---

## String

```python
employee_name = "Ali Khan"
department = "IT"
```

---

## Boolean

```python
is_active = True
is_admin = False
```

---

## Database Record Example

```python
employee = {
    "employee_id": 101,
    "name": "Ali",
    "department": "IT",
    "salary": 75000,
    "active": True
}
```

---

## Checking Data Type

### Syntax

```python
type(variable)
```

### Example

```python
salary = 75000

print(type(salary))
```

Output:

```python
<class 'int'>
```

---

# Type Conversion

## Definition

Type conversion changes data from one type to another.

---

## Why It Exists

Input data often arrives as strings.

Example:

```python
age = "25"
```

To perform calculations:

```python
age = int(age)
```

---

## Common Conversion Functions

|Function|Purpose|
|---|---|
|int()|Convert to Integer|
|float()|Convert to Float|
|str()|Convert to String|
|bool()|Convert to Boolean|
|list()|Convert to List|

---

## String to Integer

```python
salary = "75000"

salary = int(salary)

print(salary)
```

Output:

```python
75000
```

---

## Integer to String

```python
employee_id = 101

employee_id = str(employee_id)

print(employee_id)
```

Output:

```python
'101'
```

---

## Integer to Float

```python
salary = 75000

salary = float(salary)

print(salary)
```

Output:

```python
75000.0
```

---

## Incorrect Example

```python
salary = "75000"

result = salary + 5000
```

Error:

```python
TypeError
```

---

## Correct Example

```python
salary = int("75000")

result = salary + 5000

print(result)
```

Output:

```python
80000
```

---

# Operators

## Definition

Operators perform operations on variables and values.

---

# Arithmetic Operators

|Operator|Meaning|
|---|---|
|+|Addition|
|-|Subtraction|
|*|Multiplication|
|/|Division|
|//|Floor Division|
|%|Modulus|
|**|Power|

---

## Example

```python
salary = 80000
bonus = 10000

total = salary + bonus

print(total)
```

Output:

```python
90000
```

---

## Modulus Operator

```python
employee_id = 101

print(employee_id % 2)
```

Output:

```python
1
```

---

# Comparison Operators

|Operator|Meaning|
|---|---|
|==|Equal|
|!=|Not Equal|
|>|Greater Than|
|<|Less Than|
|>=|Greater Than or Equal|
|<=|Less Than or Equal|

---

## Example

```python
salary = 90000

print(salary > 80000)
```

Output:

```python
True
```

---

# Logical Operators

|Operator|Meaning|
|---|---|
|and|Both Conditions True|
|or|Any Condition True|
|not|Reverse Result|

---

## Example

```python
salary = 90000
department = "IT"

print(
    salary > 80000 and
    department == "IT"
)
```

Output:

```python
True
```

---

# Assignment Operators

```python
salary = 50000

salary += 5000

print(salary)
```

Output:

```python
55000
```

---

# Input and Output

## Definition

Input receives data from users.

Output displays data to users.

---

# Output Using print()

```python
print("Employee Management System")
```

Output:

```text
Employee Management System
```

---

## Multiple Values

```python
employee_name = "Ali"
salary = 75000

print(employee_name, salary)
```

Output:

```text
Ali 75000
```

---

# Input Using input()

```python
employee_name = input(
    "Enter employee name: "
)
```

---

## Example

```python
employee_name = input(
    "Employee Name: "
)

print(
    f"Welcome {employee_name}"
)
```

Input:

```text
Ali
```

Output:

```text
Welcome Ali
```

---

## Input Always Returns String

```python
salary = input("Salary: ")

print(type(salary))
```

Output:

```python
<class 'str'>
```

---

## Correct Numeric Input

```python
salary = int(
    input("Salary: ")
)
```

---

# Python Keywords

## Definition

Keywords are reserved words with special meaning in Python.

They cannot be used as variable names.

---

## Common Python Keywords

|Keyword|Purpose|
|---|---|
|if|Conditional Logic|
|else|Alternative Path|
|elif|Multiple Conditions|
|for|Loop|
|while|Loop|
|break|Exit Loop|
|continue|Skip Iteration|
|def|Function Definition|
|return|Return Value|
|class|Class Definition|
|import|Import Module|
|try|Exception Handling|
|except|Error Handling|
|True|Boolean True|
|False|Boolean False|
|None|No Value|

---

## Incorrect Example

```python
class = "Python"
```

Error:

```python
SyntaxError
```

---

## Correct Example

```python
course_name = "Python"
```

---

## View All Keywords

```python
import keyword

print(keyword.kwlist)
```

---

# Memory Management Basics

## Definition

Memory Management is the process of allocating and releasing memory automatically.

Python handles memory automatically through:

- Reference Counting
    
- Garbage Collection
    

---

# Mental Model

```text
Variable
   |
Reference
   |
Object in Memory
```

Example:

```python
employee_name = "Ali"
```

```text
employee_name
      |
      V
    "Ali"
```

---

# Memory Allocation Example

```python
employee = {
    "employee_id": 101,
    "name": "Ali"
}
```

Python allocates memory for:

```text
Dictionary Object
String Objects
Integer Objects
Variable References
```

---

# Reference Counting

Python tracks how many variables reference an object.

---

## Example

```python
employee_name = "Ali"

manager_name = employee_name
```

Memory:

```text
employee_name ----\
                   \
                    ---> "Ali"
                   /
manager_name -----/
```

Reference count:

```text
2
```

---

## Removing Reference

```python
employee_name = None
```

Reference count becomes:

```text
1
```

---

# Garbage Collection

When no references exist:

```python
employee_name = "Ali"

employee_name = None
```

Python removes the unused object automatically.

---

## Internal Behavior

```text
Create Object
      |
Reference Assigned
      |
Reference Removed
      |
Reference Count = 0
      |
Garbage Collector Frees Memory
```

---

# Step-by-Step Example

## Employee Salary Calculator

### Step 1: Receive Input

```python
employee_name = input(
    "Employee Name: "
)

salary = int(
    input("Salary: ")
)
```

---

### Step 2: Calculate Bonus

```python
bonus = salary * 0.10
```

---

### Step 3: Calculate Total Salary

```python
total_salary = salary + bonus
```

---

### Step 4: Display Result

```python
print(
    f"Employee: {employee_name}"
)

print(
    f"Total Salary: {total_salary}"
)
```

---

# Real-World Use Case 1: Employee Registration System

```python
employee = {
    "employee_id": 101,
    "name": "Ali",
    "department": "IT"
}

print(employee)
```

Used in:

- HR Systems
    
- Payroll Systems
    
- Employee Portals
    

---

# Real-World Use Case 2: Product Management System

```python
product = {
    "product_id": 501,
    "name": "Laptop",
    "price": 1200
}

print(product)
```

Used in:

- E-Commerce Applications
    
- Inventory Management
    
- Retail Systems
    

---

# Common Mistakes

## Mistake 1: Using String as Number

### Wrong

```python
salary = "75000"

print(salary + 5000)
```

### Fix

```python
salary = int("75000")

print(salary + 5000)
```

---

## Mistake 2: Using Keywords as Variables

### Wrong

```python
for = 10
```

### Fix

```python
count = 10
```

---

## Mistake 3: Forgetting Input Conversion

### Wrong

```python
salary = input("Salary: ")

print(salary + 5000)
```

### Fix

```python
salary = int(
    input("Salary: ")
)

print(salary + 5000)
```

---

# Edge Cases and Pitfalls

## Invalid Conversion

```python
salary = int("abc")
```

Error:

```python
ValueError
```

---

## Division by Zero

```python
salary = 10000

print(salary / 0)
```

Error:

```python
ZeroDivisionError
```

---

## Empty Input

```python
name = input("Name: ")
```

User enters:

```text
(empty)
```

Result:

```python
''
```

---

# Comparison Table

|Concept|Purpose|Example|
|---|---|---|
|Variable|Store Data|`salary = 75000`|
|Data Type|Define Data Kind|`int`, `str`|
|Conversion|Change Type|`int("10")`|
|Operator|Perform Operation|`+`, `-`, `*`|
|Input|Receive Data|`input()`|
|Output|Display Data|`print()`|
|Keyword|Reserved Word|`if`, `for`|
|Memory Management|Handle Memory|Garbage Collection|

---

# Key Points

- Variables store references to objects.
    
- Python supports multiple built-in data types.
    
- Type conversion changes data types.
    
- Operators perform calculations and comparisons.
    
- `input()` always returns a string.
    
- Keywords cannot be used as variable names.
    
- Python automatically manages memory.
    
- Garbage collection removes unused objects.
    

---

# Interview Summary

### What is a variable?

A named reference to an object stored in memory.

---

### What are Python's main data types?

- int
    
- float
    
- str
    
- bool
    
- list
    
- tuple
    
- set
    
- dict
    

---

### What does `input()` return?

```python
str
```

Always a string unless converted.

---

### Difference Between `=` and `==`?

|Operator|Meaning|
|---|---|
|=|Assignment|
|==|Comparison|

---

### What is garbage collection?

A mechanism that automatically removes unused objects from memory.

---

### What are Python keywords?

Reserved words that have predefined meanings and cannot be used as identifiers.

---

# Conclusion

Python Fundamentals provide the foundation for all Python development. Understanding variables, data types, type conversion, operators, input/output operations, keywords, and memory management enables developers to write reliable, efficient, and maintainable programs. These concepts are essential prerequisites for advanced Python topics such as functions, object-oriented programming, databases, web development, and data science.