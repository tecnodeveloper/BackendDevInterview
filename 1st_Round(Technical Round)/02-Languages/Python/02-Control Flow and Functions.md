# Control Flow and Functions

## Definition

**Control Flow** determines the order in which statements execute in a Python program.

**Functions** are reusable blocks of code designed to perform specific tasks.

Together, control flow and functions allow developers to:

- Make decisions
    
- Repeat tasks
    
- Organize code
    
- Reduce duplication
    
- Build scalable applications
    

This file covers:

- If, Elif, Else
    
- Loops (For, While)
    
- Break, Continue, Pass
    
- Functions
    
- Arguments (`*args`, `**kwargs`)
    
- Lambda Functions
    
- Recursion
    
- Scope (Local, Global, Nonlocal)
    

---

# Why Control Flow and Functions Exist

Without control flow:

```python
print("Process Employee")
print("Process Employee")
print("Process Employee")
```

Programs would execute sequentially without decision-making.

Without functions:

```python
print("Employee: Ali")
print("Employee: Sara")
print("Employee: Ahmed")
```

Code would be repetitive and difficult to maintain.

Control flow and functions solve these problems by making code dynamic and reusable.

---

# Mental Model

Think of a Python program as a road map.

```text
Start
  |
  V
Decision?
 /      \
Yes      No
 |        |
 V        V
Action A Action B
    |
    V
 Continue
```

Functions are reusable tools:

```text
Toolbox
  |
  ├── calculate_salary()
  ├── validate_employee()
  ├── send_email()
  └── generate_report()
```

---

# If, Elif, Else

## Definition

Conditional statements allow a program to make decisions based on conditions.

---

# if Statement

## Syntax

```python
if condition:
    statement
```

---

## Example

```python
salary = 90000

if salary > 80000:
    print("Senior Employee")
```

Output:

```text
Senior Employee
```

---

# if-else Statement

## Syntax

```python
if condition:
    statement
else:
    statement
```

---

## Example

```python
salary = 60000

if salary > 80000:
    print("Senior Employee")
else:
    print("Junior Employee")
```

Output:

```text
Junior Employee
```

---

# if-elif-else Statement

Used when multiple conditions exist.

---

## Example

```python
salary = 95000

if salary >= 100000:
    print("Executive")
elif salary >= 80000:
    print("Manager")
else:
    print("Employee")
```

Output:

```text
Manager
```

---

# Nested Conditions

## Example

```python
employee = {
    "department": "IT",
    "salary": 90000
}

if employee["department"] == "IT":
    if employee["salary"] > 80000:
        print("Senior IT Employee")
```

---

# Loops

## Definition

Loops execute code repeatedly until a condition is met.

---

# For Loop

Used to iterate through collections.

---

## Syntax

```python
for item in collection:
    statement
```

---

## Database Example

```python
employees = [
    {"employee_id": 101, "name": "Ali"},
    {"employee_id": 102, "name": "Sara"}
]

for employee in employees:
    print(employee["name"])
```

Output:

```text
Ali
Sara
```

---

## Using range()

```python
for employee_id in range(1, 6):
    print(employee_id)
```

Output:

```text
1
2
3
4
5
```

---

# While Loop

Repeats while a condition remains true.

---

## Syntax

```python
while condition:
    statement
```

---

## Example

```python
count = 1

while count <= 5:
    print(count)
    count += 1
```

Output:

```text
1
2
3
4
5
```

---

# Comparison: For vs While

|Feature|For Loop|While Loop|
|---|---|---|
|Iteration Count Known|Yes|Usually No|
|Collection Traversal|Excellent|Possible|
|Infinite Loop Risk|Low|High|
|Readability|Better|Moderate|

---

# Break, Continue, Pass

---

# break

Stops loop execution immediately.

---

## Example

```python
for employee_id in range(1, 10):

    if employee_id == 5:
        break

    print(employee_id)
```

Output:

```text
1
2
3
4
```

---

# continue

Skips current iteration.

---

## Example

```python
for employee_id in range(1, 6):

    if employee_id == 3:
        continue

    print(employee_id)
```

Output:

```text
1
2
4
5
```

---

# pass

Placeholder statement.

---

## Example

```python
if True:
    pass
```

Useful during development when code is not yet implemented.

---

# Functions

## Definition

Functions are reusable blocks of code that perform specific tasks.

---

# Function Syntax

```python
def function_name():
    statements
```

---

# Basic Function

```python
def display_employee():
    print("Employee Information")
```

Calling function:

```python
display_employee()
```

Output:

```text
Employee Information
```

---

# Function with Parameters

```python
def display_employee(name):
    print(name)
```

Usage:

```python
display_employee("Ali")
```

Output:

```text
Ali
```

---

# Function with Return Value

```python
def calculate_bonus(salary):
    return salary * 0.10
```

Usage:

```python
bonus = calculate_bonus(80000)

print(bonus)
```

Output:

```text
8000
```

---

# Step-by-Step Function Execution

```python
def calculate_total_salary(
    salary,
    bonus
):
    total = salary + bonus
    return total

result = calculate_total_salary(
    80000,
    10000
)

print(result)
```

---

## Internal Execution

```text
Function Call
      |
Parameters Assigned
      |
Calculation Performed
      |
Return Value Generated
      |
Returned To Caller
```

Output:

```text
90000
```

---

# Function Arguments

Python supports flexible argument handling.

---

# Positional Arguments

```python
def create_employee(
    employee_id,
    name
):
    print(employee_id)
    print(name)

create_employee(
    101,
    "Ali"
)
```

---

# Default Arguments

```python
def create_employee(
    name,
    department="IT"
):
    print(name)
    print(department)

create_employee("Ali")
```

Output:

```text
Ali
IT
```

---

# *args

Accepts multiple positional arguments.

---

## Syntax

```python
def function_name(*args):
    pass
```

---

## Example

```python
def calculate_total_salary(*salaries):

    total = sum(salaries)

    return total

print(
    calculate_total_salary(
        50000,
        60000,
        70000
    )
)
```

Output:

```text
180000
```

---

# **kwargs

Accepts multiple keyword arguments.

---

## Syntax

```python
def function_name(**kwargs):
    pass
```

---

## Example

```python
def create_employee(**employee):

    print(employee)

create_employee(
    employee_id=101,
    name="Ali",
    department="IT"
)
```

Output:

```python
{
    'employee_id': 101,
    'name': 'Ali',
    'department': 'IT'
}
```

---

# Comparison: *args vs **kwargs

|Feature|*args|**kwargs|
|---|---|---|
|Type|Tuple|Dictionary|
|Input|Positional Arguments|Named Arguments|
|Symbol|*|**|

---

# Lambda Functions

## Definition

A lambda function is a small anonymous function written in a single line.

---

## Syntax

```python
lambda arguments: expression
```

---

## Example

```python
calculate_tax = lambda salary: salary * 0.05

print(
    calculate_tax(100000)
)
```

Output:

```text
5000
```

---

## Equivalent Function

```python
def calculate_tax(salary):
    return salary * 0.05
```

---

# Recursion

## Definition

Recursion occurs when a function calls itself.

---

# Mental Model

```text
Function
   |
Calls Itself
   |
Calls Itself
   |
Calls Itself
   |
Base Case Reached
```

---

# Example: Employee Hierarchy Levels

```python
def hierarchy_level(level):

    if level == 0:
        return

    print(level)

    hierarchy_level(level - 1)

hierarchy_level(5)
```

Output:

```text
5
4
3
2
1
```

---

# Recursive Flow

```text
hierarchy_level(5)
       |
hierarchy_level(4)
       |
hierarchy_level(3)
       |
hierarchy_level(2)
       |
hierarchy_level(1)
       |
hierarchy_level(0)
       |
Stop
```

---

# Common Recursion Mistake

### Wrong

```python
def loop_forever():
    loop_forever()
```

Problem:

```text
RecursionError
```

---

### Fix

Always provide a base case.

```python
def safe_function(count):

    if count == 0:
        return

    safe_function(count - 1)
```

---

# Scope

## Definition

Scope determines where variables can be accessed.

---

# Types of Scope

|Scope|Description|
|---|---|
|Local|Inside Function|
|Global|Entire Program|
|Nonlocal|Outer Function Variable|

---

# Local Scope

```python
def employee():

    name = "Ali"

    print(name)

employee()
```

---

### Wrong Access

```python
def employee():
    name = "Ali"

employee()

print(name)
```

Error:

```text
NameError
```

---

# Global Scope

```python
company_name = "Tech Corp"

def display_company():
    print(company_name)

display_company()
```

Output:

```text
Tech Corp
```

---

# Global Keyword

```python
salary = 50000

def update_salary():

    global salary

    salary = 70000

update_salary()

print(salary)
```

Output:

```text
70000
```

---

# Nonlocal Scope

Used inside nested functions.

---

## Example

```python
def company():

    department = "IT"

    def employee():

        nonlocal department

        department = "HR"

    employee()

    print(department)

company()
```

Output:

```text
HR
```

---

# Scope Hierarchy (LEGB Rule)

Python follows:

```text
L → Local
E → Enclosing
G → Global
B → Built-in
```

Search order:

```text
Local
  ↓
Enclosing
  ↓
Global
  ↓
Built-in
```

---

# Real-World Use Case 1: Employee Filtering System

```python
employees = [
    {
        "employee_id": 101,
        "salary": 90000
    },
    {
        "employee_id": 102,
        "salary": 60000
    }
]

for employee in employees:

    if employee["salary"] > 80000:
        print(employee)
```

Used in:

- HR Applications
    
- Payroll Systems
    
- Employee Dashboards
    

---

# Real-World Use Case 2: Banking Transaction Validation

```python
def withdraw(
    balance,
    amount
):

    if amount > balance:
        return "Insufficient Funds"

    return balance - amount

print(
    withdraw(
        5000,
        1000
    )
)
```

Output:

```text
4000
```

Used in:

- Banking Applications
    
- FinTech Platforms
    
- Payment Systems
    

---

# Common Mistakes

## Mistake 1: Missing Colon

### Wrong

```python
if salary > 50000
    print("Valid")
```

### Fix

```python
if salary > 50000:
    print("Valid")
```

---

## Mistake 2: Infinite While Loop

### Wrong

```python
count = 1

while count <= 5:
    print(count)
```

Problem:

```text
Never Ends
```

### Fix

```python
count = 1

while count <= 5:
    print(count)
    count += 1
```

---

## Mistake 3: Missing Return

### Wrong

```python
def calculate_salary():
    salary = 50000
```

Output:

```python
print(calculate_salary())
```

```text
None
```

---

### Fix

```python
def calculate_salary():
    return 50000
```

---

## Mistake 4: Modifying Global Variables Unnecessarily

### Wrong

```python
salary = 50000

def update():
    global salary
    salary += 1000
```

Prefer returning values instead:

```python
def update_salary(salary):
    return salary + 1000
```

---

# Edge Cases and Pitfalls

---

## Empty Collection Loop

```python
employees = []

for employee in employees:
    print(employee)
```

Output:

```text
No Output
```

---

## Recursive Depth Limit

```python
def recursive():
    recursive()
```

Eventually causes:

```text
RecursionError
```

---

## Accessing Local Variable Outside Function

```python
def employee():
    name = "Ali"

print(name)
```

Raises:

```text
NameError
```

---

# Internal Behavior

## Function Call Stack

```text
main()
   |
   V
calculate_salary()
   |
   V
calculate_bonus()
   |
Return
```

Python stores function calls in a stack structure.

---

## Loop Execution

```text
Check Condition
       |
True ------> Execute
 |
False
 |
Stop
```

---

# Key Points

- `if`, `elif`, and `else` control decision-making.
    
- `for` loops iterate over collections.
    
- `while` loops repeat while a condition is true.
    
- `break` stops a loop.
    
- `continue` skips an iteration.
    
- `pass` acts as a placeholder.
    
- Functions improve code reuse and maintainability.
    
- `*args` accepts multiple positional arguments.
    
- `**kwargs` accepts multiple keyword arguments.
    
- Lambda functions are anonymous one-line functions.
    
- Recursion requires a base case.
    
- Python follows the LEGB scope rule.
    

---

# Interview Summary

### What is control flow?

The order in which statements execute in a program.

---

### Difference Between `if`, `elif`, and `else`?

|Statement|Purpose|
|---|---|
|if|First Condition|
|elif|Additional Conditions|
|else|Default Path|

---

### Difference Between `for` and `while`?

|For|While|
|---|---|
|Known Iterations|Unknown Iterations|
|Collection Traversal|Condition-Based|

---

### What is the purpose of `break`?

Terminates a loop immediately.

---

### Difference Between `*args` and `**kwargs`?

|Feature|*args|**kwargs|
|---|---|---|
|Data Type|Tuple|Dictionary|
|Accepts|Positional Arguments|Named Arguments|

---

### What is recursion?

A technique where a function calls itself until a base condition is reached.

---

### What is the LEGB Rule?

```text
Local
Enclosing
Global
Built-in
```

Python searches variables in this order.

---

### What is a Lambda Function?

A small anonymous function written in one line.

Example:

```python
lambda x: x * 2
```

---

# Conclusion

Control Flow and Functions are the foundation of program logic in Python. Control structures enable decision-making and repetition, while functions promote modularity, code reuse, and maintainability. Mastering conditionals, loops, recursion, argument handling, lambda functions, and variable scope is essential for building scalable Python applications, APIs, automation scripts, and enterprise software systems.