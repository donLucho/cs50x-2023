-- Required Problem set 7 by Luis Artavia - movies (4.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023


-- 4. In 4.sql , write a SQL query to determine the number of movies with an IMDb rating of 10.0.
--     ■ Your query should output a table with a single column and a single row (not counting the header) containing the number of movies with a 10.0 rating.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 4.sql results in a table with 1 column and 1 row.


-- $ cat 4.sql | sqlite3 movies.db > output.txt
-- $ cat 4.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

-- ratings.movie_id, ratings.rating, ratings.votes

SELECT COUNT(movie_id)
    FROM ratings
    WHERE rating = 10.0;
