SELECT
    creature.id,
    creature.name,
    creature.description,
    creature.tile,
    _colour.value,
    creature.temperament,
    creature.rating,
    creature.strength,
    creature.intelligence,
    creature.mobility
FROM
    creature
LEFT JOIN
    _colour
ON
    creature.colour = _colour.name;
