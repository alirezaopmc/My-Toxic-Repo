SELECT Cus.cname
FROM Customer as Cus
WHERE NOT EXISTS (
    (
        SELECT bname FROM Branch WHERE bcity="Tehran"
    ) EXCEPT (
        SELECT Br.bname
        FROM Branch 
        AS Br, account, depositor
		WHERE account.a = depositor.a
        AND account.bname = Br.bname 
        AND depositor.cname = Cus.cnmae
    )
);