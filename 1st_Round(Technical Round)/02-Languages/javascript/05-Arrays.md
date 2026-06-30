# JavaScript Arrays

Arrays are used to store **multiple values in a single variable**.

```javascript
let numbers = [1, 2, 3, 4]
```

Arrays are a special type of **object** in JavaScript.

---

# 1. Creating Arrays

### Using array literal

**Syntax**

```javascript
let arr = [element1, element2, element3]
```

Example

```javascript
let arr = [1, 2, 3]
```

---

### Using Array constructor

**Syntax**

```javascript
let arr = new Array(element1, element2, element3)
```

Example

```javascript
let arr = new Array(1, 2, 3)
```

---

### Edge Case

```javascript
let arr1 = new Array(3)
console.log(arr1) // [empty × 3]

let arr2 = new Array(1, 2, 3)
console.log(arr2) // [1, 2, 3]
```

If `Array()` gets **one number**, it creates an array with that length.  
If it gets **multiple values**, it creates an array with those values.

Because JavaScript enjoys ambiguity more than it should.

---

# 2. Accessing Elements

Arrays are **zero-indexed**, which means indexing starts from `0`.

**Syntax**

```javascript
arr[index]
```

Example

```javascript
let arr = ["a", "b", "c"]

console.log(arr[0]) // "a"
console.log(arr[2]) // "c"
```

---

### Edge Cases

```javascript
let arr = ["a", "b", "c"]

console.log(arr[5])   // undefined
console.log(arr[-1])  // undefined
```

Normal array indexing does not support negative indexes directly. which usually works in python or other languages , which bring and show the element from last .

---

# 3. Modifying Arrays

Array elements can be changed using their index.

**Syntax**

```javascript
arr[index] = newValue
```

Example

```javascript
let arr = [1, 2, 3]

arr[1] = 10

console.log(arr) // [1, 10, 3]
```

---

### Adding value at a higher index

```javascript
let arr = [1, 2]

arr[5] = 100

console.log(arr) // [1, 2, empty × 3, 100]
console.log(arr.length) // 6
```

This creates **empty slots** in between.

---

# 4. Array Properties

## length

Returns the number of elements up to the highest index + 1.

**Syntax**

```javascript
arr.length
```

Example

```javascript
let arr = [1, 2, 3]

console.log(arr.length) // 3
```

---

### Changing length

```javascript
let arr = [1, 2, 3, 4]

arr.length = 2

console.log(arr) // [1, 2]
```

You can reduce array size by changing `length`.

---

### Edge Case

```javascript
let arr = []
arr[3] = "x"

console.log(arr.length) // 4
```

Length depends on the **highest index**, not just visible values.

---

# 5. Common Array Methods

Arrays have built-in methods to add, remove, search, and modify elements.

## Adding Elements

```javascript
arr.push(4)     // add to end
arr.unshift(0)  // add to beginning
```

## Removing Elements

```javascript
arr.pop()     // remove last
arr.shift()   // remove first
```

## Finding Elements

```javascript
arr.indexOf(2)   // returns index
arr.includes(2)  // returns true/false
```

## Slicing & Splicing

### slice (non-destructive)

```javascript
arr.slice(1, 3) // [2, 3]
```

### splice (destructive)

```javascript
arr.splice(1, 2) // [1,4]
```

For detailed explanation, syntax, and edge cases → [[Array Methods#5. Slicing & Splicing]]

---

# 6. Iterating Arrays

Iteration means going through array elements one by one.

## for loop

**Syntax**

```javascript
for(initialization; condition; update){
  // code
}
```

Example

```javascript
let arr = [10, 20, 30]

for(let i = 0; i < arr.length; i++){
  console.log(arr[i])
}
```

---

## for...of

Used to directly access values.

**Syntax**

```javascript
for(let value of arr){
  // code
}
```

Example

```javascript
let arr = [10, 20, 30]

for(let value of arr){
  console.log(value)
}
```

---

## forEach

Runs a callback for each element.

**Syntax**

```javascript
arr.forEach((item, index) => {
  // code
})
```

Example

```javascript
let arr = [10, 20, 30]

arr.forEach((item, index) => {
  console.log(item, index)
})
```

---

### Important Note

- `for` loop gives full control
- `for...of` is cleaner for values
- `forEach` cannot be stopped using `break` or `continue`

For advanced iteration methods → [[Array Iteration Methods]]

---

# 7. Important Concepts

## Arrays are Objects

```javascript
typeof [] // "object"
```

So arrays are technically objects, but they are used for **ordered collections**.

To correctly check an array:

```javascript
Array.isArray([]) // true
```

---

## Reference Behavior

Arrays are copied by **reference**, not by value.

```javascript
let a = [1, 2]
let b = a

b.push(3)

console.log(a) // [1, 2, 3]
```

Both variables point to the same array in memory.

---

## Empty Slots

```javascript
let arr = new Array(3)

console.log(arr) // [empty × 3]
```

These are not the same as `undefined` values.

### Example

```javascript
let a = [undefined]
let b = new Array(1)

console.log(a) // [undefined]
console.log(b) // [empty × 1]
```

---

## Array Destructuring

Used to extract values into variables.

**Syntax**

```javascript
let [a, b] = arr
```

Example

```javascript
let arr = [10, 20]

let [x, y] = arr

console.log(x) // 10
console.log(y) // 20
```

---

## Spread Operator with Arrays

Used to copy or merge arrays.

```javascript
let a = [1, 2]
let b = [...a, 3]

console.log(b) // [1, 2, 3]
```

This is a **shallow copy**.

---

# 8. Multidimensional Arrays

A multidimensional array is an array that contains **other arrays**.

Example

```javascript
let matrix = [
  [1, 2],
  [3, 4]
]
```

Accessing nested values:

```javascript
console.log(matrix[0][1]) // 2
```

For full explanation → [[05-Multidimensional Arrays]]

---

# 9. Interview Traps

## Comparing arrays

```javascript
[] == []   // false
[] === []  // false
```

Arrays are compared by **reference**, not by value.

---

## typeof array

```javascript
typeof [] // "object"
```

---

## Checking array

```javascript
Array.isArray([]) // true
```

---

## Empty array is truthy

```javascript
if([]){
  console.log("Runs")
}
```

Output

```javascript
Runs
```

Even empty arrays are **truthy**.

---

## Array constructor confusion

```javascript
new Array(5)       // empty array with length 5
new Array("5")     // ["5"]
```

---

# 10. Interview Summary

- Arrays store multiple values in one variable
- Arrays are **zero-indexed**
- Arrays are a special type of **object**
- `length` depends on the highest index
- Arrays are copied by **reference**
- Empty slots are different from `undefined`
- `push/pop` work at the end
- `shift/unshift` work at the beginning
- `slice` is non-destructive
- `splice` is destructive
- Use `Array.isArray()` to check arrays
- Multidimensional arrays are arrays inside arrays

---
# JavaScript Multidimensional Arrays

A multidimensional array is an array that contains **other arrays** as elements.

```javascript
let arr = [
  [1, 2, 3],
  [4, 5, 6]
]
```

This is a **2D array** (array of arrays).

---

# 1. Structure

Think of it like a table:

```
[ [1, 2, 3],
  [4, 5, 6] ]
```

| Index | Value |
|------|------|
| arr[0] | [1,2,3] |
| arr[1] | [4,5,6] |

---

# 2. Accessing Elements

Use **multiple indexes**.

```javascript
let arr = [
  [1, 2, 3],
  [4, 5, 6]
]

console.log(arr[0])     // [1,2,3]
console.log(arr[0][1])  // 2
console.log(arr[1][2])  // 6
```

---

# 3. Modifying Values

```javascript
let arr = [
  [1, 2],
  [3, 4]
]

arr[0][1] = 10

console.log(arr) // [[1,10],[3,4]]
```

---

# 4. Iterating Multidimensional Arrays

### Using nested loops

```javascript
let arr = [
  [1,2],
  [3,4]
]

for(let i = 0; i < arr.length; i++){
  for(let j = 0; j < arr[i].length; j++){
    console.log(arr[i][j])
  }
}
```

---

### Using for...of

```javascript
for(let row of arr){
  for(let value of row){
    console.log(value)
  }
}
```

---

# 5. Adding Elements

### Add new row

```javascript
let arr = [[1,2],[3,4]]

arr.push([5,6])

console.log(arr) // [[1,2],[3,4],[5,6]]
```

---

### Add element inside row

```javascript
arr[0].push(3)

console.log(arr) // [[1,2,3],[3,4]]
```

---

# 6. Common Use Cases

- Matrix representation  
- Grids (game boards, UI layouts)  
- Tables (rows & columns) 

---

# 7. Important Concepts

### Jagged Arrays

Rows can have different lengths.

```javascript
let arr = [
  [1,2],
  [3,4,5]
]
```

Valid in JavaScript.

---

### Reference Behavior

```javascript
let a = [[1,2]]
let b = a

b[0][0] = 99

console.log(a) // [[99,2]]
```

Nested arrays are also **reference types**.

---

# 8. Interview Traps

### Accessing wrong index

```javascript
arr[0][5] // undefined
```

---

### Shallow Copy Issue

```javascript
let arr = [[1,2],[3,4]]

let copy = [...arr]

copy[0][0] = 99

console.log(arr) // [[99,2],[3,4]]
```

Because inner arrays are still referenced.

---

# 9. Interview Summary

- Multidimensional arrays = arrays inside arrays  
- Access using multiple indexes  
- Use nested loops for traversal  
- Arrays can have uneven lengths (jagged arrays)  
- Inner arrays are reference types  
- Shallow copy does NOT clone nested arrays  

---
# JavaScript Array Methods

Array methods are used to **add, remove, search, and transform data** inside arrays.

---

# 1. Adding Elements

### push

**Syntax**

```
arr.push(element1, element2, ...)
```

Adds element(s) to the **end**.

```javascript
let arr = [1,2]

arr.push(3)

console.log(arr) // [1,2,3]
```

---

### unshift

**Syntax**

```
arr.unshift(element1, element2, ...)
```

Adds element(s) to the **beginning**.

```javascript
let arr = [2,3]

arr.unshift(1)

console.log(arr) // [1,2,3]
```

---

# 2. Removing Elements

### pop

**Syntax**

```
arr.pop()
```

Removes last element.

```javascript
let arr = [1,2,3]

let removed = arr.pop()

console.log(removed) // 3
console.log(arr)     // [1,2]
```

---

### shift

**Syntax**

```
arr.shift()
```

Removes first element.

```javascript
let arr = [1,2,3]

let removed = arr.shift()

console.log(removed) // 1
console.log(arr)     // [2,3]
```

---

# 3. Finding Elements

### indexOf

**Syntax**

```
arr.indexOf(value)
```

```javascript
[1,2,3].indexOf(2) // 1
```

---

### includes

**Syntax**

```
arr.includes(value)
```

```javascript
[1,2,3].includes(2) // true
```

---

### find

**Syntax**

```
arr.find(callback)
```

Returns first matching element.

```javascript
[1,2,3,4].find(num => num > 2) // 3
```

---

### Edge Case

```javascript
[NaN].indexOf(NaN)   // -1
[NaN].includes(NaN)  // true
```

Because `indexOf` uses `===`, but `includes` handles `NaN`.

---

# 4. Filtering & Transforming

### map

**Syntax**

```
arr.map(callback)
```

Transforms each element.

```javascript
[1,2,3].map(x => x * 2) // [2,4,6]
```

---

### filter

**Syntax**

```
arr.filter(callback)
```

Returns elements that match condition.

```javascript
[1,2,3,4].filter(x => x > 2) // [3,4]
```

---

### reduce

**Syntax**

```
arr.reduce((accumulator, current) => {}, initialValue)
```

Reduces array to single value.

```javascript
[1,2,3].reduce((acc, curr) => acc + curr, 0) // 6
```

---

### Edge Case (reduce)

```javascript
[].reduce((a,b) => a + b)
// ❌ Error
```

Fix:

```javascript
[].reduce((a,b) => a + b, 0) // 0
```

---

# 5. Slicing & Splicing

## slice() → Non-Destructive (Safe Copy)

### Syntax

```
arr.slice(start, end)
```

---

### Key Points

- Returns a **shallow copy** of part of the array  
- **Does NOT modify** the original array  
- `end` index is **NOT included**  
- Supports **negative indexing**  
- No arguments → returns full copy  

---

### Examples

```javascript
let arr = [1, 2, 3, 4]

arr.slice(1, 3)   // [2, 3]
arr.slice(2)      // [3, 4]
arr.slice()       // [1, 2, 3, 4]
```

---

### Negative Indexing

```javascript
[1,2,3].slice(-1) // [3]
[1,2,3].slice(-2) // [2,3]
```

---

### Edge Cases

```javascript
[1,2,3].slice(5)      // []
[1,2,3].slice(2,1)    // []
[1,2,3].slice(-5, 2)  // [1,2]
```

---

### Mental Model

```
slice → copy without touching original
```

---

## splice() → Destructive (Modify Original)

### Syntax

```
arr.splice(start, deleteCount, item1, item2, ...)
```

---

### Parameters

- `start` → index to begin changes  
- `deleteCount` → number of elements to remove  
- `item1...` → elements to insert 
### Key Points

- **Modifies original array**  
- Returns **removed elements**  
- Can:
  - remove  
  - insert  
  - replace  

---

### Remove Elements

```javascript
let arr = [1,2,3,4]

let removed = arr.splice(1,2)

console.log(removed) // [2,3]
console.log(arr)     // [1,4]
```

---

### Insert Elements

```javascript
let arr = [1,2,3]

arr.splice(1,0,100)

console.log(arr) // [1,100,2,3]
```

---

### Replace Elements

```javascript
let arr = [1,2,3]

arr.splice(1,1,99)

console.log(arr) // [1,99,3]
```

---

### Edge Cases

```javascript
[1,2,3].splice(1)     
// removes [2,3], arr becomes [1]

[1,2,3].splice(-1)    
// removes [3]

[1,2,3].splice(5,1)   
// [], nothing removed

[1,2,3].splice(1,10)  
// removes [2,3]

[1,2,3].splice(1,0)   
// [], no change
```

### Mental Model

```
splice → cut / insert / replace in original array
```

# Final Difference

| Feature | slice | splice |
|--------|------|--------|
| Modifies original | ❌ No | ✅ Yes |
| Returns | Copied portion | Removed elements |
| Use case | Read / copy | Update / mutate |

---
# 6. Other Useful Methods

### concat

**Syntax**

```
arr.concat(array2)
```

```javascript
[1,2].concat([3,4]) // [1,2,3,4]
```

---

### join

**Syntax**

```
arr.join(separator)
```

```javascript
["a","b"].join("-") // "a-b"
```

---

### reverse

```javascript
[1,2,3].reverse() // [3,2,1]
```

⚠️ modifies original

---

### sort

**Syntax**

```
arr.sort(compareFn)
```

```javascript
[3,1,2].sort() // [1,2,3]
```

---

### Edge Case

```javascript
[10,2,5].sort() // [10,2,5]
```

Fix:

```javascript
[10,2,5].sort((a,b) => a - b)
```

---

# 7. Important Concepts

### Destructive Methods

```
push, pop, shift, unshift, splice, reverse, sort
```

---

### Non-Destructive Methods

```
map, filter, slice, concat
```

---

# 8. Interview Summary

- `push/pop` → end  
- `shift/unshift` → start  
- `slice` → safe (no mutation)  
- `splice` → modifies array  
- `map` → transform  
- `filter` → condition  
- `reduce` → single value  
- `sort()` needs compare function  
- `includes` works with `NaN`, `indexOf` does not  

---

# JavaScript Array Iteration Methods

Array iteration methods are used to **loop through arrays and process elements** without writing manual loops.

---

# 1. forEach

### Syntax

```
arr.forEach((item, index, array) => {})
```

---

### Example

```javascript
[1,2,3].forEach((num, index) => {
  console.log(num, index)
})
```

---

### Key Points

- Does **NOT return anything** (`undefined`)
- Used for **side effects** (logging, API calls, DOM updates)
- Cannot use `break` or `continue`
- Always iterates through entire array

---

### Edge Cases

```javascript
let result = [1,2,3].forEach(x => x * 2)

console.log(result) // undefined
```

```javascript
[].forEach(x => console.log(x))
// nothing happens
```

---

### Mental Model

```
forEach → just loop, no return
```

---

# 2. map

### Syntax

```
arr.map((item, index, array) => {})
```

---

### Example

```javascript
let result = [1,2,3].map(num => num * 2)

console.log(result) // [2,4,6]
```

---

### Key Points

- Returns a **new array**
- Output length = input length
- Does NOT modify original array
- Used for **transforming data**

---

### Edge Cases

```javascript
[1,2,3].map(() => {})
// [undefined, undefined, undefined]
```

```javascript
[].map(x => x * 2)
// []
```

```javascript
[1,2,3].map(parseInt)
// [1, NaN, NaN] ❌
```

Reason:

```
map passes (value, index)
parseInt(value, radix)
```

Fix:

```javascript
[1,2,3].map(x => parseInt(x))
```

---

### Mental Model

```
map → same size array, values changed
```

---

# 3. filter

### Syntax

```
arr.filter((item, index, array) => {})
```

---

### Example

```javascript
let result = [1,2,3,4].filter(num => num > 2)

console.log(result) // [3,4]
```

---

### Key Points

- Returns a **new array**
- Output size ≤ input size
- Does NOT modify original
- Used for **selecting data**

---

### Edge Cases

```javascript
[1,2,3].filter(() => true)
// [1,2,3]
```

```javascript
[1,2,3].filter(() => false)
// []
```

```javascript
[].filter(x => x > 2)
// []
```

---

### Mental Model

```
filter → keep what matches condition
```

---

%% # 4. reduce

### Syntax

```
arr.reduce((accumulator, current, index, array) => {}, initialValue)
```

---

### Example (Sum)

```javascript
let sum = [1,2,3].reduce((acc, curr) => acc + curr, 0)

console.log(sum) // 6
```

---

### Example (Object Creation)

```javascript
let arr = ["a", "b"]

let result = arr.reduce((acc, curr) => {
  acc[curr] = true
  return acc
}, {})

console.log(result) // {a: true, b: true}
```

---

### Key Points

- Returns a **single value**
- Most flexible method
- Can return number, object, array, etc.

---

### Edge Cases

```javascript
[].reduce((a,b) => a + b)
// ❌ Error
```

Fix:

```javascript
[].reduce((a,b) => a + b, 0)
```

---

```javascript
[1].reduce((a,b) => a + b)
// 1 (no iteration happens)
```

---

### Important Behavior

If no initial value:

- First element → accumulator
- Loop starts from second element

---

### Step-by-Step Example

```javascript
[1,2,3,4].reduce((acc, curr) => acc + curr, 0)
```

Steps:

```
0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10
```

---

### Mental Model

```
reduce → take many values → produce one result
```
 %%
---

# 4. reduce

### Syntax

```
arr.reduce((accumulator, current, index, array) => {}, initialValue)
```

---

### What is accumulator?

Accumulator = value that stores the result after each step

---

### Example (Sum)

```javascript
[1,2,3,4].reduce((acc, curr) => acc + curr, 0)
```

Steps:

```
acc = 0

0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10
```

Final result → `10`

---

### Example (Find Max)

```javascript
[1,5,2,9].reduce((acc, curr) => {
  return acc > curr ? acc : curr
}, 0)

// 9
```

---

### Example (Count Occurrences)

```javascript
let arr = ["a","b","a"]

let result = arr.reduce((acc, curr) => {
  acc[curr] = (acc[curr] || 0) + 1
  return acc
}, {})

console.log(result)
// {a: 2, b: 1}
```

---

### Important Behavior

If NO initial value:

```javascript
[1,2,3].reduce((a,b) => a + b)
```

Then:

```
acc = first element (1)
loop starts from second element
```

---

### Edge Cases

```javascript
[].reduce((a,b) => a + b)
// ❌ Error
```

Fix:

```javascript
[].reduce((a,b) => a + b, 0)
```

---

### Common Mistake

```javascript
[1,2,3].reduce((acc, curr) => {
  acc + curr
}, 0)
```

Returns:

```
undefined
```

Fix:

```javascript
return acc + curr
```

---

### Mental Model

```
reduce → build something step by step
```

---

### When to use reduce?

Use when:

- you want a **single value**
- you want to build:
  - sum
  - object
  - grouped data
# 5. Key Differences

| Method | Returns | Output Size | Use Case |
|--------|--------|------------|----------|
| forEach | undefined | same | side effects |
| map | new array | same | transform |
| filter | new array | ≤ same | select |
| reduce | single value | 1 | aggregate |

---

# 6. Common Mistakes

### Mistake 1

```javascript
[1,2,3].map(x => { x * 2 })
// [undefined, undefined, undefined]
```

Fix:

```javascript
[1,2,3].map(x => x * 2)
```

---

### Mistake 2

```javascript
forEach used when return is needed ❌
```

Use `map` instead.

---

### Mistake 3

```javascript
reduce without initial value ❌
```

Always safer to provide initial value.

---

# 7. Mutating vs Non-Mutating Methods

### Non-Mutating (Safe)

These return new arrays and do NOT change original:

```
map
filter
reduce
```

Example:

```javascript
let arr = [1,2,3]

let result = arr.map(x => x * 2)

console.log(arr)    // [1,2,3]
console.log(result) // [2,4,6]
```

---

### Mutating (Modify Original)

These change the original array:

```
push, pop, shift, unshift, splice, sort, reverse
```

Example:

```javascript
let arr = [1,2,3]

arr.push(4)

console.log(arr) // [1,2,3,4]
```

---

### Important Note

Iteration methods (`map`, `filter`, `reduce`) are designed to be **non-mutating**.

But…

You *can still mutate manually* inside them:

```javascript
let arr = [1,2,3]

arr.map((x, i, a) => {
  a[i] = x * 2
})

console.log(arr) // [2,4,6] ❗ mutated
```

So:
```
Method → non-mutating  
Your code → can still mutate
```

# 7. Interview Summary

- `forEach` → no return, used for side effects  
- `map` → transform each element  
- `filter` → select elements  
- `reduce` → combine into one value  
- `map(parseInt)` is a common trap  
- Always give initial value in `reduce`  