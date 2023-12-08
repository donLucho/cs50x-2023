-- Required Lab(s) 7 by Luis Artavia - 5.sql
-- draft processed on: September 15, 2023
-- submitted for grade on: September 15, 2023

-- In 5.sql, write a SQL query that returns the average energy of all the songs.
-- Your query should output a table with a single column and a single row containing the average energy.

-- $ sqlite3 songs.db
-- $ cat 5.sql | sqlite3 songs.db

-- SELECT name, energy FROM songs;
SELECT AVG(energy) FROM songs;
