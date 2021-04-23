SELECT pname
FROM Professor, College, Section, Course 
WHERE clgName="IT"
AND Section.term='881' 
AND College.clg_id = Professor.clg_id
AND Professor.pname = Section.pname
AND Section.c_id = course.c_id
GROUP BY pname
HAVING COUNT(cname) >= all (
    SELECT COUNT(cname)
    FROM Professor, College, Section, course 
    WHERE clgName="IT"
    AND section.term='881' 
    AND college.clg_id = Professor.clg_id
    AND professor.pname = section.pname
    AND section.c_id = course.c_id
    GROUP BY pname
);