select DATE_FORMAT(s.sales_date, '%Y') as YEAR, DATE_FORMAT(s.sales_date, '%c') as MONTH, 
COUNT(DISTINCT(i.user_id)) as PURCHASED_USERS, ROUND(COUNT(DISTINCT(i.user_id))/u.users,1) as PURCHASED_RATIO
from user_info i, online_sale s,
(
    select COUNT(i.user_id) as users 
    from user_info i
    where DATE_FORMAT(i.JOINED, '%Y') = '2021'
) as u
where i.user_id = s.user_id and i.user_id in (s.user_id)
and DATE_FORMAT(i.JOINED, '%Y') = '2021'
group by DATE_FORMAT(s.sales_date, '%Y%m')
order by DATE_FORMAT(s.sales_date, '%Y') asc, DATE_FORMAT(s.sales_date, '%m') asc;

