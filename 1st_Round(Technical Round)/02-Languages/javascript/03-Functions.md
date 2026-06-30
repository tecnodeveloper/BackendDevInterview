# JavaScript Functions Basics

A function is a block of code designed to perform a specific task.

---

## Definition

Functions help to **reuse code**, improve readability, and organize logic.

---

## Syntax

```javascript
function functionName(parameters) {
  // code
}
```

---

## Basic Example

```javascript
function greet() {
  console.log("Hello")
}

greet() // Hello
```

---

## Function with Parameters

```javascript
function greet(name) {
  console.log("Hello " + name)
}

greet("John") // Hello John
```

---

## Return Value

```javascript
function add(a, b) {
  return a + b
}

const result = add(2, 3)
console.log(result) // 5
```

---

# Function Declarations & Types

JavaScript supports multiple ways to define functions.

---

## 1. Function Declaration

### Definition
A function defined using the `function` keyword with a name.

### Syntax
```javascript
function functionName() {
  // code
}
```

### Example
```javascript
function greet() {
  console.log("Hello")
}
```

### When to use
- When function should be available anywhere in the scope  
- When readability is important  

### When NOT to use
- When you need more control over execution order  

### Behavior
- Stored completely in memory during creation phase  

### Hoisting
- Can be called before declaration  

👉 Detailed explanation: [[16-Hoisting#^54928a]]

---

## 2. Function Expression

### Definition
A function stored inside a variable.

### Syntax
```javascript
const functionName = function () {
  // code
}
```

### Example
```javascript
const greet = function () {
  console.log("Hello")
}
```

### When to use
- When function should run only after definition  
- When assigning functions dynamically  

### When NOT to use
- When early access (before declaration) is required  

### Behavior
- Treated like a variable  

### Hoisting
- Cannot be called before declaration  

👉 Detailed explanation: [[16-Hoisting#^dc5e30]]

---

## 3. Arrow Function

### Definition
A shorter syntax for writing functions introduced in ES6.

### Syntax
```javascript
const functionName = () => {
  // code
}
```

### Example
```javascript
const greet = () => {
  console.log("Hello")
}
```

### When to use
- Short functions  
- Functional programming (map, filter, etc.)  

### When NOT to use
- When working with `this` keyword (object methods, constructors)  

### Behavior
- Does not have its own `this`  

→ [[21-Arrow functions]]

---

## 4. Callback Function

### Definition
A function passed as an argument to another function.

### Syntax
```javascript
function mainFunction(param, callback) {
  callback()
}
```

### Example
```javascript
function greet(name, callback) {
  console.log("Hello " + name)
  callback()
}
```

### When to use
- Async operations  
- Event handling  
- Reusable logic  

### When NOT to use
- When code becomes deeply nested (callback hell)  

### Behavior
- Executed after main function completes  

→ [[20-CallBack Functions]]

---

## 5. Constructor Function

### Definition
A function used to create multiple objects using `new`.

### Syntax
```javascript
function FunctionName() {
  this.property = value
}
```

### Example
```javascript
function User(name) {
  this.name = name
}

const user1 = new User("John")
```

### When to use
- Creating multiple similar objects  

### When NOT to use
- In modern apps (prefer classes)  

### Behavior
- `this` refers to new object  

→ [[24-Constructor Functions]]

---

## 6. call / apply / bind

### Definition
Methods used to control the value of `this` in functions.

### Syntax
```javascript
functionName.call(thisArg)
functionName.apply(thisArg)
functionName.bind(thisArg)
```

### Example
```javascript
function greet() {
  console.log(this.name)
}
```

### When to use
- Changing execution context (`this`)  

### When NOT to use
- When not dealing with `this` keyword  

### Behavior
- Explicitly sets `this`  

→ [[23-Call Apply Bind]]

---

# Additional Function Concepts

These are commonly asked in interviews and essential for deeper understanding.

---

## 7. Immediately Invoked Function Expression (IIFE)

### Definition
A function that runs immediately after it is defined.

### Syntax
```javascript
(function () {
  // code
})()
```

### Example
```javascript
(function (name) {
  console.log("Hello " + name)
})("John")
```

### When to use
- One-time execution  
- Creating private scope  
- Avoiding global variable pollution  

### When NOT to use
- Modern JavaScript modules already handle scope better  

### Behavior
- Executes immediately  
- No separate function call needed  

---

## 8. Named vs Anonymous Functions

### Definition
Functions can be named or anonymous.

### Example
```javascript
// Named
function greet() {}

// Anonymous
const greet = function () {}
```

### When to use
- Named → debugging, readability  
- Anonymous → callbacks  

### Behavior
- Named functions appear in stack traces  

---

## 9. First-Class Functions

### Definition
Functions are treated as values in JavaScript.

### Example
```javascript
function greet() {}

const sayHello = greet
```

### Behavior
- Can be stored in variables  
- Passed as arguments  
- Returned from functions  

---

## 10. Higher-Order Functions

### Definition
A function that takes another function as argument or returns a function.

### Example
```javascript
function main(fn) {
  fn()
}
```

### When to use
- Functional programming  
- Array methods (map, filter, reduce)  

---

## 11. Default Parameters

### Definition
Allows default values for function parameters.

### Example
```javascript
function add(a = 0, b = 0) {
  return a + b
}
```

### Behavior
- Used when argument is `undefined`  

---

## 12. Rest Parameters

### Definition
Allows handling multiple arguments as an array.

### Example
```javascript
function sum(...numbers) {
  return numbers.reduce((a, b) => a + b)
}
```

### Behavior
- Collects all remaining arguments  

---

## 13. Pure vs Impure Functions

### Pure Function
```javascript
function add(a, b) {
  return a + b
}
```

### Impure Function
```javascript
let total = 0

function add(num) {
  total += num
}
```

### Behavior
- Pure → predictable, no side effects  
- Impure → modifies external state  

---

# ⚠️ Edge Cases

### Missing return

```javascript
function test() {}

console.log(test()) // undefined
```

---

### Extra arguments

```javascript
function add(a, b) {
  return a + b
}

add(2, 3, 4) // 5
```

---

### Missing arguments

```javascript
add(2) // NaN
```

---

# ❌ Common Mistakes

### Forgetting return

```javascript
function add(a, b) {
  a + b // ❌
}
```

### Fix
```javascript
function add(a, b) {
  return a + b // ✅
}
```

---

### Calling function expression before declaration

```javascript
greet() // ❌ Error

const greet = function () {
  console.log("Hello")
}
```

### Fix
```javascript
const greet = function () {
  console.log("Hello")
}

greet() // ✅
```

---

### Not passing required arguments

```javascript
function add(a, b) {
  return a + b
}

add(2) // ❌ NaN
```

### Fix
```javascript
function add(a = 0, b = 0) {
  return a + b
}
```

---

# 💡 When to Use

- Reusable logic  
- Avoid repetition  
- Organize code into smaller units  

---
# Callback Functions

## Definition

A callback function is a function passed as an argument to another function and executed later.

It allows one function to control when and how another function runs.

---

## Syntax

```javascript
function mainFunction(callback) {
  callback()
}
```

---

## Basic Example

```javascript
function greet(name, callback) {
  console.log("Hello " + name)
  callback()
}

function sayBye() {
  console.log("Goodbye")
}

greet("John", sayBye)

// Output:
// Hello John
// Goodbye
```

---

## Additional Examples

### Example 1: Anonymous Callback

```javascript
function greet(callback) {
  console.log("Hello")
  callback()
}

greet(function () {
  console.log("This is a callback")
})
```

---

### Example 2: Arrow Function Callback

```javascript
function process(callback) {
  callback()
}

process(() => {
  console.log("Arrow callback executed")
})
```

---

### Example 3: Callback in Array Methods

```javascript
const numbers = [1, 2, 3]

numbers.forEach(function (num) {
  console.log(num)
})
```

---

### Example 4: Asynchronous Callback

```javascript
setTimeout(function () {
  console.log("Executed after 2 seconds")
}, 2000)
```

---

## Calling vs Invoking a Function

### Calling a Function

Calling means executing a function directly using its name.

```javascript
function greet() {
  console.log("Hello")
}

greet()
```

---

### Invoking a Function

Invoking means executing a function through a reference, often inside another function.

```javascript
function main(callback) {
  callback()
}

function sayHi() {
  console.log("Hi")
}

main(sayHi)
```

---

### Key Idea

- Calling → direct execution  
- Invoking → execution via reference (common in callbacks)

---

### Callback Flow

1. Function is passed as an argument  
2. Received as a parameter  
3. Invoked using `callback()`

```javascript
function outerFunction(callback) {
  console.log("Before callback")
  callback()
  console.log("After callback")
}

function innerFunction() {
  console.log("Inside callback")
}

outerFunction(innerFunction)
```

---
## How JavaScript Differentiates Callback vs Normal Argument

JavaScript does NOT explicitly differentiate between a callback and a normal argument.

It checks the **type of the value at runtime**.

---

### Key Idea

- If argument is a function → it can be invoked  
- If not → it throws an error  

---

### Example

```javascript
function execute(value) {
  value()
}

execute(() => console.log("I am a callback")) // works
execute(10) // error
```

---

### What Happens Internally

When `value()` runs:

- Function → executes  
- Non-function → TypeError  

```
TypeError: value is not a function
```

---

### Safe Handling

```javascript
function execute(value) {
  if (typeof value === "function") {
    value()
  } else {
    console.log("Not a function")
  }
}
```

---

### Mixed Arguments Example

```javascript
function process(data, callback) {
  console.log(data)

  if (typeof callback === "function") {
    callback()
  }
}

process("Hello", () => console.log("Callback"))
process("Hello", 123)
```

---

### Key Difference

- Normal argument → used as value  
- Callback → used with `()` (invoked)

---

## When to use

- Asynchronous operations (API calls, timers)
- Event handling
- Array methods (map, filter, forEach)
- Reusable logic

---

## When NOT to use

- Deep nesting (callback hell)
- When Promises / async-await are clearer

---

## Behavior

- Callback runs only when invoked
- Can be synchronous or asynchronous
- Execution depends on where it is called

---

## Edge Cases

### 1. Callback is optional but not handled

```javascript
function greet(callback) {
  console.log("Hello")
  callback()
}

greet()
```

### What happens

Error: `callback is not a function`

### Why it is an edge case

Function assumes callback always exists

### Fix

```javascript
function greet(callback) {
  console.log("Hello")
  if (callback) {
    callback()
  }
}
```

---

### 2. Callback executed multiple times unintentionally

```javascript
function process(callback) {
  callback()
  callback()
}
```

### What happens

Callback runs twice

### Why it is an edge case

May cause duplicate actions

---

### 3. Asynchronous execution order confusion

```javascript
console.log("Start")

setTimeout(() => {
  console.log("Callback")
}, 0)

console.log("End")
```

### Output

```
Start
End
Callback
```

### Why it is an edge case

Callback runs later due to event loop

---

### 4. Callback never invoked

```javascript
function main(callback) {
  // forgot to call callback
}

main(() => console.log("Never runs"))
```

### Why it is an edge case

Logic fails silently

---

## Common Mistakes

### ❌ Wrong Code

```javascript
greet(callback())
```

### Why it is a mistake

Function executes immediately instead of being passed

### ✅ Fix

```javascript
greet(callback)
```

### Why the fix works

Passes function reference

---

### ❌ Wrong Code

```javascript
function greet(callback) {
  console.log("Hello")
}

greet(() => console.log("Callback"))
```

### Why it is a mistake

Callback is never executed

### ✅ Fix

```javascript
function greet(callback) {
  console.log("Hello")
  callback()
}
```

### Why the fix works

Explicit invocation

---

### ❌ Wrong Code

```javascript
setTimeout(callback(), 1000)
```

### Why it is a mistake

Executes immediately

### ✅ Fix

```javascript
setTimeout(callback, 1000)
```

### Why the fix works

Schedules execution properly

---

### ❌ Wrong Code

```javascript
function main(cb) {
  cb
}
```

### Why it is a mistake

Function is not executed

### ✅ Fix

```javascript
function main(cb) {
  cb()
}
```

### Why the fix works

Proper invocation

---

### ❌ Wrong Code

```javascript
function greet(cb) {
  console.log("Hello")
  cb
}
```

### Why it is a mistake

Missing parentheses

### ✅ Fix

```javascript
function greet(cb) {
  console.log("Hello")
  cb()
}
```

### Why the fix works

Ensures execution

---

# JavaScript Arrow Functions

Arrow functions provide a shorter syntax for writing functions and behave differently from regular functions in some key ways.

---
## Definition

Arrow functions are a concise way to write functions introduced in ES6. They do **not have their own `this`**, `arguments`, or `prototype`.

---

## Syntax

```javascript
const functionName = () => {
  // code
}
```

---

## Basic Example

```javascript
const greet = () => {
  console.log("Hello")
}

greet() // Hello
```

---

## With Parameters

```javascript
const greet = (name) => {
  console.log("Hello " + name)
}

greet("John") // Hello John
```

---

## Single Parameter (No Parentheses)

```javascript
const greet = name => {
  console.log("Hello " + name)
}
```

---

## Implicit Return (Single Line)

```javascript
const add = (a, b) => a + b

add(2, 3) // 5
```

---

## Returning Object (Important)

```javascript
const getUser = () => ({ name: "John" })
```

---

# Behavior

- Does **not have its own `this`**
- Inherits `this` from surrounding scope (lexical this)
- Cannot be used as constructor (`new` will fail)
- Does not have `arguments` object
- Does not have `prototype`

---

# `this` Behavior (Very Important)

## Regular Function

```javascript
const obj = {
  name: "John",
  greet: function () {
    console.log(this.name)
  }
}

obj.greet() // John
```

---

## Arrow Function

```javascript
const obj = {
  name: "John",
  greet: () => {
    console.log(this.name)
  }
}

obj.greet() // undefined
```

### Why?

- Arrow function does not bind its own `this`
- It takes `this` from the outer scope (likely global)

---

# When to Use

- Short functions  
- Array methods (`map`, `filter`, `reduce`)  
- When you want lexical `this`  

---

# When NOT to Use

- Object methods  
- Constructor functions  
- When `this` is required dynamically  

---

# Comparison: Arrow vs Regular Function

| Feature        | Arrow Function        | Regular Function       |
|----------------|----------------------|------------------------|
| Syntax         | Short                | Verbose                |
| `this`         | Lexical              | Dynamic                |
| `arguments`    | Not available        | Available              |
| Constructor    | ❌ Not allowed       | ✅ Allowed             |
| Prototype      | ❌ Not available     | ✅ Available           |

---

## Arrow Function Hoisting

```javascript
greet() // ❌ Error

const greet = () => {
  console.log("Hello")
}
```

### Why it happens
- Arrow functions are stored in variables  
- Only the variable is hoisted (not initialized)  

---

## Cannot Be Used as Constructor

```javascript
const User = () => {
  this.name = "John"
}

const user = new User() // ❌ Error
```

### Why it is wrong
- Arrow functions do not have constructor behavior  
- No proper `this` binding  

---
%%
## Real Use Case (Lexical `this`)

```javascript
function Timer() {
  this.count = 0

  setInterval(() => {
    this.count++
    console.log(this.count)
  }, 1000)
}
```

### Why it works
- Arrow function inherits `this` from `Timer`  
- Prevents losing context inside callback  
%%
---

# ⚠️ Edge Cases

### Returning Object Without Parentheses

```javascript
const getUser = () => { name: "John" } // ❌ undefined
```

### Why it is wrong
- `{}` is treated as a function body  
- No return statement → returns `undefined`  

### Fix

```javascript
const getUser = () => ({ name: "John" }) // ✅
```

### How it fixes
- Forces JavaScript to treat `{}` as an object  

---

### Using Arrow Function as Object Method

```javascript
const obj = {
  name: "John",
  greet: () => {
    console.log(this.name) // ❌ undefined
  }
}
```

### Why it is wrong
- Arrow function does not have its own `this`  
- `this` refers to outer scope  

### Fix

```javascript
const obj = {
  name: "John",
  greet() {
    console.log(this.name) // ✅
  }
}
```

### How it fixes
- Regular function binds `this` to object  

---
%%
### Using `arguments` Inside Arrow Function

```javascript
const fn = () => {
  console.log(arguments) // ❌ Error
}
```

### Why it is wrong
- Arrow functions do not have `arguments`  

### Fix

```javascript
const fn = (...args) => {
  console.log(args) // ✅
}
```

### How it fixes
- Rest parameters replace `arguments`  
%%
---

# ❌ Common Mistakes

### Using Arrow Function for Methods

```javascript
const obj = {
  name: "John",
  greet: () => console.log(this.name) // ❌
}
```

### Fix

```javascript
const obj = {
  name: "John",
  greet() {
    console.log(this.name) // ✅
  }
}
```

---

### Expecting `arguments` to Work

```javascript
const fn = () => {
  console.log(arguments) // ❌
}
```

### Fix

```javascript
const fn = (...args) => {
  console.log(args) // ✅
}
```

---

# 💡 When to Use

- Cleaner syntax  
- Functional programming  
- Callbacks and inline functions  

---

# JavaScript 'this' keyword

## Definition

The `this` keyword refers to the object that is currently executing the function.

Its value depends on how the function is called, not where it is defined.


## Syntax

~~~javascript
this
~~~

---

## Basic Example

~~~javascript
const user = {
  name: "John",
  greet() {
    console.log(this.name)
  }
}

user.greet()
~~~

### Output

~~~javascript
John
~~~

---

## Additional Examples

### Global Context

~~~javascript
console.log(this)
~~~

### Output (browser)

~~~javascript
window
~~~

---

### Inside Regular Function

~~~javascript
function show() {
  console.log(this)
}

show()
~~~

### Output

~~~javascript
window (non-strict)
undefined (strict mode)
~~~

---

### Arrow Function Behavior

~~~javascript
const obj = {
  value: 20,
  getValue: () => {
    console.log(this.value)
  }
}

obj.getValue()
~~~

### Output

~~~javascript
undefined
~~~

---

## When to use

- Access object properties inside methods  
- Maintain context in OOP  
- Work with dynamic execution context  

## When NOT to use

- Inside arrow functions when object context is needed  
- When `this` creates confusion (prefer explicit variables)  

## Behavior

- Determined at runtime (dynamic binding)  
- Depends on call site  
- Arrow functions do NOT have their own `this`  
- In strict mode, `this` in functions is `undefined`  

---

## Hoisting (only if applicable)

- `this` is not hoisted  
- It is assigned during execution  

---

## Edge Cases

### Losing `this` in Callback

~~~javascript
const obj = {
  name: "John",
  greet() {
    setTimeout(function () {
      console.log(this.name)
    }, 1000)
  }
}

obj.greet()
~~~

### Output

~~~javascript
undefined
~~~

### Why it is an edge case

Callback function loses object context.

---

### Fix

~~~javascript
setTimeout(() => {
  console.log(this.name)
}, 1000)
~~~

### Output

~~~javascript
John
~~~

### Why the fix works

Arrow function inherits `this` from parent scope.

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
const obj = {
  value: 10,
  getValue: () => {
    console.log(this.value)
  }
}

obj.getValue()
~~~

### Output

~~~javascript
undefined
~~~

### Why it is a mistake

Arrow function does not bind `this`.

---

### ✅ Fix

~~~javascript
const obj = {
  value: 10,
  getValue() {
    console.log(this.value)
  }
}

obj.getValue()
~~~

### Output

~~~javascript
10
~~~

### Why the fix works

Regular function binds `this` to object.

---

### ❌ Wrong Code

~~~javascript
function test() {
  console.log(this)
}

test()
~~~

### Output

~~~javascript
window
~~~

### Why it is a mistake

Unexpected global binding.

---

### ✅ Fix

~~~javascript
"use strict"

function test() {
  console.log(this)
}

test()
~~~

### Output

~~~javascript
undefined
~~~

### Why the fix works

Strict mode prevents global binding.

---

### ❌ Wrong Code

~~~javascript
const obj = {
  name: "John",
  greet() {
    const fn = this.greet
    fn()
  }
}

obj.greet()
~~~

### Output

~~~javascript
undefined
~~~

### Why it is a mistake

Function is detached from object.

---

### ✅ Fix

~~~javascript
const fn = this.greet.bind(this)
fn()
~~~

### Output

~~~javascript
John
~~~

### Why the fix works

`bind` preserves context.

---
# JavaScript Call Apply Bind

## Definition

`call`, `apply`, and `bind` are methods used to control the value of `this` in JavaScript functions.

They allow a function to be reused with different objects.

---

## Syntax

### call

~~~javascript
functionName.call(thisArg, arg1, arg2, ...)
~~~

### apply

~~~javascript
functionName.apply(thisArg, [arg1, arg2, ...])
~~~

### bind

~~~javascript
const newFunction = functionName.bind(thisArg, arg1, arg2, ...)
~~~

---

## Basic Example

~~~javascript
function greet() {
  console.log(this.name)
}

const user = { name: "John" }

greet.call(user) // John
~~~

---

## Additional Examples

### call()

#### Definition
Invokes the function immediately with a given `this` value and arguments passed individually.
 
~~~javascript
function greet(age) {
  console.log(this.name + " is " + age)
}

const user = { name: "Alice" }

greet.call(user, 25)
// Alice is 25
~~~

---

### apply()

#### Definition
Invokes the function immediately with a given `this` value and arguments passed as an array.

~~~javascript
function greet(age, city) {
  console.log(this.name + " is " + age + " from " + city)
}

const user = { name: "Bob" }

greet.apply(user, [30, "Chennai"])
// Bob is 30 from Chennai
~~~

---

### bind()

#### Definition
Returns a new function with a fixed `this` value. It does NOT execute immediately.

~~~javascript
function greet(age) {
  console.log(this.name + " is " + age)
}

const user = { name: "Charlie" }

const boundFn = greet.bind(user)

boundFn(28)
// Charlie is 28
~~~

---

## When to use

- When you need to manually control `this`
- Reusing a function across different objects
- Fixing `this` inside callbacks (setTimeout, event handlers)
- Partial application (using bind)

---

## When NOT to use

- When `this` is not involved
- With arrow functions (they ignore call/apply/bind)
- When normal function calls are sufficient

---

## Behavior

- `call` → executes immediately, arguments passed one by one  
- `apply` → executes immediately, arguments passed as array  
- `bind` → returns new function, execution happens later  

---

## Hoisting (only if applicable)

Not applicable.

There is no special hoisting behavior for `call`, `apply`, or `bind`.

They are just methods used at runtime.

Hoisting depends only on how the function is declared:
- Function declaration → hoisted  
- Function expression → not hoisted  

---

## Edge Cases

### Arrow functions ignore call/apply/bind

~~~javascript
const obj = { name: "John" }

const greet = () => {
  console.log(this.name)
}

greet.call(obj) // undefined
~~~

---

%% ### Partial application using bind

~~~javascript
function multiply(a, b) {
  return a * b
}

const double = multiply.bind(null, 2)

double(5) // 10
~~~
 %%

### Partial Application using bind

Partial application means fixing some arguments of a function in advance and creating a new function.
'bind' is not used to bind thisArg but also normal arg

~~~javascript
function multiply(a, b) {
  return a * b;
}

// Fix the first argument (a = 2)
const double = multiply.bind(null, 2); 

// Now only one argument is needed
double(5); // 10
~~~

### Explanation

- `bind` creates a new function
- First argument → `this` (not needed here, so we pass `null`)
- Remaining arguments → pre-filled values

So this line:
~~~javascript
const double = multiply.bind(null, 2);
~~~

means:

- "Create a new function where `a` is always 2"
- The new function only needs `b`

So internally it behaves like:
~~~javascript
function double(b) {
  return multiply(2, b);
}
~~~

---

### Method Borrowing

#### Definition
Using a function from one object with another object by changing `this`.

~~~javascript
const person1 = {
  name: "A"
}

const person2 = {
  name: "B"
}

function greet() {
  console.log(this.name)
}

// Borrowing greet for different objects
greet.call(person1) // A
greet.call(person2) // B
~~~

#### Explanation

- `greet` is not inside any object  
- But using `call`, we "attach" it temporarily to different objects  
- So the same function works for multiple objects  

---

## Comparison: call vs apply vs bind

| Feature        | call                | apply               | bind                     |
|----------------|---------------------|---------------------|--------------------------|
| Execution      | Immediate           | Immediate           | Not immediate            |
| Arguments      | Individual          | Array               | Individual (preset)      |
| Return value   | Function result     | Function result     | New function             |
| Use case       | Direct invocation   | Dynamic arguments   | Reusable function        |

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
greet.bind(user)
~~~

### Why it is a mistake

`bind` does not execute the function.

---

### ✅ Fix

~~~javascript
const fn = greet.bind(user)
fn()
~~~

### Why the fix works

`bind` returns a function which must be called.

---

### ❌ Wrong Code

~~~javascript
greet.apply(user, 25, "Chennai")
~~~

### Why it is a mistake

`apply` requires arguments as an array.

---

### ✅ Fix

~~~javascript
greet.apply(user, [25, "Chennai"])
~~~

### Why the fix works

Arguments are passed correctly as an array.

---

### ❌ Wrong Code

~~~javascript
const greet = () => {
  console.log(this.name)
}

greet.call(user) // greet is an arrow function => this directs to global object
~~~

### Why it is a mistake

Arrow functions do not have their own `this`.

---

### ✅ Fix

~~~javascript
function greet() {
  console.log(this.name)
}

greet.call(user) // 'this' is directs towards the object provided
~~~

### Why the fix works

Regular functions allow dynamic `this`.

---
# Constructor Functions

## Definition

A constructor function is a special type of function used to create multiple objects with the same structure using the `new` keyword.

It acts as a blueprint for creating objects.

---

## Syntax
```javascript
    function FunctionName(param1, param2) {
      this.property = param1
    }

    const obj = new FunctionName(value1, value2)
```




---

## Basic Example
```javascript
    function User(name, age) {
      this.name = name
      this.age = age
    }

    const user1 = new User("John", 25)

    console.log(user1.name)

```

```javascript
```

---

## Additional Examples

```javascript
 function Car(brand, price) {
      this.brand = brand
      this.price = price
    }

    const car1 = new Car("BMW", 50000)
    const car2 = new Car("Audi", 60000)
``` 
---
```javascript
function Person(name) {
      this.name = name
    }

    Person.prototype.greet = function () {
      return "Hello " + this.name
    }

    const p1 = new Person("Sam")
    p1.greet()
  
```
---

## Calling vs Invoking (if applicable)

- Calling a constructor uses `new`
- Invoking without `new` runs it like a normal function

```javascript
   function User(name) {
      this.name = name
    }

    new User("John")
    User("John")

```

---

## How It Works Internally (if applicable)

1. A new empty object is created  
2. `this` is set to that object  
3. Properties are assigned  
4. Object is returned automatically  

---

## When to use

- Creating multiple similar objects  
- Working with prototypes  
- Interview scenarios  

---

## When NOT to use

- Modern apps (use classes)  
- Simple object creation  
- No reuse needed  

---

## Behavior

- Functions are hoisted  
- `this` depends on call  
- `new` ensures correct object creation  
- Prototype enables method sharing  

---

## Edge Cases

### Code

 ``` javascript
    function User(name) {
      this.name = name
      return { name: "Override" }
    }

    const u = new User("John")
    console.log(u.name)
 ```

### What happens

Returned object replaces default object.

### Why it is an edge case

Explicit object return overrides constructor behavior.

---

### Code

```javascript
    function User(name) {
      this.name = name
      return 100
    }

    const u = new User("John")
    console.log(u.name)
```
### What happens

Primitive return is ignored.

### Why it is an edge case

Only objects override return, primitives do not.

---

### Code

```javascript
    function User(name) {
      this.name = name
    }

    const u = new User("John", 25)
    console.log(u.name)
```
### What happens

Extra arguments are ignored.

### Why it is an edge case

JavaScript does not enforce argument count.

---

## Common Mistakes

### ❌ Wrong Code

```javascript
    function user(name) {
      this.name = name
    }

    const u = new user("John")
```

### Why it is a mistake

Constructor naming convention is violated.

### ✅ Fix
```javascript
    function User(name) {
      this.name = name
    }

    const u = new User("John")
```

### Why the fix works

Uppercase naming indicates constructor usage.

---

### ❌ Wrong Code
```javascript
    function User(name) {
      this.name = name
    }

    const u = User("John")
```

### Why it is a mistake

`this` is not bound to a new object.

### ✅ Fix
```javascript
    const u = new User("John")

```
### Why the fix works

`new` creates object and binds `this`.

---

### ❌ Wrong Code

```javascript
    function User(name) {
      this.name = name

      this.greet = function () {
        return "Hello"
      }
    }
```

### Why it is a mistake

Method is recreated for every instance.

### ✅ Fix

```javascript
    function User(name) {
      this.name = name
    }

    User.prototype.greet = function () {
      return "Hello"
    }
```

### Why the fix works

Method is shared across instances using prototype.

---
