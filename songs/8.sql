-- Required Lab(s) 7 by Luis Artavia - 8.sql
-- draft processed on: September 15, 2023
-- submitted for grade on: September 15, 2023

-- In 8.sql, write a SQL query that lists the names of the songs that feature other artists.
-- Songs that feature other artists will include “feat.” in the name of the song.
-- Your query should output a table with a single column for the name of each song.

-- $ sqlite3 songs.db
-- $ cat 8.sql | sqlite3 songs.db

SELECT name FROM songs WHERE name LIKE '%feat.%';
