LISTA=[]
import Pachet.citire
import Pachet.adaugare
import Pachet.functionalitati
import Pachet.tiparire
import Pachet.modificare
import Pachet.mesaje
import Pachet.filtrare
import Pachet.operatii

def meniu():
    while True:
        Pachet.mesaje.mesaje()
        
        x=int(input())
        
        if x==0:
            exit()
        if x==1:
            n=int(input("Tasteaza numarul participantilor:"))
            l=Pachet.citire.citireScor(n)
            LISTA.append(l)
            
        if x==2:
            x=Pachet.citire.citireScoradaugare()
            l=Pachet.adaugare.adaugareSfarsit(l, x)
            LISTA.append(l)  
              
        if x==3:
            x=Pachet.citire.citireScoradaugare()
            i=Pachet.citire.citireIndiceinlocuire()
            l=Pachet.adaugare.inserareScor(l, x, i)
            LISTA.append(l)
        if x==4:
            x=Pachet.citire.citireScorListAC()
            listA=Pachet.functionalitati.listaA(l, x)
            Pachet.tiparire.tiparirelista(listA)
            
        if x==5:
            x=Pachet.citire.citireScorListAC()
            listB=Pachet.functionalitati.listaB(l)
            Pachet.tiparire.tiparirelista(listB)
        if x==6:
            x=Pachet.citire.citireScorListAC()
            listC=Pachet.functionalitati.listaC(l,x)
            Pachet.tiparire.tiparirelista(listC)
        if x==7:
            i=Pachet.citire.citireIndicestergere()
            l=Pachet.modificare.stergereParticipant(l, i)
            LISTA.append(l)
        if x==8:
            capat1=Pachet.citire.citireCapat1()
            capat2=Pachet.citire.citireCapat2(l)
            l=Pachet.modificare.stergereInterval(l, capat1, capat2)
            LISTA.append(l)
        if x==9:
            i=Pachet.citire.citireIndiceinlocuire()
            x=Pachet.citire.citireScorinlocuire()
            l=Pachet.modificare.inlocuire(l, i, x)
            LISTA.append(l)
        if x==10:
            capat1=Pachet.citire.citireCapat1()
            capat2=Pachet.citire.citireCapat2(l)
            media=Pachet.operatii.media(l, capat1, capat2)
            Pachet.tiparire.tiparireNumar(media)
        if x==11:
            capat1=Pachet.citire.citireCapat1()
            capat2=Pachet.citire.citireCapat2(l)
            valoare=Pachet.operatii.minim(l, capat1, capat2)
            Pachet.tiparire.tiparireNumar(valoare)
        if x==12:
            capat1=Pachet.citire.citireCapat1()
            capat2=Pachet.citire.citireCapat2(l)
            listM=Pachet.operatii.multiplu(l, capat1, capat2)
            Pachet.tiparire.tiparirelista(listM)
                
        if x==13:
            x=Pachet.citire.citireMultiplu()
            l=Pachet.filtrare.multipluX(l, x)
            LISTA.append(l)
        if x==14:
            x=Pachet.citire.citireNumar()
            l=Pachet.filtrare.filtrare_Mic(l, x)
            LISTA.append(l) 
        
        if x == 15:
            l = Pachet.filtrare.filtrare_prim(l)
            LISTA.append(l)
        if x==16:
            if len(LISTA)>0:
                l=LISTA[len(LISTA)-2]
                del LISTA[len(LISTA)-1]
            else:
                print("Nu se poate efectua functia undo deoarece nu s-au efectuat actiuni asupra listei vide")
                
        if x==17:
            Pachet.tiparire.tiparirelista(l)
            
print(meniu())
