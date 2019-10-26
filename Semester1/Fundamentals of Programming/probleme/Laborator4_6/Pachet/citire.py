
def citireScor(n):
    """
    Functia citeste scorul corespunzator fiecarui participant
    Parametrii: n
    Returneaza: lista l 
    """
    l=[]
    for i in range(1,n+1):
        x=int(input("Tasteaza scorul participantului i:"))
        if x>-1 and x<101:
            l.append(x)
        else:
            print("Introdu o valoare corecta")
            i=i-1
    return l

def citireCapat1():
    """
    Functia citeste primul capat al unui interval
    Parametrii: 
    Returneaza: capat1- valoarea citita a intervalului
    Raise ValueError if capat<0
    """
    capat1=int(input("Introdu primul capat al intervalului"))
    if capat1<0:
        raise ValueError("Introdu corect primul capat al intervalului")
    return capat1

def citireCapat2(l):
    """
    Functia citeste ultimul capat al unui interval
    Parametrii: l
    Returneaza: capat2- valoarea citita a intervalului
    Raise ValueError if capat2>len(l)
    """
    capat2=int(input("Introdu al doilea capat al intervalului"))
    if capat2>=len(l):
        raise ValueError("Introdu corect primul capat al intervalului")
    return capat2

def citireIndicestergere():
    """
    Functia citeste indicele participantului care trebuie sters
    Parametri: 
    Returneaza: x-valoarea indicelui
    """
    x=int(input("Tasteaza indicele participantului"))
    return x

def citireIndiceinlocuire():
    """
    Functia citeste indicele participantului care trebuie inlocuit
    Parametri: 
    Returneaza: i-valoarea indicelui
    """
    i=int(input("Introdu indexul participantului in lista a carui scor trebuie inlocuit:"))
    return i 

def citireScorinlocuire():
    """
    Functia citeste scorul participantului ce trebuie inlocuit
    Parametri: 
    Returneaza: x-valoarea scorului
    Raise ValueError if x>100 or x<0
    """
    x=int(input("Introdu scorul pentru inlocuire"))
    if x>100 or x<0:
        raise ValueError("Introdu o valoare corecta")
    return x

def citireScorListAC():
    """
    Functia citeste scorul participantului 
    Parametri: 
    Returneaza: x-valoarea scorului
    Raise ValueError if x>100 or x<0
    """
    x=int(input("Introdu scorul:"))
    if x>100 or x<0:
        raise ValueError("Introdu o valoare corecta")
    return x 

def citireScoradaugare():
    """
    Functia citeste scorul participantului ce trebuie adaugat la sfarsitul listei
    Parametri: 
    Returneaza: x-valoarea scorului
    Raise ValueError if x>100 or x<0
    """
    x=int(input("Adauga scorul unui nou participant, la sfarsitul listei:"))
    if x>100 or x<0:
        raise ValueError("Introdu o valoare corecta")
    return x

def citireMultiplu():
    """
    Functia citeste divizorul ce va fi folosit in functia de filtrare
    Parametri:
    Returneaxa: x-valoarea divizorului dorit
    """
    x=int(input("Adauga divizorul dorit"))
    return x

def citireNumar():
    """
    Functia citeste scorul participantului 
    Parametri: 
    Returneaza: x-valoarea scorului
    Raise ValueError if x>100 or x<0
    """
    x=int(input("Adauga numar"))
    if x>100 or x<0:
        raise ValueError("Introdu o valoare corecta")
    return x