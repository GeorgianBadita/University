USE Magazin

CREATE TABLE Client(
	Cid INT PRIMARY KEY IDENTITY(1, 1),
	Nume VARCHAR(50),
	Gen VARCHAR(1)
)

CREATE TABLE Produs(
	Pid INT PRIMARY KEY IDENTITY(1, 1),
	Denumire VARCHAR(50),
	Pret FLOAT,
	Cid INT,
    FOREIGN KEY (Cid) REFERENCES Client(Cid) 
)

GO

INSERT INTO Client VALUES ('Alin', 'M'),('Andrei', 'M'),('Andreea', 'F')
INSERT INTO Produs VALUES ('Telefon', 1.42, 1), ('TV', 1251.25, 3)


