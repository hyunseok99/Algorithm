# CTE 생성 
with recursive HOURS as(
    select 0 as val
    union all
    select val+1
    from HOURS
    where val < 23
), MINE as(
    select HOUR(a.DATETIME) as HOUR, count(*) as COUNT
    from ANIMAL_OUTS a
    group by HOUR
)

select a.val, coalesce(b.COUNT,0)
from HOURS a
left join MINE b on a.val = b.HOUR ;
