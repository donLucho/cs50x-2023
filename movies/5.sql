-- Required Problem set 7 by Luis Artavia - movies (5.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 5. In 5.sql , write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
--     ■ Your query should output a table with two columns, one for the title of each movie and one for the release year of each movie.
--     ■ You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 5.sql results in a table with 2 columns and 12 rows.


-- $ cat 5.sql | sqlite3 movies.db > output.txt
-- $ cat 5.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

SELECT title, year
    FROM movies
    WHERE title LIKE 'Harry Potter%'
    ORDER BY year ASC;
