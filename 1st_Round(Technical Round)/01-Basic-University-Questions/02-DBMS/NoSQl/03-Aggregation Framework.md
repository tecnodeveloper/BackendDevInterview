# Aggregation Framework Using Pipelines (`$match`, `$group`, `$sort`)


The **MongoDB Aggregation Framework** is a system that processes documents through a sequence of steps to transform, filter, group, and analyze data stored in a collection.

These steps are called a **pipeline**.

Each stage takes input documents, processes them, and passes the result to the next stage.

Main stages:

- `$match` → filters documents
    
- `$group` → groups documents and calculates values
    
- `$sort` → orders documents
    

Think of it like an assembly line where raw data gets refined step by step.

---

# Why Aggregation Framework Exists

Normal queries are good for fetching data, but real applications need analysis such as:

- Sales reports
    
- Revenue summaries
    
- User statistics
    
- Category-wise totals
    
- Leaderboards
    
- Analytics dashboards
    

Without aggregation:

- Data must be pulled into backend code
    
- Processing happens outside database
    
- More memory and network usage
    

Aggregation fixes this by doing processing inside the database.

---

# Mental Model

Take an `orders` collection:

```javascript
[
  { customer: "Ali", amount: 1000, status: "completed" },
  { customer: "Sara", amount: 2000, status: "completed" },
  { customer: "Ali", amount: 1500, status: "pending" }
]
```

Pipeline flow:

```text
Documents
   ↓
$match
   ↓
$group
   ↓
$sort
   ↓
Final Result
```

Each stage modifies the data before passing it forward.

---

# Basic Aggregation Syntax

```javascript
db.collection.aggregate([
  { stage1 },
  { stage2 },
  { stage3 }
]);
```

Example:

```javascript
db.orders.aggregate([
  { $match: { status: "completed" } },
  { $group: { _id: "$customer", total: { $sum: "$amount" } } },
  { $sort: { total: -1 } }
]);
```

---

# Sample Dataset

We will use this `orders` collection:

```javascript
[
  {
    _id: 1,
    customer: "Ali",
    product: "Laptop",
    category: "Electronics",
    amount: 1200,
    status: "completed"
  },
  {
    _id: 2,
    customer: "Sara",
    product: "Phone",
    category: "Electronics",
    amount: 800,
    status: "completed"
  },
  {
    _id: 3,
    customer: "Ali",
    product: "Mouse",
    category: "Accessories",
    amount: 50,
    status: "pending"
  },
  {
    _id: 4,
    customer: "Ahmed",
    product: "Keyboard",
    category: "Accessories",
    amount: 100,
    status: "completed"
  }
]
```

---

# Stage 1: `$match`

## Purpose

Filters documents based on conditions.

Equivalent to SQL:

```sql
WHERE
```

---

## Syntax

```javascript
{
  $match: {
    field: value
  }
}
```

---

## Example: Completed Orders

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed"
    }
  }
]);
```

---

## Output

```javascript
[
  {
    _id: 1,
    customer: "Ali",
    amount: 1200,
    status: "completed"
  },
  {
    _id: 2,
    customer: "Sara",
    amount: 800,
    status: "completed"
  },
  {
    _id: 4,
    customer: "Ahmed",
    amount: 100,
    status: "completed"
  }
]
```

---

## With Conditions

```javascript
db.orders.aggregate([
  {
    $match: {
      amount: { $gt: 500 }
    }
  }
]);
```

Meaning:

```text
amount > 500
```

---

## Multiple Conditions

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed",
      amount: { $gt: 500 }
    }
  }
]);
```

---

## Key Points

- Filters early in pipeline
    
- Reduces data size
    
- Improves performance
    
- Works like `WHERE` clause
    

---
# `$group`

`$group` is used to **combine multiple documents into groups** and calculate summary values.

It works like SQL:

```sql
GROUP BY
```

---

## Syntax

```javascript
{
  $group: {
    _id: "$fieldName",
    resultField: {
      accumulator: "$field"
    }
  }
}
```

---

## Important Accumulators

|Operator|Meaning|
|---|---|
|`$sum`|total|
|`$avg`|average|
|`$max`|highest value|
|`$min`|lowest value|
|`$push`|collect values (allows duplicates)|
|`$addToSet`|collect unique values|
|`$first`|first value|
|`$last`|last value|

---

# Example 1: Total Sales per Customer

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$customer",
      totalSales: {
        $sum: "$amount"
      }
    }
  }
]);
```

---

## Output

```javascript
[
  { _id: "Ali", totalSales: 1250 },
  { _id: "Sara", totalSales: 800 },
  { _id: "Ahmed", totalSales: 100 }
]
```

---

# Mental Model

Input:

```javascript
[
  { customer: "Ali", amount: 100 },
  { customer: "Ali", amount: 200 },
  { customer: "Sara", amount: 300 }
]
```

Grouping:

```text
Ali  → [100, 200]
Sara → [300]
```

After aggregation:

```text
Ali  → 300
Sara → 300
```

---

# Example 2: Count Orders

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$status",
      totalOrders: {
        $sum: 1
      }
    }
  }
]);
```

---

## Output

```javascript
[
  { _id: "completed", totalOrders: 3 },
  { _id: "pending", totalOrders: 1 }
]
```

---

# Example 3: Average Order Value

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$customer",
      avgAmount: {
        $avg: "$amount"
      }
    }
  }
]);
```

---

# Example 4: Group by Multiple Fields

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: {
        category: "$category",
        status: "$status"
      },
      totalAmount: {
        $sum: "$amount"
      }
    }
  }
]);
```

---

# Key Points — `$group`

- Combines documents into categories
    
- Always requires `_id` (group key)
    
- Supports calculations like sum, avg, count
    
- Can group by single or multiple fields
    
- Memory usage increases with data size
    

---

# Stage 3: `$sort`

## Purpose

`$sort` is used to **arrange documents in order**.

Equivalent to SQL:

```sql
ORDER BY
```

---

## Syntax

```javascript
{
  $sort: {
    field: 1   // ascending
    field: -1  // descending
  }
}
```

---

## Sorting Rules

|Value|Meaning|
|---|---|
|1|Ascending|
|-1|Descending|

---

# Example 1: Sort by Amount (High to Low)

```javascript
db.orders.aggregate([
  {
    $sort: {
      amount: -1
    }
  }
]);
```

---

## Output

```javascript
[
  { amount: 1200 },
  { amount: 800 },
  { amount: 100 },
  { amount: 50 }
]
```

---

# Example 2: Multi-Level Sorting

```javascript
db.orders.aggregate([
  {
    $sort: {
      category: 1,
      amount: -1
    }
  }
]);
```

Meaning:

1. Sort by category (A → Z)
    
2. Inside each category, sort by amount (high → low)
    

---

# Key Points — `$sort`

- Orders final results
    
- Uses 1 (asc) and -1 (desc)
    
- Can sort by multiple fields
    
- Large sorts may use disk if memory is exceeded
    

---

# Full Pipeline Example ($match → $group → $sort)

## Problem

Find top customers based on completed order revenue.

---

## Pipeline

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed"
    }
  },
  {
    $group: {
      _id: "$customer",
      totalRevenue: {
        $sum: "$amount"
      }
    }
  },
  {
    $sort: {
      totalRevenue: -1
    }
  }
]);
```

---

## Step-by-Step Flow

### 1. `$match`

Keeps only completed orders:

```javascript
[
  { customer: "Ali", amount: 1200 },
  { customer: "Sara", amount: 800 },
  { customer: "Ahmed", amount: 100 }
]
```

---

### 2. `$group`

```javascript
[
  { _id: "Ali", totalRevenue: 1200 },
  { _id: "Sara", totalRevenue: 800 },
  { _id: "Ahmed", totalRevenue: 100 }
]
```

---

### 3. `$sort`

```javascript
[
  { _id: "Ali", totalRevenue: 1200 },
  { _id: "Sara", totalRevenue: 800 },
  { _id: "Ahmed", totalRevenue: 100 }
]
```

---

# Real-World Use Cases

---

## 1. E-Commerce Dashboard

```javascript
db.orders.aggregate([
  {
    $match: { status: "completed" }
  },
  {
    $group: {
      _id: "$customer",
      revenue: { $sum: "$amount" }
    }
  },
  {
    $sort: { revenue: -1 }
  }
]);
```

Used for:

- Top customers
    
- Sales ranking
    
- Revenue reports
    

---

## 2. Category Analytics

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$category",
      totalRevenue: { $sum: "$amount" }
    }
  },
  {
    $sort: { totalRevenue: -1 }
  }
]);
```

Used for:

- Product performance
    
- Business insights
    
- Marketing decisions
    

---

# Internal Behavior

## `$match`

- Uses indexes if available
    
- Reduces dataset early
    

---

## `$group`

- Builds groups in memory
    
- Updates accumulators per document
    
- Expensive for large datasets
    

---

## `$sort`

- Sorts final output
    
- May spill to disk for large data
    

---

# Optimization Rule

### Good

```javascript
$match → $group → $sort
```

### Bad

```javascript
$group → $match → $sort
```

Because grouping everything first wastes memory.

---

# Common Mistakes

### 1. Missing `$` in field reference

```javascript
$group: {
  _id: "customer"
}
```

Wrong → treats as string

Correct:

```javascript
_id: "$customer"
```

---

### 2. Wrong sort format

```javascript
$sort: {
  amount: "DESC"
}
```

Wrong

Correct:

```javascript
$sort: {
  amount: -1
}
```

---

### 3. Grouping before filtering

Bad performance pattern.

---

# Key Takeaways

- `$group` creates summaries from data
    
- `$sort` organizes results
    
- `$match` reduces dataset early
    
- Pipelines are executed step-by-step
    
- Order of stages affects performance
    

---

# Final Summary

Aggregation pipelines allow MongoDB to process data efficiently inside the database. `$match` filters data, `$group` performs calculations, and `$sort` arranges results. Together, they form the foundation of reporting systems, analytics dashboards, and business intelligence queries.