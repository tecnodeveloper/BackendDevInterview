# File 4: Object-Oriented Programming (OOP)

## Definition

**Object-Oriented Programming (OOP)** is a programming paradigm that organizes code into **objects**, which are instances of **classes**. OOP helps developers model real-world entities, improve code reusability, and build scalable applications.

A class acts as a blueprint, while an object is a real instance created from that blueprint.

This file covers:

- Classes and Objects
    
- Constructors
    
- Instance vs Class Variables
    
- Inheritance
    
- Polymorphism
    
- Encapsulation
    
- Abstraction
    
- Method Overriding
    
- Method Resolution Order (MRO)
    

---

# Why OOP Exists

Imagine building an Employee Management System.

Without OOP:

```python
employee1_name = "Ali"
employee1_salary = 75000

employee2_name = "Sara"
employee2_salary = 85000
```

As the application grows, managing thousands of variables becomes difficult.

With OOP:

```python
employee = Employee(
    101,
    "Ali",
    75000
)
```

Data and behavior stay together, making applications easier to maintain and scale.

---

# Mental Model

Think of a class as a blueprint for a building.

```text
Blueprint (Class)
       |
       V
House 1 (Object)

House 2 (Object)

House 3 (Object)
```

Database Example:

```text
Class      → Employee
Object     → Ali
Object     → Sara
Object     → Ahmed
```

---

# Classes and Objects

## What is a Class?

A class is a blueprint that defines attributes and behaviors.

---

## Syntax

```python
class ClassName:
    pass
```

---

## What is an Object?

An object is an instance of a class.

---

## Example

```python
class Employee:

    pass

employee1 = Employee()
employee2 = Employee()
```

---

## Database-Oriented Example

```python
class Employee:

    employee_id = 101
    name = "Ali"
    department = "IT"

employee = Employee()

print(employee.name)
```

Output:

```text
Ali
```

---

# Constructors

## Definition

A constructor initializes object data when an object is created.

In Python, constructors use:

```python
__init__()
```

---

## Syntax

```python
class ClassName:

    def __init__(self):
        pass
```

---

## Example

```python
class Employee:

    def __init__(
        self,
        employee_id,
        name,
        salary
    ):
        self.employee_id = employee_id
        self.name = name
        self.salary = salary

employee = Employee(
    101,
    "Ali",
    75000
)

print(employee.name)
```

Output:

```text
Ali
```

---

## Internal Behavior

```text
Employee(...)
     |
     V
__init__()
     |
Assign Values
     |
Object Created
```

---

# Instance vs Class Variables

---

# Instance Variables

Unique to each object.

---

## Example

```python
class Employee:

    def __init__(
        self,
        employee_id,
        name
    ):
        self.employee_id = employee_id
        self.name = name
```

---

## Usage

```python
employee1 = Employee(
    101,
    "Ali"
)

employee2 = Employee(
    102,
    "Sara"
)
```

Each object has different values.

---

# Class Variables

Shared across all objects.

---

## Example

```python
class Employee:

    company_name = "Tech Corp"
```

---

## Usage

```python
print(
    Employee.company_name
)
```

Output:

```text
Tech Corp
```

---

# Comparison

|Feature|Instance Variable|Class Variable|
|---|---|---|
|Ownership|Object|Class|
|Memory|Separate Copy|Shared|
|Access|self.variable|Class.variable|
|Usage|Employee Data|Global Settings|

---

# Inheritance

## Definition

Inheritance allows one class to inherit properties and methods from another class.

---

# Mental Model

```text
Employee
    |
    |
Manager
```

Manager inherits Employee functionality.

---

## Example

```python
class Employee:

    def display_role(self):
        print("Employee")

class Manager(Employee):

    pass

manager = Manager()

manager.display_role()
```

Output:

```text
Employee
```

---

## Database Example

```python
class Employee:

    def __init__(
        self,
        employee_id,
        name
    ):
        self.employee_id = employee_id
        self.name = name

class Manager(Employee):

    def approve_leave(self):
        print("Leave Approved")
```

---

# Polymorphism

## Definition

Polymorphism means "many forms."

Different objects can use the same method name with different behavior.

---

## Example

```python
class Employee:

    def role(self):
        print("Employee")

class Manager:

    def role(self):
        print("Manager")

class Director:

    def role(self):
        print("Director")

users = [
    Employee(),
    Manager(),
    Director()
]

for user in users:
    user.role()
```

Output:

```text
Employee
Manager
Director
```

---

# Encapsulation

## Definition

Encapsulation hides internal data and controls access to it.

---

# Public Variable

```python
class Employee:

    def __init__(self):
        self.name = "Ali"
```

Accessible everywhere.

---

# Protected Variable

```python
class Employee:

    def __init__(self):
        self._salary = 75000
```

Convention: Internal use only.

---

# Private Variable

```python
class Employee:

    def __init__(self):
        self.__salary = 75000
```

Python performs name mangling.

---

## Example

```python
class Employee:

    def __init__(self):
        self.__salary = 75000

    def get_salary(self):
        return self.__salary

employee = Employee()

print(
    employee.get_salary()
)
```

Output:

```text
75000
```

---

# Abstraction

## Definition

Abstraction hides implementation details and exposes only essential functionality.

---

# Real-World Example

ATM User:

```text
Insert Card
Enter PIN
Withdraw Money
```

User doesn't see banking internals.

---

## Python Example

```python
from abc import ABC, abstractmethod

class Employee(ABC):

    @abstractmethod
    def calculate_salary(self):
        pass
```

---

## Concrete Class

```python
class FullTimeEmployee(Employee):

    def calculate_salary(self):
        return 80000
```

Usage:

```python
employee = FullTimeEmployee()

print(
    employee.calculate_salary()
)
```

Output:

```text
80000
```

---

# Method Overriding

## Definition

A child class provides its own implementation of a parent method.

---

## Example

```python
class Employee:

    def role(self):
        print("Employee")

class Manager(Employee):

    def role(self):
        print("Manager")

manager = Manager()

manager.role()
```

Output:

```text
Manager
```

---

## Using super()

```python
class Employee:

    def role(self):
        print("Employee")

class Manager(Employee):

    def role(self):

        super().role()

        print("Manager")

manager = Manager()

manager.role()
```

Output:

```text
Employee
Manager
```

---

# Method Resolution Order (MRO)

## Definition

MRO determines the order Python follows when searching for methods.

---

# Why MRO Exists

Multiple inheritance can create ambiguity.

Example:

```text
      Employee
      /      \
     /        \
 Manager    Developer
      \      /
       TeamLead
```

Python must decide which method to execute.

---

## Example

```python
class Employee:

    def role(self):
        print("Employee")

class Manager(Employee):

    pass

class Developer(Employee):

    pass

class TeamLead(
    Manager,
    Developer
):

    pass
```

---

## Check MRO

```python
print(
    TeamLead.__mro__
)
```

Output:

```text
(
 TeamLead,
 Manager,
 Developer,
 Employee,
 object
)
```

---

## Internal Search Order

```text
TeamLead
    |
Manager
    |
Developer
    |
Employee
    |
object
```

---

# Step-by-Step Example

## Employee Management System

### Step 1: Create Base Class

```python
class Employee:

    def __init__(
        self,
        employee_id,
        name
    ):
        self.employee_id = employee_id
        self.name = name
```

---

### Step 2: Create Child Class

```python
class Manager(Employee):

    def approve_leave(self):
        print("Leave Approved")
```

---

### Step 3: Create Object

```python
manager = Manager(
    101,
    "Ali"
)
```

---

### Step 4: Access Parent Data

```python
print(manager.name)
```

Output:

```text
Ali
```

---

### Step 5: Access Child Method

```python
manager.approve_leave()
```

Output:

```text
Leave Approved
```

---

# Real-World Use Case 1: Employee Management System

```python
class Employee:

    def __init__(
        self,
        employee_id,
        name
    ):
        self.employee_id = employee_id
        self.name = name
```

Used in:

- HR Systems
    
- Payroll Software
    
- Employee Portals
    

---

# Real-World Use Case 2: E-Commerce Product System

```python
class Product:

    def __init__(
        self,
        product_id,
        name,
        price
    ):
        self.product_id = product_id
        self.name = name
        self.price = price
```

Used in:

- E-Commerce Applications
    
- Inventory Systems
    
- ERP Platforms
    

---

# Common Mistakes

## Mistake 1: Forgetting self

### Wrong

```python
class Employee:

    def display():
        print("Employee")
```

Error:

```text
TypeError
```

---

### Fix

```python
class Employee:

    def display(self):
        print("Employee")
```

---

## Mistake 2: Not Calling Parent Constructor

### Wrong

```python
class Manager(Employee):

    def __init__(self):
        pass
```

Parent initialization is skipped.

---

### Fix

```python
class Manager(Employee):

    def __init__(
        self,
        employee_id,
        name
    ):
        super().__init__(
            employee_id,
            name
        )
```

---

## Mistake 3: Direct Access to Private Variables

### Wrong

```python
employee.__salary
```

Raises:

```text
AttributeError
```

---

### Fix

```python
employee.get_salary()
```

---

# Edge Cases and Pitfalls

---

## Mutable Class Variables

### Wrong

```python
class Employee:

    skills = []
```

All objects share the same list.

---

### Fix

```python
class Employee:

    def __init__(self):
        self.skills = []
```

---

## Instantiating Abstract Class

### Wrong

```python
employee = Employee()
```

Raises:

```text
TypeError
```

---

### Fix

Instantiate a concrete child class.

---

## Deep Inheritance Chains

```text
Employee
  |
Manager
  |
SeniorManager
  |
Director
  |
VicePresident
```

Too much inheritance makes code difficult to maintain.

Prefer composition when appropriate.

---

# Internal Behavior

## Object Creation

```text
Class Definition
      |
Object Creation
      |
Memory Allocation
      |
__init__()
      |
Object Ready
```

---

## Method Lookup

```text
Object
  |
Class
  |
Parent Class
  |
Grandparent
  |
object
```

Python follows MRO to locate methods.

---

# Comparison Table

|Concept|Purpose|Example|
|---|---|---|
|Class|Blueprint|Employee|
|Object|Instance|employee1|
|Constructor|Initialization|**init**()|
|Inheritance|Reuse Code|Manager(Employee)|
|Polymorphism|Multiple Behaviors|role()|
|Encapsulation|Protect Data|__salary|
|Abstraction|Hide Complexity|ABC|
|Overriding|Replace Method|role()|
|MRO|Method Search Order|**mro**|

---

# Key Points

- Classes are blueprints for objects.
    
- Objects contain data and behavior.
    
- Constructors initialize object state.
    
- Instance variables belong to objects.
    
- Class variables are shared.
    
- Inheritance promotes code reuse.
    
- Polymorphism allows common interfaces.
    
- Encapsulation protects internal data.
    
- Abstraction hides implementation details.
    
- Method overriding customizes parent behavior.
    
- MRO determines method lookup order.
    

---

# Common Interview Questions

## Q1: What is OOP?

A programming paradigm that organizes code using classes and objects.

---

## Q2: Difference Between Class and Object?

|Class|Object|
|---|---|
|Blueprint|Instance|
|Definition|Actual Entity|
|No Memory for Data|Stores Data|

---

## Q3: Difference Between Instance and Class Variables?

|Instance Variable|Class Variable|
|---|---|
|Unique Per Object|Shared|
|Uses self|Uses Class Name|

---

## Q4: What is Inheritance?

The ability of one class to acquire properties and methods from another class.

---

## Q5: What is Polymorphism?

One interface, multiple implementations.

Example:

```python
user.role()
```

Different classes implement `role()` differently.

---

## Q6: What is Encapsulation?

Restricting direct access to internal data and exposing controlled methods.

---

## Q7: What is Abstraction?

Hiding implementation details while exposing essential functionality.

---

## Q8: What is Method Overriding?

Providing a new implementation of a parent class method in a child class.

---

## Q9: What is MRO?

Method Resolution Order determines how Python searches for methods during inheritance.

---

## Q10: What is super()?

Used to access parent class methods and constructors.

Example:

```python
super().__init__(
    employee_id,
    name
)
```

---

# Interview Summary

### Four Pillars of OOP

```text
1. Encapsulation
2. Abstraction
3. Inheritance
4. Polymorphism
```

---

### Most Common Constructor?

```python
__init__()
```

---

### How Does Python Resolve Methods?

Using:

```python
MRO (Method Resolution Order)
```

---

### How Are Private Variables Created?

Using double underscore:

```python
self.__salary
```

---

### Which Module Supports Abstraction?

```python
abc
```

---

# Conclusion

Object-Oriented Programming is a foundational programming paradigm that enables developers to model real-world systems using classes and objects. Concepts such as inheritance, polymorphism, encapsulation, abstraction, method overriding, and MRO help create modular, reusable, and maintainable software. Mastering OOP is essential for building enterprise applications, backend systems, APIs, database-driven platforms, and large-scale Python projects.