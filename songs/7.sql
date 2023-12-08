-- Required Lab(s) 7 by Luis Artavia - 7.sql
-- draft processed on: September 15, 2023
-- submitted for grade on: September 15, 2023

-- In 7.sql, write a SQL query that returns the average energy of songs that are by Drake.
-- Your query should output a table with a single column and a single row containing the average energy.
-- You should not make any assumptions about what Drake’s artist_id is.

-- $ sqlite3 songs.db
-- $ cat 7.sql | sqlite3 songs.db

-- SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake');

SELECT AVG(songs.energy) FROM songs JOIN artists on songs.artist_id = artists.id WHERE artists.name = 'Drake';
