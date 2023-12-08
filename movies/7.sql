-- Required Problem set 7 by Luis Artavia - movies (7.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 7. In 7.sql , write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
--     ■ Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
--     ■ Movies that do not have ratings should not be included in the result.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 7.sql results in a table with 2 columns and 7,085 rows.


-- $ cat 7.sql | sqlite3 movies.db > output.txt
-- $ cat 7.sql | sqlite3 movies.db
-- $ sqlite3 movies.db


-- SELECT movies.id, movies.title, movies.year, ratings.movie_id, ratings.rating, ratings.votes
--   FROM movies
--     JOIN ratings ON movies.id = ratings.movie_id
--       WHERE movies.year = 2010
--       ORDER BY ratings.rating DESC, movies.title ASC;


SELECT movies.title, ratings.rating
    FROM movies
        JOIN ratings ON movies.id = ratings.movie_id
    WHERE movies.year = 2010
    ORDER BY ratings.rating DESC, movies.title ASC;
