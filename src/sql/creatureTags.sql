SELECT
    tag.category
FROM
    tag
INNER JOIN
    creature
ON
    creature.id = tag.creature
WHERE
    tag.category = ?;
