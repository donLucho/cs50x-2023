-- Required Problem set 7 by Luis Artavia - movies (11.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 11. In 11.sql , write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
--     ■ Your query should output a table with a single column for the title of each movie.
--     ■ You may assume that there is only one person in the database with the name Chadwick Boseman.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 11.sql results in a table with 1 column and 5 rows.


-- $ cat 11.sql | sqlite3 movies.db > output.txt
-- $ cat 11.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

-- SELECT movies.id, movies.title, movies.year FROM movies;
-- SELECT ratings.movie_id, ratings.rating, ratings.votes FROM ratings;
-- SELECT stars.movie_id, stars.person_id FROM stars;
-- SELECT people.id, people.name, people.birth FROM people;


/*
-- Error when executing query: ambiguous column name: stars.movie_id
SELECT movies.title
FROM movies
JOIN ratings ON ratings.movie_id = movies.id
JOIN stars ON stars.movie_id = movies.id
JOIN stars ON stars.person_id = people.id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;
*/


/*
-- expected "42\nBlack Pant...", not "Inception\nInc..."
SELECT movies.title
FROM movies
JOIN ratings ON ratings.movie_id = movies.id
JOIN stars AS s1 ON s1.movie_id = movies.id
JOIN stars AS s2 ON s2.person_id = people.id
JOIN people ON people.id = s2.person_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;
*/

-- whoopsies!
/*
SELECT movies.title
FROM movies
JOIN ratings ON ratings.movie_id = movies.id
JOIN stars ON stars.movie_id = movies.id
-- JOIN stars ON stars.person_id = people.id
-- JOIN people ON people.id = stars.person_id
JOIN people ON stars.person_id = people.id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;
*/


SELECT movies.title
    FROM movies
        JOIN ratings ON ratings.movie_id = movies.id
        JOIN stars ON stars.movie_id = movies.id
        JOIN people ON stars.person_id = people.id
    WHERE people.name = 'Chadwick Boseman'
    ORDER BY ratings.rating DESC
    LIMIT 5;
