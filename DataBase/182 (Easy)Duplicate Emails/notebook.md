# Algorithm
Use GROUP BY or (GROUP BY and HAVING)

Algorithm1:
select Email, count(Email) as num
from Person
group by Email;

Algorithm2:
select Email
from Person
group by Email
having count(Email) > 1;
