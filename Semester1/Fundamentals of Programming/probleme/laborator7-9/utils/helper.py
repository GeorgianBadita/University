'''
Created on Nov 20, 2017

@author: Geo
'''
import random, string

def rand_int():
    '''
    Returns a random integer between 6 and 200
    '''
    return random.randint(6, 20000)

def rand_string(length):
    '''
    Returns a random string
    '''
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for letter in range(length))
    

def print_list(list):
    '''
    Function that prints a given list
    '''
    for item in list:
        print(item)


def read_int(text):
    while True:
        try:
            num = int(input(text))
            return num
        except ValueError:
            print("The number must be a positivie integer!")


def date_validation(date):
    '''
    Validates a date
    :param date:
    :return: None if the date is correct, else returns a list with errors
    '''
    errors = []
    try:
        day, month, year = get_date(date)
        if day < 1 or day > 31:
            errors.append("The day must be between 1 and 31")
        if month < 1 or month > 12:
            errors.append("The month must be between 1 and 12")
        if year < 2000 or year > 2050:
            errors.append("The year must be between 2010 and 2050")
        return errors
    except ValueError:
        errors.append("Date format incorrect!")
        return errors
    except IndexError:
        errors.append("Date format incorrect!")
        return errors



def get_date(date):
    '''
    gets a date from a string if it exists
    :param date:
    :return: int values day, month, year if they are correct
    '''
    date.split("/")
    day = int(date[0])
    day = day * 10 + int(date[1])
    month = int(date[3])
    month = month * 10 + int(date[4])
    year = int(date[6])
    year = year * 10 + int(date[7])
    year = year * 10 + int(date[8])
    year = year * 10 + int(date[9])
    if len(date) > 10:
        year *= 10
    return day, month, year


def hour_validation(hour):
    '''
    Validates if an hour is correct
    :param hour:
    :return: None if the hour is correct else returns errors
    '''
    errors = []
    try:
        hh, mm = get_hour(hour)
        if hh < 1 or hh > 24:
            errors.append("The hour must be an integer between 1 and 24")
        if mm < 0 or mm > 59:
            errors.append("The minute must be an integer between 0 and 59")
        return errors
    except ValueError:
        errors.append("The hour format is incorrect!")
        return errors
    except IndexError:
        errors.append("The hour format is incorrect!")
        return errors

def get_hour(hour):
    '''
    gets hour from a string if it exists
    :param hour:
    :return: two values hh, mm representing the hour and the minute
    '''
    hour.split(":")
    hh = int(hour[0])
    hh = hh * 10 + int(hour[1])
    mm = int(hour[3])
    mm = mm * 10 + int(hour[4])

    return hh, mm


def make_key(key):
    '''
    Function that returns the key of the sorting function
    '''
    if key is None:
        return lambda x:x
    elif key != None:
        return key


def quick_sort(list, *, key = lambda x : x, reverse = False):
    '''
    Quicksort using list comprehension
    '''
    #key = make_key(key)
    if len(list) <= 1:
        return list
    else:
        pivot = list[0]
        lower = quick_sort([x for x in list[1:] if key(x) < key(pivot)], key = key, reverse = reverse)
        greater = quick_sort([x for x in list[1:] if key(x) >= key(pivot)], key = key, reverse = reverse)
        
        if reverse == False:
            return lower + [pivot] + greater
        elif reverse == True:
            return greater + [pivot] + lower
    

def gnome_sort(lst, *, key=lambda x: x, reverse=False):
    """
    Function to implement the gnome sort
    """

    """
    key = make_key(key)
    """
    pos = 0
    while pos < len(lst):
        if pos == 0 or key(lst[pos]) >= key(lst[pos - 1]):
            pos = pos + 1
        else:
            lst[pos], lst[pos - 1] = lst[pos - 1], lst[pos]
            pos = pos - 1
    
    if reverse is False:
        return lst
    elif reverse is True:
        return lst[::-1]

