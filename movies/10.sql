-- Required Problem set 7 by Luis Artavia - movies (10.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023


-- 10. In 10.sql , write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
--     ■ Your query should output a table with a single column for the name of each person.
--     ■ If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 10.sql results in a table with 1 column and 3,392 rows.


-- $ cat 10.sql | sqlite3 movies.db > output.txt
-- $ cat 10.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

-- SELECT movies.id, movies.title, movies.year FROM movies;
-- SELECT directors.movie_id, directors.person_id FROM directors;
-- SELECT people.id, people.name, people.birth FROM people;
-- SELECT ratings.movie_id, ratings.rating, ratings.votes FROM ratings;

-- SELECT COUNT(DISTINCT people.name)

SELECT DISTINCT people.name
    FROM people
        JOIN directors ON directors.person_id = people.id
        JOIN movies ON movies.id = directors.movie_id
        JOIN ratings ON ratings.movie_id = movies.id
    WHERE ratings.rating >= 9.0;
