# Distributed Databases: CAP Theorem and Scaling Strategies

---

# CAP Theorem (Consistency, Availability, and Partition Tolerance)

## Definition

The **CAP Theorem** is a fundamental principle in distributed database systems that states:

> A distributed system can guarantee at most **two out of the following three properties simultaneously**:
> 
> - **Consistency (C)**
>     
> - **Availability (A)**
>     
> - **Partition Tolerance (P)**
>     

In practical distributed systems, when a network partition occurs, a database must choose between **Consistency** and **Availability**.

The theorem helps architects understand the trade-offs involved when designing distributed databases and NoSQL systems.

---

# Why CAP Theorem Exists

Modern applications rarely store data on a single server.

Distributed databases use:

- Multiple servers
    
- Multiple data centers
    
- Geographic replication
    
- High availability architectures
    

However, networks are not perfect.

Problems such as:

- Server failures
    
- Network outages
    
- Data center failures
    
- Communication delays
    

can cause different database nodes to become isolated from each other.

CAP Theorem explains what happens during these failures and what trade-offs a database must make.

---

# Historical Background

The theorem was proposed by:

Eric Brewer

in 2000 and later formally proven by:

- Seth Gilbert
    
- Nancy Lynch
    

Because of this, CAP Theorem is sometimes called:

```text
Brewer's Theorem
```

---

# Mental Model

Imagine a database cluster:

```text
          Client
             |
             V

    +-------------+
    |   Node A    |
    +-------------+
           |
           |
    Network Link
           |
           |
    +-------------+
    |   Node B    |
    +-------------+
```

Normally both nodes communicate.

Now imagine the network cable is cut:

```text
          Client

    +-------------+
    |   Node A    |
    +-------------+

   X Network Failure X

    +-------------+
    |   Node B    |
    +-------------+
```

Both nodes are alive but cannot talk to each other.

The system must decide:

- Reject requests (Consistency)
    
- Accept requests (Availability)
    

It cannot fully guarantee both.

---

# The Three Components

## 1. Consistency (C)

### Definition

Every read receives the most recent write.

After data is updated:

```javascript
db.accounts.updateOne(
  { accountId: 1001 },
  {
    $set: {
      balance: 5000
    }
  }
);
```

All nodes must return:

```javascript
{
  accountId: 1001,
  balance: 5000
}
```

No node should return older data.

### Example

Node A:

```javascript
{
  accountId: 1001,
  balance: 5000
}
```

Node B:

```javascript
{
  accountId: 1001,
  balance: 5000
}
```

Data remains identical.

### Goal

Prevent:

- Dirty reads
    
- Stale data
    
- Conflicting versions
    

---

## 2. Availability (A)

### Definition

Every request receives a response.

Even if some nodes fail:

```javascript
db.products.findOne({
  productId: 500
});
```

must return a result.

The database should not reject requests simply because another node is unavailable.

### Example

Node B is down.

Node A still serves requests:

```javascript
{
  productId: 500,
  stock: 25
}
```

The system remains operational.

### Goal

Keep applications online.

---

## 3. Partition Tolerance (P)

### Definition

The system continues operating despite network communication failures between nodes.

### Example

```text
Node A <----X----> Node B
```

Network partition occurs.

Both nodes continue running.

The system tolerates the partition.

### Goal

Survive network failures.

---

# Understanding the Trade-Off

CAP is often misunderstood.

Many believe:

```text
Choose any two:
C + A
A + P
C + P
```

This is not entirely accurate.

In distributed systems:

```text
Partition Tolerance is mandatory.
```

Networks fail.

Therefore the real decision becomes:

```text
When a partition occurs:

Choose Consistency
or
Choose Availability
```

---

# CAP Models

## CP Systems (Consistency + Partition Tolerance)

### Characteristics

Prioritize:

- Correct data
    
- Data integrity
    
- Strong consistency
    

May reject requests during partitions.

### Example

Banking database:

```javascript
{
  accountId: 1001,
  balance: 10000
}
```

User withdraws:

```javascript
{
  amount: 2000
}
```

During network failure:

```text
Reject operation
```

rather than risk incorrect balances.

### Benefits

- Strong consistency
    
- Accurate data
    
- No stale reads
    

### Drawbacks

- Reduced availability
    
- Requests may fail
    

### Typical Databases

|Database|CAP Style|
|---|---|
|MongoDB (strong consistency settings)|CP|
|HBase|CP|
|ZooKeeper|CP|
|Redis Sentinel (certain modes)|CP|

---

## AP Systems (Availability + Partition Tolerance)

### Characteristics

Prioritize:

- High uptime
    
- Continuous operation
    

Accept temporary inconsistencies.

### Example

E-commerce inventory:

Node A:

```javascript
{
  productId: 200,
  stock: 15
}
```

Node B:

```javascript
{
  productId: 200,
  stock: 14
}
```

During partition:

Both nodes continue serving requests.

Later:

```text
Data synchronization occurs
```

### Benefits

- Always available
    
- High uptime
    
- Better user experience
    

### Drawbacks

- Stale reads possible
    
- Eventual consistency
    

### Typical Databases

|Database|CAP Style|
|---|---|
|Cassandra|AP|
|DynamoDB|AP|
|CouchDB|AP|
|Riak|AP|

---

## CA Systems (Consistency + Availability)

### Characteristics

Provide:

- Consistency
    
- Availability
    

But only when partitions do not occur.

### Example

Single database server:

```javascript
db.users.find()
```

No distributed network exists.

No partition is possible.

### Examples

|Database Type|CAP Style|
|---|---|
|Traditional single-node RDBMS|CA|
|Standalone MySQL|CA|
|Standalone PostgreSQL|CA|

### Important Note

True distributed systems cannot realistically guarantee CA when partitions occur.

---

# Database-Oriented Examples

(Keep all remaining CAP Theorem sections exactly as written in your original document up to the CAP Theorem Conclusion.)

---

# Horizontal Scaling (Sharding) vs Vertical Scaling

## Definition

**Scaling** is the process of increasing a system’s capacity to handle more load (users, requests, or data).

There are two primary approaches:

- **Vertical Scaling (Scale Up)** → Increase power of a single machine
    
- **Horizontal Scaling (Sharding / Scale Out)** → Add more machines and distribute data
    

In simple terms:

- Vertical scaling = make one server stronger
    
- Horizontal scaling = add more servers
    

---

# Why Scaling Concepts Exist

Modern applications face:

- Millions of users
    
- High read/write traffic
    
- Large datasets (TBs to PBs)
    
- Real-time processing needs
    

A single database server cannot handle unlimited load due to:

- CPU limits
    
- Memory limits
    
- Disk I/O bottlenecks
    
- Network throughput constraints
    

Scaling strategies solve these limitations.

---

# Mental Model

Imagine a restaurant:

## Vertical Scaling

```text
One chef → upgraded to super chef
Same kitchen, same workflow
```

## Horizontal Scaling

```text
One restaurant → multiple restaurants
Each handles customers independently
```

---

# Vertical Scaling (Scale Up)

## Definition

Vertical scaling means increasing the capacity of a single server by upgrading hardware.

---

# Horizontal Scaling (Sharding / Scale Out)

## Definition

Horizontal scaling means distributing data across multiple servers (nodes).

This is commonly implemented using **sharding** in NoSQL systems.

---

# Comparison Table

|Feature|Vertical Scaling|Horizontal Scaling|
|---|---|---|
|Approach|Upgrade single machine|Add multiple machines|
|Complexity|Low|High|
|Cost|Expensive at high-end|More cost-efficient long-term|
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