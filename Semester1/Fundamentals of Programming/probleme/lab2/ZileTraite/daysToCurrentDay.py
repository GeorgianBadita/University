import datetime as dt

currDay = dt.datetime.now().day
currMonth = dt.datetime.now().month
currYear = dt.datetime.now().year
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def validData(day, month, year):
    if day < 1 or day > 31 or month > 12 or month < 1 or year < 0:
        return False
    if currYear < year:
        return  False
    if currYear == year and month > currMonth:
        return  False
    if currYear == year and month == currMonth and day > currDay:
        return False
    return True


def isLeapYear(year):
    if year % 400 == 0:
        if year % 100 == 0:
            return True
    elif year % 4 == 0:
        return True
    return False

def daysInFrstYear(day, month, year):
    if year == currYear:
        return  0
    isLeap = isLeapYear(year)
    if isLeap:
        months[1] += 1
    days = 0
    days += months[month - 1] - day + 1
    for i in range(month + 1, 13):
        days += months[i - 1]
    if isLeap:
        months[1] -= 1
    return days

def countYears(year):
    if year == currYear:
        return  0
    days = 0
    year += 1
    for i in range(year, currYear):
        if isLeapYear(i):
            days += 366
        else:
            days += 365
    return days

def daysInLastYear(day, month, year):
    isLeap = isLeapYear(year)
    if isLeap:
        months[1] += 1
    days = 0
    days += day
    for i in range(0, month -1):
        days += months[i]
    if isLeap:
        months[1] -= 1
    return days


day = int(input("Day: "))
month = int(input("Month: "))
year = int(input("Year: "))

if not validData(day, month, year):
    print("Invalid date, please try again...")
else:
    res = daysInFrstYear(day, month, year) + countYears(year) + daysInLastYear(currDay, currMonth, currYear)
    print(str(res) + " days have past since " + str(day) + "/" + str(month) + "/" + str(year))

