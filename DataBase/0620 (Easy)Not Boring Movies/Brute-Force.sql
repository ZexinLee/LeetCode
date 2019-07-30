# Write your MySQL query statement below
SELECT * FROM cinema WHERE id % 2 != 0 and description != 'boring' ORDER BY rating DESC;
