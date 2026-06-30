  
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


  # JavaScript Numbers

JavaScript uses a **single number type** to represent both integers and floating-point values.

Example:

```javascript
let a = 10        // integer
let b = 3.14      // floating point
```

---

# Number Basics

JavaScript numbers are based on **IEEE 754 (double precision)**.

This allows:

- Large range of values
- Decimal precision (with some limitations)

---

# Creating Numbers

```javascript
let num1 = 100
let num2 = 10.5
let num3 = Number("50") // explicit conversion
```

See:  
[[08-Type Conversions]]

---

# Special Numeric Values

## NaN (Not a Number)

Represents an invalid number. refer [[11-NaN]]

```javascript
Number("hello") // NaN
```

Check using:

```javascript
Number.isNaN(NaN) // true
```

---

## Infinity

Represents values larger than the maximum limit.

```javascript
1 / 0 // Infinity
-1 / 0 // -Infinity
```

---

# Number Methods

## toFixed()

Formats number to fixed decimal places.

```javascript
let num = 10.567

num.toFixed(2)
```

Output

```
"10.57"
```

---

## toString()

Converts number to string.

```javascript
let num = 100

num.toString()
```

Output

```
"100"
```

---

## parseInt()

Extracts integer from string.

```javascript
parseInt("25px") // 25
```

---

## parseFloat()

Extracts decimal number.

```javascript
parseFloat("10.75px") // 10.75
```

---

# Math Object

JavaScript provides a built-in **Math object** for calculations.
refer [[13-Math Object]]

---

## Math.round()

Rounds to nearest integer.

```javascript
Math.round(4.6) // 5
```

---

## Math.floor()

Rounds down.

```javascript
Math.floor(4.9) // 4
```

---

## Math.ceil()

Rounds up.

```javascript
Math.ceil(4.1) // 5
```

---

## Math.random()

Generates random number between 0 and 1.

```javascript
Math.random()
```

Random integer example:

```javascript
Math.floor(Math.random() * 100)
```

---

# Floating Point Precision Issue

JavaScript cannot precisely represent some decimal values.

Example:

```javascript
0.1 + 0.2
```

Output

```
0.30000000000000004
```

Reason:

- Binary representation of decimals is not exact

---

# Fixing Precision Issues

```javascript
(0.1 + 0.2).toFixed(2)
```

Output

```
"0.30"
```

Or:

```javascript
Number((0.1 + 0.2).toFixed(2))
```

---

# Number Conversion (Important)

JavaScript often converts values into numbers.

Example:

```javascript
"5" - 2
```

Output

```
3
```

See:  
[[08-Type Conversions]]

---

# Checking Numbers

```javascript
typeof 10 // "number"
```

Check if value is finite:

```javascript
Number.isFinite(10) // true
```

---

# Interview Summary

Important points:

- JavaScript has **only one number type**
- Uses **IEEE 754 floating point**
- `NaN` represents invalid numbers
- `Infinity` represents overflow
- `parseInt()` and `parseFloat()` extract numbers
- Floating point precision is not exact
- Math object provides utility functions

---

# JavaScript Strings

A **string** in JavaScript represents **textual data**.

Strings can contain letters, numbers, symbols, and spaces.

JavaScript strings are **immutable**, meaning their values cannot be changed after creation.

Example:

```javascript
let name = "John"
let city = "Chennai"
```

---

# Creating Strings

Strings can be created using:

- Double quotes `""`
- Single quotes `''`
- Backticks `` ` ` `` (Template Literals)

Example:

```javascript
let str1 = "Hello"
let str2 = 'World'
let str3 = `JavaScript`
```

---

# String Length

The `length` property returns the number of characters in a string.

```javascript
let text = "JavaScript"

console.log(text.length)
```

Output

```
10
```

---

# Accessing Characters

Characters in a string can be accessed using **index positions**.

Index starts from **0**.

```javascript
let text = "JavaScript"

console.log(text[0])
console.log(text[4])
```

Output

```
J
S
```

Alternative method:

```javascript
text.charAt(0)
```

---

# String Immutability

Strings in JavaScript are **immutable**.

This means characters cannot be changed directly.

```javascript
let text = "Hello"

text[0] = "Y"

console.log(text)
```

Output

```
Hello
```

To modify a string, JavaScript actually **creates a new string**.

```javascript
let text = "Hello"

text = text.replace("H","Y")

console.log(text)
```

Output

```
Yello
```

---

# Template Literals

Template literals allow:

- **String interpolation**
- **Multi-line strings**

They use **backticks**.

```javascript
let name = "John"
let age = 25

let message = `My name is ${name} and I am ${age} years old`
```

Output

```
My name is John and I am 25 years old
```

---

# String Concatenation

Strings can be combined using the `+` operator.

```javascript
let first = "Hello"
let second = "World"

let result = first + " " + second
```

Output

```
Hello World
```

⚠️ If numbers are involved, JavaScript may perform **type coercion**.

Example:

```javascript
"5" + 2
```

Output

```
"52"
```

This happens because JavaScript converts the number into a string.

See:  
[[08-Type Conversions]]

---

# Common String Methods

JavaScript provides many built-in string methods.

---

## toUpperCase()

Converts string to uppercase.

```javascript
let text = "hello"

text.toUpperCase()
```

Output

```
HELLO
```

---

## toLowerCase()

Converts string to lowercase.

```javascript
let text = "HELLO"

text.toLowerCase()
```

Output

```
hello
```

---

## trim()

Removes whitespace from both ends.

```javascript
let text = "  hello  "

text.trim()
```

Output

```
"hello"
```

---

## slice()

Extracts part of a string.

```javascript
let text = "JavaScript"

text.slice(0,4)
```

Output

```
Java
```

Supports **negative indexes**.

```javascript
text.slice(-6)
```

Output

```
Script
```

---

## substring()

Similar to `slice()` but **does not support negative indexes**.

```javascript
let text = "JavaScript"

text.substring(0,4)
```

Output

```
Java
```

---

## replace()

Replaces part of a string.

```javascript
let text = "Hello World"

text.replace("World","JavaScript")
```

Output

```
Hello JavaScript
```

---

## split()

Splits a string into an array.

```javascript
let text = "apple,banana,orange"

text.split(",")
```

Output

```
["apple","banana","orange"]
```

---

## includes()

Checks if a string contains a value.

```javascript
let text = "JavaScript"

text.includes("Script")
```

Output

```
true
```

---

## startsWith()

Checks if a string starts with a value.

```javascript
let text = "JavaScript"

text.startsWith("Java")
```

Output

```
true
```

---

## endsWith()

Checks if a string ends with a value.

```javascript
let text = "JavaScript"

text.endsWith("Script")
```

Output

```
true
```

---

# slice() vs substring()

| Feature | slice() | substring() |
|-------|-------|-------|
| Negative indexes | Allowed | Not allowed |
| Start > End | Returns empty string | Swaps values |

Example:

```javascript
"JavaScript".slice(-6)
```

Output

```
Script
```

---

# Interview Summary

Important points:

- Strings represent **textual data**
- Strings are **immutable**
- Index starts from **0**
- `length` returns the number of characters
- Template literals support **string interpolation**
- `slice()` supports negative indexes
- `substring()` does not support negative indexes
- String + Number behavior is related to **type coercion**

---

# JavaScript Operators

Operators are used to perform operations on variables and values.

---

# 1. Arithmetic Operators

Used for mathematical calculations.

| Operator | Description | Example |
|--------|------------|--------|
| + | Addition | 5 + 2 → 7 |
| - | Subtraction | 5 - 2 → 3 |
| * | Multiplication | 5 * 2 → 10 |
| / | Division | 5 / 2 → 2.5 |
| % | Modulus (remainder) | 5 % 2 → 1 |
| ** | Exponentiation | 2 ** 3 → 8 |

---

# 2. Assignment Operators

Used to assign values.

```javascript
let x = 10
```

Common types:

```javascript
x += 5   // x = x + 5
x -= 5
x *= 2
x /= 2
x %= 2
```

---

# 3. Comparison Operators

Used to compare values. Returns boolean.

```javascript
5 > 3   // true
5 < 3   // false
```

| Operator | Meaning |
|--------|--------|
| == | Loose equality |
| === | Strict equality |
| != | Not equal |
| !== | Strict not equal |
| > | Greater than |
| < | Less than |
| >= | Greater than or equal |
| <= | Less than or equal |

---

# 4. Logical Operators

Used for combining conditions.

| Operator | Description |
| -------- | ----------- |
| &&       | AND         |
| \|\|     | OR          |
| !        | NOT         |

---

## Examples

```javascript
true && false   // false
true || false   // true
!true           // false
```

---

## Short-Circuit Behavior

### AND (`&&`)

Returns first falsy value or last value.

```javascript
0 && "Hello"   // 0
"Hi" && "JS"   // "JS"
```

---

### OR (`||`)

Returns first truthy value.

```javascript
"" || "Default"   // "Default"
"Hello" || "JS"   // "Hello"
```

---

# 5. Ternary Operator

Short form of if-else.

```javascript
condition ? value1 : value2
```

Example

```javascript
let age = 18

let result = age >= 18 ? "Adult" : "Minor"
```

---

# 6. Type Operators

### typeof

Returns the type of a variable.

```javascript
typeof "hello"  // string
typeof 10       // number
typeof true     // boolean
typeof {}       // object
```

---

# 7. Special Operators

### Nullish Coalescing (`??`)

Returns right side only if left is `null` or `undefined`.

```javascript
null ?? "Default"       // "Default"
undefined ?? "Default"  // "Default"
0 ?? 10                // 0
```

---

### Optional Chaining (`?.`)

Prevents errors when accessing nested properties.

```javascript
user?.name
```

If `user` is null/undefined → returns undefined instead of error.

---

# 8. Operator Precedence (Basic Idea)

Operators follow priority rules.

Example

```javascript
2 + 3 * 4   // 14
```

Because `*` has higher precedence than `+`.

---

# 9. Interview Summary

- Operators perform operations on values
- `===` is preferred over `==`
- `&&` returns first falsy value
- `||` returns first truthy value
- `??` works only with null and undefined
- `typeof null` → "object" (known bug)
- Operator precedence affects evaluation order

---


# JavaScript Type Conversions

JavaScript automatically converts data types when performing operations.  
This process is called **Type Conversion** or **Type Coercion**.

Type conversion happens in two ways:

1. **Implicit Conversion (Type Coercion)** → done automatically by JavaScript  
2. **Explicit Conversion (Type Casting)** → done manually by the developer  

---

# 1. Implicit Type Conversion (Type Coercion)

JavaScript automatically converts values when different types interact.

Example:

```javascript
"5" + 2
```

Output

```
"52"
```

Reason

```
2 → "2"
```

String concatenation happens.

---

Another example

```javascript
"5" - 2
```

Output

```
3
```

Reason

```
"5" → 5
```

Subtraction forces **number conversion**.

---

### Important Rule

If **+ operator sees a string → everything becomes a string**

Example

```javascript
1 + "2" + 3
```

Output

```
"123"
```

---

# 2. Explicit Type Conversion (Type Casting)

Explicit conversion is performed manually using built-in functions.

Common methods:

```
String()
Number()
Boolean()
parseInt()
parseFloat()
```

Example

```javascript
Number("100")  // 100
String(50)     // "50"
Boolean(1)     // true
```

---

# 3. String Conversion

Convert values into strings.

Methods:

- `String()`
- `.toString()`
- String concatenation

Example

```javascript
let value = 100

String(value)      // "100"
value.toString()   // "100"
```

Using concatenation

```javascript
let num = 50

num + ""   // "50"
```

---

# 4. Number Conversion

Convert values into numbers.

Methods

- `Number()`
- `parseInt()`
- `parseFloat()`

Example

```javascript
Number("100")  // 100
Number("10.5") // 10.5
```

Using `parseInt`

```javascript
parseInt("25px") // 25
```

Using `parseFloat`

```javascript
parseFloat("10.75px") // 10.75
```

Invalid conversion

```javascript
Number("hello") // NaN
```

`NaN` means **Not a Number**.

---

### Special Number Conversions

```javascript
Number(true)  // 1
Number(false) // 0
Number(null)  // 0
Number(undefined) // NaN
```

These are common **interview traps**.

---

# 5. Boolean Conversion

Convert values into boolean.

Method

```
Boolean(value)
```

Example

```javascript
Boolean(1)       // true
Boolean(0)       // false
Boolean("hello") // true
Boolean("")      // false
```

---

# 6. Truthy and Falsy Values

When values are used in conditions, JavaScript converts them to **boolean**.

JavaScript internally uses:

```javascript
Boolean(value)
```

Only **6 values are falsy**:

```
false, 0, "", null, undefined, NaN
```

Everything else is **truthy**.

Example

```javascript
if("hello"){
  console.log("Runs")
}
```

Output

```
Runs
```

For detailed explanation and edge cases → [[09-Truthy and Falsy]]

---

# 7. Loose Equality vs Strict Equality

JavaScript has two comparison operators. 

refer [[12-Equality Comparison]]

---

## Loose Equality (`==`)

Performs **type coercion** before comparison.

Example

```javascript
5 == "5"
```

Output

```
true
```

Because `"5"` becomes `5`.

---

## Strict Equality (`===`)

Does **not perform type conversion**.

Example

```javascript
5 === "5"
```

Output

```
false
```

Because types differ.

---

# 8. Common Type Coercion Examples

Example

```javascript
"5" + 2
```

Output

```
"52"
```

---

Example

```javascript
"5" - 2
```

Output

```
3
```

---

Example

```javascript
true + 1
```

Output

```
2
```

Reason

```
true → 1
false → 0
```

---

Example

```javascript
null + 1
```

Output

```
1
```

---

Example

```javascript
undefined + 1
```

Output

```
NaN
```

---

# 9. Weird JavaScript Coercion (Interview Traps)

These confuse developers constantly.

Example

```javascript
[] + []
```

Output

```
""
```

Because arrays convert to empty strings.

---

Example

```javascript
[] + {}
```

Output

```
"[object Object]"
```

---

Example

```javascript
{} + []
```

Output may differ depending on context.

---

Example

```javascript
null == undefined
```

Output

```
true
```

But

```javascript
null === undefined
```

Output

```
false
```

---

# 10. Mental Model (Important)

When JavaScript converts values, it usually follows this order:

```
Object → Primitive
Primitive → String / Number / Boolean
```

And operators influence the conversion.

Example

```
+  → prefers strings
-  → prefers numbers
```

---

# 11. Interview Summary

Important things interviewers expect you to know:

- JavaScript performs **automatic type conversion**
- `==` performs **type coercion**
- `===` compares both **value and type**
- JavaScript has **6 falsy values**
- `NaN` represents an invalid number
- `Number(null)` → `0`
- `Number(undefined)` → `NaN`
- `+` prefers **string conversion**
- Arrays convert to strings in many operations

---
# JavaScript Truthy and Falsy

In JavaScript, every value is either **truthy** or **falsy** when used in a boolean context.

This happens automatically in conditions like:

```javascript
if(value){
  // runs if truthy
}
```

JavaScript internally converts values using:

```javascript
Boolean(value)
```

---

# 1. Falsy Values

There are only **6 falsy values** in JavaScript.

```
false
0
""
null
undefined
NaN
```

These always evaluate to **false**.

---

## Example

```javascript
if(0){
  console.log("Will not run")
}
```

Because `0` is falsy.

---

# 2. Truthy Values

Everything that is **not falsy** is truthy.

Examples:

```
"hello"
1
[]
{}
true
"0"
"false"
```

---

## Example

```javascript
if("hello"){
  console.log("Runs")
}
```

Output

```
Runs
```

---

# 3. Important Rules

### Rule 1

Only **6 falsy values exist**. Everything else is truthy.

---

### Rule 2

Empty structures are still truthy.

```javascript
Boolean([])  // true
Boolean({})  // true
```

---

### Rule 3

Strings matter

```javascript
Boolean("")     // false
Boolean(" ")    // true (space is a character)
Boolean("0")    // true
```

---

# 4. Common Mistakes

### Mistake 1

```javascript
if([]){
  console.log("Runs")
}
```

Many expect false, but it runs because arrays are truthy.

---

### Mistake 2

```javascript
if({}){
  console.log("Runs")
}
```

Objects are also truthy.

---

### Mistake 3

```javascript
if("false"){
  console.log("Runs")
}
```

Strings are truthy unless empty.

---

# 5. Boolean Conversion Examples

```javascript
Boolean(false)      // false
Boolean(0)          // false
Boolean("")         // false
Boolean(null)       // false
Boolean(undefined)  // false
Boolean(NaN)        // false
```

Everything else → true

---

# 6. Real Use Cases

### Default Values

```javascript
let name = input || "Guest"
```

If `input` is falsy, `"Guest"` is used.

---

### Conditional Checks

```javascript
if(user){
  // user exists
}
```

---

### Filtering Values

```javascript
[0, 1, "", "hello", null].filter(Boolean)
```

Output

```
[1, "hello"]
```

---

# 7. Interview Summary

- JavaScript has **only 6 falsy values**
- Everything else is **truthy**
- Empty arrays `[]` and objects `{}` are **truthy**
- `"0"` and `"false"` are **truthy**
- Boolean conversion happens automatically in conditions
- `Boolean(value)` is used internally

---

# JavaScript - null vs undefined

`null` and `undefined` both represent **absence of a value**, but they mean **different things** in JavaScript.

- **undefined** → value **not assigned yet**
- **null** → value **intentionally empty**

---

# undefined

`undefined` is the **default value assigned by JavaScript** when something has no value.

## When does `undefined` occur?

### 1. Variable declared but not assigned

```javascript
let a
console.log(a)
```

Output

```
undefined
```

---

### 2. Function without return

```javascript
function test() {}

console.log(test())
```

Output

```
undefined
```

---

### 3. Missing object property

```javascript
const user = { name: "John" }

console.log(user.age)
```

Output

```
undefined
```

---

### 4. Missing function parameter

```javascript
function greet(name) {
  console.log(name)
}

greet()
```

Output

```
undefined
```

---

# null

`null` is **assigned intentionally** to represent **empty or no value**.

## Example

```javascript
let user = null
```

Meaning:

> The variable exists but currently has no value.

---

## Example use cases

- Reset a variable
- Empty object reference
- Placeholder value

```javascript
let selectedUser = null
```

---

# typeof behavior (JavaScript weirdness)

```javascript
typeof undefined // "undefined"
typeof null      // "object"
```

⚠️ `typeof null` returning `"object"` is a **historical bug** in JavaScript.

---

# Equality comparison

## Loose equality (`==`)

```javascript
null == undefined // true
```

Because JavaScript treats them as **equal absence of value**.

---

## Strict equality (`===`)

```javascript
null === undefined // false
```

Different types → not equal.

---

# Conversion Behavior (Important)

```javascript
Number(null)      // 0
Number(undefined) // NaN
```

See:  
[[08-Type Conversions]]

---

# Boolean Context

Both values are **falsy**.

```javascript
Boolean(null)      // false
Boolean(undefined) // false
```

---

# Quick Comparison

| Feature | undefined | null |
|--------|-----------|------|
| Meaning | Value not assigned | Intentional empty value |
| Assigned by | JavaScript | Developer |
| Type | undefined | object (bug) |
| Number conversion | NaN | 0 |
| Boolean conversion | false | false |

---

# Common Interview Traps

## 1. typeof null

```javascript
typeof null // "object"
```

---

## 2. Equality confusion

```javascript
null == undefined  // true
null === undefined // false
```

---

## 3. Conversion trap

```javascript
Number(null)      // 0
Number(undefined) // NaN
```

---

# Mental Model

```
undefined → JavaScript hasn't assigned a value yet
null → Developer intentionally says "no value"
```

---

# When to use which?

## Use `undefined`

Let JavaScript handle it for:

- uninitialized variables
- missing values
- default states

---

## Use `null`

Use when you want to **explicitly indicate empty value**.

```javascript
let currentUser = null
```

Meaning:

> A value may exist later, but currently none is assigned.

---

# Interview Summary

Important points:

- `undefined` = default value by JavaScript
- `null` = intentional empty value
- `typeof null` → `"object"` (bug)
- `null == undefined` → true
- `null === undefined` → false
- `Number(null)` → 0
- `Number(undefined)` → NaN
- Both are **falsy values**

---

# JavaScript NaN (Not a Number)

`NaN` stands for **Not a Number**.

It represents a value that is **not a valid number**, usually the result of an invalid mathematical operation.

---

# What is NaN?

`NaN` is a special value in JavaScript of type **number**.

```javascript
typeof NaN
```

Output

```
"number"
```

Yes, it’s confusing. JavaScript made that choice and never looked back.

---

# How NaN Occurs

## Invalid Number Conversion

```javascript
Number("hello") // NaN
```

---

## Invalid Math Operations

```javascript
"abc" - 2   // NaN
0 / 0       // NaN
Math.sqrt(-1) // NaN
```

---

# Key Property of NaN

## NaN is NOT equal to anything (even itself)

```javascript
NaN === NaN // false
NaN == NaN  // false
```

This is one of the most important interview points.

---

# Checking for NaN

## isNaN()

```javascript
isNaN("hello") // true
```

⚠️ Problem:

- It performs **type coercion**
- `"hello"` → NaN → true

See:  
[[08-Type Conversions]]

---

## Number.isNaN()

```javascript
Number.isNaN("hello") // false
Number.isNaN(NaN)     // true
```

✅ Recommended method

- Does **not perform type coercion**
- More reliable

---

# Difference: isNaN vs Number.isNaN

|Method|Type Coercion|Reliable|
|---|---|---|
|isNaN()|Yes|No|
|Number.isNaN()|No|Yes|

---

# NaN in Comparisons

```javascript
NaN > 5   // false
NaN < 5   // false
NaN == 5  // false
```

Any comparison with `NaN` returns **false**.

---

# NaN Propagation

If `NaN` appears in a calculation, it **spreads**.

```javascript
let result = NaN + 10

console.log(result)
```

Output

```
NaN
```

Once NaN enters, it contaminates everything.

---

# Common Interview Traps

## typeof NaN

```javascript
typeof NaN
```

Output

```
"number"
```

---

## NaN comparison

```javascript
NaN === NaN // false
```

---

## isNaN behavior

```javascript
isNaN("123")   // false
isNaN("hello") // true
```

Because of **type coercion**.

---

# Mental Model

When JavaScript fails to convert something into a number:

```
Invalid Number → NaN
```

And once you get NaN:

```
NaN + anything → NaN
```

---

# Interview Summary

Important points:

- `NaN` means **invalid number**
- `typeof NaN` → `"number"`
- `NaN !== NaN`
- Use `Number.isNaN()` instead of `isNaN()`
- NaN spreads in calculations
- Often caused by **invalid type conversion**

---

# JavaScript Equality Comparison

JavaScript provides two types of equality comparison:

1. **Loose Equality (`==`)**
2. **Strict Equality (`===`)**

---

# 1. Loose Equality (`==`)

Loose equality compares values **after performing type conversion (coercion)**.

Example

```javascript
5 == "5"
```

Output

```
true
```

Reason

```
"5" → 5
```

---

## More Examples

```javascript
true == 1           // true
false == 0          // true
null == undefined   // true
```

---

## Important Rule

When using `==`, JavaScript tries to convert both values to the **same type** before comparing.

---

# 2. Strict Equality (`===`)

Strict equality compares **value AND type**.

No type conversion is performed.

Example

```javascript
5 === "5"
```

Output

```
false
```

Because:

```
number ≠ string
```

---

## More Examples

```javascript
true === 1           // false
false === 0          // false
null === undefined   // false
```

---

# 3. Key Differences

| Feature | `==` | `===` |
|--------|------|------|
| Type Conversion | Yes | No |
| Compares Value | Yes | Yes |
| Compares Type | No | Yes |
| Recommended | No | Yes |

---

# 4. Truthy vs Equality (Important)

Truthy/falsy and `==` are **different concepts**.

refer [[09-Truthy and Falsy]]

### Boolean Context

```javascript
if([]){
  console.log("Runs")
}
```

Output

```
Runs
```

Because:

```javascript
Boolean([]) // true
```

---

### Loose Equality

```javascript
[] == false   // true
```

This confuses many developers.

---

## Step-by-step Breakdown

```javascript
[] == false
```

Step 1

```
false → 0
```

Step 2

```
[] → ""
```

Step 3

```
"" → 0
```

Final

```
0 == 0 → true
```

---

# 5. Special Cases

### null and undefined

```javascript
null == undefined   // true
null === undefined  // false
```

---

### NaN comparison

```javascript
NaN == NaN   // false
NaN === NaN  // false
```

Correct way:

```javascript
Number.isNaN(NaN) // true
```

---

### Objects and Arrays

```javascript
[] == []   // false
{} == {}   // false
```

Because they are compared by **reference**, not value.

---

# 6. Common Edge Cases (Interview Traps)

### Empty array vs false

```javascript
[] == false   // true
```

---

### Empty string vs false

```javascript
"" == false   // true
```

---

### String vs false

```javascript
"0" == false   // true
```

---

### Array vs number

```javascript
[] == 0   // true
```

---

### Array with value

```javascript
[1] == 1   // true
```

---

### Weird case

```javascript
[] == ![]
```

Breakdown

```javascript
![] → false
[] == false → true
```

Final

```
true
```

---

# 7. Type Coercion Rules (Simplified)

When using `==`, JavaScript follows these conversions:

```
boolean → number
string → number
object → primitive → string → number
```

---

# 8. Best Practice

Always prefer:

```javascript
===
```

Avoid:

```javascript
==
```

Unless you fully understand coercion.

---

# 9. Mental Model (Important)

Remember:

```
Truthy/Falsy → Boolean conversion
==           → Type coercion rules
```

They are **not the same thing**.

---

# 10. Interview Summary

- `==` performs **type coercion**
- `===` compares **value and type**
- `null == undefined` → true
- `NaN !== NaN`
- Objects are compared by **reference**
- `[] == false` → true (due to coercion)
- Truthy/falsy is different from equality comparison
- Always prefer `===` in real-world code

---

