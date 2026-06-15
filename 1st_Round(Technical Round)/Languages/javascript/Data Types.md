  
# JavaScript Data Types

JavaScript is a **dynamically typed language**, meaning the type of a variable is determined at runtime.

### Example

```javascript
let x = 10
x = "Hello"
```

Here the variable `x` changes from **number → string**.

---

# Types of JavaScript Data

JavaScript has **two main categories of data types**:

1. Primitive Data Types
2. Non-Primitive (Reference) Data Types

---

# 1. Primitive Data Types

Primitive values are **immutable** and stored directly in memory.

JavaScript has **7 primitive data types**.

| Type | Example |
|-----|-----|
| String | `"Hello"` |
| Number | `10`, `3.14` |
| Boolean | `true`, `false` |
| Undefined | variable declared but not assigned |
| Null | intentional empty value |
| Symbol | unique identifier |
| BigInt | very large integers |

---

## String

Represents textual data.

```javascript
let name = "John"
let city = "Chennai"
```

---

## Number

Represents both integers and floating point numbers.

```javascript
let age = 25
let price = 99.99
```

JavaScript has **only one number type**.

---

## Boolean

Represents logical values.

```javascript
let isLoggedIn = true
let isAdmin = false
```

Used mainly in **conditions and comparisons**.

---

## Undefined

A variable that is declared but **not assigned a value**. so JavaScript set the default value as 
undefined .

```javascript
let x

console.log(x) // undefined
```

---

## Null

Represents an **intentional empty value**.

```javascript
let user = null
```

**Difference**

```
undefined → value not assigned  
null → value intentionally empty
```

---

## Symbol

A **unique identifier** introduced in ES6.

```javascript
let id = Symbol("userID")
```

Even if two symbols have the same description, they are unique.

```javascript
Symbol("id") === Symbol("id") // false
```

Symbols are often used for **object property keys**.

---

## BigInt

Used for very large integers beyond the safe limit of JavaScript numbers.

```javascript
let bigNumber = 123456789012345678901234567890n
```

---

# 2. Non-Primitive (Reference) Data Types

Non-primitive values are stored as **references in memory**.

Main types:

- Object
- Array
- Function

---

## Objects

Objects store data in **key-value pairs**.

```javascript
let user = {
  name: "John",
  age: 25
}
```

Objects are the **foundation of JavaScript**.

Many structures are built from objects.

---

## Arrays

Arrays store **multiple values in a single variable**.

```javascript
let numbers = [1,2,3,4]
```

Arrays are actually a **special type of object**.

---

## Functions

Functions are **first-class objects in JavaScript**.

```javascript
function greet(){
  console.log("Hello")
}
```

Functions can be:

- stored in variables
- passed as arguments
- returned from other functions

---

# Checking Data Types

JavaScript provides the `typeof` operator.

```javascript
typeof "Hello"   // string
typeof 10        // number
typeof true      // boolean
typeof undefined // undefined
typeof {}        // object
typeof []        // object
```

Important note:

```javascript
typeof null // object
```

This is a **known JavaScript bug**.

---

# Primitive vs Reference Types

## Primitive Example

```javascript
let a = 10
let b = a

b = 20

console.log(a) // 10
```

Primitive values are **copied by value**.

---

## Reference Example

```javascript
let obj1 = {name:"John"}
let obj2 = obj1

obj2.name = "Mike"

console.log(obj1.name) // Mike
```

Objects are **copied by reference**.

---

# Memory Model

JavaScript memory is divided into:

```
Stack → Primitive values  
Heap → Objects and reference types
```

Example:

```
Stack
a = 10

Heap
object → {name:"John"}
```

---

# Interview Summary

Important points for interviews:

- JavaScript has **7 primitive data types**
- Primitive values are **immutable**
- Objects, arrays, and functions are **reference types**
- Primitive values are stored in **stack memory**
- Reference types are stored in **heap memory**
- `typeof null` returns **object** due to a historical bug
- Arrays are technically **objects**

---


  