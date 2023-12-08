-- Required Problem set 7 by Luis Artavia - movies (9.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 9. In 9.sql , write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
--     ■ Your query should output a table with a single column for the name of each person.
--     ■ People with the same birth year may be listed in any order.
--     ■ No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
--     ■ If a person appeared in more than one movie in 2004, they should only appear in your results once.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 9.sql results in a table with 1 column and 18,946 rows.


-- $ cat 9.sql | sqlite3 movies.db > output.txt
-- $ cat 9.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

-- SELECT movies.id, movies.title, movies.year FROM movies;
-- SELECT stars.movie_id, stars.person_id FROM stars;
-- SELECT people.id, people.name, people.birth FROM people;

-- SELECT COUNT(DISTINCT people.name)

SELECT DISTINCT people.name
    FROM people
        JOIN stars ON stars.person_id = people.id
        JOIN movies ON movies.id = stars.movie_id
    WHERE movies.year = 2004
    ORDER BY people.birth ASC;
