/*
10 Query-uri
-5 cu where
-3 cu group by
-2 cu distinct
-7 cu mai mult de 2 tabele
-2 pe tabele cu m-n
-3 cu having
*/


/*
1.
Sa se afiseze pentru fiecare Post, numarul de angajati
-GROPU BY
--having
*/
SELECT P.Descriere, Count(A.Id_post) as NrAngajati
FROM Post P INNER JOIN Angajat A ON P.Id_post = A.Id_post
GROUP BY P.Descriere
HAVING Count(A.Id_post) > 1

/*
2.
Afisarea clientilor care au carti ce incep cu litera L
-Distinct
-Where
-Rel m-n
-Info > 2 tabele
*/
SELECT DISTINCT Cl.Nume, Cl.Prenume, Ca.Titlu
FROM Client Cl INNER JOIN CarteClient CaCl ON Cl.Id_cl = CaCl.Id_cl
INNER JOIN Carte Ca ON CaCl.Id_car = Ca.Id_car
WHERE Ca.Titlu LIKE 'L%' ORDER BY Cl.Nume ASC

/*
3.
Afisarea furnizorilor care au mai mult de 2 tipuri de carti
-Group by
-Info > 2 tabele
-Rel m-n
--having
*/
SELECT F.Nume, Count(CaF.Id_fur) as TipuriCarti
FROM Furnizor F INNER JOIN CarteFurnizor CaF ON F.Id_fur = CaF.Id_fur
INNER JOIN Carte Ca ON CaF.Id_car = Ca.Id_car
GROUP BY F.Nume
HAVING Count(CaF.Id_fur) > 1


/*
4.
Afisarea numarului maxim de carti ale unui cititor
-Group by
-> 2 tabele
*/
SELECT MAX(NrCarti) as MAXIM
FROM (SELECT Cl.Nume,COUNT(CaCl.Id_Cl) as NrCarti
FROM Client Cl INNER JOIN CarteClient CaCl ON CaCl.Id_cl = Cl.Id_cl
INNER JOIN Carte Ca ON Ca.Id_car = CaCl.Id_Car 
GROUP BY Cl.Nume) AS Nc 

/*
5.
Afisarea fiecarui Client si a numarului de carti corespunzator
-Group By
->2 tabele
-Distinct
*/
SELECT DISTINCT Cl.Nume,COUNT(CaCl.Id_Cl) as NrCarti
FROM Client Cl INNER JOIN CarteClient CaCl ON CaCl.Id_cl = Cl.Id_cl
INNER JOIN Carte Ca ON Ca.Id_car = CaCl.Id_Car 
GROUP BY Cl.Nume

/*
6.
Clientii care citesc carti de la un furnizor din Ramnicu Valcea
>2 tabele
-where
*/
SELECT Cl.Nume, Cl.prenume, A.Oras
FROM Client Cl INNER JOIN CarteClient CaCl ON Cl.Id_cl = CaCl.Id_cl
INNER JOIN Carte Ca ON Ca.Id_car = CaCl.Id_car
INNER JOIN CarteFurnizor Cf ON Cf.Id_car = Ca.Id_car
INNER JOIN Furnizor F ON F.Id_fur = Cf.Id_fur
INNER JOIN Adresa A ON A.Id_adr = F.Id_adr
WHERE A.Oras = 'Ramnicu Valcea'

/*
7.
Cartiile de Stiinta de la editura UniPress
> 2 tabele
-Where
*/
SELECT Ca.Titlu
FROM Carte Ca INNER JOIN Categorie Cat ON Ca.Id_cat = Cat.Id_cat
INNER JOIN Editura E ON Ca.Id_edit = E.Id_edit
WHERE E.Nume = 'UniPress' AND Cat.Nume = 'Stiinta'

/*
8.
Salariul angajatiilor care locuiesc in Cluj-Napoca
-where
->2 tabele
*/ 
SELECT A.Nume, P.Salariu
FROM Angajat A INNER JOIN Post P ON A.Id_post = P.Id_post
INNER JOIN Adresa Ad ON Ad.Id_adr = A.Id_adr
WHERE Ad.Oras = 'Cluj-Napoca'

/*
9. Clientii cititori mai batrani de 30 de ani
--Where
-->2 tabele
--distinct
*/
SELECT DISTINCT Cl.Nume
FROM Client Cl INNER JOIN CarteClient CaCl ON Cl.Id_cl = CaCl.Id_cl
INNER JOIN Carte Ca ON Ca.Id_car = CaCl.Id_car
WHERE Cl.Varsta > 30

/*
10. Clientii care citesc din mai multe categorii
-->2 tabele
--Group By
--having
*/
SELECT Cl.Nume, COUNT(Cat.Nume) as Categorii
FROM Client Cl INNER JOIN CarteClient CaCl ON Cl.Id_cl = CaCl.Id_cl
INNER JOIN Carte Ca ON Ca.Id_car = CaCl.Id_car INNER JOIN Categorie Cat
ON Cat.Id_cat = Ca.Id_cat
GROUP BY Cl.Nume
HAVING COUNT(Cat.Nume) > 1

--Grup By - 5
--Where - 5
--m-n - 2
-->2 tabele - 9
--distinct - 3
--having - 3
