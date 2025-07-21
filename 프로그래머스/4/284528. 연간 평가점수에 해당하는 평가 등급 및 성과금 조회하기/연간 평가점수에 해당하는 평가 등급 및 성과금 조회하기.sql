WITH GRADE_TABLE AS (
    SELECT g.EMP_NO,
        CASE
            WHEN (SUM(g.SCORE) >= 192) THEN 'S'
            WHEN (SUM(g.SCORE) >= 180) THEN 'A'
            WHEN (SUM(g.SCORE) >= 160) THEN 'B'
            ELSE 'C'
        END as GRADE
    FROM HR_GRADE g
    GROUP BY g.EMP_NO
)
select DISTINCT(e.EMP_NO), e.EMP_NAME, g.GRADE,
    CASE
        WHEN g.GRADE = 'S' THEN 0.2
        WHEN g.GRADE = 'A' THEN 0.15
        WHEN g.GRADE = 'B' THEN 0.10
        ELSE 0
    END * e.SAL as BONUS
from GRADE_TABLE g, HR_EMPLOYEES e
where g.EMP_NO = e.EMP_NO
order by e.EMP_NO;