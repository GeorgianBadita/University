CREATE PROCEDURE do_proc_4
AS
BEGIN
--PROCEDURE'S CODE
ALTER TABLE Abonament
ADD Id_cl INT NOT NULL 

PRINT 'Coloana Id_cl a fost adaugata cu succes in tabelul Abonament!'

END
GO

CREATE PROCEDURE undo_proc_4
AS
BEGIN
--PROCEDURE'S CODE
ALTER TABLE Abonament
DROP COLUMN Id_cl

PRINT 'Coloana Id_cl a fost stearsa cu succes din tabelul Abonament!'
END
GO