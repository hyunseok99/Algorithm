# select a.CAR_ID, a.START_DATE
#         from (
#                 select *
#                 from CAR_RENTAL_COMPANY_RENTAL_HISTORY c
#                 where DATE_FORMAT(c.START_DATE, '%Y%c') >= '20228' and 
#                 DATE_FORMAT(c.START_DATE, '%Y%c')  <= '202210'
#              ) a
#         group by a.CAR_ID
#         having count(a.CAR_ID) >= 5
# order by a.CAR_ID desc;
# select *
#     from CAR_RENTAL_COMPANY_RENTAL_HISTORY c
#     where (DATE_FORMAT(c.START_DATE, '%Y-%m-d') >= '2022-08') and 
#     (DATE_FORMAT(c.START_DATE, '%Y-%m-d')  < '2022-11');

select MONTH(c2.START_DATE) as MONTH, c2.CAR_ID, COUNT(*) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY c2
where c2.CAR_ID in (
        select c.CAR_ID
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY c
        where (DATE_FORMAT(c.START_DATE, '%Y-%m') >= '2022-08') and 
        (DATE_FORMAT(c.START_DATE, '%Y-%m')  < '2022-11')
        group by c.CAR_ID 
        having count(c.CAR_ID) >= 5
    ) 
and (DATE_FORMAT(c2.START_DATE, '%Y-%m') >= '2022-08') 
and (DATE_FORMAT(c2.START_DATE, '%Y-%m')  < '2022-11')
group by DATE_FORMAT(c2.START_DATE, '%c'), c2.CAR_ID
order by MONTH asc, c2.CAR_ID desc;
 
 
# select * from  CAR_RENTAL_COMPANY_RENTAL_HISTORY c order by car_id desc;
