-- 3.4.
-- a
SELECT COUNT( DISTINCT driver_id)
FROM owns, participated, accident
WHERE accident.year=2017
AND accident.report_number=participated.report_number
AND participated.license_plate = owns.license_plate;


-- b
DELETE FROM car
WHERE year=2010
AND license_plate IN (
    SELECT license_plate
    FROM owns
    WHERE driver_id ='12345'
);