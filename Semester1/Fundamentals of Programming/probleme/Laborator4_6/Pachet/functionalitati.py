
def listaA(l,x):
    """
    Functia formeaza o lista noua in care se afla participantii care au scorul mai mic decat un scor dat
    Parametri:lista l, scorul x
    Returneaza: listA
    """
    listA=[]
    for i in range(len(l)):
        if l[i]<x:
            listA.append(l[i])
    return listA

def listaB(l):
    """
    Functia formeaza o lista noua in care se afla sortati participantii
    Parametri: lista l
    Returneaza: listB
    """
    listB=[]
    for i in range(len(l)):
        listB.append(l[i])
    listB.sort()
    return listB

def listaC(l,x):
    """
    Functia formeaza o lista noua in care se afla sortati participantii cu scorul mai mare decat un scor dat
    Parametri: lista l, scorul x
    Returneaza: listC
    """
    listC=[]
    for i in range(len(l)):
        if l[i]>x:
            listC.append(l[i])
    listC.sort()
    return listC
            
        
def test_ListaA():
    assert listaA([12,32,44,50],40)==[12,32]
    assert listaA([80,80,80,80,80,90,10],50)==[10]
    assert listaA([90],50)==[]
    
test_ListaA()

def test_ListaB():
    assert listaB([40,20,65,40,22,44])==[20,22,40,40,44,65]
    assert listaB([55,55,55,55,55,55])==[55,55,55,55,55,55]
    assert listaB([11,99,22,88,33,77])==[11,22,33,77,88,99]
    
test_ListaB()

def test_ListaC():
    assert listaC([60,40,20,65,44], 30)==[40,44,60,65]
    assert listaC([10,20,30,40], 50)==[]
    
test_ListaC()
