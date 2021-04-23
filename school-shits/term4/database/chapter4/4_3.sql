-- 4.3
-- a
SELECT * FROM student ,takes
WHERE student.id = takes.id 
UNION
SELECT id, name, dept_name, tot_cred, NULL, NULL, NULL, NULL, NULL, NULL
FROM student st
WHERE st.id NOT IN (
    SELECT id FROM takes t
);

-- b
SELECT * FROM student ,takes
WHERE student.id = takes.id 
UNION
SELECT *, NULL, NULL, NULL, NULL, NULL, NULL
FROM student st_a
WHERE st_a.id NOT IN (
    SELECT id FROM takes take_a
)
UNION
SELECT NULL, NULL, NULL, NULL, * FROM takes take_b 
WHERE take_b.id NOT IN (SELECT id FROM student st_b)