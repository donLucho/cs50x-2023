-- Required Problem set 7 by Luis Artavia - movies (3.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 3. In 3.sql , write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
--     ■ Your query should output a table with a single column for the title of each movie.
--     ■ Movies released in 2018 should be included, as should movies with release dates in the future.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 3.sql results in a table with 1 column and 88,918 rows.


-- $ cat 3.sql | sqlite3 movies.db > output.txt
-- $ cat 3.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

SELECT title
    FROM movies
    WHERE year >= 2018
    ORDER BY title;
