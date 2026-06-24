# Exception Handling 

**Exception handling** in C++ is a mechanism to handle **runtime errors** (unexpected situations) in a controlled way, preventing program crashes.

---
## Mental Model

Think of exception handling like a **safety net**:

- Code runs normally
- If something goes wrong → control jumps to handler
- Program recovers instead of crashing
- It allows you to separate **error-handling code** from normal logic.

---

## Core Syntax 

```javascript
try {
  // risky code thow error to catch block
} catch (error) {
  // handle error
} finally {
  // always runs (optional)
}
```

---

## C++ Equivalent Keywords

- `try` → block of code to monitor
- `throw` → signal an error
- `catch` → handle the error

---

## Step-by-Step Execution

1. Code enters `try` block    
2. Error condition detected
3. `throw` is executed
4. Control jumps to `catch`
5. Error is handled


---

## Key Points

- `try` → risky code
- `throw` → generate error
- `catch` → handle error

---

## Comparison: Exceptions vs Error Codes

|Feature|Exceptions|Error Codes|
|---|---|---|
|Readability|High|Low|
|Flow control|Automatic|Manual|
|Error handling|Centralized|Scattered|

---

### Common Questions:

- What is exception handling?
- What happens when exception is thrown?
- What is stack unwinding?
- Can constructors throw exceptions?

---

## Interview Summary

- Exception handling manages runtime errors
- Uses `try`, `throw`, `catch`
- Prevents crashes and improves reliability
- Works with RAII for automatic cleanup

---

## Final Mental Model

- `try` → “attempt this”
- `throw` → “something went wrong”
- `catch` → “handle the problem”

--- 
# Friend Function (interview only)

A **friend function** is a special function that is **not a member of a class**, but it has **access to private and protected members** of that class.

---
##  Mental Model

Think of a **VIP guest pass in a secure building**:

- Normal people → cannot enter restricted rooms (private data)
- Friend function → special pass → can access restricted areas
- Still not a resident (not a class member)
- Use friend functions only when necessary
- Prefer getters/setters or public APIs

---

#  Friend Function vs Member Function

| Feature             | Member Function    | Friend Function            |
| ------------------- | ------------------ | -------------------------- |
| Belongs to class    | Yes                | No                         |
| Access private data | Yes                | Yes                        |
| Uses `this` pointer | Yes                | No                         |
| Encapsulation       | Maintains strictly | Breaks controlled boundary |
| Use case            | Core behavior      | Utility / special access   |

---

#  Interview Tips

- Friend function = **controlled violation of encapsulation**
- Friend function is NOT a member
- Common use case = **operator overloading**
- It is not inherited and not part of class scope
- No `this` pointer exists
---

#  Final Mental Model

- Encapsulation → strict access control
- Friend function → **controlled exception mechanism**

> “A trusted outsider with full access to private internals”

---