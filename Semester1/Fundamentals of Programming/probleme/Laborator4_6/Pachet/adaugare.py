def adaugareSfarsit(l,x):
    """
    Functia adauga la sfarsitul listei scorul ultimului concurent adaugat in aceasta
    Parametri: lista l, valoarea x
    Returneaza: lista in urma operatiei de adaugare la sfarsit
    """
    if x>-1 and x<101:
        l.append(x)
    else:
        print("Introdu o valoare corecta:")
    return l
def inserareScor(l,x,i):
    """
    Functia insereaza scorul unui participant
    Parametri: lista l, x-valoarea, i-indicele
    Returneaza:lista in urma efectuarii operatiei de inserare
    """
    if x>-1 and x<101:
        l.insert(i,x)
    else:
        print("Introdu o valoare corecta:")
    return l

def test_adaugareSfarsit():
    assert adaugareSfarsit([10,20], 30)==[10,20,30]

test_adaugareSfarsit()

def test_inserareScor():
    assert inserareScor([30,20,10,40,30], 99, 3)==[30,20,10,99,40,30]
    
