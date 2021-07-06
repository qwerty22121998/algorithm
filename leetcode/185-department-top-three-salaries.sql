# MYSQL
SELECT d.Name AS Department, e1.Name AS Employee, e1.Salary
FROM Department d
         JOIN Employee e1 ON e1.DepartmentId = d.Id
         JOIN Employee e2 ON e2.DepartmentId = e1.DepartmentId AND e1.Salary <= e2.Salary
GROUP BY d.Id, e1.Name
HAVING COUNT(DISTINCT e2.Salary) <= 3
ORDER BY d.Name, e1.Salary DESC