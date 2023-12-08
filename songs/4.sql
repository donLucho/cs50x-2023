-- Required Lab(s) 7 by Luis Artavia - 4.sql
-- draft processed on: September 15, 2023
-- submitted for grade on: September 15, 2023

-- In 4.sql, write a SQL query that lists the names of any songs that have danceability, energy, and valence greater than 0.75.
-- Your query should output a table with a single column for the name of each song.

-- $ sqlite3 songs.db
-- $ cat 4.sql | sqlite3 songs.db

-- SELECT name, danceability, energy, valence FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;
