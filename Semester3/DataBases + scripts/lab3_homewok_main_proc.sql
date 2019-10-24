CREATE PROCEDURE main
@vers INT
AS
BEGIN

if @vers < 0 OR @vers > 5
	THROW 510000, 'VERSIUNEA TREBUIE SA FIE UN NUMAR INTREG INTRE 0 si 5', 1;

DECLARE  @curr_vers INT
DECLARE @to_execute VARCHAR(50)
SELECT TOP 1 @curr_vers = Vid
FROM KeepVersion

if @curr_vers > @vers
	WHILE @curr_vers > @vers
	BEGIN
		SET @to_execute = CAST(@curr_vers as varchar(1))
		SET @to_execute =  CONCAT('undo_proc_', @to_execute)
		exec @to_execute
		SET @curr_vers = @curr_vers - 1
		UPDATE KeepVersion
		SET Vid = @curr_vers
	END;
ELSE
	WHILE @curr_vers < @vers
	BEGIN
		SET @to_execute = CAST(@curr_vers + 1 as varchar(1))
		SET @to_execute =  CONCAT('do_proc_', @to_execute)
		exec @to_execute
		SET @curr_vers = @curr_vers + 1
		UPDATE KeepVersion
		SET Vid = @curr_vers
	END;
END
GO

exec main 10
exec main 0

SELECT * FROM KeepVersion