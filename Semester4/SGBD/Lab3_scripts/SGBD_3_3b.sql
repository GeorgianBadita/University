--Dirty Reads Part 1
BEGIN TRANSACTION
UPDATE LiniiProduse SET denumire = 'DENUMIRE'
WHERE lnId = 78
WAITFOR DELAY '00:00:10'
ROLLBACK TRANSACTION

--Dirty Reads Part 2
SET TRANSACTION ISOLATION LEVEL READ
UNCOMMITTED
BEGIN TRAN
SELECT * FROM LiniiProduse
WAITFOR DELAY '00:00:15'
SELECT * FROM LiniiProduse
COMMIT TRAN

--Solution: SET TRANSACTION ISOLATION LEVEL TO READ COMMITTED
SET TRANSACTION ISOLATION LEVEL READ COMMITTED
BEGIN TRAN
SELECT * FROM LiniiProduse
WAITFOR DELAY '00:00:15'
SELECT * FROM LiniiProduse
COMMIT TRAN

-- Non repeatable 1
INSERT INTO LiniiProduse values('dsda','dssad')
BEGIN TRAN
WAITFOR DELAY '00:00:05'
UPDATE LiniiProduse SET descriere='DDD' where
descriere = 'dssad'
COMMIT TRAN

-- Non repeatable 2
SET TRANSACTION ISOLATION LEVEL READ
COMMITTED
BEGIN TRAN
SELECT * FROM LiniiProduse
WAITFOR DELAY '00:00:05'
SELECT * FROM LiniiProduse
COMMIT TRAN

-- Non repeatable SOLUTION
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
BEGIN TRAN
SELECT * FROM LiniiProduse
WAITFOR DELAY '00:00:05'
SELECT * FROM LiniiProduse
COMMIT TRAN

-- Phantom Reads Part 1
-- DELETE FROM LiniiProduse
BEGIN TRAN
WAITFOR DELAY '00:00:04'
INSERT INTO LiniiProduse VALUES('333','33333')
COMMIT TRAN

--Phantom Reads Part 2
SET TRANSACTION ISOLATION LEVEL REPEATABLE
READ
BEGIN TRAN
SELECT * FROM LiniiProduse
WAITFOR DELAY '00:00:05'
SELECT * FROM LiniiProduse
COMMIT TRAN

-- Phantom reads SOLUTION
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE
BEGIN TRAN
SELECT * FROM LiniiProduse
WAITFOR DELAY '00:00:05'
SELECT * FROM LiniiProduse
COMMIT TRAN


-- DEADLOCK

-- transaction 1
begin tran
update Produse set pret=5000
waitfor delay '00:00:10'
update LiniiProduse set descriere='DEAD'
commit tran


-- transaction 2
begin tran
update LiniiProduse set descriere='DEAD'
waitfor delay '00:00:10'
update Produse set pret=500
commit tran

-- deadlock SOLUTION

-- transaction 2
SET DEADLOCK_PRIORITY HIGH
begin tran
update LiniiProduse set descriere='DEAD'
waitfor delay '00:00:10'
update Produse set pret=500
commit tran

exec dbo.Dead1
