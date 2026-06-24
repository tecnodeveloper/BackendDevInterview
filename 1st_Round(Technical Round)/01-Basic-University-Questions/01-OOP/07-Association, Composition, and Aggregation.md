# Association, Composition and Aggregation  ([ACA](https://blog.devgenius.io/association-composition-and-aggregation-in-c-925465987061))

---

## Association

Relationship between two objects where they can  communicate  or interact with each other.

The objects are completely independent and neither object owns the other. 

---

## Mental Model

Think of:

- Doctor treats Patients    
- Teacher teaches Students
- Association = "uses-a" or "works-with" relationship

The objects collaborate but maintain independent lifecycles.

---

## Example Doctor and Patient

```cpp
class Patient
{
public:
    void takeMedicine()
    {
        cout << "Patient Taking Medicine" << endl;
    }
};

class Doctor
{
public:
    void treat(Patient& patient)
    {
        patient.takeMedicine();
    }
};

int main()
{
    Patient patient;
    Doctor doctor;

    doctor.treat(patient);
}
```
---

## Internal Behavior

```text
Doctor  ─────────► Patient
```

Doctor communicates with Patient. Neither owns the other. Both live independently.

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

class Student
{
public:
    string name;

    Student(string name)
    {
        this->name = name;
    }
};

class University
{
private:
public:
    void addStudent(Student* student)
    {
        students.push_back(student);
    }
};
```


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

Engine belongs to Car. like if order(parent) is dead then orderItem is also dead(child)

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