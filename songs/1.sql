-- Required Lab(s) 7 by Luis Artavia - 1.sql
-- draft processed on: September 15, 2023
-- submitted for grade on: September 15, 2023

-- In 1.sql, write a SQL query to list the names of all songs in the database.
-- Your query should output a table with a single column for the name of each song.

-- $ sqlite3 songs.db
-- $ cat 1.sql | sqlite3 songs.db

SELECT name FROM songs;
