# Constructor, Destructor and `this` Pointer

- A **constructor** is a special member function that is automatically called when an object is created. It initializes the object.

- A **destructor** is used to cleans up resources. It is called when an object is destroyed.
---
## Mental Model

Think of an object like a **hotel room**:
- Constructor → preparing the room before guest arrives
- Destructor → cleaning the room after guest leaves

---

##  Syntax

```cpp

class Example {
public:
    int value;

    // Constructor
    Example(int value) {
        this->value = value;
        cout << "Constructor called and object values are intialized ";
    }

    // Destructor
    ~Example() {
        cout << "Destructor called";
    }
};
int main(){
    Example exampleObject(2);
}
```


---

## Key Points

- Same name as class    
- No return type
- Called automatically 
- Can be overloaded

---

## Interview Tip

Constructor = **object initialization**

---

# Destructor

A destructor is used to **release resources automatically** when an object is destroyed.

---

## Key Points

- Same name as class with `~`
- No parameters, no return type
- Called automatically
- Only one destructor per class

---

``` C++

## 8. Real-World Example (Database Connection)

```cpp

class DatabaseConnection {
public:
    string connection;

    DatabaseConnection(string connection) {
        this->connection = connection;
        cout << "Connected to DB ";
    }

    ~DatabaseConnection() {
        cout << "Disconnected from DB ";
    }
};

int main() {
    DatabaseConnection db("localhost");
}
```

---
## Interview Tip

Destructor = **automatic cleanup**

---

#  Constructor vs Destructor

| Feature     | Constructor       | Destructor      |
| ----------- | ----------------- | --------------- |
| Purpose     | Initialize object | Clean resources |
| Execution   | On creation       | On destruction  |
| Name        | ClassName         | ~ClassName      |
| Parameters  | Allowed           | Not allowed     |
| Overloading | Yes               | No              |

---

#  Final Mental Model

- Constructor → **Setup phase**
- Destructor → **Cleanup phase**
- Together → **Lifecycle control (RAII)**

---

#  Interview Summary

- Constructor initializes object automatically
- Destructor cleans resources automatically
- Always manage dynamic memory properly

---
# `this` keyword

The **`this` pointer** is a special pointer automatically available inside every non-static member function. 
It points to the object that invoked the member function. `this` = "pointer to the current object"

---

## Mental Model

Think of `this` as:

> "Who am I right now?"

Whenever an object calls a member function, C++ automatically passes the address of that object through the `this` pointer.

---

# Basic Syntax

```cpp

class Person
{
public:
    string name = "Ali";

    void greet()
    {
        cout << this->name << endl;
    }
};

int main()
{
    Person person;
    person.greet();
}
```
---

# How `this` Works Internally

When C++ executes:

```cpp
person.greet();
```

The compiler internally treats it similarly to:

```cpp
Person::greet(&person);
```

Meaning:

```cpp
this = &person;
```

Inside the function:

```cpp
this->name
```

becomes:

```cpp
person.name
```

---

# Resolving Naming Conflicts


```cpp
class User
{
public:
    string name;
//Constructor with same input as private variable so this is used
    User(string name)
    {
        name = name;
        //this->name = name;
    }
};
```

---

# Common Mistakes with `this`

```cpp
class User
{
public:
    static void greet()
    {
        cout << this->name;
    }
};
```

### Why?

Static functions belong to the class, not an object.

No `this` pointer exists.

