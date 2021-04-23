-- Alireza Jafartash
-- 983112029
-- https://github.com/alirezaopmc/My-Toxic-Repo/blob/master/school-shits/db-term4/chapter3/solution.sql

-- 3.1
--  a
SELECT title
FROM course
WHERE dept_name = 'Comp.Sci' AND credit = 3;

--  b
SELECT DISTINCT student.ID
FROM (student join takes using (ID)) using (course_id, sec_id, semester, year)
WHERE instructor.name = 'Einstein';

--  c
SELECT MAX(salary) FROM instructor;

--  d
SELECT ID, name
FROM instructor
WHERE salary = (SELECT MAX(salary) FROM instructor);

--  e
SELECT course_id, sec_id, COUNT(ID)
FROM section NATURAL JOIN takes
WHERE semester = 'Autumn' AND year = 2009
GROUP BY course_id, sec_id;

--  f
SELECT MAX(enrollment)
FROM (
    SELECT COUNT(ID) as enrollment
    FROM section NATURAL JOIN takes
    WHERE semester = 'Autumn' AND year = 2009
    GROUP BY course_id, sec_id
);

--  g
WITH sec_enrollment AS (
    SELECT course_id, sec_id, COUNT(ID) AS enrollment
    FROM section NATURAL JOIN takes
    WHERE semester = 'Autumn' AND year = 2009
    GROUP BY course_id, sec_id
) SELECT course_id, sec_id
FROM sec_enrollment
WHERE enrollment = (SELECT MAX(enrollment) FROM sec_enrollment);

-- 2
--  a
SELECT SUM(credit * points)
FROM (takes NATURAL JOIN course) NATURAL JOIN grade_points
WHERE ID = '12345'
UNION
(
    SELECT 0
    FROM student
    WHERE takes.ID = '12345' AND NOT EXISTS (SELECT * FROM takes WHERE takes.ID = '12345')
);

--  b
SELECT SUM(credits * points) / SUM(credits) AS GPA
FROM (takes NATURAL JOIN course) NATURAL JOIN grade_points
WHERE ID = '12345'
UNION
(
    SELECT NULL as GPA
    FROM student
    WHERE takes.ID = '12345' AND NOT EXISTS (
        SELECT * FROM takes WHERE takes.ID = '12345'
    )
);

--  c
SELECT ID, SUM(credits * points) / SUM(credits) AS GPA
FROM (takes NATURAL JOIN course) NATURAL JOIN grade_points
GROUP BY ID
UNION
(
    SELECT ID, NULL AS GPA
    FROM stundet
    WHERE NOT EXISTS (
        SELECT * FROM takes WHERE takes.ID = student.ID
    )
);

-- 3
--  a
UPDATE instructor
SET salary = salary * 1.10
WHERE dept_name = 'Comp.Sci';

--  b
DELETE FROM course
WHERE course_id
NOT IN (
    SELECT course_id
    FROM section
);

--  c
INSERT INTO instructor
SELECT ID, name, dept_name, 10000
FROM student
WHERE tot_cred > 100;

-- 8
--  a
SELECT ID
FROM depositor
EXCEPT (
    SELECT ID
    FROM borrower
);

--  b
SELECT A.ID
FROM customer
AS A, customer
AS B 
WHERE A.customer_street = B.customer_street
	AND F.customer_city = S.customer_city
	AND S.customer_id ="12345"

--  c
SELECT DISTINCT branch_name
FROM account, customer, depositor 
WHERE customer.id = depositor.id
    AND depositor.account_number = account.account_number
    AND customer.customer_city = 'Harrison'

-- 22
WHERE (
    SELECT COUNT(*), title FROM course
) = 1

-- 23 [With help of my friend]
SELECT dept_name
FROM (
    SELECT dept_name, SUM(salary)
    FROM instructor
    GROUP BY dept_name
),(
    SELECT AVG(value)
    FROM (
        SELECT dept_name, SUM(salary)
        FROM instructor
        GROUP BY dept_name
    )
) WHERE (
    SELECT VALUE FROM (
        SELECT dept_name, SUM(salary)
        FROM instructor
        GROUP BY dept_name)) >= (SELECT value
                                    FROM (
                                    SELECT AVG(value) FROM (
                                        SELECT dept_name, SUM(salary)
                                        FROM instructor
                                        GROUP BY dept_name
                                    )
                                )
);
						