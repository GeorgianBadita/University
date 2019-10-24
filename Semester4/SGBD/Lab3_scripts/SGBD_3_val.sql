create function ValidateEmail 
(@email varchar(100))
returns int as
begin
	declare @return int
	set @return = 0
	if @email LIKE '%_@__%.__%'
		set @return = 1
	return @return
end

select dbo.ValidareData('04/04/2012')

create function ValidateModPlata
(@mod varchar(100))
returns int as
begin
	declare @return int
	set @return = 0
	if @mod IN('CARD', 'RAMBURS')
		set @return = 1
	return @return
end

select dbo.ValidateModPlata('CARD')

create function ValidatePret
(@pret float)
returns int as
begin
	declare @return int
	set @return = 0
	if @pret > 0 
		set @return = 1
	return @return
end

select dbo.ValidatePret(-23)

create function ValidateVarchar
(@str varchar(100))
returns int as
begin
	declare @return int
	set @return = 0
	if @str != ''
		set @return = 1
	return @return
end

select dbo.ValidateVarchar('dsa')