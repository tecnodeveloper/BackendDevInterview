# File 5: Modules, Packages & Advanced Python

## Definition

As Python applications grow, code must be organized, reused, and optimized. Python provides several advanced features that help developers write scalable, maintainable, and efficient applications.

This file covers:

- Modules and Imports    
- Packages    
- Iterators    
- Generators    
- Decorators    
- Closures    
- `map()`, `filter()`, `reduce()`    
- `zip()` and `enumerate()`    

These concepts are widely used in:

- Backend Development
    
- Data Engineering
    
- APIs
    
- Automation Scripts
    
- Machine Learning
    
- Enterprise Applications
    

---

# Why These Concepts Exist

Imagine building an Employee Management System with thousands of lines of code.

Without modules:

```python
# Everything in one file
create_employee()
update_employee()
delete_employee()
generate_report()
send_email()
```

The file becomes difficult to maintain.

Without generators:

```python
employees = load_1000000_records()
```

Memory usage becomes excessive.

Without decorators:

```python
log_start()
execute_function()
log_end()
```

The same code gets repeated everywhere.

Python provides advanced tools to solve these problems.

---

# Mental Model

```text
Large Application
        |
        V
   Modules
        |
        V
   Packages
        |
        V
Reusable Components
```

Advanced Python Features:

```text
Iterators   -> One item at a time
Generators  -> Lazy data production
Decorators  -> Modify functions
Closures    -> Remember values
map/filter  -> Functional processing
zip         -> Combine collections
enumerate   -> Index tracking
```

---

# Modules and Imports

## Definition

A module is a Python file containing variables, functions, and classes.

Example:

```text
employee.py
```

---

# Why Modules Exist

Modules improve:

- Code organization
    
- Reusability
    
- Maintainability
    
- Separation of concerns
    

---

# Creating a Module

## employee.py

```python
def calculate_bonus(salary):
    return salary * 0.10
```

---

# Importing a Module

```python
import employee

print(
    employee.calculate_bonus(80000)
)
```

Output:

```text
8000.0
```

---

# Import Specific Function

```python
from employee import calculate_bonus

print(
    calculate_bonus(80000)
)
```

---

# Import Alias

```python
import employee as emp

print(
    emp.calculate_bonus(80000)
)
```

---

# Common Built-in Modules

|Module|Purpose|
|---|---|
|math|Mathematical Functions|
|random|Random Values|
|datetime|Dates and Times|
|os|Operating System|
|json|JSON Processing|
|collections|Specialized Containers|

---

## Example

```python
import math

print(
    math.sqrt(25)
)
```

Output:

```text
5.0
```

---

# Packages

## Definition

A package is a collection of related modules organized in directories.

---

# Structure

```text
company/
│
├── __init__.py
├── employee.py
├── payroll.py
└── reports.py
```

---

# Mental Model

```text
Package
   |
   ├── Module A
   ├── Module B
   └── Module C
```

---

# Example

## employee.py

```python
def get_employee():
    return "Ali"
```

---

## main.py

```python
from company.employee import get_employee

print(
    get_employee()
)
```

Output:

```text
Ali
```

---

# Iterators

## Definition

An iterator produces one value at a time.

---

# Internal Behavior

```text
Collection
     |
Iterator
     |
next()
     |
Return Item
```

---

## Example

```python
employees = [
    "Ali",
    "Sara",
    "Ahmed"
]

employee_iterator = iter(employees)

print(next(employee_iterator))
print(next(employee_iterator))
```

Output:

```text
Ali
Sara
```

---

# StopIteration

```python
employees = ["Ali"]

iterator = iter(employees)

print(next(iterator))
print(next(iterator))
```

Error:

```text
StopIteration
```

---

# Generators

## Definition

Generators produce values lazily using the `yield` keyword.

Unlike lists, generators do not store all values in memory.

---

# Why Generators Exist

Without generators:

```python
employee_ids = [
    employee_id
    for employee_id in range(1000000)
]
```

Large memory consumption.

With generators:

```python
employee_ids = (
    employee_id
    for employee_id in range(1000000)
)
```

Memory efficient.

---

# Generator Function

```python
def employee_generator():

    yield "Ali"
    yield "Sara"
    yield "Ahmed"
```

---

## Usage

```python
employees = employee_generator()

print(next(employees))
print(next(employees))
```

Output:

```text
Ali
Sara
```

---

# Database Example

```python
def fetch_employee_records():

    for employee_id in range(1, 1000000):

        yield {
            "employee_id": employee_id
        }
```

Used for processing large datasets.

---

# Iterator vs Generator

|Feature|Iterator|Generator|
|---|---|---|
|Creation|iter()|yield|
|Memory Efficient|Yes|More Efficient|
|Custom Logic|Moderate|Easy|
|Implementation|Manual|Automatic|

---

# Decorators

## Definition

Decorators modify or extend function behavior without changing the original function.

---

# Mental Model

```text
Function
   |
Decorator
   |
Enhanced Function
```

---

# Example

```python
def logger(function):

    def wrapper():

        print("Starting...")

        function()

        print("Completed")

    return wrapper
```

---

## Apply Decorator

```python
@logger
def generate_report():

    print("Generating Report")
```

---

## Usage

```python
generate_report()
```

Output:

```text
Starting...
Generating Report
Completed
```

---

# Real-World Backend Example

```python
@login_required
def employee_dashboard():
    pass
```

Used in:

- Authentication
    
- Authorization
    
- Logging
    
- Monitoring
    

---

# Closures

## Definition

A closure is a function that remembers variables from its enclosing scope even after the outer function has finished execution.

---

# Example

```python
def department_manager(department):

    def get_department():

        return department

    return get_department
```

---

## Usage

```python
it_department = department_manager("IT")

print(
    it_department()
)
```

Output:

```text
IT
```

---

# Internal Behavior

```text
Outer Function
      |
Creates Variable
      |
Returns Inner Function
      |
Variable Remembered
```

---

# map()

## Definition

Applies a function to every item in an iterable.

---

## Example

```python
salaries = [
    50000,
    60000,
    70000
]

updated_salary = map(
    lambda salary: salary * 1.10,
    salaries
)

print(list(updated_salary))
```

Output:

```python
[55000.0, 66000.0, 77000.0]
```

---

# filter()

## Definition

Filters elements based on a condition.

---

## Example

```python
employees = [
    {
        "name": "Ali",
        "salary": 90000
    },
    {
        "name": "Sara",
        "salary": 60000
    }
]

high_salary = filter(
    lambda employee:
    employee["salary"] > 80000,
    employees
)

print(list(high_salary))
```

Output:

```python
[
    {
        'name': 'Ali',
        'salary': 90000
    }
]
```

---

# reduce()

## Definition

Reduces multiple values into a single value.

Requires:

```python
from functools import reduce
```

---

## Example

```python
from functools import reduce

salaries = [
    50000,
    60000,
    70000
]

total_salary = reduce(
    lambda total, salary:
    total + salary,
    salaries
)

print(total_salary)
```

Output:

```text
180000
```

---

# Comparison: map vs filter vs reduce

|Function|Purpose|Output|
|---|---|---|
|map()|Transform Data|Collection|
|filter()|Select Data|Collection|
|reduce()|Aggregate Data|Single Value|

---

# zip()

## Definition

Combines multiple iterables element-by-element.

---

## Example

```python
employee_ids = [
    101,
    102,
    103
]

employee_names = [
    "Ali",
    "Sara",
    "Ahmed"
]

result = zip(
    employee_ids,
    employee_names
)

print(list(result))
```

Output:

```python
[
    (101, 'Ali'),
    (102, 'Sara'),
    (103, 'Ahmed')
]
```

---

# Database Example

```python
employee_ids = [101, 102]
departments = ["IT", "HR"]

employees = list(
    zip(
        employee_ids,
        departments
    )
)
```

Output:

```python
[
    (101, 'IT'),
    (102, 'HR')
]
```

---

# enumerate()

## Definition

Adds an index to iterable items.

---

## Example

```python
employees = [
    "Ali",
    "Sara",
    "Ahmed"
]

for index, employee in enumerate(employees):

    print(index, employee)
```

Output:

```text
0 Ali
1 Sara
2 Ahmed
```

---

## Custom Start Index

```python
for index, employee in enumerate(
    employees,
    start=1
):
    print(index, employee)
```

Output:

```text
1 Ali
2 Sara
3 Ahmed
```

---

# Step-by-Step Example

## Employee Salary Processing

### Step 1: Raw Data

```python
employees = [
    {
        "employee_id": 101,
        "salary": 50000
    },
    {
        "employee_id": 102,
        "salary": 60000
    }
]
```

---

### Step 2: Increase Salary

```python
updated_salary = map(
    lambda employee: {
        **employee,
        "salary":
        employee["salary"] * 1.10
    },
    employees
)
```

---

### Step 3: Filter Employees

```python
high_salary = filter(
    lambda employee:
    employee["salary"] > 55000,
    updated_salary
)
```

---

### Step 4: Display Results

```python
print(
    list(high_salary)
)
```

Output:

```python
[
    {
        'employee_id': 102,
        'salary': 66000.0
    }
]
```

---

# Real-World Use Case 1: API Authentication

```python
@login_required
def employee_dashboard():
    return "Dashboard"
```

Used in:

- Django
    
- Flask
    
- FastAPI
    

Purpose:

- Authentication
    
- Access Control
    

---

# Real-World Use Case 2: Processing Large Database Records

```python
def fetch_records():

    for record_id in range(
        1,
        1000000
    ):
        yield {
            "record_id": record_id
        }
```

Used in:

- ETL Pipelines
    
- Data Warehouses
    
- Analytics Systems
    

Purpose:

- Low Memory Usage
    
- High Scalability
    

---

# Common Mistakes

## Mistake 1: Importing Everything

### Wrong

```python
from employee import *
```

---

### Fix

```python
from employee import calculate_bonus
```

---

## Mistake 2: Using List Instead of Generator

### Wrong

```python
records = [
    record
    for record in range(
        1000000
    )
]
```

High memory consumption.

---

### Fix

```python
records = (
    record
    for record in range(
        1000000
    )
)
```

---

## Mistake 3: Forgetting Return in Decorator

### Wrong

```python
def logger(function):

    def wrapper():
        function()
```

Decorator won't work properly.

---

### Fix

```python
def logger(function):

    def wrapper():
        function()

    return wrapper
```

---

## Mistake 4: Consuming Generator Twice

### Wrong

```python
employees = employee_generator()

list(employees)

list(employees)
```

Second call returns empty results.

---

### Fix

Create a new generator.

```python
employees = employee_generator()
```

---

# Edge Cases and Pitfalls

---

## Empty zip()

```python
employee_ids = []
employee_names = []

print(
    list(
        zip(
            employee_ids,
            employee_names
        )
    )
)
```

Output:

```python
[]
```

---

## Unequal zip() Lengths

```python
ids = [1, 2, 3]
names = ["Ali"]
```

Output:

```python
list(zip(ids, names))
```

```python
[(1, 'Ali')]
```

zip stops at the shortest iterable.

---

## Generator Exhaustion

```python
generator = employee_generator()

list(generator)

list(generator)
```

Second result:

```python
[]
```

---

# Internal Behavior

## Iterator Flow

```text
Iterable
    |
iter()
    |
Iterator
    |
next()
    |
Return Value
```

---

## Generator Flow

```text
yield
   |
Pause Function
   |
next()
   |
Resume Function
```

---

## Decorator Flow

```text
Original Function
        |
Decorator
        |
Wrapper Function
        |
Enhanced Function
```

---

# Comparison Table

|Concept|Purpose|Memory Efficient|
|---|---|---|
|Module|Reuse Code|N/A|
|Package|Organize Modules|N/A|
|Iterator|Sequential Access|Yes|
|Generator|Lazy Evaluation|Excellent|
|Decorator|Extend Functions|N/A|
|Closure|Preserve State|N/A|
|map()|Transform Data|Yes|
|filter()|Filter Data|Yes|
|reduce()|Aggregate Data|Yes|
|zip()|Combine Iterables|Yes|
|enumerate()|Add Indexes|Yes|

---

# Key Points

- Modules help organize and reuse code.
    
- Packages group related modules.
    
- Iterators provide sequential access.
    
- Generators use `yield` for lazy evaluation.
    
- Decorators modify functions without changing their code.
    
- Closures remember variables from outer scopes.
    
- `map()` transforms data.
    
- `filter()` selects data.
    
- `reduce()` aggregates data.
    
- `zip()` combines iterables.
    
- `enumerate()` provides indexes during iteration.
    

---

# Common Interview Questions

## Q1: Difference Between Module and Package?

|Module|Package|
|---|---|
|Single Python File|Collection of Modules|
|`.py` File|Directory|

---

## Q2: Difference Between Iterator and Generator?

|Iterator|Generator|
|---|---|
|Uses `iter()`|Uses `yield`|
|Manual Implementation|Automatic|
|More Code|Less Code|

---

## Q3: Why Use Generators?

To process large datasets with low memory consumption.

---

## Q4: What is a Decorator?

A function that modifies another function's behavior without changing its source code.

---

## Q5: What is a Closure?

A nested function that remembers variables from its enclosing scope.

---

## Q6: Difference Between map(), filter(), and reduce()?

|Function|Purpose|
|---|---|
|map()|Transform|
|filter()|Select|
|reduce()|Aggregate|

---

## Q7: What Does zip() Do?

Combines multiple iterables into tuples.

---

## Q8: What Does enumerate() Do?

Adds index values while iterating.

---

# Interview Summary

### Which Feature Uses `yield`?

```python
Generator
```

---

### Which Feature Modifies Functions?

```python
Decorator
```

---

### Which Function Aggregates Data?

```python
reduce()
```

---

### Which Function Filters Data?

```python
filter()
```

---

### Which Function Combines Collections?

```python
zip()
```

---

### Which Function Adds Indexes?

```python
enumerate()
```

---

### Best Feature for Large Dataset Processing?

```python
Generator
```

Because generators load data lazily and consume minimal memory.

---

# Conclusion

Modules, Packages, and Advanced Python concepts provide the foundation for building scalable and maintainable Python applications. Modules and packages improve code organization, generators optimize memory usage, decorators extend functionality, closures preserve state, and functional programming tools such as `map()`, `filter()`, and `reduce()` simplify data processing. Mastering these concepts is essential for backend development, automation, APIs, data engineering, and technical interviews.