-- 15:36~
WITH T AS(
    SELECT e.id,
        rank() over(order by e.SIZE_OF_COLONY desc) as ran,
        count(e.id) over() as cnt
    FROM ECOLI_DATA e
)

select T.id,
    case 
        when (T.ran/T.cnt) <= 0.25 then 'CRITICAL'
        when (T.ran/T.cnt) <= 0.5 then 'HIGH'
        when (T.ran/T.cnt) <= 0.75 then 'MEDIUM'
        else 'LOW'
    end as 'COLONY_NAME'
from T
order by T.id asc;


