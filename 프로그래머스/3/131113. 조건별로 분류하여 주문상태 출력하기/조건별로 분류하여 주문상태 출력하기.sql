select o.ORDER_ID, o.PRODUCT_ID, DATE_FORMAT(o.OUT_DATE, '%Y-%m-%d'), 
(case
    when o.OUT_DATE is null then '출고미정'
    when o.OUT_DATE < '2022-05-02' then '출고완료'
    else '출고대기'
end) as '출고여부'
from FOOD_ORDER o
order by o.ORDER_ID asc;