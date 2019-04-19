SELECT
    name,
    description,
    tile,
    colour,
    temperament,
    rating,
    strength,
    intelligence,
    mobility
FROM
    creature
WHERE
    id = ?;
