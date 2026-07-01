# MongoDB Basics & CRUD Operations 

---

# MongoDB Basics

## Definition

**MongoDB** is a NoSQL, document-oriented database that stores data in flexible, JSON-like documents instead of rows and columns.

Unlike traditional relational databases that use tables, MongoDB organizes data into:

- Databases
    
- Collections
    
- Documents
    

MongoDB is designed for:

- High performance
    
- Horizontal scalability
    
- Flexible schemas
    
- Rapid application development
    

---

# Why MongoDB Exists

Traditional relational databases are excellent for structured data, but modern applications often require:

- Rapid development
    
- Frequent schema changes
    
- Large volumes of data
    
- Distributed architectures
    
- High availability
    

MongoDB addresses these challenges by allowing documents to have different structures while maintaining efficient querying and scalability.

---

# Mental Model

Think of MongoDB as a digital filing cabinet.

```text
MongoDB Server
    |
    ├── Database
    |      |
    |      ├── Collection
    |      |      |
    |      |      ├── Document
    |      |      ├── Document
    |      |      └── Document
```

Comparison with a relational database:

|Relational Database|MongoDB|
|---|---|
|Database|Database|
|Table|Collection|
|Row|Document|
|Column|Field|

---

# Core MongoDB Components

## Database

A database contains collections.

Example:

```javascript
companyDB
```

---

## Collection

A collection stores documents.

Example:

```javascript
employees
```

---

## Document

A document is a single record stored as BSON (Binary JSON).

Example:

```javascript
{
  _id: 1,
  name: "Ali",
  department: "IT",
  salary: 75000
}
```

---

# MongoDB Data Structure

## Example Database

### Database

```javascript
companyDB
```

### Collection

```javascript
employees
```

### Documents

```javascript
[
  {
    _id: 1,
    name: "Ali",
    department: "IT",
    salary: 75000
  },
  {
    _id: 2,
    name: "Sara",
    department: "HR",
    salary: 65000
  }
]
```

---

# BSON (Binary JSON)

MongoDB internally stores documents as BSON.

Example Document:

```javascript
{
  _id: ObjectId("507f1f77bcf86cd799439011"),
  name: "Ahmed",
  age: 28,
  active: true,
  joinedDate: new Date()
}
```

BSON supports:

- Strings
    
- Numbers
    
- Arrays
    
- Dates
    
- Boolean values
    
- Nested objects
    
- ObjectIds
    

---

# Creating and Selecting Databases

## Create or Switch Database

```javascript
use companyDB
```

MongoDB creates the database automatically when data is inserted.

---

## View Current Database

```javascript
db
```

Output

```javascript
companyDB
```

---

## List Databases

```javascript
show dbs
```

---

# Creating Collections

## Explicit Collection Creation

```javascript
db.createCollection("employees")
```

---

## Implicit Collection Creation

MongoDB automatically creates collections when data is inserted.

```javascript
db.employees.insertOne({
  name: "Ali"
})
```

---

# CRUD Operations Overview

CRUD stands for:

|Operation|Meaning|
|---|---|
|Create|Insert Data|
|Read|Retrieve Data|
|Update|Modify Data|
|Delete|Remove Data|

---

# Create Documents

## Syntax

```javascript
db.collection.insertOne(document)
```

---

## Example

```javascript
db.employees.insertOne({
  employeeId: 101,
  name: "Ali",
  department: "IT",
  salary: 75000
})
```

---

## Output

```javascript
{
  acknowledged: true,
  insertedId: ObjectId("...")
}
```

---

# Read Documents

## Retrieve All Documents

```javascript
db.employees.find()
```

---

## Find Specific Employee

```javascript
db.employees.find({
  department: "IT"
})
```

---

## Output

```javascript
[
  {
    employeeId: 101,
    name: "Ali",
    department: "IT"
  }
]
```

---

# Update Documents

## Syntax

```javascript
db.collection.updateOne(
  filter,
  update
)
```

---

## Example

Increase salary.

```javascript
db.employees.updateOne(
  {
    employeeId: 101
  },
  {
    $set: {
      salary: 80000
    }
  }
)
```

---

## Output

```javascript
{
  matchedCount: 1,
  modifiedCount: 1
}
```

---

# Delete Documents

## Syntax

```javascript
db.collection.deleteOne(filter)
```

---

## Example

```javascript
db.employees.deleteOne({
  employeeId: 101
})
```

---

## Output

```javascript
{
  deletedCount: 1
}
```

---

# Query Operators

## Equal

```javascript
db.employees.find({
  department: "IT"
})
```

---

## Greater Than

```javascript
db.employees.find({
  salary: {
    $gt: 70000
  }
})
```

---

## Less Than

```javascript
db.employees.find({
  salary: {
    $lt: 90000
  }
})
```

---

## Multiple Conditions

```javascript
db.employees.find({
  department: "IT",
  salary: {
    $gt: 70000
  }
})
```

---

# Working with Nested Documents

## Example Document

```javascript
{
  employeeId: 101,
  name: "Ali",
  address: {
    city: "Lahore",
    country: "Pakistan"
  }
}
```

---

## Query Nested Field

```javascript
db.employees.find({
  "address.city": "Lahore"
})
```

---

# Working with Arrays

## Example Document

```javascript
{
  employeeId: 101,
  name: "Ali",
  skills: [
    "JavaScript",
    "MongoDB",
    "Node.js"
  ]
}
```

---

## Find by Array Value

```javascript
db.employees.find({
  skills: "MongoDB"
})
```

---

# MongoDB Indexes

## Why Indexes Matter

Without indexes:

```javascript
db.employees.find({
  employeeId: 101
})
```

MongoDB scans every document.

---

## Create Index

```javascript
db.employees.createIndex({
  employeeId: 1
})
```

---

## Internal Behavior

Without Index:

```text
Collection Scan
Document 1
Document 2
Document 3
...
```

With Index:

```text
Index Lookup
     |
     V
Matching Document
```

---

# Schema Flexibility

One of MongoDB's key advantages is flexible schemas.

## Document 1

```javascript
{
  employeeId: 101,
  name: "Ali"
}
```

---

## Document 2

```javascript
{
  employeeId: 102,
  name: "Sara",
  department: "HR",
  salary: 60000
}
```

Both can exist in the same collection.

---

# Step-by-Step Example

## Employee Management Database

### Step 1: Create Employee

```javascript
db.employees.insertOne({
  employeeId: 201,
  name: "Ahmed",
  department: "Finance",
  salary: 90000
})
```

---

### Step 2: Read Employee

```javascript
db.employees.find({
  employeeId: 201
})
```

Output

```javascript
[
  {
    employeeId: 201,
    name: "Ahmed",
    department: "Finance"
  }
]
```

---

### Step 3: Update Salary

```javascript
db.employees.updateOne(
  {
    employeeId: 201
  },
  {
    $set: {
      salary: 95000
    }
  }
)
```

---

### Step 4: Delete Employee

```javascript
db.employees.deleteOne({
  employeeId: 201
})
```

---

# Real-World Use Case 1: E-Commerce Product Catalog

## Product Document

```javascript
{
  productId: 5001,
  name: "Laptop",
  category: "Electronics",
  price: 1200,
  specifications: {
    ram: "16GB",
    storage: "512GB SSD"
  }
}
```

---

## Query Products

```javascript
db.products.find({
  category: "Electronics"
})
```

---

## Why MongoDB?

Products often have different attributes.

---

# Real-World Use Case 2: User Profile System

## User Document

```javascript
{
  userId: 101,
  username: "ali123",
  email: "ali@example.com",
  preferences: {
    theme: "dark",
    language: "en"
  }
}
```

---

## Backend Example

```javascript
const user = await db
  .collection("users")
  .findOne({
    userId: 101
  });
```

Used in:

- Web applications
    
- Mobile applications
    
- REST APIs
    

---

# MongoDB vs SQL Databases

|Feature|MongoDB|SQL Database|
|---|---|---|
|Data Model|Document|Table|
|Schema|Flexible|Fixed|
|Scaling|Horizontal|Mostly Vertical|
|Joins|Limited|Strong|
|Data Format|BSON|Rows|
|Development Speed|Fast|Moderate|

--- 
# Common Mistakes  
  
## Mistake 1: Forgetting Update Operators  
  
### Incorrect  
  
```javascript  
db.employees.updateOne(  
{  
employeeId: 101  
},  
{  
salary: 90000  
}  
)  
```  
  
### Problem  
  
Entire document may be replaced.  
  
### Correct  
  
```javascript  
db.employees.updateOne(  
{  
employeeId: 101  
},  
{  
$set: {  
salary: 90000  
}  
}  
)  
```  
  
---  
  
## Mistake 2: Missing Indexes  
  
### Problem  
  
```javascript  
db.employees.find({  
email: "ali@example.com"  
})  
```  
  
can become slow on millions of documents.  
  
### Fix  
  
```javascript  
db.employees.createIndex({  
email: 1  
})  
```  
  
---  
  
## Mistake 3: Using MongoDB Like SQL  
  
### Incorrect Design  
  
```javascript  
{  
customerId: 101  
}  
```  
  
Store everything in separate collections and perform excessive joins.  
  
### Better Design  
  
```javascript  
{  
customerId: 101,  
customerName: "Ali",  
city: "Lahore"  
}  
```  
  
Embed related data when appropriate.  
  
---  
  
# Edge Cases and Pitfalls  
  
## Empty Collection  
  
```javascript  
db.employees.find()  
```  
  
Output:  
  
```javascript  
[]  
```  
  
No error occurs.  
  
---  
  
## Duplicate Data  
  
Without unique indexes:  
  
```javascript  
db.employees.insertOne({  
email: "ali@example.com"  
})  
```  
  
Duplicate emails may occur.  
  
---  
  
## Missing Fields  
  
```javascript  
{  
employeeId: 101  
}  
```  
  
Query:  
  
```javascript  
db.employees.find({  
department: "IT"  
})  
```  
  
Document will not match.  
  
---  
  
# Internal Architecture Overview  
  
MongoDB consists of:  
  
```text  
MongoDB Server  
|  
├── Databases  
|  
├── Collections  
|  
├── Documents  
|  
└── Indexes  
```  
  
Data is stored using:  
  
```text  
BSON Storage Engine  
```  
  
Queries are processed through:  
  
```text  
Query Parser  
|  
Query Optimizer  
|  
Execution Engine  
```  
  
---  
  
# Key Points  
  
- MongoDB is a document-oriented NoSQL database.  
- Data is stored as BSON documents.  
- Collections store documents.  
- Databases store collections.  
- MongoDB supports flexible schemas.  
- CRUD operations are the foundation of MongoDB usage.  
- Indexes improve query performance.  
- Nested documents and arrays are first-class features.  
- Horizontal scaling is supported through sharding.  
- Replication provides high availability.  
  
---  
  
# Interview Summary  
  
### What is MongoDB?  
  
A document-oriented NoSQL database that stores data in BSON documents.  
  
---  
  
### What is a collection?  
  
A group of related documents.  
  
---  
  
### What is a document?  
  
A JSON-like record stored inside a collection.  
  
---  
  
### What is BSON?  
  
Binary JSON format used internally by MongoDB.  
  
---  
  
### Difference Between Collection and Table?  
  
|SQL|MongoDB|  
|---|---|  
|Table|Collection|  
|Row|Document|  
|Column|Field|  
  
---  
  
### How does MongoDB scale?  
  
Using horizontal scaling through sharding.  
  
---  
  
### Why are indexes important?  
  
They allow fast document retrieval without scanning the entire collection.  
  
---  
  
### What are MongoDB's main advantages?  
  
- Flexible schema  
- High scalability  
- Fast development  
- JSON-like document model  
  
---  
  
# Conclusion  
  
MongoDB is a leading NoSQL database designed for flexibility, scalability, and high-performance application development. By organizing data into databases, collections, and BSON documents, MongoDB enables developers to build modern applications that can handle changing requirements, large datasets, and distributed architectures. Understanding collections, documents, CRUD operations, indexes, and schema design forms the foundation for mastering MongoDB and advanced NoSQL concepts.  
  
---  
  
# CRUD Operations in MongoDB (`insertOne`, `find`, `updateMany`, `deleteOne`)  
  
## Definition  
  
**CRUD** stands for:  
  
- **C** → Create  
- **R** → Read  
- **U** → Update  
- **D** → Delete  
  
CRUD operations are the fundamental database operations used to manage data inside a collection.  
  
In MongoDB, CRUD operations allow applications to:  
  
- Store new documents  
- Retrieve existing documents  
- Modify existing documents  
- Remove documents that are no longer needed  
  
Every database-driven application—from e-commerce platforms to social media systems—uses CRUD operations extensively.  
  
---  
  
# Why CRUD Operations Exist  
  
Applications continuously interact with data.  
  
Examples:  
  
|Application|CRUD Activity|  
|---|---|  
|E-Commerce|Create orders, read products, update inventory, delete expired carts|  
|Banking|Create transactions, read balances, update accounts|  
|Social Media|Create posts, read feeds, update profiles, delete comments|  
|School Management|Create students, read records, update grades|  
  
Without CRUD operations, applications would not be able to manage persistent data.  
  
---  
  
# Mental Model  
  
Imagine a collection named `users`.  
  
```javascript  
[  
{  
_id: 1,  
name: "Ali",  
email: "ali@example.com"  
},  
{  
_id: 2,  
name: "Sara",  
email: "sara@example.com"  
}  
]  
```  
  
CRUD operations work like this:  
  
```text  
Create → Add New User  
  
Read → View Users  
  
Update → Modify User Information  
  
Delete → Remove User  
```  
  
---  
  
# Sample Database Collection  
  
## users Collection  
  
```javascript  
[  
{  
_id: 1,  
name: "Ali",  
age: 25,  
city: "Lahore",  
status: "Active"  
},  
{  
_id: 2,  
name: "Sara",  
age: 30,  
city: "Karachi",  
status: "Active"  
},  
{  
_id: 3,  
name: "Ahmed",  
age: 28,  
city: "Lahore",  
status: "Inactive"  
}  
]  
```  
  
---  
  
# CREATE Operation (`insertOne`)  
  
## Purpose  
  
Adds a new document to a collection.  
  
---  
  
## Syntax  
  
```javascript  
db.collection.insertOne(document);  
```  
  
---  
  
## Basic Example  
  
```javascript  
db.users.insertOne({  
name: "Usman",  
age: 27,  
city: "Islamabad",  
status: "Active"  
});  
```  
  
---  
  
## Result  
  
```javascript  
{  
acknowledged: true,  
insertedId: ObjectId("...")  
}  
```  
  
---  
  
## Real-World Example: User Registration  
  
```javascript  
db.users.insertOne({  
username: "john123",  
email: "john@example.com",  
passwordHash: "encryptedPassword",  
createdAt: new Date()  
});  
```  
  
---  
  
# READ Operation (`find`)  
  
## Syntax  
  
```javascript  
db.collection.find(query);  
```  
  
---  
  
## Retrieve All Documents  
  
```javascript  
db.users.find();  
```  
  
---  
  
## Find Specific User  
  
```javascript  
db.users.find({  
name: "Ali"  
});  
```  
  
---  
  
## Multiple Conditions  
  
```javascript  
db.users.find({  
city: "Lahore",  
status: "Active"  
});  
```  
  
---  
  
## Comparison Operators  
  
```javascript  
db.users.find({  
age: {  
$gt: 25  
}  
});  
```  
  
---  
  
## Projection  
  
```javascript  
db.users.find(  
{},  
{  
name: 1,  
city: 1,  
_id: 0  
}  
);  
```  
  
---  
  
# UPDATE Operation (`updateMany`)  
  
## Syntax  
  
```javascript  
db.collection.updateMany(  
filter,  
update  
);  
```  
  
---  
  
## Example  
  
```javascript  
db.users.updateMany(  
{  
city: "Lahore"  
},  
{  
$set: {  
city: "Islamabad"  
}  
}  
);  
```  
  
---  
  
## Increment Values  
  
```javascript  
db.users.updateMany(  
{},  
{  
$inc: {  
age: 1  
}  
}  
);  
```  
  
---  
  
## Add New Field  
  
```javascript  
db.users.updateMany(  
{},  
{  
$set: {  
country: "Pakistan"  
}  
}  
);  
```  
  
---  
  
## Result  
  
```javascript  
{  
acknowledged: true,  
matchedCount: 3,  
modifiedCount: 3  
}  
```  
  
---  
  
# DELETE Operation (`deleteOne`)  
  
## Syntax  
  
```javascript  
db.collection.deleteOne(filter);  
```  
  
---  
  
## Example  
  
```javascript  
db.users.deleteOne({  
name: "Ahmed"  
});  
```  
  
---  
  
## Result  
  
```javascript  
{  
acknowledged: true,  
deletedCount: 1  
}  
```  
  
---  
  
## Dangerous Query  
  
```javascript  
db.users.deleteOne({});  
```  
  
Deletes the first matching document.  
  
Safer:  
  
```javascript  
db.users.deleteOne({  
_id: 3  
});  
```  
  
---  
  
# CRUD Operation Comparison  
  
|Operation|Method|Purpose|Returns|  
|---|---|---|---|  
|Create|`insertOne()`|Add document|Insert result|  
|Read|`find()`|Retrieve documents|Cursor|  
|Update|`updateMany()`|Modify documents|Update result|  
|Delete|`deleteOne()`|Remove document|Delete result|  
  
---  
  
# CRUD vs SQL  
  
|SQL|MongoDB|  
|---|---|  
|INSERT|`insertOne()`|  
|SELECT|`find()`|  
|UPDATE|`updateMany()`|  
|DELETE|`deleteOne()`|  
  
---  
  
# Common CRUD Mistakes  
  
|Mistake|Problem|Fix|  
|---|---|---|  
|Missing `$set`|Replaces document|Use `$set`|  
|Empty delete filter|Deletes unintended data|Use specific filters|  
|No indexes|Slow queries|Create indexes|  
|Assuming `find()` returns array|Returns cursor|Use `.toArray()`|  
|Ignoring update result|Hard to verify changes|Check `modifiedCount`|  
  
---  
  
# Performance Considerations  
  
## Create Index  
  
```javascript  
db.users.createIndex({  
email: 1  
});  
```  
  
Good Query:  
  
```javascript  
db.users.find({  
email: "ali@example.com"  
});  
```  
  
Poor Query without index:  
  
```javascript  
db.users.find({  
age: {  
$gt: 20  
}  
});  
```  
  
---  
  
# Vertical vs Horizontal Scaling  
  
|Feature|Vertical Scaling|Horizontal Scaling|  
|---|---|---|  
|Approach|Upgrade single machine|Add multiple machines|  
|Complexity|Low|High|  
|Cost|Expensive at high-end|More cost-efficient|  
|Downtime Risk|High|Low|  
|Scalability Limit|Hardware bound|Nearly unlimited|  
|Failure Impact|Single point of failure|Distributed failure handling|  
|Setup Difficulty|Easy|Complex|  
  
---  
  
# Interview Summary  
  
### What is vertical scaling?  
  
Increasing the power of a single server by upgrading CPU, RAM, or storage.  
  
### What is horizontal scaling?  
  
Adding more servers and distributing data across them.  
  
### What is sharding?  
  
A horizontal scaling technique that splits data across multiple database nodes.  
  
### Which is more scalable?  
  
Horizontal scaling.  
  
### What is a shard key?  
  
A field used to determine how data is distributed across shards.  
  
### Main disadvantage of horizontal scaling?  
  
Complexity in setup, maintenance, and query routing.  
  
---  
  
# Final Combined Conclusion  
  
CAP Theorem and Scaling Strategies are two of the most important concepts in distributed database design.  
  
- CAP Theorem explains trade-offs between Consistency, Availability, and Partition Tolerance during network failures.  
- Vertical Scaling increases the power of a single machine.  
- Horizontal Scaling distributes data and workload across multiple machines.  
- Modern distributed databases often combine horizontal scaling with CAP-aware architecture decisions.  
- Understanding both concepts helps architects design systems that balance correctness, scalability, fault tolerance, and performance.