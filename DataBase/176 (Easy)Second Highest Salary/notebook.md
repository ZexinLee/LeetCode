#### Approach: Using sub-query and `LIMIT` clause [Accepted]

**Algorithm**

Sort the distinct salary in descend order and then utilize the [`LIMIT`](https://dev.mysql.com/doc/refman/5.7/en/select.html) clause to get the second highest salary.

```sql
SELECT DISTINCT
    Salary AS SecondHighestSalary
FROM
    Employee
ORDER BY Salary DESC
LIMIT 1 OFFSET 1
```

However, this solution will be judged as 'Wrong Answer' if there is no such second highest salary since there might be only one record in this table. To overcome this issue, we can take this as a temp table.

**MySQL**

```sql
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;
```

#### Approach: Using `IFNULL` and `LIMIT` clause [Accepted]

Another way to solve the 'NULL' problem is to use `IFNULL` funtion as below.

**MySQL**

```sql
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary
```