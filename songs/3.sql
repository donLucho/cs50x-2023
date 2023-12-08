-- Required Lab(s) 7 by Luis Artavia - 3.sql
-- draft processed on: September 15, 2023
-- submitted for grade on: September 15, 2023

-- In 3.sql, write a SQL query to list the names of the top 5 longest songs, in descending order of length.
-- Your query should output a table with a single column for the name of each song.

-- $ sqlite3 songs.db
-- $ cat 3.sql | sqlite3 songs.db

-- SELECT name, duration_ms FROM songs ORDER BY duration_ms DESC;
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;
