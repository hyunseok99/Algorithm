# SELECT *
# FROM (
#     SELECT 
#     CASE
#         WHEN 
#             SUM(CASE WHEN c.NAME = 'Python' THEN 1 ELSE 0 END) > 0 AND
#             SUM(CASE WHEN c.CATEGORY = 'Front End' THEN 1 ELSE 0 END) > 0
#         THEN 'A'
#         WHEN 
#             SUM(CASE WHEN c.NAME = 'C#' THEN 1 ELSE 0 END) > 0
#         THEN 'B'
#         WHEN
#             SUM(CASE WHEN c.CATEGORY = 'Front End' THEN 1 ELSE 0 END) > 0
#         THEN 'C'
#     END as GRADE, d.ID, d.EMAIL
#     FROM DEVELOPERS d, SKILLCODES c
#     WHERE (d.SKILL_CODE & c.CODE) = c.CODE
#     GROUP BY d.ID, d.EMAIL
#     ORDER BY GRADE asc, d.ID asc
# ) x
# WHERE x.GRADE is not NULL

select t.*
from(
    select
        case 
            when sum(if(s.CATEGORY = 'FRONT END', 1, 0)) > 0 and
                sum(if(s.NAME = 'Python', 1, 0)) > 0 then 'A'
            when sum(if(s.NAME = 'C#',1 , 0)) > 0 then 'B'
            when sum(if(s.CATEGORY = 'FRONT END', 1, 0)) > 0 then 'C'
        end as GRADE,
        d.id as ID, d.email as EMAIL
    from DEVELOPERS d
    left join SKILLCODES s on d.SKILL_CODE & s.CODE = s.CODE
    group by d.id, d.email
    order by GRADE asc, ID asc
) as t
where t.GRADE is not null;
