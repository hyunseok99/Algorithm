select b.MCDP_CD as '진료과 코드', count(*) as '5월예약건수'
from APPOINTMENT b
where b.APNT_NO in (
    select a.APNT_NO
    from APPOINTMENT a
    where DATE_FORMAT(a.APNT_YMD,'%Y-%m') = '2022-05'
)
group by b.MCDP_CD
order by count(*) asc, b.MCDP_CD asc;