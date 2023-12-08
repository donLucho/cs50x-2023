-- Required Problem set 7 by Luis Artavia - movies (6.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 6. In 6.sql , write a SQL query to determine the average rating of all movies released in 2012.
--     ■ Your query should output a table with a single column and a single row (not counting the header) containing the average rating.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 6.sql results in a table with 1 column and 1 row.


-- $ cat 6.sql | sqlite3 movies.db > output.txt
-- $ cat 6.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

-- SELECT movies.id, movies.title, movies.year FROM movies WHERE year = 2012;
-- SELECT ratings.movie_id, ratings.rating, ratings.votes FROM ratings;

-- SELECT movies.id, movies.title, movies.year, ratings.movie_id, ratings.rating, ratings.votes
--   FROM movies
--     JOIN ratings ON movies.id = ratings.movie_id
--       WHERE year = 2012;

SELECT AVG(ratings.rating)
    FROM movies
        JOIN ratings ON movies.id = ratings.movie_id
    WHERE year = 2012;
