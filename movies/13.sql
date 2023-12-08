-- Required Problem set 7 by Luis Artavia - movies (13.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 13. In 13.sql , write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
--     ■ Your query should output a table with a single column for the name of each person.
--     ■ There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
--     ■ Kevin Bacon himself should not be included in the resulting list.

-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 13.sql results in a table with 1 column and 182 rows.


-- $ cat 13.sql | sqlite3 movies.db > output.txt
-- $ cat 13.sql | sqlite3 movies.db
-- $ sqlite3 movies.db


-- SELECT movies.id, movies.title, movies.year FROM movies;
-- SELECT stars.movie_id, stars.person_id FROM stars;
-- SELECT people.id, people.name, people.birth FROM people;



/*
-- Error when executing query: ambiguous column name: people.name
SELECT people.name
FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Kevin Bacon'
AND people.birth = 1958;
*/


/*
-- expected "James McAvoy\n...", not "Kevin Bacon"
SELECT people.name
FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE people.name = 'Kevin Bacon'
AND people.birth = 1958;
*/


SELECT people.name
    FROM people
        JOIN stars ON stars.person_id = people.id
        JOIN movies ON movies.id = stars.movie_id
    WHERE movies.id IN (
        SELECT movies.id
            FROM movies
                JOIN stars ON stars.movie_id = movies.id
                JOIN people ON people.id = stars.person_id
            WHERE people.name = 'Kevin Bacon'
            AND people.birth = 1958
    )
    AND people.name != 'Kevin Bacon';
