# JavaScript Objects

Objects store **key-value pairs** and are used to represent **structured data**.

---

## Example

```javascript
const user = {
  name: "John",
  age: 25
}
```

- key → `name`
- value → `"John"`

---

## Array vs Object

```javascript
let arr = ["John", 25]
arr[0] // "John"

let obj = { name: "John", age: 25 }
obj.name // "John"
```

- Array → index-based
- Object → key-based

---

# Object Creation

```javascript
const obj = {
  name: "John"
}
```

Other ways:

```javascript
const obj = new Object()
```

---

## Prototype (Important Concept)

Every object in JavaScript has a **prototype (parent)**.

```javascript
const obj = { name: "John" }
```

Internally:

```
obj → Object.prototype → null
```

---

## Object.create()

Used to create an object with a **custom prototype**

```javascript
const parent = { city: "Salem" }

const obj = Object.create(parent)
obj.name = "John"
```

Structure:

```
obj → parent → Object.prototype → null
```

---

## Why use Object.create()?

### 1. Inheritance

```javascript
const animal = {
  speak() {
    console.log("Some sound")
  }
}

const dog = Object.create(animal)

dog.speak()
```

---

### 2. Shared methods (memory efficiency)

```javascript
const userMethods = {
  greet() {
    console.log("hi")
  }
}

const user1 = Object.create(userMethods)
const user2 = Object.create(userMethods)
```

---

### 3. Create object without default prototype

```javascript
const obj = Object.create(null)

console.log(obj.toString) // undefined
```

Structure:

```
obj → null
```

---

## When to use

- Mostly **not needed in modern React/MERN**
- Useful for:
  - inheritance
  - shared methods
  - special cases (dictionary objects)

---

# Accessing Properties

## Dot notation

```javascript
obj.name
```

## Bracket notation

```javascript
obj["name"]
```

Use when:
- dynamic keys
- keys with spaces

```javascript
const key = "name"
obj[key]
```

---

# Updating & Deleting

```javascript
obj.age = 25
delete obj.age
```

---

# Object Methods (User-defined)

```javascript
const user = {
  name: "John",
  greet() {
    return "Hello"
  }
}
```

---

# Object Methods

Used to work with object properties (keys, values, entries, iteration)

→ [[Object Methods]]

---

# Important Concepts

## Object Destructuring
Used to extract values from objects into variables.

→ [[Object Destructuring]]

---

## Spread Operator
Used to copy or merge objects (shallow copy).

→ [[Spread Operator]]

---

## Object Reference Behavior
Objects are stored by reference, not value.

→ [[Object Reference Behavior]]

---

## Optional Chaining
Safely access nested properties.

→ [[Optional Chaining]]

---

# Edge Cases

```javascript
typeof null // "object"
```

```javascript
const obj = {}
obj.a = undefined
console.log("a" in obj) // true
```

```javascript
const obj = { a: 1 }
delete obj.a
console.log(obj.a) // undefined
```

---
# JavaScript Object Reference Behavior

Objects in JavaScript are stored and copied by **reference**, not by value.

---

## 1. What it means

```javascript
const obj1 = { name: "John" }
const obj2 = obj1
```

- `obj1` and `obj2` point to the **same memory location**

---

## 2. Proof

```javascript
obj2.name = "Doe"

console.log(obj1.name) // "Doe"
```

Changing one affects the other.

---

## 3. Visual

```
obj1 ─┐
      ├──> { name: "John" }
obj2 ─┘
```

---

## 4. Comparison

```javascript
const obj1 = { name: "John" }
const obj2 = { name: "John" }

console.log(obj1 === obj2) // false
```

Why?

- Different memory references

---

## 5. Primitive vs Object

```javascript
let a = 10
let b = a

b = 20

console.log(a) // 10
```

- Primitives → copied by **value**
- Objects → copied by **reference**

---

## 6. Copying Objects (Important)

### ❌ Wrong way (reference copy)

```javascript
const obj1 = { name: "John" }
const obj2 = obj1
```

---

### ✅ Shallow Copy (Spread)

```javascript
const obj1 = { name: "John" }
const obj2 = { ...obj1 }
```

Now:

```javascript
obj2.name = "Doe"

console.log(obj1.name) // "John"
```

---

### ⚠️ Shallow Copy Problem

```javascript
const obj1 = {
  user: { name: "John" }
}

const obj2 = { ...obj1 }

obj2.user.name = "Doe"

console.log(obj1.user.name) // "Doe"
```

Nested objects are still shared.

---

### ✅ Deep Copy (basic way)

```javascript
const obj2 = JSON.parse(JSON.stringify(obj1))
```

⚠️ Limitations:
- loses functions
- loses undefined
- loses special types (Date, Map, etc.)

---

## 7. Real World Problem

```javascript
function updateUser(user) {
  user.name = "Updated"
}

const user = { name: "John" }

updateUser(user)

console.log(user.name) // "Updated"
```

Function modifies original object.

---

## 8. Safe Practice

```javascript
function updateUser(user) {
  return { ...user, name: "Updated" }
}
```

---
# JavaScript Object Destructuring

Object destructuring is used to **extract values from objects into variables**.

---

## Basic Syntax

```javascript
const obj = { name: "John", age: 25 }

const { name, age } = obj

console.log(name) // "John"
console.log(age)  // 25
```

---

## Renaming Variables

```javascript
const obj = { name: "John" }

const { name: userName } = obj

console.log(userName) // "John"
```

---

## Default Values

```javascript
const obj = { name: "John" }

const { name, age = 18 } = obj

console.log(age) // 18
```

---

## Missing Property

```javascript
const obj = { name: "John" }

const { age } = obj

console.log(age) // undefined
```

---

## Nested Destructuring

```javascript
const obj = {
  user: {
    name: "John"
  }
}

const { user: { name } } = obj

console.log(name) // "John"
```

---

## Function Parameters (Object Destructuring)

Using destructuring in function parameters allows passing an object and extracting values directly.

---

### Normal Parameters

```javascript
function printUser(name, age) {
  console.log(name, age)
}

printUser("John", 25)
```

**Limitations:**

- Order matters  
- Hard to manage with many parameters  

---

### Object Parameter (Destructuring)

```javascript
function printUser({ name, age }) {
  console.log(name, age)
}

printUser({ name: "John", age: 25 })
```

---

### Why use this?

- Order does NOT matter  

```javascript
printUser({ age: 25, name: "John" })
```

- More readable (self-explanatory)  
- Easy to add new fields  

```javascript
function printUser({ name, age, city }) {}
```

- Supports default values  

```javascript
function printUser({ name, age = 18 }) {}
```

---

### Behind the Scenes

```javascript
function printUser(obj) {
  const name = obj.name
  const age = obj.age
}
```

Destructuring is just a **shortcut**.

---

### When to Use

- Few parameters → normal parameters  
- Many / optional parameters → object destructuring  

---

## Rest Operator

```javascript
const obj = { name: "John", age: 25, city: "Salem" }

const { name, ...rest } = obj

console.log(name) // "John"
console.log(rest) // { age: 25, city: "Salem" }
```

---

## Important Points

- Extracts values from objects  
- Order does NOT matter (unlike arrays)  
- Variable name must match key (unless renamed)  
- Can use default values  

---

## Common Mistake

```javascript
const obj = { name: "John" }

const { age } = obj

console.log(age.toString()) // ❌ Error
```

### What’s happening?

- `age` does NOT exist in the object  
- So destructuring gives:

```javascript
age = undefined
```

Now this runs:

```javascript
undefined.toString()
```

Which causes:

```
TypeError: Cannot read properties of undefined
```

Because `undefined` does not have methods.

---

## Fix (Default Value)

```javascript
const { age = 0 } = obj

console.log(age.toString()) // "0"
```

### Why this works

- If `age` is missing → it uses default value `0`
- So now:

```javascript
age = 0
```

And:

```javascript
0.toString() // works
```

---

## Key Idea

If a property might be missing, always use a **default value** during destructuring.

## Mental Model

```
Destructuring → pull values out of object into variables
```

---

## Interview Summary

- Used to extract object values  
- Supports default values  
- Supports renaming  
- Works in function parameters  
- Supports nested objects  

---
# Spread Operator (Objects)

The spread operator (`...`) is used to **copy or merge objects**.

---

## Basic Syntax

```javascript
const obj = { name: "John", age: 25 }

const newObj = { ...obj }
```

---

## Copying Objects

```javascript
const obj = { name: "John" }

const copy = { ...obj }

console.log(copy) // { name: "John" }
```

### Important

```javascript
const a = { name: "John" }
const b = a

b.name = "Sam"

console.log(a.name) // "Sam"
```

This copies **reference**, not the object.

---

### Correct Way (using spread)

```javascript
const a = { name: "John" }
const b = { ...a }

b.name = "Sam"

console.log(a.name) // "John"
```

Now it's a **new object (shallow copy)**.

---

## Merging Objects

```javascript
const obj1 = { name: "John" }
const obj2 = { age: 25 }

const merged = { ...obj1, ...obj2 }

console.log(merged)
// { name: "John", age: 25 }
```

---

## Overwriting Properties

```javascript
const obj1 = { name: "John", age: 20 }
const obj2 = { age: 25 }

const merged = { ...obj1, ...obj2 }

console.log(merged)
// { name: "John", age: 25 }
```

### Rule

- Later values overwrite earlier ones

---

## Shallow Copy (Important)

Spread operator creates a **shallow copy**, not deep copy.

```javascript
const obj = {
  name: "John",
  address: {
    city: "Salem"
  }
}

const copy = { ...obj }

copy.address.city = "Chennai"

console.log(obj.address.city) // "Chennai"
```

### Why?

Nested objects are still **shared by reference**.

---

## Spread vs Reference

```javascript
const a = { name: "John" }

const ref = a
const copy = { ...a }

ref.name = "Sam"

console.log(a.name)   // "Sam"
console.log(copy.name) // "John"
```

---

## Real-world Usage

### Updating object (React style)

```javascript
const user = { name: "John", age: 25 }

const updatedUser = { ...user, age: 26 }
```

---

### Adding new property

```javascript
const user = { name: "John" }

const newUser = { ...user, city: "Salem" }
```

---

## Mental Model

```
Spread → take all properties → put into new object
```

---

## Important Points

- Used to copy objects  
- Used to merge objects  
- Creates shallow copy  
- Later properties overwrite earlier ones  

---

## Interview Summary

- Used for copying and merging objects  
- Does NOT create deep copy  
- Common in React state updates  

---
# JavaScript Optional Chaining (?.)

Optional chaining is used to **safely access nested object properties** without causing errors if a property does not exist.

---

## Definition

Prevents runtime errors when accessing properties of `undefined` or `null`.

---

## Syntax

```javascript
obj?.property
obj?.[key]
obj?.method()
```

---

## Example

### Without optional chaining ❌

```javascript
const user = {}

console.log(user.address.city) 
// ❌ Error: Cannot read properties of undefined
```

---

### With optional chaining ✅

```javascript
console.log(user.address?.city) 
// ✅ undefined (no error)
```

---

## Nested Example

```javascript
const user = {
  profile: {
    name: "John"
  }
}

console.log(user.profile?.name) // John
console.log(user.address?.city) // undefined
```

---

## Array Example

```javascript
const users = [{ name: "John" }]

console.log(users[0]?.name) // John
console.log(users[1]?.name) // undefined
```

---

## Function Example

```javascript
const user = {
  greet() {
    return "Hello"
  }
}

console.log(user.greet?.()) // Hello
console.log(user.sayHi?.()) // undefined
```

---

# ⚠️ Edge Cases

### 1. Only stops at null/undefined

```javascript
const obj = { a: null }

console.log(obj.a?.b) // undefined
```

- Works because `a` is null

---

### 2. Does NOT stop other errors

```javascript
const obj = { a: 10 }

console.log(obj.a?.b) // undefined (safe)

console.log(obj.a.toUpperCase()) // ❌ Error (not a function)
```

---

### 3. Cannot assign using optional chaining

```javascript
obj?.name = "John" // ❌ Error
```

---

# ❌ Common Mistakes

### Accessing without optional chaining

```javascript
const user = {}

console.log(user.address.city) // ❌ Error
```

### Why it is wrong
- `address` is undefined  
- Trying to access `.city` causes runtime error  

### Fix
```javascript
console.log(user.address?.city) // ✅ undefined
```

### How it fixes
- Stops execution if `address` is undefined  
- Returns `undefined` instead of crashing  

---

### Overusing optional chaining

```javascript
console.log(user?.name?.toUpperCase())
```

### Why it is wrong
- If `name` is undefined, result becomes `undefined`  
- You may hide bugs unintentionally  

### Fix
```javascript
if (user.name) {
  console.log(user.name.toUpperCase())
}
```

### How it fixes
- Ensures value exists before using it  
- Prevents silent failures  

---

### Using with non-existing root object

```javascript
console.log(user?.name) // ❌ if user is not defined at all
```

### Why it is wrong
- Optional chaining does NOT work on undeclared variables  

### Fix
```javascript
let user

console.log(user?.name) // ✅ undefined
```

### How it fixes
- Variable is declared, so JS can safely evaluate it  

---

# 💡 When to Use

- Accessing **API response data**
- Deeply nested objects
- Optional properties
- Function calls that may not exist

---

# 🚫 When NOT to Use

- When you expect value to always exist  
- When it hides real bugs  

---