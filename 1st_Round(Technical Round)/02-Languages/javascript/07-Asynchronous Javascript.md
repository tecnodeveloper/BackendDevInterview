# JavaScript Synchronous vs Asynchronous 

## Definition

### Synchronous

Synchronous code executes **line by line**, one after another.  
Each statement waits for the previous one to finish before executing.

---

## Syntax

~~~javascript
statement1
statement2
statement3
~~~

---

## Basic Example

~~~javascript
console.log("Start")

function task() {
  console.log("Task running")
}

task()

console.log("End")
~~~

---

## Execution Flow (Step by Step)

1. `console.log("Start")` → executes  
2. function `task` is defined  
3. `task()` is called → executes  
4. `console.log("End")` → executes  

---

## Output

~~~javascript
Start
Task running
End
~~~

---

## Definition (Asynchronous)

### Asynchronous

Asynchronous code allows certain operations to run **in the background**, without blocking the execution of the next lines.

---

## Syntax

~~~javascript
setTimeout(() => {
  // async code
}, delay)

// Promise
fetch(url).then()

// async/await
async function fn() {
  await something()
}
~~~

---

## Basic Example

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Async Task")
}, 1000)

console.log("End")
~~~

---

## Execution Flow (Step by Step)

1. `console.log("Start")` → executes  
2. `setTimeout` is registered → handled by Web APIs  
3. `console.log("End")` → executes  
4. After delay → callback pushed to queue  
5. Callback is handled by the JavaScript runtime using the Event Loop  
   → For detailed understanding: [[Event Loop]]

---

## Output

~~~javascript
Start
End
Async Task
~~~

---

## Blocking vs Non-Blocking

### Blocking (Synchronous Behavior)

~~~javascript
function heavyTask() {
  for (let i = 0; i < 1e9; i++) {}
  console.log("Done")
}

console.log("Start")
heavyTask()
console.log("End")
~~~

#### Explanation

- `heavyTask` blocks execution  
- "End" waits until loop finishes  

---

### Non-Blocking (Asynchronous Behavior)

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Done")
}, 0)

console.log("End")
~~~

#### Explanation

- Task is deferred  
- Execution continues without waiting  

---

## When to use

### Synchronous

- Simple logic  
- When strict order is required  
- Small and fast operations  

---

### Asynchronous

- API calls  
- File operations  
- Timers  
- Long-running tasks  

---

## When NOT to use

### Synchronous

- Heavy computations (blocks UI / freezes app)  

---

### Asynchronous

- When strict step-by-step execution is required without control  

---

## Behavior

- Synchronous → blocking  
- Asynchronous → non-blocking (handled using Event Loop, Call Stack, and Callback Queue)  
  → See: [[Event Loop]], [[18-Call Stack]], [[Event Queue]]

---

## Edge Cases

### setTimeout with 0 delay

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Async")
}, 0)

console.log("End")
~~~

---

### Why it is an edge case

Even with `0ms`, it does NOT run immediately.  
It waits until the call stack is empty.

---

### Output

~~~javascript
Start
End
Async
~~~

---

### Async return issue

~~~javascript
function getData() {
  let data

  setTimeout(() => {
    data = "Hello"
  }, 1000)

  return data
}

console.log(getData()) // undefined
~~~

---

### Why it is an edge case

Function returns before async task completes.

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Async")
}, 1000)

console.log("End")

// Expected:
// Start
// Async
// End
~~~

### Why it is a mistake

Async code does not block execution.

---

### ✅ Fix

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Async")
  console.log("End")
}, 1000)
~~~

### Why the fix works

Dependent logic is moved inside async callback.

---

### ❌ Wrong Code

~~~javascript
function getData() {
  let data

  setTimeout(() => {
    data = "Hello"
  }, 1000)

  return data
}
~~~

### Why it is a mistake

Returns before async completes.

---

### ✅ Fix

~~~javascript
function getData(callback) {
  setTimeout(() => {
    callback("Hello")
  }, 1000)
}

getData((data) => {
  console.log(data)
})
~~~

### Why the fix works

Uses callback to access result after completion.

---

## Next Step

### Promises

Callbacks can become hard to manage in complex scenarios.

Promises provide a cleaner and more structured way to handle asynchronous operations.

---
# JavaScript Event Queue (Callback Queue)

## Definition

The Event Queue is a data structure that stores callback functions from asynchronous operations that are ready to be executed.

These callbacks wait in the queue until the Call Stack is empty.

---

## Key Concept

- Stores callbacks from async operations  
- Works with the Event Loop  
- Uses FIFO (First In First Out)  
- Executes only when Call Stack is empty  

---

## How It Works

1. Async operation is triggered (e.g., setTimeout, fetch)  
2. Handled by Web APIs  
3. Once completed → callback moves to Event Queue  
4. Event Loop checks if Call Stack is empty  
5. Callback is moved to Call Stack and executed  

---

## Example

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Callback")
}, 0)

console.log("End")
~~~

---

## Output

~~~javascript
Start
End
Callback
~~~

---

## Execution Flow

1. `Start` → Call Stack  
2. `setTimeout` → Web API  
3. `End` → Call Stack  
4. Callback added to Event Queue  
5. Event Loop moves callback → Call Stack  
6. `Callback` executes  

---

## Important Clarification

- Even with `0ms`, callbacks are NOT executed immediately  
- They must wait until the Call Stack is empty  

---
## Nested Async Callback Behavior

Inside an async callback (like `setTimeout`), all synchronous code runs first.

Even if another async function is called inside, it does NOT execute immediately.

The inner async callback is added to the Event Queue and waits for the Call Stack to be empty again.

---

### Example

~~~javascript
setTimeout(() => {
  console.log("A")

  setTimeout(() => {
    console.log("B")
  }, 0)

  console.log("C")
}, 0)
~~~

### Output

~~~javascript
A
C
B
~~~

### Explanation

- "A" runs first  
- Inner `setTimeout` is scheduled and sent to Event Queue  
- "C" runs immediately after (still synchronous inside callback)  
- "B" runs later when Event Loop processes the queue  

---

### Key Point

Execution does NOT pause for nested async calls.  
Each async callback is scheduled separately and handled by the Event Loop.

---

## FIFO Behavior

Callbacks are executed in the order they are added.

~~~javascript
setTimeout(() => console.log("A"), 0)
setTimeout(() => console.log("B"), 0)
~~~

### Output

~~~javascript
A
B
~~~

---

## Event Queue vs Microtask Queue

| Queue Type | Example | Priority |
|-----------|--------|----------|
| Event Queue (Macrotask) | setTimeout, setInterval | Lower |
| Microtask Queue | Promise `.then()`, `.catch()` | Higher |

---

## Example: Priority Difference

~~~javascript
setTimeout(() => console.log("Timeout"), 0)

Promise.resolve().then(() => {
  console.log("Promise")
})
~~~

### Output

~~~javascript
Promise
Timeout
~~~

---

## Why it happens

- Promise callbacks go to Microtask Queue  
- Microtasks run before Event Queue  
- Event Loop prioritizes Microtasks  

---

## Behavior

- Works with Event Loop  
- Executes after Call Stack is empty  
- Lower priority than Microtask Queue  
- Maintains execution order (FIFO)  

---

## Edge Cases

### Multiple async tasks

~~~javascript
setTimeout(() => console.log("A"), 0)
setTimeout(() => console.log("B"), 0)
setTimeout(() => console.log("C"), 0)
~~~

### Output

~~~javascript
A
B
C
~~~

### Why it works

Callbacks are queued and executed in order.

---

## Common Mistakes

### ❌ Wrong Assumption

~~~javascript
setTimeout(() => console.log("A"), 0)
console.log("B")
~~~

### Expected (wrong thinking)

~~~javascript
A
B
~~~

### Actual Output

~~~javascript
B
A
~~~

### Why it is a mistake

Async callbacks always go through Event Queue and wait for Call Stack.

---

## When to use

(Not directly used, but important for understanding)

- Understanding async execution  
- Debugging execution order  
- Handling timing-related issues  

## When NOT to use

- You don’t directly interact with Event Queue  
- It is managed by the JavaScript runtime  

---
## Next Step

### Event Loop

The Event Queue works with the Event Loop to schedule execution of asynchronous tasks.

---
# JavaScript Event Loop

## Definition

The Event Loop is a mechanism in JavaScript that manages the execution of asynchronous operations.

It continuously checks the call stack and the callback queue, and moves tasks to the call stack when it is empty.

---

## Core Components

### Call Stack

- Executes synchronous code  
- Works in LIFO (Last In First Out) order  

→ See: [[18-Call Stack]]


---
### Web APIs

- Handle async operations (setTimeout, fetch, DOM events)  
- Provided by browser / Node.js  

---

### Callback Queue (Event Queue)

- Stores completed async callbacks  
- Example: setTimeout callbacks  

→ See: [[Event Queue]]

---

### Microtask Queue

- Stores Promise callbacks (`.then`, `catch`, `finally`)  
- Higher priority than callback queue  

---

## How Event Loop Works

1. Execute all synchronous code in Call Stack  
2. Async tasks are handled by Web APIs  
3. Once completed → moved to queue  
4. Event Loop checks if Call Stack is empty  
5. Moves tasks from queue → Call Stack  

---

## Example

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Timeout")
}, 0)

Promise.resolve().then(() => {
  console.log("Promise")
})

console.log("End")
~~~

---

## Output

~~~javascript
Start
End
Promise
Timeout
~~~

---

## Execution Flow

1. `Start` → call stack  
2. `setTimeout` → Web API  
3. Promise → Microtask queue  
4. `End` → call stack  
5. Microtasks run → `Promise`  
6. Callback queue → `Timeout`  

---

## Key Concept

- Microtasks (Promises) run BEFORE macrotasks (setTimeout)  
- Event Loop prioritizes Microtask Queue  

---

## When to use

(Not directly used, but important for understanding async behavior)

- Debugging async issues  
- Understanding execution order  
- Handling performance issues  

---

## When NOT to use

- You don’t directly "use" event loop in code  
- It is an internal mechanism  

---

## Behavior

- JavaScript is single-threaded  
- Event Loop enables non-blocking behavior  
- Executes tasks in order based on priority  

---

## Edge Cases

### setTimeout with 0ms

~~~javascript
setTimeout(() => {
  console.log("Hi")
}, 0)
~~~

### Why it is an edge case

It does NOT execute immediately.  
It waits until the call stack is empty.

---

## Common Mistakes

### ❌ Wrong Assumption

~~~javascript
setTimeout(() => console.log("A"), 0)
console.log("B")
~~~

### Output

~~~javascript
B
A
~~~

### Why it is a mistake

setTimeout is asynchronous and goes through the event loop.

---

## Next Step

### Promises

Promises use the microtask queue, which has higher priority in the event loop.

---
# JavaScript Promises

## Definition
  
A Promise is an object that represents the eventual completion (or failure) of an asynchronous operation and its resulting value.    
### Simple Understanding

A promise is an object that represents the result of an asynchronous operation that will be available in the future.

It provides a mechanism to handle success (resolve) or failure (reject) once the operation is completed.

---
## Real Life Analogy

Ordering food in a restaurant:

- You place an order (async operation starts)
- You don’t wait, you do other things
- Waiter promises to bring food
- If successful → food is served (fulfilled)
- If something goes wrong → informed (rejected)

---

## Syntax

~~~javascript
const promise = new Promise((resolve, reject) => {
  // async operation

  if (success) {
    resolve(value)
  } else {
    reject(error)
  }
})
~~~

---

## Basic Example

~~~javascript
const promise = new Promise((resolve, reject) => {
  const success = true

  if (success) {
    resolve("Success")
  } else {
    reject("Error")
  }
})

promise
  .then((result) => {
    console.log(result)
  })
  .catch((error) => {
    console.log(error)
  })
~~~

---
## Consuming a Promise

### then()

Executed when promise is fulfilled.

~~~javascript
promise.then((result) => {
  console.log(result)
})
~~~

---

### catch()

Executed when promise is rejected.

~~~javascript
promise.catch((error) => {
  console.log(error)
})
~~~

---

### finally()

Runs regardless of success or failure.

~~~javascript
promise.finally(() => {
  console.log("Completed")
})
~~~
---

## Additional Examples

### Using setTimeout (Async Simulation)

~~~javascript
const promise = new Promise((resolve) => {
  setTimeout(() => {
    resolve("Data received")
  }, 1000)
})

promise.then((data) => {
  console.log(data)
})
~~~

### Output

~~~javascript
Data received   // after 1 second
~~~

---

## When to use

- Handling asynchronous operations  
- API calls  
- File handling  
- Avoiding callback hell  
- When multiple async tasks need coordination  
## When NOT to use

- Simple synchronous logic  
- When a direct return is enough  
- When async handling is unnecessary  

---

## Behavior

- A Promise has 3 states:
  1. Pending → initial state  
  2. Fulfilled → resolved successfully  
  3. Rejected → operation failed  

- Promises execute immediately when created
- The executor function inside a Promise runs synchronously, but the resolution happens asynchronously

~~~javascript
const promise = new Promise(() => {
  console.log("Running...");
});

console.log("After creation");
~~~

### Output

~~~javascript
Running...
After creation
~~~

- `.then()` runs after the promise is resolved  
- `.catch()` runs if the promise is rejected  
- `.finally()` runs regardless of result  
- Each `.then()` returns a new Promise (important for chaining)

---

## Edge Cases

### Multiple resolve/reject

~~~javascript
const promise = new Promise((resolve, reject) => {
  resolve("First")
  resolve("Second")
  reject("Error")
})

promise.then(console.log).catch(console.log)
~~~
### Explanation

Only the **first call** is considered.  
Subsequent calls are ignored.
### Output

~~~javascript
First
~~~

---
### Missing catch()

~~~javascript
const promise = new Promise((resolve, reject) => {
  reject("Something went wrong")
})

promise.then((res) => {
  console.log(res)
})
~~~

### Explanation

Rejection is not handled, leading to an **Unhandled Promise Rejection**.

### Output

~~~javascript
Uncaught (in promise) Something went wrong
~~~

---
## Common Mistakes

### ❌ Wrong Code

~~~javascript
const promise = new Promise((resolve, reject) => {
  setTimeout(() => {
    return "Data"
  }, 1000)
})
~~~

### Output

~~~javascript
(no output)
~~~

### Why it is a mistake

Returning inside an async function does NOT resolve a Promise.

---
### ✅ Fix

~~~javascript
const promise = new Promise((resolve) => {
  setTimeout(() => {
    resolve("Data")
  }, 1000)
})
~~~

### Output

~~~javascript
Data   // after 1 second
~~~

### Why the fix works

`resolve()` properly sends the value to the Promise.

---
### ❌ Wrong Code

~~~javascript
promise.then((res) => {
  console.log(res)
})

promise.then((res) => {
  console.log(res)
})
~~~
### Output

~~~javascript
Success
Again: Success
~~~

### Why it is a mistake

These `.then()` calls are not chained, so they run independently on the same promise.

Each `.then()` should return a value or another promise to pass data to the next `.then()`.

---

### ✅ Fix

~~~javascript
promise
  .then((res) => {
    console.log(res)
    return res
  })
  .then((res) => {
    console.log("Again:", res)
  })
~~~
### Output

~~~javascript
Success
Again: Success
~~~

### Why the fix works

Chaining ensures proper data flow between steps.

---
### ❌ Wrong Code

~~~javascript
const promise = new Promise((resolve, reject) => {
  const success = false

  if (!success) {
    throw new Error("Something went wrong")
  }

  resolve("Success")
})

promise.then((res) => {
  console.log(res)
})
~~~

### Output

~~~javascript
Uncaught (in promise) Error: Something went wrong
~~~

### Why it is a mistake

The error rejects the Promise, but there is no `.catch()` to handle it.

---

### ✅ Fix

~~~javascript
const promise = new Promise((resolve, reject) => {
  const success = false;

  if (!success) {
    throw new Error("Something went wrong");
  }

  resolve("Success");
});

promise
  .then((res) => {
    console.log(res);
  })
  .catch((err) => {
    console.log(err.message);
  });
~~~

### Why the fix works

Errors inside a Promise automatically reject it, and `.catch()` handles it.

---
## Promise Methods

### Promise.resolve()

Returns a resolved Promise.

~~~javascript
Promise.resolve("Hello").then(console.log)
~~~

---

### Promise.reject()

Returns a rejected Promise.

~~~javascript
Promise.reject("Error").catch(console.log)
~~~

---

### Promise.all()

Waits for all promises to resolve.  
Fails if any one promise rejects.

~~~javascript
Promise.all([p1, p2, p3]).then(console.log)
~~~

---

### Promise.race()

Returns the first settled promise (resolve or reject).

~~~javascript
Promise.race([p1, p2]).then(console.log)
~~~

---

### Promise.allSettled()

Waits for all promises to complete (both resolve and reject).

~~~javascript
Promise.allSettled([p1, p2]).then(console.log)
~~~

---

### Promise.any()

Returns the first fulfilled promise.  
Ignores rejected ones unless all fail.

~~~javascript
Promise.any([p1, p2]).then(console.log)
~~~

---
## Promise Chaining (Intro)

Used to execute multiple asynchronous operations in sequence.

Each `.then()` should return a value or another Promise so the next `.then()` can use it.

### Basic Example

~~~javascript
Promise.resolve(2)
  .then((num) => {
    return num * 2
  })
  .then((num) => {
    console.log(num)
  })
~~~

### Output

~~~javascript
4
~~~


### Why Promise Chaining is Important

When multiple asynchronous operations depend on each other, chaining ensures:

- Clean and readable code  
- Proper execution order  
- No nested callbacks (avoids callback hell)  

### Detailed Explanation

→ Continue: [[Promise Chaining]]

---
## Final Notes

- Promises are a core part of asynchronous JavaScript  
- They help manage async operations cleanly  
- They are the foundation for `async/await`  
- Proper chaining and error handling are critical for real-world applications  

---
# JavaScript Promise Chaining

## Definition

Promise Chaining is a technique used to execute multiple asynchronous operations in sequence, where the result of one step is passed to the next using `.then()`.

Each `.then()` receives the value returned from the previous `.then()`.

---

## Syntax

~~~javascript
promise
  .then((result1) => {
    return result2
  })
  .then((result2) => {
    return result3
  })
  .then((result3) => {
    // final result
  })
  .catch((error) => {
    // handle error
  })
~~~

---

## Basic Example

~~~javascript
Promise.resolve(2)
  .then((num) => {
    return num * 2
  })
  .then((num) => {
    return num * 3
  })
  .then((num) => {
    console.log(num)
  })
~~~

### Output

~~~javascript
12
~~~

---

## How It Works

1. First `.then()` receives `2`
2. Returns `4`
3. Second `.then()` receives `4`
4. Returns `12`
5. Third `.then()` receives `12` and logs it

---

## Key Concept

- Each `.then()` always returns a new Promise
- This is what enables chaining

If nothing is returned, the next `.then()` receives `undefined`.

---

## Example: Missing Return

~~~javascript
Promise.resolve(2)
  .then((num) => {
    num * 2   // no return
  })
  .then((num) => {
    console.log(num)
  })
~~~

### Output

~~~javascript
undefined
~~~

### Explanation

Since the first `.then()` does not return anything, the next `.then()` receives `undefined`.

---

## Returning a Promise

~~~javascript
Promise.resolve(5)
  .then((num) => {
    return new Promise((resolve) => {
      setTimeout(() => resolve(num * 2), 1000)
    })
  })
  .then((result) => {
    console.log(result)
  })
~~~

### Output

~~~javascript
10   // after 1 second
~~~

### Explanation

If a promise is returned, the next `.then()` waits for it to resolve.

---

## When to use

- When multiple async steps depend on each other  
- When output of one operation is needed for the next  
- To avoid nested callbacks (callback hell)  

---

## When NOT to use

- When operations are independent (can run in parallel)  
- When logic becomes too complex (prefer async/await)  

---

## Error Handling in Chain

~~~javascript
Promise.resolve(10)
  .then((num) => {
    return num / 2
  })
  .then((num) => {
    throw new Error("Something broke")
  })
  .then((num) => {
    console.log(num)
  })
  .catch((err) => {
    console.log(err.message)
  })
~~~

### Output

~~~javascript
Something broke
~~~

### Explanation

- Error in any `.then()` skips remaining `.then()`  
- Control jumps directly to `.catch()`  

---

## Edge Cases

### Skipping `.then()`

~~~javascript
Promise.resolve(5)
  .then((num) => num * 2)
  .then()
  .then((num) => console.log(num))
~~~

### Output

~~~javascript
10
~~~

### Why it is an edge case

An empty `.then()` just passes the value to the next `.then()`.

---

### Returning undefined

~~~javascript
Promise.resolve(5)
  .then((num) => {
    return
  })
  .then((num) => {
    console.log(num)
  })
~~~

### Output

~~~javascript
undefined
~~~

### Why it is an edge case

Returning nothing is equivalent to returning `undefined`.

---

## Common Mistakes

### ❌ Wrong Code (Nested then instead of chaining)

~~~javascript
Promise.resolve(2)
  .then((num) => {
    Promise.resolve(num * 2).then((res) => {
      console.log(res)
    })
  })
~~~

### Why it is a mistake

Creates nested structure (callback-style), breaking the chain.

---

### Output

~~~javascript
4
~~~

---

### ✅ Fix

~~~javascript
Promise.resolve(2)
  .then((num) => {
    return Promise.resolve(num * 2)
  })
  .then((res) => {
    console.log(res)
  })
~~~

### Why the fix works

Returning the promise keeps the chain flat and predictable.

---

### Output

~~~javascript
4
~~~

---

### ❌ Wrong Code (Missing return in async chain)

~~~javascript
Promise.resolve(3)
  .then((num) => {
    setTimeout(() => {
      return num * 2
    }, 1000)
  })
  .then((res) => {
    console.log(res)
  })
~~~

### Why it is a mistake

The async operation is not returned, so the chain does not wait.

---

### Output

~~~javascript
undefined
~~~

---

### ✅ Fix

~~~javascript
Promise.resolve(3)
  .then((num) => {
    return new Promise((resolve) => {
      setTimeout(() => resolve(num * 2), 1000)
    })
  })
  .then((res) => {
    console.log(res)
  })
~~~

### Why the fix works

Returning the promise ensures the next `.then()` waits for completion.

---

### Output

~~~javascript
6   // after 1 second
~~~

---
## Next Step  
  
### Async Await  
  
Promise chaining can become hard to read when there are many steps.  
  
`async/await` provides a cleaner and more readable way to handle the same logic.  
  
----
# JavaScript Async Await

## Definition

`async/await` is a modern way to handle asynchronous operations in JavaScript.

It allows you to write asynchronous code that looks and behaves like synchronous code, improving readability and maintainability.

It is built on top of Promises.

---

## Syntax

~~~javascript
async function functionName() {
  const result = await promise
}
~~~

---

## Basic Example

~~~javascript
function getData() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("Data received")
    }, 1000)
  })
}

async function fetchData() {
  const data = await getData()
  console.log(data)
}

fetchData()
~~~

### Output  
  
~~~javascript  
Data received // after 1 second  
~~~


---

## Additional Examples

### Handling Multiple Awaits

~~~javascript
function getUser() {
  return new Promise((resolve) => {
    setTimeout(() => resolve("User"), 1000)
  })
}

function getPosts() {
  return new Promise((resolve) => {
    setTimeout(() => resolve("Posts"), 1000)
  })
}

async function fetchAll() {
  const user = await getUser()
  const posts = await getPosts()

  console.log(user, posts)
}

fetchAll()
~~~

### Output  
  
~~~javascript  
User Posts // after 2 seconds  
~~~  
  
### Note  
  
This runs sequentially (one after another).  
Total time = sum of all awaits (1s + 1s = 2s), because each runs one after another.  

For parallel execution, use `Promise.all()`.

---
### Parallel Execution using Promise.all()

~~~javascript
async function fetchAll() {
  const [user, posts] = await Promise.all([getUser(), getPosts()])
  console.log(user, posts)
}

fetchAll()
~~~

### Output

~~~javascript
User Posts // after 1 second
~~~

### Explanation

Both async operations run in parallel.  
Total time = maximum of all tasks instead of sum.

---
### Using try...catch for Error Handling

~~~javascript
function getData() {
  return new Promise((resolve, reject) => {
    reject("Error occurred")
  })
}

async function fetchData() {
  try {
    const data = await getData()
    console.log(data)
  } catch (error) {
    console.log(error.message)
  }
}

fetchData()
~~~

### Output  
  
~~~javascript  
Error occurred  
~~~

---

## When to use

- Handling asynchronous operations  
- API calls  
- Working with Promises in a cleaner way  
- Sequential async operations  

---

## When NOT to use

- Pure synchronous logic  
- When Promises are not involved  
- For simple one-line async operations where `.then()` is sufficient  

---

## Behavior

- `async` always returns a Promise  
- `await` pauses execution until the Promise resolves  
- Code after `await` runs only after completion  
- `await` pauses execution only inside the async function (non-blocking)  
- It does NOT block the JavaScript thread

---

## Hoisting

`async` function declarations are hoisted like normal functions.

~~~javascript
test()

async function test() {
  return "Hello"
}
~~~

### Output

~~~javascript
Promise {<fulfilled>: "Hello"}
~~~

### Explanation

Async functions are hoisted like normal functions.  
Calling them returns a Promise immediately.


---

## Edge Cases

### Await only works inside async

~~~javascript
function test() {
  const data = await Promise.resolve("Hello")
}
~~~
### Output  
  
~~~javascript  
SyntaxError: await is only valid in async functions  
~~~


### Why it is an edge case

`await` can only be used inside an `async` function.

---

### Async function return value

~~~javascript
async function test() {
  return "Hello"
}

console.log(test())
~~~

### Output

~~~javascript
Promise {<fulfilled>: "Hello"}
~~~

### Why it is an edge case

Even a normal return is wrapped inside a Promise.

---

### Await with non-Promise

~~~javascript
async function test() {
  const value = await 10
  console.log(value)
}

test()
~~~

### Output

~~~javascript
10
~~~

### Why it is an edge case

`await` automatically wraps non-promises into resolved Promises.

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
async function test() {
  const data = getData()
  console.log(data)
}
~~~
### Output  
  
~~~javascript  
Promise {<pending>}  
~~~

### Why it is a mistake

`getData()` returns a Promise, not the resolved value.

---

### ✅ Fix

~~~javascript
async function test() {
  const data = await getData()
  console.log(data)
}
~~~

### Output  
  
~~~javascript  
Data received  
~~~
### Why the fix works

`await` extracts the resolved value from the Promise.

---

### ❌ Wrong Code

~~~javascript
async function test() {
  const data = await getData()
}

test().then((res) => {
  console.log(res)
})
~~~

### Output  
  
~~~javascript  
undefined  
~~~

### Why it is a mistake

Nothing is returned from the async function.

---

### ✅ Fix

~~~javascript
async function test() {
  const data = await getData()
  return data
}

test().then((res) => {
  console.log(res)
})
~~~
### Output  
  
~~~javascript  
Data received  
~~~

### Why the fix works

Returned value is wrapped in a Promise and passed to `.then()`.

---

### ❌ Wrong Code

~~~javascript
async function test() {
  const data = await getData()
  throw new Error("Failed")
}

test()
~~~

### Output  
  
~~~javascript  
Uncaught (in promise) Error: Failed  
~~~

### Why it is a mistake

Error is not handled.

---

### ✅ Fix

~~~javascript
async function test() {
  try {
    const data = await getData()
    throw new Error("Failed")
  } catch (error) {
    console.log(error.message)
  }
}
~~~
### Output  
  
~~~javascript  
Failed  
~~~

### Why the fix works

`try...catch` handles errors in async/await.

---
## Next Step  
  
### Fetch API  
  
`async/await` is commonly used with the Fetch API to handle API requests in a clean and readable way.  
  
It simplifies working with HTTP requests and responses compared to `.then()` chaining.  
  