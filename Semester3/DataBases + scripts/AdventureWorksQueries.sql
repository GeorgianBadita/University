SELECT ProductID, Name
FROM Production.Product
WHERE Name = 'Blade' AND ProductID >= 12

SELECT ProductID, Name
FROM Production.Product
WHERE ProductID = 2 OR ProductID = 4 OR Name = 'Spokes'

SELECT ProductID, Name, Color
FROM Production.Product
WHERE Name LIKE ('%Frame%')
AND Name LIKE ('HL%') AND Color = 'Red' ; 

SELECT ProductID, Name, Color
FROM Production.Product
WHERE Name IN ('Blade', 'Crown Race', 'Spokes');


SELECT ProductID, Name, Color
FROM Production.Product
WHERE ProductID BETWEEN 725 AND 734

SELECT AVG(UnitPrice) AS [Average Price]
FROM Sales.SalesOrderDetail;

SELECT Name, ProductNumber, ListPrice AS Price
FROM Production.Product
ORDER BY Name DESC;SELECT Name, ProductNumber, ListPrice
FROM Production.Product
WHERE ProductLine = 'R' AND DaysToManufacture < 4
ORDER BY Name;SELECT ProductID, Name
FROM Production.Product
WHERE Name LIKE 'Lock Washer%'
ORDER BY ProductID ASC; 

SELECT DISTINCT TOP 5 JobTitle
FROM HumanResources.Employee
ORDER BY JobTitle;