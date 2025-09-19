-- 코드를 작성해주세요
# null인 데이터 1세대 -> 2세대 -> 3세대 

select e3.ID
from ECOLI_DATA e3, (
    select e2.ID
    from ECOLI_DATA e2, (
        select e1.ID
        from  ECOLI_DATA e1
        where e1.PARENT_ID is NULL
    )e1
    where e2.PARENT_ID = e1.ID
)e2
where e3.PARENT_ID = e2.ID
order by e3.ID asc;
