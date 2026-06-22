# Exception Handling and Python Libraries & Frameworks

## Definition

This file covers two major areas of Python development:

1. **Exception Handling** — the mechanism used to manage runtime errors safely.
    
2. **Python Libraries & Frameworks** — reusable tools that speed up development and solve common problems.
    

Exception handling ensures programs do not crash unexpectedly, while libraries/frameworks provide pre-built functionality for real-world applications.

---

# Why These Concepts Exist

## Without Exception Handling

```python
x = 10 / 0
print("This will never run")
```

Program crashes immediately.

## Without Libraries

```python
# Without requests library
import socket
# You must manually build HTTP calls
```

Too complex for basic tasks.

---

# Mental Model

```text
Python Program
     |
     V
Runtime Execution
     |
     +--> Success Path
     |
     +--> Error Path (Exception Handling)
```

Libraries:

```text
Problem → Library → Solution
```

Frameworks:

```text
Framework controls flow
Developer fills logic
```

---

# Try, Except, Else, Finally

## Definition

Python uses `try-except` blocks to handle runtime errors gracefully.

---

# Basic Syntax

```python
try:
    # risky code
except Exception:
    # handle error
else:
    # runs if no error
finally:
    # always runs
```

---

# Try and Except

## Example

```python
try:
    result = 10 / 0
except ZeroDivisionError:
    print("Cannot divide by zero")
```

Output:

```
Cannot divide by zero
```

---

# Try, Except, Else

## Example

```python
try:
    result = 10 / 2
except ZeroDivisionError:
    print("Error occurred")
else:
    print("Success:", result)
```

Output:

```
Success: 5.0
```

---

# Finally Block

Always executes.

## Example

```python
try:
    file = open("data.txt", "r")
    data = file.read()
except FileNotFoundError:
    print("File not found")
finally:
    print("Execution completed")
```

Output:

```
Execution completed
```

---

# Internal Flow

```text
Try Block
   |
   +--> Error? ---- Yes ----> Except
   |                     |
   |                     No
   |                     |
   V                     V
 Else Block         Continue Execution
   |
   V
Finally Block (Always Runs)
```

---

# Common Built-in Exceptions

|Exception|Meaning|
|---|---|
|ZeroDivisionError|Divide by zero|
|TypeError|Wrong data type|
|ValueError|Invalid value|
|IndexError|List index out of range|
|KeyError|Missing dictionary key|
|FileNotFoundError|File missing|

---

# Custom Exceptions

## Definition

Custom exceptions allow developers to define application-specific error types.

---

# Why Custom Exceptions Exist

Built-in errors are generic.

Example problem:

```text
UserAgeError → better than ValueError
PaymentFailedError → better than Exception
```

---

# Creating Custom Exception

## Example

```python
class InvalidAgeError(Exception):
    pass
```

---

# Using Custom Exception

```python
def check_age(age):

    if age < 18:
        raise InvalidAgeError("Age must be 18 or above")

    return "Allowed"
```

---

## Usage

```python
try:
    print(check_age(15))
except InvalidAgeError as e:
    print(e)
```

Output:

```
Age must be 18 or above
```

---

# Advanced Custom Exception

```python
class PaymentFailedError(Exception):

    def __init__(self, message, code):

        super().__init__(message)

        self.code = code
```

---

## Usage

```python
raise PaymentFailedError(
    "Transaction failed",
    500
)
```

---

# Mental Model

```text
Business Logic Error
        |
        V
Custom Exception Class
        |
        V
Meaningful Error Handling
```

---

# Key Points

- Custom exceptions improve clarity.
    
- They help in debugging and logging.
    
- They make APIs more readable and maintainable.
    

---

# Python Libraries (Brief Overview)

## Definition

A library is a collection of pre-written code used to perform specific tasks.

---

# Why Libraries Exist

Instead of building everything from scratch:

```text
HTTP requests
Data processing
Machine learning
Database handling
```

Python provides ready-made solutions.

---

# Common Python Standard Libraries

## 1. math

```python
import math

print(math.sqrt(16))
```

---

## 2. datetime

```python
from datetime import datetime

print(datetime.now())
```

---

## 3. os

```python
import os

print(os.listdir())
```

---

## 4. json

```python
import json

data = {"name": "Ali"}

print(json.dumps(data))
```

---

## 5. random

```python
import random

print(random.randint(1, 10))
```

---

# Popular External Libraries

## 1. requests

Used for HTTP requests.

```python
import requests

response = requests.get("https://api.example.com")
```

---

## 2. numpy

Used for numerical computing.

```python
import numpy as np

arr = np.array([1, 2, 3])
```

---

## 3. pandas

Used for data analysis.

```python
import pandas as pd

df = pd.DataFrame({"name": ["Ali", "Sara"]})
```

---

## 4. flask

Lightweight web framework.

```python
from flask import Flask

app = Flask(__name__)
```

---

## 5. django

Full-stack web framework.

```text
Handles:
- Authentication
- ORM
- Routing
- Admin panel
```

---

# Python Frameworks

## Definition

A framework is a structured environment that defines application flow.

---

# Library vs Framework

|Feature|Library|Framework|
|---|---|---|
|Control|Developer|Framework|
|Flexibility|High|Structured|
|Example|requests|Django|

---

# Popular Python Frameworks

## 1. Django

```text
Full-stack framework
```

Used for:

- E-commerce
    
- CMS
    
- Large applications
    

---

## 2. Flask

```text
Micro-framework
```

Used for:

- APIs
    
- Lightweight services
    

---

## 3. FastAPI

```text
Modern API framework
```

Used for:

- High-performance APIs
    
- Async systems
    

---

# Real-World Use Cases

## Use Case 1: API Error Handling

```python
try:
    response = requests.get("invalid-url")
except requests.exceptions.RequestException:
    print("API request failed")
```

---

## Use Case 2: Banking System Exception

```python
class InsufficientBalanceError(Exception):
    pass
```

Used in:

- Banking apps
    
- Payment systems
    

---

## Use Case 3: Web API with Flask

```python
from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return "Hello World"
```

---

# Common Mistakes

## Mistake 1: Catching All Exceptions

### Wrong

```python
try:
    x = 10 / 0
except:
    print("Error")
```

---

### Fix

```python
except ZeroDivisionError:
```

---

## Mistake 2: Ignoring finally Use

### Wrong

```python
file = open("data.txt")
```

---

### Fix

```python
with open("data.txt") as file:
    pass
```

---

## Mistake 3: Overusing Custom Exceptions

Too many custom exceptions make code complex.

---

# Edge Cases

## Exception Masking

```python
try:
    raise ValueError()
except Exception:
    raise
```

---

## Nested Exceptions

```python
try:
    try:
        1 / 0
    except ZeroDivisionError:
        raise ValueError("Wrapped Error")
except ValueError as e:
    print(e)
```

---

# Interview Questions

## Q1: Difference between try, except, else, finally?

|Block|Purpose|
|---|---|
|try|Risky code|
|except|Handle error|
|else|No error path|
|finally|Always executes|

---

## Q2: What is a custom exception?

A user-defined error class that extends `Exception`.

---

## Q3: Why use libraries?

To avoid reinventing the wheel and speed up development.

---

## Q4: Difference between library and framework?

Framework controls flow, library does not.

---

## Q5: Name popular Python frameworks

- Django
    
- Flask
    
- FastAPI
    

---

# Key Points

- Exception handling prevents program crashes.
    
- `finally` always executes.
    
- Custom exceptions improve clarity.
    
- Libraries provide reusable functionality.
    
- Frameworks define application structure.
    
- Python has rich ecosystem for web, data, and automation.
    

---

# Interview Summary

```text
try → risky code
except → handle errors
else → success path
finally → always runs
```

---

```text
Library → You control flow
Framework → Framework controls flow
```

---

# Conclusion

Exception handling and Python’s ecosystem of libraries and frameworks are essential for building robust applications. Exception handling ensures reliability, while libraries and frameworks accelerate development. Mastering these concepts is critical for backend development, APIs, data systems, and production-level Python applications.