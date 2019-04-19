SELECT
    wall.id,
    wall.description,
    wall.tile,
    _colour.value,
    wall.blockSight,
    wall.blockMove
FROM
    wall
LEFT JOIN
    _colour
ON
    wall.colour = _colour.name;
