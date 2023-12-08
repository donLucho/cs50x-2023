-- Required Lab(s) 7 by Luis Artavia - 2.sql
-- draft processed on: September 15, 2023
-- submitted for grade on: September 15, 2023

-- In 2.sql, write a SQL query to list the names of all songs in increasing order of tempo.
-- Your query should output a table with a single column for the name of each song.

-- $ sqlite3 songs.db
-- $ cat 2.sql | sqlite3 songs.db

-- SELECT name, tempo FROM songs ORDER BY tempo;
SELECT name FROM songs ORDER BY tempo;
