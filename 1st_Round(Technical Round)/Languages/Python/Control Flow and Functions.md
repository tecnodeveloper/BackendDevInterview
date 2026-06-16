# Control Structures and Functions in Python

## Definition

**Control Structures** are programming constructs that control the flow of execution in a program.

**Functions** are reusable blocks of code that perform a specific task and can be called multiple times throughout a program.

In simple terms:

- Control Structures decide **what code runs and when**
    
- Functions allow you to **reuse logic without rewriting code**
    

---

# Why Control Structures and Functions Exist

Without control structures:

```python
print("Checking user")
print("Checking user")
print("Checking user")
```

Programs would execute line-by-line without decision-making capabilities.

Without functions:

```python
name = "Ali"
print(f"Hello {name}")

name = "Sara"
print(f"Hello {name}")

name = "Ahmed"
print(f"Hello {name}")
```

The same code would be repeated multiple times.

Control structures and functions solve these problems by:

- Making decisions
    
- Repeating tasks efficiently
    
- Organizing code
    
- Improving maintainability
    
- Reducing duplication
    

---

# Mental Model

Think of a program as a road.

```text
Program Start
      |
      V
   Decision?
   /      \
 Yes      No
  |        |
  V        V
Action A  Action B
      |
      V
 Continue
```

Functions are like reusable tools:

```text
Toolbox
   |
   ├── calculate_salary()
   ├── send_email()
   └── validate_user()
```

---

# Types of Control Structures

Python provides three main control structures:

1. Sequential Execution
    
2. Selection (Decision Making)
    
3. Iteration (Loops)
    

---

# Sequential Execution

Statements execute from top to bottom.

## Example

```python
employee_name = "Ali"
salary = 75000

print(employee_name)
print(salary)
```

### Output

```text
Ali
75000
```

---

# Selection Control Structures

Selection structures allow a program to make decisions.

---

## if Statement

### Syntax

```python
if condition:
    statement
```

### Example

```python
salary = 90000

if salary > 80000:
    print("Senior Employee")
```

---

## if-else Statement

### Syntax

```python
if condition:
    statement
else:
    statement
```

### Example

```python
salary = 60000

if salary > 80000:
    print("Senior Employee")
else:
    print("Junior Employee")
```

### Output

```text
Junior Employee
```

---

## if-elif-else Statement

### Example

```python
salary = 95000

if salary >= 100000:
    print("Executive")
elif salary >= 80000:
    print("Manager")
else:
    print("Employee")
```

---

# Nested Conditions

## Example

```python
employee = {
    "name": "Ali",
    "department": "IT",
    "salary": 90000
}

if employee["department"] == "IT":
    if employee["salary"] > 80000:
        print("Senior IT Employee")
```

---

# Iteration (Loops)

Loops execute code repeatedly.

---

## for Loop

### Syntax

```python
for item in iterable:
    statement
```

### Example

```python
employees = ["Ali", "Sara", "Ahmed"]

for employee in employees:
    print(employee)
```

### Output

```text
Ali
Sara
Ahmed
```

---

## Loop Through Database Records

```python
employees = [
    {"id": 1, "name": "Ali"},
    {"id": 2, "name": "Sara"},
    {"id": 3, "name": "Ahmed"}
]

for employee in employees:
    print(employee["name"])
```

---

## while Loop

### Syntax

```python
while condition:
    statement
```

### Example

```python
count = 1

while count <= 5:
    print(count)
    count += 1
```

---

# Loop Control Statements

---

## break

Stops loop execution.

```python
for employee_id in range(1, 10):
    if employee_id == 5:
        break

    print(employee_id)
```

---

## continue

Skips current iteration.

```python
for employee_id in range(1, 6):
    if employee_id == 3:
        continue

    print(employee_id)
```

---

## pass

Placeholder statement.

```python
if True:
    pass
```

---

# Functions

Functions encapsulate reusable logic.

---

## Function Syntax

```python
def function_name():
    statements
```

---

## Basic Function

```python
def display_employee():
    print("Employee Information")
```

Calling function:

```python
display_employee()
```

---

## Function with Parameters

```python
def display_employee(name):
    print(f"Employee: {name}")
```

Usage:

```python
display_employee("Ali")
```

---

## Function with Multiple Parameters

```python
def create_employee(employee_id, name, department):
    print(employee_id)
    print(name)
    print(department)
```

Usage:

```python
create_employee(
    101,
    "Ali",
    "IT"
)
```

---

# Returning Values

## Example

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

## Example

```python
def calculate_total_salary(salary, bonus):
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
Function Called
       |
Parameters Assigned
       |
Calculation Performed
       |
Return Value Created
       |
Returned To Caller
```

---

# Lambda Functions

Small anonymous functions.

## Syntax

```python
lambda arguments: expression
```

---

## Example

```python
calculate_tax = lambda salary: salary * 0.05

print(calculate_tax(100000))
```

---

# Real-World Example 1: Employee Management System

## Employee Data

```python
employees = [
    {
        "id": 1,
        "name": "Ali",
        "salary": 90000
    },
    {
        "id": 2,
        "name": "Sara",
        "salary": 70000
    }
]
```

---

## Function

```python
def get_high_salary_employees(employee_list):
    result = []

    for employee in employee_list:
        if employee["salary"] > 80000:
            result.append(employee)

    return result
```

---

## Usage

```python
print(
    get_high_salary_employees(
        employees
    )
)
```

---

# Real-World Example 2: Banking System

## Function

```python
def withdraw(balance, amount):
    if amount > balance:
        return "Insufficient Funds"

    return balance - amount
```

---

## Usage

```python
new_balance = withdraw(
    5000,
    1000
)

print(new_balance)
```

---

# Comparison Table

|Feature|Control Structures|Functions|
|---|---|---|
|Purpose|Control flow|Reuse logic|
|Examples|if, for, while|def, lambda|
|Reusability|No|Yes|
|Decision Making|Yes|Optional|
|Looping|Yes|No|

---

# Common Mistakes

## Mistake 1: Incorrect Indentation

### Wrong

```python
if True:
print("Hello")
```

### Fix

```python
if True:
    print("Hello")
```

---

## Mistake 2: Missing Return

### Wrong

```python
def calculate_salary():
    salary = 50000
```

Usage:

```python
result = calculate_salary()

print(result)
```

Output:

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

## Mistake 3: Infinite Loop

### Wrong

```python
count = 1

while count <= 5:
    print(count)
```

Problem:

```text
Loop never ends
```

---

### Fix

```python
count = 1

while count <= 5:
    print(count)
    count += 1
```

---

# Edge Cases and Pitfalls

## Empty List Iteration

```python
employees = []

for employee in employees:
    print(employee)
```

Output:

```text
No output
```

---

## Function Returning None

```python
def get_employee():
    pass
```

Output:

```python
print(get_employee())
```

```text
None
```

---

## Division by Zero

```python
def calculate_ratio(a, b):
    return a / b
```

Problem:

```python
calculate_ratio(10, 0)
```

Raises:

```text
ZeroDivisionError
```

---

# Internal Behavior

## Function Call Stack

```text
main()
   |
   V
calculate_bonus()
   |
   V
return value
```

Python stores function calls in memory using a stack structure.

---

# Key Points

- Control structures determine program flow.
    
- `if`, `elif`, and `else` handle decisions.
    
- `for` and `while` handle repetition.
    
- Functions encapsulate reusable logic.
    
- Functions can accept parameters and return values.
    
- Proper indentation is mandatory in Python.
    
- Lambda functions are useful for small operations.
    

---

# Interview Summary

### What are control structures?

Programming constructs that control execution flow.

---

### What are the main control structures in Python?

- if
    
- if-else
    
- if-elif-else
    
- for loop
    
- while loop
    

---

### What is a function?

A reusable block of code that performs a specific task.

---

### Difference Between Parameters and Arguments?

|Parameters|Arguments|
|---|---|
|Defined in function|Passed during call|
|Placeholder values|Actual values|

Example:

```python
def display(name):  # parameter
    print(name)

display("Ali")      # argument
```

---

### What is a Lambda Function?

A small anonymous function written in a single line.

---

### What is the Difference Between break and continue?

|break|continue|
|---|---|
|Stops loop completely|Skips current iteration|

---

# Conclusion

Control structures and functions are foundational concepts in Python programming. Control structures enable decision-making and repetition, while functions provide modularity and code reuse. Together, they form the building blocks for creating maintainable, scalable, and efficient applications ranging from simple scripts to enterprise-grade systems.