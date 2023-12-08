-- Required Problem set 7 by Luis Artavia - fiftyville
-- draft processed on: September 16, 2023
-- submitted for grade on: September 16, 2023
-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Your goal is to identify:
--   ■ Who the thief is,
--   ■ What city the thief escaped to, and
--   ■ Who the thief’s accomplice is who helped them escape
-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.
-- ■ You may find it helpful to start with the crime_scene_reports table. Start by looking for a crime scene report that matches the date and the location of the crime.
-- SELECT * FROM crime_scene_reports;
-- step 01 - id number 295 is of interest
SELECT
  id,
  YEAR,
  MONTH,
  DAY,
  street,
  description
FROM
  crime_scene_reports
WHERE
  MONTH = 7
  AND DAY = 28
  AND YEAR = 2021;

-- step 02 - 3 records of interest are returned
SELECT
  *
FROM
  interviews
WHERE
  transcript LIKE '%baker%'
  AND MONTH = 7
  AND DAY = 28
  AND YEAR = 2021;

-- step 03 - 8 records of interest are returned
-- SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND activity = 'exit' AND hour = 10 AND minute >= 15 AND minute <= 25;
-- SELECT bakery_security_logs.activity, bakery_security_logs.license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND activity = 'exit' AND hour = 10 AND minute >= 15 AND minute <= 25;
-- SELECT people.name, people.license_plate, bakery_security_logs.activity, bakery_security_logs.license_plate FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.year = 2021 AND bakery_security_logs.activity = 'exit' AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25;
-- SELECT people.name, people.license_plate, people.phone_number, people.passport_number FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.year = 2021 AND bakery_security_logs.activity = 'exit' AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25;
SELECT
  people.name,
  people.license_plate,
  people.phone_number,
  people.passport_number
FROM
  bakery_security_logs
  JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE
  bakery_security_logs.month = 7
  AND bakery_security_logs.day = 28
  AND bakery_security_logs.year = 2021
  AND bakery_security_logs.activity = 'exit'
  AND bakery_security_logs.hour = 10
  AND bakery_security_logs.minute >= 15
  AND bakery_security_logs.minute <= 25;

-- step 04 - 8 records of interest are returned
-- SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
-- SELECT people.name, atm_transactions.account_number FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.year = 2021 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw';
SELECT
  people.name,
  atm_transactions.account_number
FROM
  atm_transactions
  JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
  JOIN people ON people.id = bank_accounts.person_id
WHERE
  atm_transactions.month = 7
  AND atm_transactions.day = 28
  AND atm_transactions.year = 2021
  AND atm_transactions.atm_location = 'Leggett Street'
  AND atm_transactions.transaction_type = 'withdraw';

-- step 05a - 9 records of interest are returned
-- SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
-- SELECT caller, receiver FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
-- SELECT people.name, phone_calls.caller FROM phone_calls JOIN people ON phone_calls.caller = people.phone_number WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
-- SELECT pcallers.name AS outgoing, phone_calls.caller, rcallers.name AS incoming, phone_calls.receiver FROM phone_calls JOIN people AS pcallers ON phone_calls.caller = pcallers.phone_number JOIN people AS rcallers ON phone_calls.receiver = rcallers.phone_number WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;
SELECT
  pcallers.name AS outgoing,
  phone_calls.caller,
  rcallers.name AS incoming,
  phone_calls.receiver
FROM
  phone_calls
  JOIN people AS pcallers ON phone_calls.caller = pcallers.phone_number
  JOIN people AS rcallers ON phone_calls.receiver = rcallers.phone_number
WHERE
  MONTH = 7
  AND DAY = 28
  AND YEAR = 2021
  AND duration < 60;

-- step 05b - Same as above but with more detail provided (e.g. - id, name, phone_number, passport_number, license_plate )
SELECT
  *
FROM
  people
WHERE
  phone_number IN (
    '(130) 555-0289',
    '(499) 555-9472',
    '(367) 555-5533',
    '(499) 555-9472',
    '(286) 555-6063',
    '(770) 555-1861',
    '(031) 555-6622',
    '(826) 555-1652',
    '(338) 555-6650'
  );

-- step 06 - Destination is New York City (i.e. - The city the thief ESCAPED TO: New York City)
-- SELECT * FROM flights WHERE month = 7 AND day = 29 AND year = 2021;
-- SELECT * FROM flights WHERE month = 7 AND day = 29 AND year = 2021 ORDER BY hour;
-- SELECT * FROM flights WHERE month = 7 AND day = 29 AND year = 2021 ORDER BY hour LIMIT 1;
-- SELECT * FROM flights WHERE flights.month = 7 AND flights.day = 29 AND flights.year = 2021 AND flights.id = 36;
-- SELECT * FROM airports;
-- SELECT COUNT(*) FROM passengers;
-- SELECT * FROM passengers LIMIT 1;
-- SELECT destination_airport_id FROM flights WHERE flights.month = 7 AND flights.day = 29 AND flights.year = 2021 AND flights.id = 36;
-- SELECT origin_airport_id, destination_airport_id, airports.id, airports.abbreviation, airports.full_name, airports.city FROM flights JOIN airports ON flights.origin_airport_id = airports.id WHERE flights.month = 7 AND flights.day = 29 AND flights.year = 2021 AND flights.id = 36;
SELECT
  origin_airport_id,
  o.city AS 'origin city',
  destination_airport_id,
  d.city AS 'destination city'
FROM
  flights
  JOIN airports AS o ON flights.origin_airport_id = o.id
  JOIN airports AS d ON flights.destination_airport_id = d.id
WHERE
  flights.month = 7
  AND flights.day = 29
  AND flights.year = 2021
  AND flights.id = 36;

-- step 07 - which name keeps popping up across ALL queries? Bruce is the culprit! (i.e. - The THIEF is: Bruce)
-- SELECT name FROM people JOIN passengers on people.passport_number = passengers.passport_number JOIN flights ON flights.id = passengers.flight_id WHERE flights.month = 7 AND flights.day = 29 AND flights.year = 2021 AND flights.id = 36 AND name IN (SELECT pcallers.name FROM phone_calls JOIN people AS pcallers ON phone_calls.caller = pcallers.phone_number WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60) AND name IN (SELECT people.name FROM atm_transactions JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number JOIN people ON people.id = bank_accounts.person_id WHERE atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.year = 2021 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw') AND name IN (SELECT people.name FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.year = 2021 AND bakery_security_logs.activity = 'exit' AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25);
SELECT
  name
FROM
  people
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN flights ON flights.id = passengers.flight_id
WHERE
  flights.month = 7
  AND flights.day = 29
  AND flights.year = 2021
  AND flights.id = 36
  AND name IN (
    SELECT
      pcallers.name
    FROM
      phone_calls
      JOIN people AS pcallers ON phone_calls.caller = pcallers.phone_number
    WHERE
      MONTH = 7
      AND DAY = 28
      AND YEAR = 2021
      AND duration < 60
  )
  AND name IN (
    SELECT
      people.name
    FROM
      atm_transactions
      JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
      JOIN people ON people.id = bank_accounts.person_id
    WHERE
      atm_transactions.month = 7
      AND atm_transactions.day = 28
      AND atm_transactions.year = 2021
      AND atm_transactions.atm_location = 'Leggett Street'
      AND atm_transactions.transaction_type = 'withdraw'
  )
  AND name IN (
    SELECT
      people.name
    FROM
      bakery_security_logs
      JOIN people ON people.license_plate = bakery_security_logs.license_plate
    WHERE
      bakery_security_logs.month = 7
      AND bakery_security_logs.day = 28
      AND bakery_security_logs.year = 2021
      AND bakery_security_logs.activity = 'exit'
      AND bakery_security_logs.hour = 10
      AND bakery_security_logs.minute >= 15
      AND bakery_security_logs.minute <= 25
  );

-- Final step - "step 05a" already revealed the recipient of the culprit's outgoing call; Robin (i.e. - The ACCOMPLICE is: Robin)