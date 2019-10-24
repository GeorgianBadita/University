CREATE DATABASE My_lib

USE My_lib

/* Address table */
CREATE TABLE Adresa(
	Id_adr INT IDENTITY(1,1) NOT NULL,
	Oras VARCHAR(50) NOT NULL,
	Strada VARCHAR(50) NOT NULL,
	Numar INT NOT NULL,
	PRIMARY KEY (Id_adr)
)

/* Category table */
CREATE TABLE Categorie(
	Id_cat INT IDENTITY(1,1) NOT NULL,
	Nume VARCHAR(50)  NOT NULL,
	Descriere VARCHAR(50)  NOT NULL,
	PRIMARY KEY (Id_cat)
)

/* Publisher table */
CREATE TABLE Editura(
	Id_edit INT IDENTITY(1,1) NOT NULL,
	Manager VARCHAR(50) NOT NULL,

	PRIMARY KEY (Id_edit),
)

/* Book table */
CREATE TABLE Carte(
	Id_car INT IDENTITY(1,1) NOT NULL,
	Titlu VARCHAR(50) NOT NULL,
	Autor VARCHAR(50) NOT NULL,
	An_Aparitie INT NOT NULL,
	Id_cat INT NOT NULL,
	Id_edit INT NOT NULL,
	
	PRIMARY KEY(Id_car),
	CONSTRAINT FK_Categorie FOREIGN KEY(Id_cat)
	REFERENCES Categorie(Id_cat),
	
	CONSTRAINT FK_Editura FOREIGN KEY(Id_edit)
	REFERENCES Editura(Id_edit)
)

/* Client Table */
CREATE TABLE Client(
	Id_cl INT IDENTITY(1,1) NOT NULL,
	Nume VARCHAR(50) NOT NULL,
	Prenume VARCHAR(50) NOT NULL,
	CNP VARCHAR(20) NOT NULL,
	Varsta INT,
	Id_adr INT NOT NULL,

	PRIMARY KEY(Id_cl)
)

/* CarteClient Table */
CREATE TABLE CarteClient(
	Id_car INT NOT NULL,
	Id_cl INT NOT NULL,

	PRIMARY KEY(Id_car, Id_cl),
	CONSTRAINT FK_ID_Car_Clinet FOREIGN KEY(Id_car)
	REFERENCES Carte(Id_car),

	CONSTRAINT FK_ID_Client_Car FOREIGN KEY(Id_cl)
	REFERENCES Client(Id_cl)
)


/* Furnizor Table */
CREATE TABLE Furnizor(
	Id_fur INT IDENTITY(1,1) NOT NULL,
	Nume VARCHAR(50) NOT NULL,
	Cantitate INT NOT NULL,
	Id_adr INT NOT NULL,
	PRIMARY KEY(Id_fur),

	CONSTRAINT FK_Addr FOREIGN KEY(Id_adr) 
	REFERENCES Adresa(Id_adr)
)

/* CarteFurnizor */
CREATE TABLE CarteFurnizor(
	Id_fur INT NOT NULL,
	Id_car INT NOT NULL,

	PRIMARY KEY(Id_fur, Id_car),
	CONSTRAINT FK_Furnizor FOREIGN KEY(Id_fur)
	REFERENCES Furnizor(Id_fur),

	CONSTRAINT FK_Carte FOREIGN KEY(Id_car)
	REFERENCES Carte(Id_car)
)

/* Post table */
CREATE TABLE Post(
	Id_post INT IDENTITY(1,1) NOT NULL,
	Descriere VARCHAR(100) NOT NULL,
	Salariu MONEY NOT NULL,
	Atribute VARCHAR(100) NOT NULL,

	PRIMARY KEY(Id_post)
)

/* Angajat table */
CREATE TABLE Angajat(
	Id_ang INT IDENTITY(1,1) NOT NULL,
	Nume VARCHAR(50) NOT NULL,
	Prenume VARCHAR(50) NOT NULL,
	CNP VARCHAR(20) NOT NULL,
	Id_adr INT NOT NULL,
	Id_post INT NOT NULL,

	PRIMARY KEY(Id_ang),
	CONSTRAINT FK_AngajatAddr FOREIGN KEY(Id_adr)
	REFERENCES Adresa(Id_adr),

	CONSTRAINT FK_AngajatPost FOREIGN KEY(Id_post)
	REFERENCES Post(Id_post)
)

/*DROP table Adresa
DROP table Angajat
DROP table Carte
DROP table CarteClient
DROP table CarteFurnizor
DROP table Categorie
DROP table Client
DROP table Editura
DROP table Furnizor
DROP table Post
*/

SELECT *
FROM 
Adresa
INNER JOIN Angajat ON Adresa.Id_adr = Angajat.Id_adr 

SELECT * 
FROM 
Post
INNER JOIN Angajat ON Post.Id_post = Angajat.Id_post