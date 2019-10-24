USE Ceainarie
go

/*
Inserare date
*/
/*1)*/ INSERT INTO TipuriDeCeaiuri (Tid, Nume, Origine) VALUES (1, 'Plante', 'India')
INSERT INTO TipuriDeCeaiuri VALUES (2,'Negru','Anglia')

/*
Query
*/
SELECT * FROM TipuriDeCeaiuri

/*2)*/
INSERT INTO Arome(Denumire, Intensitate) VALUES ('Musetel', 3), ('Vanilie', 10)
--Query
SELECT * FROM Arome

--3)
INSERT INTO Ceaiuri VALUES ('Fructe de padure', 100, 2), ('Sunatoare', 80, 2)

--Query
SELECT * FROM Ceaiuri

--4)
INSERT INTO Comenzi VALUES(1,2, 0),(2,1,7)

--Query
SELECT * FROM Comenzi

--afisati ceairui din fiecare tip aand gramajul > 50 si orogine india
SELECT C.Denumire, C.Gramaj, T.Nume
FROM Ceaiuri as C, TipuriDeCeaiuri as T
WHERE C.Gramaj > 50 AND T.Origine = 'India' AND T.Tid = C.Tid

SELECT Denumire, Gramaj, Nume
FROM Ceaiuri C INNER JOIN TipuriDeCeaiuri T ON T.Tid=C.Tid
WHERE Gramaj > 50 AND Origine = 'India'

SELECT Denumire, Gramaj, Nume
FROM Ceaiuri C INNER JOIN TipuriDeCeaiuri T ON T.Tid=C.Tid


SELECT Denumire, Gramaj, Nume
FROM Ceaiuri C LEFT OUTER JOIN TipuriDeCeaiuri T ON T.Tid=C.Tid

SELECT Denumire, Gramaj, Nume
FROM Ceaiuri C RIGHT OUTER JOIN TipuriDeCeaiuri T ON T.Tid=C.Tid

SELECT Denumire, Gramaj, Nume
FROM Ceaiuri C FULL JOIN TipuriDeCeaiuri T ON T.Tid=C.Tid

--Afisare ceaiuri cu arome + (ordonate dupa denumirea ceaiului) avand litera a/A in interiorul aromei

SELECT DISTINCT C.Denumire, A.Denumire
FROM Ceaiuri C INNER JOIN Comenzi Co ON C.Cid = Co.Cid
INNER JOIN Arome A ON CO.Aid = A.Aid
WHERE A.Denumire LIKE '%_A_%' ORDER BY C.Denumire DESC 

--Sa se afiseze pentru fiecare tip de ceai suma gramajelor
SELECT T.Tid, SUM(Gramaj) as Gramaj_Total
FROM TipuriDeCeaiuri T INNER JOIN Ceaiuri C ON T.Tid = C.Tid
GROUP BY T.Tid

SELECT T.Tid, SUM(Gramaj) as Gramaj_Total
FROM TipuriDeCeaiuri T INNER JOIN Ceaiuri C ON T.Tid = C.Tid
GROUP BY T.Tid
HAVING SUM(Gramaj) > 100 AND T.Tid = 2

--AdentureWorks 2012.backup