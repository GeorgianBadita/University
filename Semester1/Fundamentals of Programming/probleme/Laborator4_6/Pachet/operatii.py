def media(l,capat1,capat2):
    """
    Functie care returneaza media scorurilor unui interval
    Parametri: lista l , capat1 si capat 2
    Returneaza: S/numar, media
    """
    lista=interval(l,capat1,capat2)
    S=suma(lista)
    numar=counter(capat1,capat2)
    return S/numar

def minim(l,capat1,capat2):
    """
    Functie care returneaza minimul dintr-un interval dat
    Parametri: lista l , capat1 si capat 2
    Returneaza: min(lista),minimul
    """
    lista=interval(l,capat1,capat2)
    return min(lista)

def multiplu(l,capat1,capat2):
    """
    Functie care formeaza o lista cu multiplii lui 10 dintr-un interval dat
    Parametri: lista l , capat1 si capat 2
    Returneaza: lista listM
    """
    lista=interval(l,capat1,capat2)
    listM=multiplu10(lista)
    return listM 
    
def suma(lista):
    """
    Functie care returneaza suma dintr-o lista
    Parametrii: lista 
    Returneaza: S, suma
    """
    S=0
    for i in range(0,len(lista)):
        S=S+lista[i]  
    return S


def counter(capat1, capat2):
    """
    Functia care numara cate elemente sunt intr-un interval
    Parametri: capat1 si capat 2
    Returneaza: valoare, numarul elementelor
    """
    valoare=capat2-capat1+1
    return valoare

def interval(l,capat1,capat2):
    """
    Functia care returneaza un interval dintr-o lista
    Parametri: lista l , capat1 si capat 2
    Returneaza: lista listaD
    """
    listaD=[]
    for i in range(capat1,capat2+1):
        listaD.append(l[i])
    return listaD

def multiplu10(l):
    """
    Functia care returneaza lista elementelor divizibile cu 10 dintr-o lista data
    Parametri: lista l 
    Returneaza: lista lista
    
    """
    lista=[]
    for i in range(0,len(l)):
        if l[i]%10==0:
            lista.append(l[i])
    return lista



def test_Suma():
    assert suma([30,40,20,90])==180
    
test_Suma()
    
def test_Interval():
    assert interval([30,40,20,40,50,60], 1, 3)==[40,20,40]
    assert interval([10,10,10,10,10,10,40,10,10], 1, 7)==[10,10,10,10,10,40,10]
    
test_Interval()
    
def test_counter():
    assert counter(2, 4)==3
    assert counter(2, 3)==2
    
test_counter()

def test_Minim():
    assert minim([30,20,10,30,40],0,4)==10
    assert minim([30,20,500,500,30], 2, 3)==500
    
test_Minim()

def test_Multiplu():
    assert multiplu([10,20,40,34,50,30], 0, 5)==[10,20,40,50,30]
    assert multiplu([32,12,92,30,40,11,223,4], 0, 3)==[30]
    
test_Multiplu()

    
def test_Media():
    assert media([40,50,20,60,70,30,20], 1, 3)==43.333333333333336
    assert media([40,40,40,40,40,40,40], 0, 6)==40.0
    assert media([15,20], 0, 1)==17.5
    
test_Media()