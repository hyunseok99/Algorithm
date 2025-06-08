-- 코드를 입력하세요
select *
from FOOD_PRODUCT
where PRICE in (
    select MAX(f.PRICE) 
    from FOOD_PRODUCT f
)
