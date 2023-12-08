-- Required Problem set 7 by Luis Artavia - movies (1.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 1. In 1.sql , write a SQL query to list the titles of all movies released in 2008.
--     ■ Your query should output a table with a single column for the title of each movie.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 1.sql results in a table with 1 column and 10,050 rows.


-- $ cat 1.sql | sqlite3 movies.db > output.txt
-- $ cat 1.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

SELECT title
    FROM movies
    WHERE year = 2008;
