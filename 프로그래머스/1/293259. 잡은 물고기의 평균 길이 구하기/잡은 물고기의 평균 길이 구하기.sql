select round(avg(b.len),2) as AVERAGE_LENGTH
from (
    select i.ID, coalesce(i.LENGTH, 10) as len
    from FISH_INFO i
    ) as b