-- 코드를 입력하세요
# select b.VIEWS, f.BOARD_ID, f.FILE_ID, f.FILE_NAME, f.FILE_EXT
# from USED_GOODS_FILE f, USED_GOODS_BOARD b
# where f.BOARD_ID = b.BOARD_ID
# and b.VIEWS = (
#   select MAX(VIEWS)
#   from USED_GOODS_BOARD
# )

WITH ResTable AS(
    select f.BOARD_ID, f.FILE_ID, CONCAT('/home/grep/src/', f.BOARD_ID, '/',f.FILE_ID, f.FILE_NAME, f.FILE_EXT) as FILE_PATH
    from USED_GOODS_FILE f, USED_GOODS_BOARD b
    where f.BOARD_ID = b.BOARD_ID
    and b.VIEWS = (
        select MAX(VIEWS)
        from USED_GOODS_BOARD
    )
)

select FILE_PATH
from ResTable
order by FILE_ID desc;
