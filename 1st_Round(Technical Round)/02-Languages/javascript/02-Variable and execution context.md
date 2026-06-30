# JavaScript use strict

`"use strict"` enables **Strict Mode** in JavaScript.

Strict Mode is a **restricted version of JavaScript** that helps catch common mistakes and prevents unsafe behavior.

It makes the code **more secure, predictable, and easier to debug**.

---

# Why Strict Mode exists

Early JavaScript allowed many **unsafe or confusing behaviors**, such as:

- creating variables accidentally
- silent errors
- incorrect `this` binding
- duplicate parameters

Strict Mode was introduced in **ES5** to prevent these problems.

---

# How to enable Strict Mode

## 1. Global strict mode

```javascript
"use strict"

let x = 10
```

Strict mode applies to the **entire script**.

---

## 2. Function-level strict mode

```javascript
function test() {
  "use strict"

  let x = 10
}
```

Strict mode applies **only inside that function**.

---

# Common Errors Prevented by Strict Mode

## 1. Prevents accidental global variables

Without strict mode:

```javascript
x = 10
console.log(x)
```

JavaScript automatically creates a **global variable**.

With strict mode:

```javascript
"use strict"

x = 10
```

Error:

```
ReferenceError: x is not defined
```

---

## 2. Prevents deleting variables

```javascript
"use strict"

let x = 10
delete x
```

Error:

```
SyntaxError
```

---

## 3. Prevents duplicate parameters

Without strict mode:

```javascript
function add(a, a) {
  return a
}
```

Allowed but confusing.

With strict mode:

```
SyntaxError
```

---

## 4. `this` behavior in functions

Without strict mode:

```javascript
function test() {
  console.log(this)
}

test()
```

Output:

```
window
```

With strict mode:

```javascript
"use strict"

function test() {
  console.log(this)
}

test()
```

Output:

```
undefined
```

---

# Strict Mode Restrictions

Strict mode disallows:

- undeclared variables
- deleting variables or functions
- duplicate function parameters
- some unsafe syntax

---

# Important Note

ES6 modules and modern JavaScript tools **automatically use strict mode**.

Example:

```javascript
export const value = 10
```

Modules run in **strict mode by default**, so `"use strict"` is usually unnecessary in modern projects.

---

# When to use it

Strict mode is useful because it:

- prevents silent errors
- improves debugging
- enforces cleaner JavaScript
- avoids accidental global variables

Most modern JavaScript environments already enforce strict mode.

---
# JavaScript let vs var vs const

JavaScript provides three ways to declare variables:

- `var`
- `let`
- `const`

They differ in **scope, redeclaration, reassignment, and hoisting behavior**.

---

# var

`var` was the original way to declare variables in JavaScript.

### Example

```javascript
var name = "John"
```

### Characteristics

- Function scoped
- Can be **redeclared**
- Can be **reassigned**
- Gets **hoisted** with an initial value of `undefined`

### Example

```javascript
var a = 10
var a = 20   // allowed

a = 30       // allowed
```

### Scope Example

```javascript
function test(){
  var x = 10
}

console.log(x) // ReferenceError
```

`var` is limited to **function scope**, not block scope.

---

# let

`let` was introduced in **ES6 (2015)** to fix problems with `var`.

### Example

```javascript
let age = 25
```

### Characteristics

- **Block scoped**
- Cannot be **redeclared in the same scope**
- Can be **reassigned**

### Example

```javascript
let a = 10
a = 20   // allowed
```

### Invalid Redeclaration

```javascript
let a = 10
let a = 20 // SyntaxError
```

### Block Scope Example

```javascript
{
  let x = 10
}

console.log(x) // ReferenceError
```

---

# const

`const` is used for variables that **should not be reassigned**.

### Example

```javascript
const PI = 3.14
```

### Characteristics

- **Block scoped**
- Cannot be **redeclared**
- Cannot be **reassigned**
- Must be **initialized during declaration**

### Example

```javascript
const a = 10
a = 20 // Error
```

### Objects with const

`const` prevents reassignment, **not mutation**.

```javascript
const user = {name:"John"}

user.name = "Mike" // allowed
```

But this is not allowed:

```javascript
user = {} // Error
```

---

# Quick Comparison

|Feature|var|let|const|
|---|---|---|---|
|Scope|Function|Block|Block|
|Redeclaration|Allowed|Not Allowed|Not Allowed|
|Reassignment|Allowed|Allowed|Not Allowed|
|Initialization required|No|No|Yes|

---

# Hoisting Relationship

All three declarations are affected by **[[16-Hoisting]]**, but they behave differently.

- `var` is hoisted and initialized with `undefined`
- `let` and `const` are hoisted but remain in the **Temporal Dead Zone (TDZ)** until initialization

To understand this behavior in detail see:

→ [[16-Hoisting]]

---

# Interview Summary

Important points:

- `var` is **function scoped**
- `let` and `const` are **block scoped**
- `let` allows reassignment
- `const` does **not allow reassignment**
- `var` allows **redeclaration**
- `let` and `const` do **not allow redeclaration**
- `const` objects can still be **mutated**

---

# JavaScript Hoisting

Hoisting is JavaScript's behavior where **variable and function declarations are processed before code execution**.

This happens during the **Creation Phase of the Execution Context**.

Hoisting does **not physically move code**, but JavaScript behaves *as if declarations were moved to the top of their scope*.

---

# Execution Context and Hoisting

When JavaScript runs code, it creates an **Execution Context**.

Each execution context has two phases:

1. **Creation Phase (Memory Creation Phase)**
2. **Execution Phase**

---

## Creation Phase (Memory Allocation)

During this phase JavaScript scans the entire scope and allocates memory.

|Declaration Type|Memory Behavior|
|---|---|
|var|initialized as `undefined`|
|let|created but placed in **Temporal Dead Zone**|
|const|created but placed in **Temporal Dead Zone**|
|function declaration|stored with full function body|

Example memory structure:

```
Creation Phase Memory

a → undefined
b → <TDZ>
c → <TDZ>
greet → function
```

No code runs yet. JavaScript is only **preparing memory**.

---

## Execution Phase

After memory allocation, JavaScript starts executing the code **line by line**.

Now assignments happen and functions execute.

---

# Hoisting with Variables

## Hoisting with var

`var` variables are hoisted and **initialized with undefined** during the creation phase.

Example:

```javascript
console.log(a)

var a = 10
```

Memory Phase:

```
a → undefined
```

Execution Phase:

```
console.log(a) → undefined
a = 10
```

Output:

```
undefined
```

The **declaration is hoisted**, but the **assignment happens later**.

---

## Hoisting with let and const

`let` and `const` are also hoisted, but they are **not initialized immediately**.

Instead they remain inside the **Temporal Dead Zone (TDZ)**.

Example:

```javascript
console.log(a)

let a = 5
```

Creation Phase:

```
a → <TDZ>
```

Execution Phase:

```
console.log(a) → ReferenceError
```

Output:

```
ReferenceError
```

The variable exists but **cannot be accessed yet**.

---

# Temporal Dead Zone (TDZ)

The **Temporal Dead Zone** is the period between:

```
Variable creation
and
Variable initialization
```

Example:

```javascript
{
  console.log(a)
  let a = 10
}
```

The area before `let a = 10` is the **TDZ**.

Accessing the variable during this time causes a **ReferenceError**.

---

# Hoisting with const

`const` behaves like `let` regarding hoisting.

Example:

```javascript
console.log(x)

const x = 10
```

Creation Phase:

```
x → TDZ
```

Execution Phase:

```
console.log(x) → ReferenceError
```

Additionally, `const` **must be initialized during declaration**.

---

# Hoisting with Functions

Function behavior during hoisting depends on **how the function is defined**.

---

## Function Declaration Hoisting

^54928a

Function declarations are **fully hoisted**.

The entire function definition is stored during the **creation phase**.

Example:

```javascript
greet()

function greet(){
  console.log("Hello")
}
```

Creation Phase:

```
greet → function(){ console.log("Hello") }
```

Execution Phase:

```
greet() executes successfully
```

Output:

```
Hello
```

The function already exists in memory before execution begins.

---

## Function Expression Hoisting

^dc5e30

Function expressions behave like **variables**.

Example:

```javascript
greet()

var greet = function(){
  console.log("Hello")
}
```

Creation Phase:

```
greet → undefined
```

Execution Phase:

```
greet() → undefined()
```

Output:

```
TypeError: greet is not a function
```

The variable is hoisted, but the **function assignment happens later**.

---

## Arrow Function Hoisting

Arrow functions behave like **function expressions**.

Example:

```javascript
greet()

const greet = () => {
  console.log("Hello")
}
```

Creation Phase:

```
greet → TDZ
```

Execution Phase:

```
greet() → accessing variable inside TDZ
```

Output:

```
ReferenceError: Cannot access 'greet' before initialization
```

---

# Function Hoisting Comparison

|Function Type|Creation Phase Value|Result|
|---|---|---|
|Function Declaration|Function stored|Works|
|Function Expression (var)|undefined|TypeError|
|Arrow Function (let/const)|TDZ|ReferenceError|

---

# Quick Visual Model

```
Execution Context
      ↓
Creation Phase
      ↓
Memory Allocation
      ↓
var → undefined
let/const → TDZ
function → full function stored
      ↓
Execution Phase
      ↓
Code runs line by line
```

---

# Key Takeaways

- Hoisting happens during the **creation phase of the execution context**
- `var` variables are hoisted and initialized with `undefined`
- `let` and `const` are hoisted but remain in the **Temporal Dead Zone**
- Function declarations are **fully hoisted**
- Function expressions behave like **variables**
- Arrow functions follow **TDZ rules when declared with let/const**

---

# JavaScript Execution Context

## Definition

An Execution Context is the environment in which JavaScript code is executed.

It contains all the information needed to run the code, including variables, functions, and the value of `this`.

---

## Types of Execution Context

### Global Execution Context (GEC)

- Created when the JavaScript program starts  
- Only one global context exists  
- `this` refers to global object (`window` in browser)  

---

### Function Execution Context (FEC)

- Created whenever a function is called  
- Each function call gets its own execution context  

---

## Phases of Execution Context

Each execution context has two phases:

### 1. Creation Phase

- Memory is allocated for variables and functions  
- Variables are initialized with `undefined`  
- Functions are stored completely in memory  
- `this` is determined  

---

### 2. Execution Phase

- Code is executed line by line  
- Variables are assigned actual values  
- Functions are invoked  

---

## Example

~~~javascript
var a = 10

function test() {
  var b = 20
  console.log(a + b)
}

test()
~~~

---

## Execution Flow

### Global Execution Context (Creation Phase)

- `a` → undefined  
- `test` → function stored  

---

### Global Execution Context (Execution Phase)

- `a = 10`  
- `test()` is called → new Function Execution Context created  

---

### Function Execution Context (Creation Phase)

- `b` → undefined  

---

### Function Execution Context (Execution Phase)

- `b = 20`  
- `console.log(a + b)` → 30  

---

## Output

~~~javascript
30
~~~

---

## Call Stack + Execution Context

- Each function call creates a new Execution Context  
- These contexts are pushed onto the Call Stack  
- When execution completes, they are removed  

→ Related: [[18-Call Stack]]

---

## Scope Chain

Execution Context also manages scope:

- Inner functions can access outer variables  
- JavaScript looks for variables in current scope, then outer scopes  

---

## Example

~~~javascript
var a = 10

function outer() {
  var b = 20

  function inner() {
    console.log(a + b)
  }

  inner()
}

outer()
~~~

### Output

~~~javascript
30
~~~

---

## Behavior

- JavaScript creates execution context before running code  
- Each function has its own context  
- Works with Call Stack for execution  

---

## Edge Cases

### Variable hoisting

~~~javascript
console.log(a)
var a = 5
~~~

### Output

~~~javascript
undefined
~~~

### Why it happens

Variable is created during creation phase but assigned later.

---

### Function hoisting

~~~javascript
test()

function test() {
  console.log("Hello")
}
~~~

### Output

~~~javascript
Hello
~~~

### Why it happens

Functions are fully stored during creation phase.

---

## Common Mistakes

### ❌ Wrong Assumption

~~~javascript
console.log(a)
let a = 10
~~~

### Output

~~~javascript
ReferenceError
~~~

### Why it is a mistake

`let` and `const` are hoisted but not initialized (Temporal Dead Zone).

---

## When to use

(Not directly used, but important for understanding)

- Understanding hoisting  
- Debugging scope issues  
- Understanding function execution  

---

## When NOT to use

- You don’t directly control execution context  
- It is handled by the JavaScript engine  

---

# JavaScript Call Stack

## Definition

The Call Stack is a data structure used by JavaScript to manage the execution of function calls.

It keeps track of which function is currently running and what should be executed next.

---

## Key Concept

- JavaScript executes code line by line (synchronously)  
- Each function call is added to the Call Stack  
- The Call Stack follows LIFO (Last In First Out)  
- The last function added is executed first  

---

## How It Works

1. Global execution starts and is pushed to the stack  
2. When a function is called → pushed onto stack  
3. When a function completes → removed (popped)  
4. Control returns to the previous function  

---

## Example: Sequential Execution

~~~javascript
function a() {
  console.log("A")
}

function b() {
  console.log("B")
}

a()
b()
~~~

### Output

~~~javascript
A
B
~~~

### Execution Flow

1. Global context pushed  
2. `a()` pushed → executed → popped  
3. `b()` pushed → executed → popped  

---

## Example: Nested Function Calls

~~~javascript
function a() {
  console.log("A start")
  b()
  console.log("A end")
}

function b() {
  console.log("B")
}

a()
~~~

### Output

~~~javascript
A start
B start // pushed into stack  
B end   // poped into stack 
A end
~~~

### Execution Flow

1. Global context pushed  
2. `a()` pushed  
3. Inside `a()`, `b()` pushed  
4. `b()` executes → popped  
5. Back to `a()` → completes → popped  

---

## Important Clarification

- LIFO applies to ALL function calls  
- Not only nested functions  
- Nested calls simply make LIFO behavior more visible  

---

## Call Stack + Execution Context

Each function in the stack has its own execution context:

- Variables  
- Function scope  
- this keyword  

→ Related: [[17-Execution Context]]

---

## Stack Overflow

### What is it?

When too many function calls are added to the stack, exceeding its limit.

---

### Example

~~~javascript
function recurse() {
  recurse()
}

recurse()
~~~

### Output

~~~javascript
RangeError: Maximum call stack size exceeded
~~~

---

### Why it happens

- Infinite recursion  
- No base condition  

---

## Behavior

- Single-threaded execution  
- Executes one function at a time  
- Blocks execution during long tasks  

---

## When to use

(Not directly used, but important for understanding)

- Debugging execution order  
- Understanding synchronous behavior  
- Avoiding stack overflow errors  

---

## When NOT to use

- You do not directly control the call stack  
- It is managed by the JavaScript engine  

---

## Common Mistakes

### ❌ Wrong Assumption

~~~javascript
function a() {
  b()
}

function b() {
  console.log("B")
}

a()
console.log("Done")
~~~

### Expected (wrong thinking)

~~~javascript
Done
B
~~~

### Actual Output

~~~javascript
B
Done
~~~

### Why it is a mistake

JavaScript executes functions immediately using the Call Stack before moving to the next line.

---
