-- 코드를 입력하세요
select ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m-%d') as DATETIME
from ANIMAL_INS
order by ANIMAL_ID asc
