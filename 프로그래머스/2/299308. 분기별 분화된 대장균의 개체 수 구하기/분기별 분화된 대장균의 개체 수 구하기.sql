-- 16:37
with Tmp as(
    select t.id, (
        case 
            when t.month >= 1 and t.month <= 3 then '1Q'
            when t.month >= 4 and t.month <= 6 then '2Q'
            when t.month >= 7 and t.month <= 9 then '3Q'
            else '4Q'
        end
    ) as 'QUARTER'
    from(
        select id,
            date_format(differentiation_date, '%c') as 'month'
        from ECOLI_DATA
    ) as t
), Res as(
    select '1Q' as QUARTER
    union all
    select '2Q' 
    union all
    select '3Q'
    union all
    select '4Q'
)



select r.QUARTER, count(t.id) as ECOLI_COUNT
from Tmp t
right join Res r on r.QUARTER = t.QUARTER
group by QUARTER;