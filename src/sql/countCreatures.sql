-- Technically this does not count creatures but give the highest ID number. This way, if there is a discrepancy in the
-- ID numbers, we will still be able to allocate an array that will accomodate all creatures based on this number.
SELECT
    MAX(id)
FROM
    creature;
