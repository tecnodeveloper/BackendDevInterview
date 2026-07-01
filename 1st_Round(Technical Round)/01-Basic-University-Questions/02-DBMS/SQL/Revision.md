# Summary

---

ER-diagram is the visual blueprint of database. It's simply map of your database before building schema
Generalization is like combining multiple classes into one class like bottom up approach  vechicle class is general, car and truck are specific classes
specialization is like breaking general classes into more specific class like top down approach

--- 

primary key is used to identify unique column in table
candidate key is all those column that can be used as uniquely identifier.
foreign key is used for data integrity like if the user is deleted from database then delete her other records like rollno also 
super key is combination of unique identifier and also other column

--- 

select -> is used to retrieve data from database
(astriek * ) -> is used to select all the columns
from -> is used to select from which table
tablename -> just write table name

transaction in sql is like all request are happen if not nothing query will run

---

joins are used to connect two rows from two tables
functional dependency is like if you know A then you C because A knows B just like if you know student rollno then you know his name fatherName.

---

indexing is used to fast the process of data retrieval. if you think of common data that can be retrieved very commonly you can put indexing on them
normalization is used for data integrity. it ensure data consistency, maintainable and scalable.