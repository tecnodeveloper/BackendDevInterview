# 06 - Intermediate Python Interview Questions

This document covers some of the most frequently asked intermediate-level Python interview topics. These concepts are important for understanding Python internals, writing efficient code, and succeeding in technical interviews.

---

# Mutable vs Immutable Objects

## Definition

In Python, objects are categorized as either:

- **Mutable** → Can be modified after creation.
    
- **Immutable** → Cannot be modified after creation.
    

### Examples

#### Mutable Objects

```python
list
dict
set
bytearray
```

#### Immutable Objects

```python
int
float
bool
str
tuple
frozenset
```

---

## Why This Concept Exists

Python stores objects in memory.

For immutable objects:

- Values never change
    
- Safer memory optimizations
    
- Easier hashing
    

For mutable objects:

- Efficient updates
    
- Better performance for frequently changing data
    

---

## Mental Model

Think of immutable objects as a printed book.

```text
Cannot modify existing pages.
Need a new book.
```

Think of mutable objects as a notebook.

```text
Can erase and write new content.
```

---

## Syntax

### Immutable Example

```python
name = "John"

name += " Doe"

print(name)
```

Python creates a new string object.

---

### Mutable Example

```python
numbers = [1, 2, 3]

numbers.append(4)

print(numbers)
```

Output:

```python
[1, 2, 3, 4]
```

---

## Internal Behavior

### String Example

```python
name = "John"

print(id(name))

name += " Doe"

print(id(name))
```

Different memory addresses appear.

---

### List Example

```python
items = [1, 2, 3]

print(id(items))

items.append(4)

print(id(items))
```

Same memory address remains.

---

## Real-World Example

### User Profile Updates

```python
profile = {
    "name": "Alice",
    "age": 25
}

profile["age"] = 26
```

Dictionary is mutable.

---

## Common Mistake

### Incorrect

```python
def add_item(items=[]):
    items.append("Python")
    return items
```

Mutable default arguments are shared.

### Correct

```python
def add_item(items=None):
    if items is None:
        items = []

    items.append("Python")
    return items
```

---

## Key Points

- Lists are mutable.
    
- Dictionaries are mutable.
    
- Strings are immutable.
    
- Tuples are immutable.
    
- Mutable objects can cause side effects.
    

---

## Interview Summary

### What is mutable?

An object whose value can change after creation.

### What is immutable?

An object whose value cannot change after creation.

---

# Deep Copy vs Shallow Copy

## Definition

Copying objects can be done in two ways:

### Shallow Copy

Copies only the outer object.

### Deep Copy

Copies nested objects recursively.

---

## Why This Concept Exists

Without proper copying:

```text
Changing one object may unexpectedly affect another.
```

---

## Mental Model

### Shallow Copy

```text
New house
Same furniture
```

### Deep Copy

```text
New house
New furniture
```

---

## Syntax

```python
import copy
```

---

## Shallow Copy Example

```python
import copy

original = [[1, 2], [3, 4]]

copied = copy.copy(original)

copied[0].append(99)

print(original)
```

Output:

```python
[[1, 2, 99], [3, 4]]
```

Original changes too.

---

## Deep Copy Example

```python
import copy

original = [[1, 2], [3, 4]]

copied = copy.deepcopy(original)

copied[0].append(99)

print(original)
```

Output:

```python
[[1, 2], [3, 4]]
```

---

## Comparison Table

|Feature|Shallow Copy|Deep Copy|
|---|---|---|
|Copies outer object|Yes|Yes|
|Copies nested objects|No|Yes|
|Faster|Yes|No|
|More memory efficient|Yes|No|
|Fully independent|No|Yes|

---

## Common Mistake

```python
a = [[1, 2]]

b = a[:]

b[0].append(3)
```

Developers assume full copy.

Nested objects are still shared.

---

## Interview Summary

### When should deep copy be used?

When nested objects must be completely independent.

---

# is vs ==

## Definition

### ==

Checks value equality.

### is

Checks object identity.

---

## Why This Concept Exists

Two objects may contain identical values but exist in different memory locations.

---

## Syntax

```python
==
```

```python
is
```

---

## Example

```python
a = [1, 2]
b = [1, 2]

print(a == b)
```

Output:

```python
True
```

---

```python
print(a is b)
```

Output:

```python
False
```

---

## Internal Behavior

```python
print(id(a))
print(id(b))
```

Different memory addresses.

---

## Correct Usage

### Comparing Values

```python
if user_input == "yes":
    pass
```

---

### Comparing None

```python
if value is None:
    pass
```

---

## Common Mistake

### Incorrect

```python
if value == None:
    pass
```

### Correct

```python
if value is None:
    pass
```

---

## Comparison Table

|Operator|Purpose|
|---|---|
|==|Value comparison|
|is|Identity comparison|

---

## Interview Summary

### Difference?

```python
==
```

compares values.

```python
is
```

compares memory identity.

---

# @staticmethod vs @classmethod

## Definition

Python classes support different method types.

### Instance Method

Uses object instance.

### Static Method

Independent utility method.

### Class Method

Works with class itself.

---

## Why This Concept Exists

Not every method needs access to object data.

---

## Syntax

### Static Method

```python
class MathUtils:

    @staticmethod
    def add(a, b):
        return a + b
```

---

### Class Method

```python
class Person:

    count = 0

    @classmethod
    def increment(cls):
        cls.count += 1
```

---

## Comparison Table

|Type|First Parameter|
|---|---|
|Instance|self|
|Class|cls|
|Static|None|

---

## Example

```python
class User:

    total_users = 0

    @classmethod
    def increase_count(cls):
        cls.total_users += 1

    @staticmethod
    def validate_email(email):
        return "@" in email
```

---

## Real-World Usage

### Backend Validation

```python
User.validate_email("test@gmail.com")
```

---

### Tracking User Counts

```python
User.increase_count()
```

---

## Interview Summary

### When use staticmethod?

Utility functions unrelated to object state.

### When use classmethod?

Operations involving class-level data.

---

# GIL (Global Interpreter Lock)

## Definition

The GIL is a lock that allows only one thread to execute Python bytecode at a time in CPython.

---

## Why It Exists

Python's memory management is not fully thread-safe.

The GIL simplifies:

- Reference counting
    
- Memory safety
    
- Garbage collection
    

---

## Mental Model

```text
10 workers
1 key

Only worker with key can work.
```

---

## Internal Behavior

```python
import threading
```

Multiple threads exist.

But only one executes Python bytecode at a time.

---

## Impact

### CPU-Bound Tasks

Poor scaling.

```python
for i in range(100000000):
    pass
```

---

### I/O-Bound Tasks

Works well.

```python
requests.get(url)
```

Thread waits for network response.

---

## Interview Summary

### Does GIL allow true parallelism?

For CPU-bound Python code:

```text
No
```

---

# Multithreading vs Multiprocessing

## Definition

Both execute tasks concurrently.

---

## Multithreading

Uses multiple threads.

```python
import threading
```

---

## Multiprocessing

Uses multiple processes.

```python
import multiprocessing
```

---

## Comparison Table

|Feature|Threading|Multiprocessing|
|---|---|---|
|Memory|Shared|Separate|
|GIL Impact|Yes|No|
|Lightweight|Yes|No|
|CPU Tasks|Poor|Excellent|
|I/O Tasks|Excellent|Good|

---

## Example

### Threading

```python
import threading

def task():
    print("Running")

thread = threading.Thread(target=task)

thread.start()
```

---

### Multiprocessing

```python
from multiprocessing import Process

def task():
    print("Running")

process = Process(target=task)

process.start()
```

---

## Real-World Usage

### Threading

- API calls
    
- Database requests
    
- File downloads
    

### Multiprocessing

- Data analysis
    
- Image processing
    
- Machine learning
    

---

## Interview Summary

### Best for CPU-intensive tasks?

Multiprocessing.

---

# Python Memory Management

## Definition

Python automatically manages memory allocation and deallocation.

---

## Why It Exists

Developers should focus on application logic rather than manual memory handling.

---

## Components

### Private Heap

Stores Python objects.

### Reference Counting

Tracks active references.

### Garbage Collector

Removes unreachable objects.

---

## Example

```python
a = [1, 2, 3]

b = a

del b
```

Reference count decreases.

---

## Circular Reference

```python
a = {}
b = {}

a["b"] = b
b["a"] = a
```

Garbage collector handles this.

---

## Interview Summary

### How does Python manage memory?

Using:

- Reference counting
    
- Garbage collection
    

---

# Duck Typing

## Definition

If an object behaves like the expected object, Python accepts it.

---

## Mental Model

```text
If it walks like a duck
and quacks like a duck

Treat it as a duck.
```

---

## Example

```python
class Dog:

    def speak(self):
        print("Woof")


class Cat:

    def speak(self):
        print("Meow")


def make_sound(animal):
    animal.speak()
```

Works for both classes.

---

## Real-World Usage

Frameworks often rely on duck typing.

```python
response.json()
```

Object only needs required behavior.

---

## Interview Summary

Python focuses on behavior, not strict types.

---

# Context Managers

## Definition

Context managers automatically manage resources.

---

## Why This Concept Exists

Prevent resource leaks.

---

## Syntax

```python
with open("data.txt") as file:
    print(file.read())
```

---

## Internal Behavior

Equivalent to:

```python
file = open("data.txt")

try:
    print(file.read())

finally:
    file.close()
```

---

## Creating Custom Context Manager

```python
class DatabaseConnection:

    def __enter__(self):
        print("Connected")
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print("Closed")
```

---

## Usage

```python
with DatabaseConnection():
    print("Querying")
```

---

## Real-World Usage

### Database Connections

```python
with connection:
    pass
```

### File Handling

```python
with open("file.txt"):
    pass
```

---

## Interview Summary

### Benefits?

Automatic cleanup and exception safety.

---

# Common Coding Interview Questions (Strings, Lists, Dicts)

## Reverse a String

### Problem

Reverse a string.

### Solution

```python
text = "python"

result = text[::-1]

print(result)
```

---

## Count Character Frequency

```python
text = "banana"

freq = {}

for ch in text:
    freq[ch] = freq.get(ch, 0) + 1

print(freq)
```

---

## Remove Duplicates from List

```python
numbers = [1, 2, 2, 3, 3]

result = list(set(numbers))

print(result)
```

---

## Find Most Frequent Element

```python
from collections import Counter

numbers = [1, 2, 2, 3]

result = Counter(numbers).most_common(1)

print(result)
```

---

## Merge Dictionaries

```python
dict1 = {"a": 1}
dict2 = {"b": 2}

result = {**dict1, **dict2}

print(result)
```

---

## Check Palindrome

```python
text = "madam"

print(text == text[::-1])
```

---

## Two Sum

```python
nums = [2, 7, 11, 15]
target = 9

seen = {}

for i, num in enumerate(nums):

    diff = target - num

    if diff in seen:
        print(seen[diff], i)

    seen[num] = i
```

---

# Interview Quick Revision

## Frequently Asked Topics

- Mutable vs Immutable
    
- Deep Copy vs Shallow Copy
    
- `is` vs `==`
    
- `@staticmethod` vs `@classmethod`
    
- GIL
    
- Multithreading vs Multiprocessing
    
- Python Memory Management
    
- Duck Typing
    
- Context Managers
    
- String/List/Dictionary Coding Problems
    

---

# Key Takeaways

- Understand object mutability and copying behavior.
    
- Know the difference between identity and equality.
    
- Understand when to use static and class methods.
    
- Learn how the GIL affects threading.
    
- Choose threading for I/O tasks and multiprocessing for CPU tasks.
    
- Understand Python memory management fundamentals.
    
- Use duck typing for flexible designs.
    
- Use context managers for safe resource handling.
    
- Practice common coding interview problems regularly.