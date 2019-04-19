SELECT
    floor.id,
    floor.tile,
    _colour.value,
    floor.description
FROM
    floor
LEFT JOIN
    _colour
ON
    floor.colour = _colour.name;
