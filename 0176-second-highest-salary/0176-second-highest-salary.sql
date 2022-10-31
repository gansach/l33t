SELECT 
IFNULL(
    (SELECT DISTINCT salary
        FROM EMPLOYEE
    ORDER BY salary DESC
    LIMIT 1
    OFFSET 1), NULL
) AS SecondHighestSalary
