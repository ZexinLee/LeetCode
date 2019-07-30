# Write your MySQL query statement below
SELECT Email FROM (SELECT Email, count(Email) as num FROM Person GROUP BY Email) as Email WHERE num > 1;
