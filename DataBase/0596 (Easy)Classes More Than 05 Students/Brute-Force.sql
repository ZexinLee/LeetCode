# Write your MySQL query statement below
SELECT class FROM (SELECT class, count(DISTINCT student) AS num FROM courses GROUP BY class) AS class WHERE num >= 5;
