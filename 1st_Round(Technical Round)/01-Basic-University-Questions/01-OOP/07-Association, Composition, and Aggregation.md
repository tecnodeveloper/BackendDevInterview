
## Association, Composition, and Aggregation(ACA)

---
## Association

Association is a relationship where two or more objects have their own independent lifecycle, and there is no ownership between them. 

Association = "Uses-a" or "Interacts-with" relationship.

---

## Why Association Exists

Some objects need to interact or communicate with each other to perform an action, but they do not own or contain one another.

Examples:

- Doctor interacts with Patient
- Driver interacts with Car
- Customer interacts with Bank Teller

Destroying one object has absolutely zero impact on the lifecycle or existence of the other.

---

## Mental Model

```text
  Doctor  ────────── Interacts With ──────────  Patient
(Lives independently)                        (Lives independently)
```

If the Doctor leaves the hospital:

```text
The Patient still exists independently.
```

---

## Association Example

## Doctor and Patient

```cpp
class Patient; // Forward declaration

class Doctor
{
public:
    string name;
    vector<Patient*> patients;

    Doctor(string n) : name(n) {}

    void prescribeMedicine()
    {
        cout << "Doctor " << name << " prescribed medicine.\n";
    }
};

class Patient
{
public:
    string name;
    vector<Doctor*> doctors;

    Patient(string n) : name(n) {}
    
    void visitDoctor(Doctor* doc)
    {
        cout << "Patient " << name << " visited Doctor " << doc->name << ".\n";
    }
};
```

---

## Internal Behavior

```text
Doctor Watson ◄──────────► Patient John
              (Loose Link)
```

Doctors and Patients simply hold temporary pointers or references to each other.

They are peer objects with equal structural hierarchy.

---

## Real-World Usage Backend Systems

## Association

```cpp
User → ChatRoom
Passenger → Flight Ticket
Teacher → Course
```

---

## Composition

Composition is an OOP relationship where one object is made up of one or more other objects.

The contained objects typically cannot exist independently within the context of the relationship. Composition = Strong "has-a" relationship

---

## Mental Model

Think of:

- Car has Engine
- House has Rooms
- Computer has CPU

The parent object owns its components.

---

## Example Engine and Car

```cpp
class Engine
{
public:
    void start()
    {
        cout << "Engine Started" << endl;
    }
};

class Car
{
private:
    Engine engine;

public:
    void startCar()
    {
        engine.start();
    }
};
int main(){
	Car car;
	car.startCar();
}
```

---

## Composition Lifecycle

A key characteristic of Composition:

> Child object's lifetime depends on the parent object's lifetime.

---

## Example

```cpp
class Engine
{
public:
    Engine()
    {
        cout << "Engine Created\n";
    }

    ~Engine()
    {
        cout << "Engine Destroyed\n";
    }
};

class Car
{
private:
    Engine engine;

public:
    Car()
    {
        cout << "Car Created\n";
    }

    ~Car()
    {
        cout << "Car Destroyed\n";
    }
};
```

Output:

```text
Engine Created
Car Created
Car Destroyed
Engine Destroyed
```

Engine is automatically created and destroyed with Car.

---

## Real-World Composition Examples

## E-Commerce Order

```cpp
class OrderItem
{
};

class Order
{
private:
    vector<OrderItem> items;
};
```

If Order is deleted, OrderItems are deleted too.

---

## Aggregation

Aggregation is relationship where child object can exist independently. Aggregation = Weak "has-a" relationship

---

## Why Aggregation Exists

Some objects need collaboration without ownership.

Examples:

- University has Students
- Company has Employees
- Team has Players

Destroying the parent does not destroy the child.

---

## Mental Model

```text
University
    ├── Student A
    ├── Student B
    └── Student C
```

If the University closes:

```text
Students still exist.
```

---

## Aggregation Example

## University and Student

```cpp
#include <vector>

class Student
{
public:
    string name;

    Student(string n)
    {
        name = n;
    }
};

class University
{
private:
    vector<Student*> students;

public:
    void addStudent(Student* student)
    {
        students.push_back(student);
    }
};
```

---

## Internal Behavior

```text
Student Ali
Student Ahmed

       ▲
       │
University
```

University references Students.

Students live independently.

---

## Comparison Table

|Feature|Association|Composition|Aggregation|
|---|---|---|---|
|Ownership|None|Strong|Weak|
|Lifetime Dependency|No|Yes|No|
|Child Exists Independently|Yes|No|Yes|
|Relationship|Uses / Interacts With|Part Of|Uses|
|Coupling|Very Loose|Strong|Loose|
|Memory Management|Independent Control|Owner Controls|External Control|

---

## Relationship Code Comparison

## Association

```cpp
class Patient;

class Doctor
{
private:
    vector<Patient*> patients; // Holds references to independent peer objects
};
```

Doctor interacts with Patient.

---

## Composition

```cpp
class Engine
{
};

class Car
{
private:
    Engine engine; // Direct instantiation means unified lifecycle
};
```

Engine belongs to Car.

---

## Aggregation

```cpp
class Engine
{
};

class Car
{
private:
    Engine* engine; // Holds pointer to an engine managed externally

public:
    Car(Engine* e)
    {
        engine = e;
    }
};
```

Engine exists independently.

---

## Real-World Usage Backend Systems

## Association

```cpp
User → ChatRoom
Passenger → Flight Ticket
Teacher → Course
```

---

## Composition

```cpp
Order → OrderItem
Invoice → InvoiceLine
```

---

## Aggregation

```cpp
Company → Employee
School → Student
```

---

## Key Points

- `this` points to the current object.
- `this` is automatically available in non-static member functions.
- Association represents structural equality without ownership.
- Composition represents strong ownership.
- Aggregation represents weak ownership.
- Association and Aggregation objects can exist independently.
- Composition objects cannot exist independently.
- Association and Aggregation usually store pointers or references.
- Composition usually stores objects directly.
- Use Association when peer objects simply need to interact.
- Use Composition when ownership exists.
- Use Aggregation when objects only collaborate.

---

# Interview Summary

## What is Association?

A relationship with zero ownership where independent objects interact.

Example:

```cpp
class Doctor 
{ 
    vector<Patient*> patients; 
};
```

---

## What is Composition?

A strong "has-a" relationship where one object owns another.

Example:

```cpp
class Car
{
    Engine engine;
};
```

---

## What is Aggregation?

A weak "has-a" relationship where one object uses another without ownership.

Example:

```cpp
class Car
{
    Engine* engine;
};
```

---

## Main Difference Between Association, Composition, and Aggregation

Association:

```text
Objects are completely independent peers.
```

Composition:

```text
Child cannot exist without Parent.
```

Aggregation:

```text
Child can exist without Parent.
```

---

## Final Mental Model

```text

Association = Interacts With Object = No Ownership

Composition = Owns Object = Strong HAS-A

Aggregation = Uses Object = Weak HAS-A
```

```text
Doctor ◄──────────► Patient
            (Association)

Car
 └── Engine
      (Composition)

University
 └── Student
      (Aggregation)
```
