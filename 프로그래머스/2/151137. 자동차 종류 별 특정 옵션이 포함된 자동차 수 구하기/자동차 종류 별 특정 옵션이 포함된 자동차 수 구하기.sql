select c.CAR_TYPE, COUNT(*) as CARS
from CAR_RENTAL_COMPANY_CAR c
where c.CAR_ID in (
    select c2.CAR_ID
    from CAR_RENTAL_COMPANY_CAR c2
    where c2.OPTIONS like '%통풍%' or 
        c2.OPTIONS like '%열선%' or 
        c2.OPTIONS like '%가죽%'
)
group by c.CAR_TYPE
order by c.CAR_TYPE asc;

    
-- find_in_set 이용 