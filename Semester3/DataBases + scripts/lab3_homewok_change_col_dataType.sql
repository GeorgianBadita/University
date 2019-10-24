CREATE PROCEDURE do_proc_1
AS 
--PROCEDURE'S CODE
ALTER TABLE Post
ALTER COLUMN Salariu
FLOAT

PRINT 'Coloana Salariu din tabelul Post a fost schimbata din Money in Float cu succes!'

GO

CREATE PROCEDURE undo_proc_1
AS
--PROCEDURE'S CODE
ALTER TABLE Post
ALTER COLUMN Salariu
MONEY

PRINT 'Coloana Salariu din tabelul Post a fost schimbata din FLoat in Money cu succes!'

GO
