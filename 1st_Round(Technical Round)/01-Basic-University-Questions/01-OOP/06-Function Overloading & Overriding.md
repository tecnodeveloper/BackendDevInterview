# Function Overloading, Overriding, and Operator Overloading

# Function Overloading

Multiple functions having the same name but different parameter lists.

---

## Example

```cpp
class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Calculator c;

    cout << c.add(2, 3) << endl;
    cout << c.add(2.5, 3.5) << endl;
    cout << c.add(1, 2, 3) << endl;
}
```

---

## Internal Behavior

Compiler chooses function based on:
- Number of arguments
- Data types of arguments
- Order of arguments

---
# Function Overriding

A derived class provides its own implementation of inherited parent class function.

---

## Example

```cpp

class Animal
{
public:
    void sound()
    {
        cout << "Animal Sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() //override
    {
        cout << "Bark" << endl;
    }
};

int main()
{
    Dog d;
    d.sound();
}
```

---

# Operator Overloading


It allow developers to redefine the functionality of operator for user defined datatype. like you can customize +,-,/,% for class instance. 

---
## Example

```cpp

class Complex
{
public:
    int real;
    int imag;

    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    Complex operator+(const Complex& c)
    {
        return Complex(
            real + c.real,
            imag + c.imag
        );
    }
};

int main()
{
    Complex c1(2, 3);
    Complex c2(4, 5);

    Complex c3 = c1 + c2;

    cout << c3.real << " "
         << c3.imag;
}
```

---
# Real-World Examples

## Function Overloading: Backend API Service

Different ways to fetch users.

```cpp
getUser(int id);
getUser(string email);
getUser(string email, bool active);
```

Same operation:

```text
Get User
```

Different inputs.

---

## Function Overriding: Payment Gateway System

Base class:

```cpp
PaymentGateway
```

Derived classes:

```cpp
Stripe
PayPal
Easypaise
```

Each overrides:

```cpp
processPayment()
```

with its own implementation.

---

# Comparison Table

| Feature               | Function Overloading            | Function Overriding       | Operator Overloading       |
| --------------------- | ------------------------------- | ------------------------- | -------------------------- |
| Purpose               | Same function, different inputs | Change inherited behavior | Redefine operator behavior |
| Inheritance Required  | No                              | Yes                       | No                         |
| Parameters            | Must differ                     | Must be same              | Depends on operator        |
| Return Type           | Can differ but not alone        | Usually same/covariant    | User-defined               |
| Binding               | Compile-Time                    | Runtime                   | Compile-Time               |
| Polymorphism Type     | Static                          | Dynamic                   | Static                     |
| Uses Virtual Function | No                              | Yes                       | No                         |
| Scope                 | Same class                      | Parent-child classes      | User-defined classes       |

---

# Key Points

- Function Overloading = Same name, different parameters.
- Function Overriding = Same signature, different implementation in derived class.
- Operator Overloading = Same operator, custom behavior for classes.
    
- Overloading and operator overloading are compile-time polymorphism. Overriding is runtime polymorphism.
- Overriding requires inheritance and virtual functions.
- Operator overloading improves readability for custom types.
- Not all operators can be overloaded (`::`, `.`, `?:`, `sizeof`).

---
# Final Mental Model

### Function Overloading

```text
Same Function Name + Different Inputs = Different Behaviors
```

### Function Overriding

```text
Same Function + Different Class = Different Behavior
```

### Operator Overloading

```text
Same Operator + Different Object Type = Custom Behavior
```

---

# Interview Summary

### What is Function Overloading?
Same function name with different parameter lists in the same scope.
### What is Function Overriding?
A derived class redefines a virtual function from the base class.
### What is Operator Overloading?
Redefining the behavior of existing operators for user-defined types.
