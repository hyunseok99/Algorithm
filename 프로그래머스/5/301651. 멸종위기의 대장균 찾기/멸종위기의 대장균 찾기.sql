-- 코드를 작성해주세요
WITH RECURSIVE generation AS(
    # init
    SELECT a.ID, a.PARENT_ID, 1 AS LEV, (
        SELECT COUNT(e.PARENT_ID)
        FROM ECOLI_DATA e
        WHERE a.ID = e.PARENT_ID 
        GROUP BY e.PARENT_ID
    ) as CHILD
    FROM ECOLI_DATA a
    WHERE a.PARENT_ID IS NULL

    UNION ALL
    
    # recursion
    SELECT e.ID, e.PARENT_ID, g.LEV+1, (
        SELECT COUNT(x.PARENT_ID)
        FROM ECOLI_DATA x
        WHERE e.ID = x.PARENT_ID 
        GROUP BY x.PARENT_ID
    ) as CHILD
    FROM ECOLI_DATA e, generation g
    WHERE g.ID = e.PARENT_ID
)


SELECT COUNT(g.ID) as COUNT, g.LEV as GENERATION
FROM generation g
WHERE g.CHILD IS NULL
GROUP By g.LEV
ORDER BY g.LEV asc;