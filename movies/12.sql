-- Required Problem set 7 by Luis Artavia - movies (12.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 12. In 12.sql , write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
--     ■ Your query should output a table with a single column for the title of each movie.
--     ■ You may assume that there is only one person in the database with the name Bradley Cooper.
--     ■ You may assume that there is only one person in the database with the name Jennifer Lawrence.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 12.sql results in a table with 1 column and 4 rows.


-- $ cat 12.sql | sqlite3 movies.db > output.txt
-- $ cat 12.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

-- SELECT movies.id, movies.title, movies.year FROM movies;
-- SELECT stars.movie_id, stars.person_id FROM stars;
-- SELECT people.id, people.name, people.birth FROM people;



/*
-- Error when executing query: ambiguous column name: stars.movie_id
SELECT movies.title
FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN stars ON stars.person_id = people.id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Bradley Cooper'
AND people.name = 'Jennifer Lawrence';
*/


/*
-- Query did not return results
SELECT movies.title
FROM movies
JOIN stars AS s1 ON s1.movie_id = movies.id
JOIN stars AS s2 ON s2.person_id = people.id
JOIN people ON people.id = s2.person_id
WHERE people.name = 'Bradley Cooper'
AND people.name = 'Jennifer Lawrence';
*/


SELECT movies.title
    FROM movies
        JOIN stars ON stars.movie_id = movies.id
        JOIN people ON people.id = stars.person_id
    WHERE people.name = 'Bradley Cooper'
    AND movies.title IN (
        SELECT movies.title
            FROM movies
                JOIN stars ON stars.movie_id = movies.id
                JOIN people ON people.id = stars.person_id
            WHERE people.name = 'Jennifer Lawrence'
    );
