# -- 코드를 작성해주세요
# WITH RECURSIVE generation AS(
#     # init
#     SELECT a.ID, a.PARENT_ID, 1 AS LEV, (
#         SELECT COUNT(e.PARENT_ID)
#         FROM ECOLI_DATA e
#         WHERE a.ID = e.PARENT_ID 
#         GROUP BY e.PARENT_ID
#     ) as CHILD
#     FROM ECOLI_DATA a
#     WHERE a.PARENT_ID IS NULL

#     UNION ALL
    
#     # recursion
#     SELECT e.ID, e.PARENT_ID, g.LEV+1, (
#         SELECT COUNT(x.PARENT_ID)
#         FROM ECOLI_DATA x
#         WHERE e.ID = x.PARENT_ID 
#         GROUP BY x.PARENT_ID
#     ) as CHILD
#     FROM ECOLI_DATA e, generation g
#     WHERE g.ID = e.PARENT_ID
# )


# SELECT COUNT(g.ID) as COUNT, g.LEV as GENERATION
# FROM generation g
# WHERE g.CHILD IS NULL
# GROUP By g.LEV
# ORDER BY g.LEV asc;





# 다른 방식: 기존의 세대까지만 구한 후 -> 일반 테이블과 조인해서 갯수 
WITH RECURSIVE generation AS(
    # init
    SELECT ID, 1 as LEV
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    
    UNION ALL
    
    SELECT e.ID, g.LEV+1
    FROM generation g, ECOLI_DATA e
    WHERE e.PARENT_ID = g.ID
)

SELECT COUNT(g.ID) as COUNT,g.LEV as generation
FROM generation g
LEFT JOIN ECOLI_DATA e ON g.ID = e.PARENT_ID
WHERE e.ID IS NULL
GROUP BY g.LEV
ORDER BY g.LEV asc;







