-- Optional Lab(s) 7 by Luis Artavia - favorites.sql
-- draft processed on: September 13, 2023 and September 14, 2023
-- Composed on: September 13, 2023 and September 14, 2023
-- Practice document not intended for evaluation

-- sqlite3 favorites.db '.dump' > dump.sql
-- sqlite3 favorites.db

-- .schema
-- .mode table
-- .headers ON

-- September 13, 2023

SELECT COUNT(*) FROM shows;
SELECT COUNT(*) FROM genres;
SELECT DISTINCT genre FROM genres ORDER BY genre ASC;
SELECT COUNT(DISTINCT genre) FROM genres;

SELECT * FROM shows WHERE title LIKE 'BROOKLYN%' OR '%99' OR '%nine%';
UPDATE shows SET title = 'Brooklyn Nine-Nine' WHERE title LIKE 'BROOKLYN%' OR '%99';

SELECT * FROM shows WHERE title LIKE '%99%';
UPDATE shows SET title = 'Brooklyn Nine-Nine' WHERE title LIKE '%99%';

SELECT * FROM shows WHERE title LIKE 'game%' OR '%thron%';
UPDATE shows SET title = 'Game Of Thrones' WHERE title LIKE 'game%' OR '%thron%';

SELECT * FROM shows WHERE title = 'GoT';
UPDATE shows SET title = 'Game Of Thrones' WHERE title = 'GoT';

SELECT * FROM shows WHERE title LIKE '%squid%';
UPDATE shows SET title = 'Squid Game' WHERE title LIKE '%squid%';

SELECT * FROM shows WHERE title LIKE '%PARK%' OR '%RECREAT%';
UPDATE shows SET title = 'Parks And Recreation' WHERE title LIKE '%Parks and rec%';

SELECT * FROM shows WHERE title LIKE '%OFFICE%';
UPDATE shows SET title = 'The Office' WHERE title LIKE '%OFFICE%';

SELECT * FROM shows WHERE title LIKE '%adventure%' OR '%time%';
UPDATE shows SET title = 'Adventure Time' WHERE title LIKE '%adventure%' OR '%time%';

SELECT * FROM shows WHERE title LIKE '%arro%';
UPDATE shows SET title = 'Arrow' WHERE title LIKE '%arro%';

SELECT * FROM shows WHERE title LIKE '%avata%' OR '%air%' OR '%bend%';
UPDATE shows SET title = 'Avatar: The Last Airbender' WHERE title LIKE '%avata%' OR '%air%' OR '%bend%';

-- September 14, 2023

SELECT * FROM shows WHERE title LIKE '%nity%';
UPDATE shows SET title = 'Community' WHERE title LIKE '%nity%';

SELECT * FROM shows WHERE title LIKE '%family guy%';
UPDATE shows SET title = 'Family Guy' WHERE title LIKE '%family guy%';

SELECT * FROM shows WHERE title LIKE '%friend%';
UPDATE shows SET title = 'Friends' WHERE title LIKE '%friend%';

SELECT * FROM shows WHERE title LIKE '%Gilmore%' OR '%girl%';
UPDATE shows SET title = 'Gilmore Girls' WHERE title LIKE '%Gilmore%' OR '%girl%';

SELECT * FROM shows WHERE title LIKE '%HOW I%' OR '%MET%' OR '%MOTHER%';
UPDATE shows SET title = 'How I Met Your Mother' WHERE title LIKE '%HOW I%' OR '%MET%' OR '%MOTHER%';

SELECT * FROM shows WHERE title LIKE '%Sherlock%';
UPDATE shows SET title = 'Sherlock' WHERE title LIKE '%Sherlock%';

SELECT * FROM shows WHERE title LIKE '%Bachelo%' OR '%rette%';
UPDATE shows SET title = 'The Bachelorette' WHERE title LIKE '%Bachelo%' OR '%rette%';

SELECT * FROM shows WHERE title LIKE '%Crown%';
UPDATE shows SET title = 'The Crown' WHERE title LIKE '%Crown%';

SELECT * FROM shows WHERE title LIKE '%untam%';
UPDATE shows SET title = 'The Untamed' WHERE title LIKE '%untam%';

SELECT * FROM shows WHERE title LIKE '%billions%';
UPDATE shows SET title = 'Billions' WHERE title LIKE '%billions%';

SELECT * FROM shows WHERE title LIKE '%grey%' OR '%anatom%';
UPDATE shows SET title = 'Grey´s Anatomy' WHERE title LIKE '%grey%' OR '%anatom%';

SELECT * FROM shows WHERE title LIKE '%Gambit%';
UPDATE shows SET title = 'The Queen´s Gambit' WHERE title LIKE '%Gambit%';

SELECT * FROM shows WHERE title LIKE '%Always%' OR '%sunny%' OR '%Philadelphia%';
UPDATE shows SET title = 'It’s Always Sunny in Philadelphia' WHERE title LIKE '%Always%' OR '%sunny%' OR '%Philadelphia%';

SELECT * FROM shows WHERE title = 'criminal minds';
UPDATE shows SET title = 'Criminal Minds' WHERE title = 'criminal minds';

-- Q. Why do you think it’s necessary to “clean” data when you can use the SQL LIKE statement?

-- A. Data integrity is key, for example, to presenting with veracity or authority. The level workmanship is obliquely commented on, too. If nothing is completed or entered to posterity, then, other not-so-obvious areas can also reflect the same under the hood. If the workmanship is shoddy, then, why believe or trust the source of the data if at all. Given that query input and data input is capitalization-agnostic, the nature of the language can invite these kinds of issues. Data output is not caps-agnostic. Letters, phonemes and symbols carry meaning which makes the task of scrubbing or clean-up all the more important. Data entry can be compared to writing in general whether it be on a technical level or prose; proofreading is the final if not penultimate step to successful writing.