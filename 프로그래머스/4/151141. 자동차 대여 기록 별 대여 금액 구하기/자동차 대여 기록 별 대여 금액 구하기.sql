-- 코드를 입력하세요
select a.history_id, 
    (
    CASE
        WHEN a.dur < 7 THEN a.price
        WHEN a.dur < 30 THEN ROUND(a.price * (
            select (100 -p.DISCOUNT_RATE)/100 
            from CAR_RENTAL_COMPANY_DISCOUNT_PLAN p 
            WHERE p.duration_type = "7일 이상" and p.car_type = "트럭"
        ), 0)
        WHEN a.dur < 90 THEN ROUND(a.price * (
                select (100 -p.DISCOUNT_RATE)/100 
                from CAR_RENTAL_COMPANY_DISCOUNT_PLAN p 
                WHERE p.duration_type = "30일 이상" and p.car_type = "트럭"
        ), 0)
        WHEN a.dur >= 90 THEN ROUND(a.price * (
            select (100 -p.DISCOUNT_RATE)/100 
            from CAR_RENTAL_COMPANY_DISCOUNT_PLAN p 
            WHERE p.duration_type = "90일 이상" and p.car_type = "트럭"
        ), 0)
    END
    ) as FEE
from
(
    select h.HISTORY_ID, datediff(h.END_DATE,h.START_DATE) + 1 as dur, (datediff(h.END_DATE,h.START_DATE) + 1)*c.DAILY_FEE as price
    from CAR_RENTAL_COMPANY_CAR c, CAR_RENTAL_COMPANY_RENTAL_HISTORY h
    where c.CAR_ID = h.CAR_ID
    and c.CAR_TYPE = "트럭"
) as a
order by Fee desc, a.HISTORY_ID desc;


