from catalog import Catalog
from studentValidator import StudentValidator
from studentRepo import StudentRepoFile
class Consola:
    def __init__(self):
        self.cat = Catalog(StudentValidator(), StudentRepoFile("stud.txt"))

    def addStudentUI(self):
        nrMatr = input("Dati nr matricol: ")
        nume = input("Dati numele: ")
        varsta = input("Dati varsta: ")
        st = self.cat.addStudent(nrMatr, nume, varsta)
        print(st.getNume() + "a fost adaugat cu succes")


    def printAllStudents(self):
        listOfStudents = self.cat.getAllStud()
        for student in listOfStudents:
            print(student.getNrMatricol() + " " + student.getNume() + " " + str(student.getVarsta()))

    def startUI(self):
        print("1 Add\n2 All students \n3 Filter by age \n4 View \n x Close")
        while True:
            cmd = input("Dati comanda dorita: ")
            if cmd == '1':
                self.addStudentUI()
            elif cmd == '2':
                self.printAllStudents()
            elif cmd == '3':
                studs = self.cat.filterByAge()
                for stud in studs:
                    print(stud.getVarsta(), stud.getCati())
            elif cmd == '4':
                toti = self.cat.getAllStud()
                for st in toti:
                    print(st.getNume(), st.getVarsta())
            else:
                exit()



