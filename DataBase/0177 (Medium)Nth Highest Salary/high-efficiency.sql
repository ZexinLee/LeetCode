CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE M INT;
    set M = N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary FROM employee
      ORDER BY salary DESC
      LIMIT 1 OFFSET M
      
  );
END
