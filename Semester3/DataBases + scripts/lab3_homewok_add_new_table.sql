CREATE PROCEDURE do_proc_3
AS
BEGIN

--PROCEDURE'S CODE
CREATE TABLE Abonament(
	AbID INT PRIMARY KEY IDENTITY
)

PRINT 'TABELUL Abonament a fost creat cu succes!'

END
GO


CREATE PROCEDURE undo_proc_3
AS
BEGIN
--PROCEDURE'S CODE
DROP TABLE Abonament
PRINT 'Tabelul Abonament a fost sters cu succes!'
END
GO
