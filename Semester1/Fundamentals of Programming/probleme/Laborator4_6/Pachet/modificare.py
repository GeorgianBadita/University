def stergereParticipant(l,x):
    """
    """
    y=l[x]
    l.remove(y)
    return l
    
def stergereInterval(l,capat1,capat2):
    """
    Functie care sterge un interval dat de scoruri
    Parametri: lista l, capat1 si capat2
    Returneaza: lista l, modificata
    """
    for i in range(capat1,capat2+1):
        stergereParticipant(l, capat1)    
    return l 

def inlocuire(l,i,x):
    """
    Functie care inlocuieste scorul unui participant
    Parametri: lista l, index i si scor x
    Returneaza: lista l, modificata
    """
    l[i]=x
    return l 
    

def test_stergereParticipant():
    assert stergereParticipant([50,30,50,60,40], 1)==[50,50,60,40]
    assert stergereParticipant([50], 0)==[]

test_stergereParticipant()

def test_stergereInterval():
    assert stergereInterval([40,20,66,50,40], 0, 3)==[40]
    assert stergereInterval([90,55,34,22,19,40,70,99], 2, 5)==[90,55,70,99]
    
test_stergereInterval()

def test_inlocuire():
    assert inlocuire([60,40,30,20,77,90,22], 2, 60)==[60,40,60,20,77,90,22]
    assert inlocuire([80,33,40,50], 0, 77)==[77,33,40,50]
    
test_inlocuire()