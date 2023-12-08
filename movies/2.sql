-- Required Problem set 7 by Luis Artavia - movies (2.sql)
-- draft processed on: September 17, 2023
-- submitted for grade on: September 17, 2023

-- 2. In 2.sql , write a SQL query to determine the birth year of Emma Stone.
--     ■ Your query should output a table with a single column and a single row (not counting the header) containing Emma Stone’s birth year.
--     ■ You may assume that there is only one person in the database with the name Emma Stone.


-- If you’re using the movies.db database provided in this problem set’s distribution, you should find that:
--     ■ Executing 2.sql results in a table with 1 column and 1 row.


-- $ cat 2.sql | sqlite3 movies.db > output.txt
-- $ cat 2.sql | sqlite3 movies.db
-- $ sqlite3 movies.db

SELECT birth
    FROM people
    WHERE name = 'Emma Stone';
