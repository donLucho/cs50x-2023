-- Required Lab(s) 7 by Luis Artavia - 6.sql
-- draft processed on: September 15, 2023
-- submitted for grade on: September 15, 2023

-- In 6.sql, write a SQL query that lists the names of songs that are by Post Malone.
-- Your query should output a table with a single column for the name of each song.
-- You should not make any assumptions about what Post Malone’s artist_id is.

-- $ sqlite3 songs.db
-- $ cat 6.sql | sqlite3 songs.db

-- these results appear in sequential order
-- SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Post Malone');

-- these results DO NOT appear in sequential order
SELECT songs.name FROM songs JOIN artists on songs.artist_id = artists.id WHERE artists.name = 'Post Malone';
