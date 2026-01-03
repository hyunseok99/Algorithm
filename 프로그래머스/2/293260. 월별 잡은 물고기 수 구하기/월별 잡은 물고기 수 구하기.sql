select COUNT(i.id) as FISH_COUNT, MONTH(i.TIME) as MONTH
from FISH_INFO i
group by MONTH(i.TIME)
order by MONTH(i.TIME) asc


