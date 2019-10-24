CREATE PROCEDURE do_proc_2
AS
BEGIN
--PROCEDURE'S CODE
ALTER TABLE Adresa
ADD CONSTRAINT oras_def DEFAULT 'Cluj' for Oras

PRINT 'Contrangerea default asupra tabelei Adresa a fost adaugata cu succes!'

END
GO


CREATE PROCEDURE undo_proc_2
AS
BEGIN
--PROCEDURE'S CODE
ALTER TABLE Adresa
DROP CONSTRAINT oras_def

PRINT 'Constrangerea default asupra tabelei Adresa a fost indepartata cu succes!'

END 
GO
