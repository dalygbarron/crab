SELECT
    tag.category
FROM
    tag
LEFT JOIN -- maybe this should be inner join so it doesn't pick up junk tags I dunno.
    creature
ON
    creature.id = tag.creature
WHERE
    tag.category = ?;
