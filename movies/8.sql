-- Required Problem set 7 by Luis Artavia - movies (8.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023


-- 8. In 8.sql , write a SQL query to list the names of all people who starred in Toy Story.
--     ■ Your query should output a table with a single column for the name of each person.
--     ■ You may assume that there is only one movie in the database with the title Toy Story.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 8.sql results in a table with 1 column and 4 rows.


-- $ cat 8.sql | sqlite3 movies.db > output.txt
-- $ cat 8.sql | sqlite3 movies.db
-- $ sqlite3 movies.db


-- SELECT movies.id, movies.title, movies.year FROM movies;
-- SELECT stars.movie_id, stars.person_id FROM stars;
-- SELECT people.id, people.name, people.birth FROM people;


SELECT people.name
    FROM people
        JOIN stars ON stars.person_id = people.id
        JOIN movies ON stars.movie_id = movies.id
    WHERE movies.title = 'Toy Story';
