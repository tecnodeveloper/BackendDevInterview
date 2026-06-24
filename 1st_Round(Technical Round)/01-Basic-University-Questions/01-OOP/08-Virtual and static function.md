## Virtual Function & Static Function

---

## Virtual Function

A virtual function is a member function in a base class that allows runtime polymorphism, meaning the function call is resolved based on the actual object type at runtime.

---
## Mental Models

Think of it as a “smart function selector”:

- Same call
- Different behavior depending on the actual object

---
## Basic Example

```javascript
class Animal {
public:
  virtual void sound() {
    console.log("Animal sound");
  }
};

class Dog extends Animal {
  void sound() override {
    console.log("Bark");
  }
};
```

---

## Step-by-Step Execution

1. Base class defines a virtual function
2. Derived class overrides it
3. Base pointer holds a derived object
4. Runtime checks the actual object type
5. Correct function is executed

---

## Usage Example

```javascript
Animal* a = new Dog();
a.sound(); // Bark
```

---
## Key Points

- Enables runtime polymorphism
- Requires inheritance
- Works with pointers/references
- Uses a vtable internally
---

## INTERNAL BEHAVIOR

- Compiler creates a vtable for the class
- Each object instance contains a vptr
- Calls are resolved at runtime through pointer lookups
- Slight performance overhead due to indirection

---
# Static Function

A static function is a class-level member function that:

- Belongs to the class itself rather than any specific object instance
- Can be called without creating an instance of the class
- Cannot access non-static data members or the `this` pointer

---

## Mental Models

Think of it as a “tool inside a shared toolbox”:

- No object ownership required
- No independent state per object
- Just a reusable tool nested inside a class namespace


---

## Step-by-Step Behavior

1. No object is created
2. Class acts as a namespace scope
3. Static function is called directly via the class name
4. No `this` pointer is passed or involved

---

## Real-World Example (Math Utility)

```javascript
class MathUtils {
public:
  static int multiply(int a, int b) {
    return a * b;
  }
};
```

## Usage:

```javascript
MathUtils::multiply(2, 3);
```

---

## Common Mistakes

- Trying to access non-static instance members inside a static function
- Creating unnecessary objects just to call a static function
- Misusing static functions for stateful logic that belongs to instances

---

## Key Points

- No object instance required to invoke it
- Shared across all instances and code locations
- Cannot access instance variables or the `this` pointer
- Ideal for stateless utility functions

---

## COMPARISON TABLE

|Feature|Virtual Function|Static Function|
|---|---|---|
|Purpose|Runtime polymorphism|Utility & helper operations|
|Object required|Yes|No|
|Binding|Runtime|Compile-time|
|Uses inheritance|Yes|No (not for overriding)|
|Memory model|Vtable-based indirection|Single shared function in memory|
|State support|Yes (accesses object state)|No (can only access static state)|

---

## INTERNAL BEHAVIOR

- Stored in program code memory exactly once
- No object context or instance pointer passed
- Direct function call compiled exactly like a regular global function

---

## REAL World Example Payment Processing System (Hybrid)

- Virtual function → handles different payment execution routines (Credit Card vs PayPal)
- Static function → handles shared mathematical utility helpers like tax calculation or currency formatting

---

## SUMMARY

## Virtual Function

> “Same function signature, different behavior depending on the dynamic object type at runtime”

## Static Function

> “A shared tool inside a class namespace that executes without needing an object instance”

---

## KEY POINTS

- Virtual functions enable runtime polymorphism; static functions provide class-level helper logic.
- Virtual functions require object instances; static functions completely remove the need for object creation.
- Virtual functions leverage inheritance; static functions operate independently of base/derived hierarchies.
- Virtual functions rely on an internal vtable; static functions are resolved as direct, fast compile-time calls.
- Both solve entirely different object-oriented architecture problems.

---

## INTERVIEW SUMMARY

- Virtual function = runtime polymorphism accomplished via vtable lookups.
- Static function = standalone class-level function requiring no object state.
- Virtual requires inheritance structures coupled with base pointers/references.
- Static methods are forbidden from accessing non-static instance members or using `this`.
- Use virtual for dynamic polymorphic behavior; use static for stateless utility helpers.

---

## FINAL MENTAL MODEL

- Virtual Function → “Dynamic decision at runtime”
- Static Function → “Shared class tool with no object needed”
