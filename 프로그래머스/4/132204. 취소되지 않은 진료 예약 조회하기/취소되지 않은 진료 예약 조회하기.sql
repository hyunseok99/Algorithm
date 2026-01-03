select a.APNT_NO, p.PT_NAME, a.PT_NO, a.MCDP_CD, d.DR_NAME, a.APNT_YMD
from APPOINTMENT a, PATIENT p, DOCTOR d
where a.MCDP_CD = 'CS' and a.APNT_CNCL_YN = "N" and DATE_FORMAT(a.APNT_YMD, '%Y%m%d') = '20220413'
and p.PT_NO = a.PT_NO and a.MDDR_ID = d.DR_ID
order by a.APNT_YMD asc;
