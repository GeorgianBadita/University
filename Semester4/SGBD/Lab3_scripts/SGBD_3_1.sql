alter procedure AddComanda
@email varchar(100),
@join_date varchar(100),
@data varchar(100),
@modplata varchar(10),
@denumire varchar(100),
@descriere varchar(100),
@pret float
as
begin
	begin tran
	begin try
		declare @idC int
		declare @idP int
		declare @idCmd int

		if (dbo.validareData(@join_date)<>1 or dbo.ValidateEmail(@email)<>1)
		begin
			print('invalid client data')
			RAISERROR('invalid client data',14,1)
		end

		insert into Clienti values(@email,@join_date)
		set @idc = SCOPE_IDENTITY()
		print('insert client')

		if (dbo.ValidateVarchar(@descriere)<>1 or dbo.ValidateVarchar(@denumire)<>1 or dbo.ValidatePret(@pret)<>1)
		begin
		print('invalid client data')
			RAISERROR('invalid item data',14,1)
		end

		set @idP = (select max(prId) from Produse)
		if (select count(*) from Produse) = 0
			set @idP = 1
		set @idP = @idP + 1
		print(@idP)
		insert into Produse values(@idP,@denumire,@descriere,@pret,1,78)
		print('insert produse')

		if (dbo.validareData(@data)<>1 or dbo.ValidateModPlata(@modplata)<>1)
		begin
			print('invalid purchase data')
			RAISERROR('invalid purchase data',14,1)
		end
		print('comanda valida')
		insert into Comenzi values(@idC,@idP,75851,1,@data,@modplata)
		print('insert comanda')

		commit tran
		print('ok')
		select 'Transaction commited'

	end try
	begin catch
		rollback tran
		select 'Transaction rolled back'
	end catch
end

delete from Comenzi
delete from Produse
delete from Clienti

select * from Clienti
select * from Produse
select * from Comenzi
exec AddComanda 'email@afds.com','04/04/2014','04/04/2014','CARD','ds','dsa',400
select * from Clienti
select * from Produse
select * from Comenzi

select * from Clienti
select * from Produse
select * from Comenzi
exec AddComanda 'email@das.com','04/04/2014','04/04/2d014','CARD','ds','dsa',400
select * from Clienti
select * from Produse
select * from Comenzi