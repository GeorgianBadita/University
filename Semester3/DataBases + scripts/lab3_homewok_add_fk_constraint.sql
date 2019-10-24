CREATE PROCEDURE do_proc_5
AS
BEGIN
--PROCEDURE'S CODE
ALTER TABLE Abonament
ADD CONSTRAINT fk_Abonament_Client FOREIGN KEY(Id_cl) REFERENCES Client(Id_cl)

PRINT 'Constrangerea de cheie primara intre tabelele Abonament si CLient a fost realizata cu succes!'
END
GO

CREATE PROCEDURE undo_proc_5
AS
BEGIN
--PROCEDURE'S CODE
ALTER TABLE Abonament
DROP CONSTRAINT fk_Abonament_Client

PRINT 'Constrangerea de cheie primara intre tabelele Abonament si CLient a fost stearsa cu succes!'
END
GO

