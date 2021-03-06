# Write your MySQL query statement below
SELECT S1.Score, COUNT(DISTINCT S2.Score) Rank
FROM Scores S1, Scores S2
WHERE S1.Score <= S2.Score
GROUP BY S1.Id
ORDER BY S1.Score DESC;
