
def multipluX(l,x):
    """
    Functie ce returneaza lista dupa ce a fost efectuata filtrarea multiplilor unui numar
    Parametri:lista l si divizorul x
    Returneaza: lista l dupa ce a fost modificata
    """
    newList=[]
    for i in range(0,len(l)):
        if l[i]%x==0:
            newList.append(l[i])
    l=newList
    return l 

def filtrare_Mic(l,x):
    """
    Functie ce returneaza lista dupa ce a fost efectuata filtrarea scorurilor mai mici decat un scor dat
    Parametri: lista l si numarul x
    Returneaza:listF, lista filtrata
    """
    listF=[]
    for i in range(0,len(l)):
        if l[i]<x:
            listF.append(l[i])
    return listF



def ePrim(x):
    '''
    Functie care returneaza True daca x e numar prim sau False altfel
    Parametrii: numarul x
    Returneaza: True daca x e prim sau fals altfel
    '''
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    for i in range(3, x):
        if x % i == 0:
            return False
    return True

def filtrare_prim(l):
    '''
    Functie ce returneaza lista dupa ce a fost efectuata filtrarea scorurilor numere prime
    Parametrii: lista l
    Returneaza: listF, lista filtrata
    '''
    listF = []
    for i in range(0, len(l)):
        if ePrim(l[i]):
            listF.append(l[i])
            
    return listF
            
            
def testEprim():
    assert ePrim(2) == True
    assert ePrim(4) == False
    assert ePrim(11) == True

def test_MultipluX():
    assert multipluX([10,41,232,4,1,2,22,90], 10)==[10,90]  
    assert multipluX([6,12,5,25,100,24], 3)==[6,12,24]
    
test_MultipluX()

def test_filtrareMic():
    assert filtrare_Mic([55,20,30,50,10,30,40,77], 53)==[20,30,50,10,30,40]
    
test_filtrareMic()

