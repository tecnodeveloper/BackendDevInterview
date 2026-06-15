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
[[Type Conversions]]

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

# Related Concepts

JavaScript Template Literals