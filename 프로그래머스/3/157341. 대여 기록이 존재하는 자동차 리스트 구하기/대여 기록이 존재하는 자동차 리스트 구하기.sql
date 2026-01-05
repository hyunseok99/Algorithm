select distinct(h.CAR_ID)
from CAR_RENTAL_COMPANY_RENTAL_HISTORY h, CAR_RENTAL_COMPANY_CAR c
where c.CAR_ID = h.CAR_ID
and c.CAR_TYPE = '세단'
and h.START_DATE between '2022-10-01' and '2022-10-31'
order by h.CAR_ID desc;

