from domain.Discipline import Discipline
from domain.Grade import Grade
from domain.Student import Student
from repository.DisciplineRepository import DisciplineRepositoryException
from repository.StudentRepository import StudentRepositoryException


class StudentFileRepository:
    '''
    Class responsible for managing a list of students (store, retrieve, update, etc.)
    '''

    def __init__(self, fileName):
        '''
        initialise repository
        :param fileName: string, filepath where the students are stored
        post: students are loaded from the file
        '''
        self.__fileName = fileName

    def __loadFromFile(self):
        '''
        Load students from file
        raise CorruptedFileException if there is an error when reading from the file
        :return:
        '''

        try:
            f = open(self.__fileName, "r")
        except IOError:
            print(self.__fileName)
            #file not exist
            return
        line = f.readline().strip()
        studs = []
        while line != "":
            attrs = line.split(",")
            st = Student(attrs[0], attrs[1])
            studs.append(st)
            line = f.readline().strip()
        f.close()
        return studs

    def store_student_rep(self, st):
        '''
        Store the student to the file. Overwrite store
        st - student
        :return:
        '''

        allS = self.__loadFromFile()
        if st in allS:
            raise StudentRepositoryException("A student with this ID already exists! ")
        allS.append(st)
        self.__storeToFile(allS)
        return  True

    def __storeToFile(self, allS):
        '''
        Store all the stundents into the file
        raise CorruptedFileException if we can not store to the file
        :param allS:
        :return:
        '''

        with open(self.__fileName, "w") as f:
            for st in allS:
                strf = str(st.student_id()) + ',' + st.student_name()
                strf += "\n"
                f.write(strf)

    def delete_student_rep(self, student):
        '''
        remove a student from the repository
        student - Student
        :post: the repository not contains student
        :return: student  if the student was deleted
        None otherwise
        '''
        allS = self.__loadFromFile()
        poz = -1
        print(student)
        for i in range(len(allS)):
            if allS[i] == student:
                poz = i

        if poz == -1:
            return  None

        del allS[poz]
        self.__storeToFile(allS)
        return student

    def find_student_rep(self, student_id):
        '''
        Find the student for a given id
        :param student_id: string
        :return: student with the given id, None otherwise
        '''

        studs = self.__loadFromFile()
        for st in studs:
            if str(st.student_id()) == str(student_id):
                return st
        return False

    def update_student_rep(self, student, student_name):
        '''
        Update student in the repository
        :param student: student to be updated
        :param student_name: new name of the student
        :return:
        '''

        allS = self.__loadFromFile()
        for st in allS:
            if str(st.student_id()) == str(student.student_id()):
                st.set_student_name(student_name)
                self.__storeToFile(allS)
                return True
        return False

    def find_student_name_rep(self, student_name):
        '''
            Searching all students matching/partially matching a given name
            :param student_name: given name
            :return: a list of all students matching/partially matching a given name
        '''
        new_list = []
        studs = self.__loadFromFile()
        for student in studs:
            if str.lower(student_name) in str.lower(student.student_name()):
                new_list.append(student.__str__())
        if len(new_list) > 0:
            return new_list
        else:
            raise StudentRepositoryException("There is no matching student! ")

    def find_student_id_rep(self, student_id):
        '''
        Searching all students matching/partially matching a given id
        :param student_id: given id
        :return: a list of all students matching/partially matching a given id
        '''
        new_list = []
        studs = self.__loadFromFile()
        for student in studs:
            if str(student_id) in str(student.student_id()):
                new_list.append(student.__str__())
        if len(new_list) > 0:
            return new_list
        else:
            raise StudentRepositoryException("There is no matching student! ")



    def get_all_students_rep(self):
        return self.__loadFromFile()

    def remove_all_students_rep(self):
        self.__storeToFile([])

    def size(self):
        return len(self.__loadFromFile())


def test_student_repo():

    fileName = "test1.txt"
    repo = StudentFileRepository(fileName)
    repo.remove_all_students_rep()
    st1 = Student("1", "Alexandra")
    st2 = Student("2", "Gabi")
    st3 = Student("3", "Sinko")
    st4 = Student("11", "Stix")

    repo.store_student_rep(st1)
    repo.store_student_rep(st2)
    repo.store_student_rep(st3)
    repo.store_student_rep(st4)

    assert repo.size() == 4
    assert repo.find_student_id_rep("1") == ['Id:1, Name: Alexandra', 'Id:11, Name: Stix']
    assert repo.delete_student_rep(st1)
    repo1 = StudentFileRepository(fileName)
    assert  repo1.size() == 3

#test_student_repo()


class DisciplineFileRepository:
    '''
    Class responsible for managing a list of disciplines (store, retrieve, update, etc.)
    '''

    def __init__(self, fileName):
        '''
        initialise repository
        :param fileName: string, filepath where the disciplines are stored
        post: disciplines are loaded from the file
        '''
        self.__fileName = fileName

    def __loadFromFile(self):
        '''
        Load disciplines from file
        raise CorruptedFileException if there is an error when reading from the file
        :return:
        '''

        try:
            f = open(self.__fileName, "r")
        except IOError:
            print(self.__fileName)
            #file not exist
            return
        line = f.readline().strip()
        discs = []
        while line != "":
            attrs = line.split(",")
            disc = Discipline(attrs[0], attrs[1])
            discs.append(disc)
            line = f.readline().strip()
        f.close()
        return discs

    def store_discipline_rep(self, disc):
        '''
        Store the student to the file. Overwrite store
        disc - discipline
        :return:
        '''

        allD = self.__loadFromFile()
        if disc in allD:
            raise DisciplineRepositoryException("A discipline with this ID already exists. ")
        allD.append(disc)
        self.__storeToFile(allD)
        return  True

    def __storeToFile(self, allD):
        '''
        Store all the disciplines into the file
        raise CorruptedFileException if we can not store to the file
        :param allD:
        :return:
        '''

        with open(self.__fileName, "w") as f:
            for disc in allD:
                strf = str(disc.discipline_id()) + ',' + disc.discipline_name()
                strf += "\n"
                f.write(strf)

    def delete_discipline_rep(self, discipline):
        '''
        remove a discipline from the repository
        discipline - Discipline
        :post: the repository not contains discipline
        :return: student  if the student was deleted
        None otherwise
        '''
        allD = self.__loadFromFile()
        poz = -1
        for i in range(len(allD)):
            if allD[i] == discipline:
                poz = i
                break
        if poz == -1:
            return  None

        del allD[poz]
        self.__storeToFile(allD)
        return  discipline

    def find_discipline_rep(self, discipline_id):
        '''
        Find the student for a given id
        :param discipline_id: string
        :return: discipline with the given id, None otherwise
        '''

        discs = self.__loadFromFile()
        for disc in discs:
            if str(disc.discipline_id()) == str(discipline_id):
                return disc
        return False

    def update_discipline_rep(self, discipline, discipline_name):
        '''
        Update student in the repository
        :param discipline: discipline to be updated
        :param discipline_name: new name of the discipline
        :return:
        '''

        allD = self.__loadFromFile()
        for disc in allD:
            if str(disc.discipline_id()) == str(discipline.discipline_id()):
                discipline.set_discipline_name(discipline_name)
                self.__storeToFile(allD)
                return True
        return False


    def find_discipline_name_rep(self, discipline_name):
        '''
        Searching all disciplines in the repository matching/partially matching a given name
        :param discipline_name: discipline name to search by
        :return: a list of all disciplines that match the criteria
        '''
        new_list = []
        allD = self.__loadFromFile()
        for discipline in allD:
            if str.lower(discipline_name) in str.lower(discipline.discipline_name()):
                new_list.append(discipline.__str__())
        if len(new_list) > 0:
            return new_list
        else:
            raise DisciplineRepositoryException("There is no matching discipline! ")

    def find_discipline_id_rep(self, discipline_id):
        '''
        Searching all disciplines in the repository matching/partially matching a given id
        :param discipline_id: discipline id to search by
        :return: a list of all disciplines that match the criteria
        '''
        new_list = []
        allD = self.__loadFromFile()
        for discipline in allD:
            if str(discipline_id) in str(discipline.discipline_id()):
                new_list.append(discipline.__str__())
        if len(new_list) > 0:
            return new_list
        else:
            raise DisciplineRepositoryException("There is no matching discipline! ")




    def get_all_disciplines_rep(self):
        return self.__loadFromFile()

    def remove_all_disciplines_rep(self):
        self.__storeToFile([])

    def size(self):
        return len(self.__loadFromFile())


def test_disc_repo():

    fileName = "test2.txt"
    repo = DisciplineFileRepository(fileName)
    repo.remove_all_disciplines_rep()
    disc1 = Discipline("1", "FP")
    disc2 = Discipline("2", "Analiza")
    disc3 = Discipline("3", "ASC")
    disc4 = Discipline("11", "Algebra")

    repo.store_discipline_rep(disc1)
    repo.store_discipline_rep(disc2)
    repo.store_discipline_rep(disc3)
    repo.store_discipline_rep(disc4)

    assert repo.size() == 4
    assert repo.find_discipline_id_rep("1") == ['ID:1, Name: FP', 'ID:11, Name: Algebra']
    assert repo.delete_discipline_rep(disc1)
    assert repo.find_discipline_name_rep("ASC") == ['ID:3, Name: ASC']
    repo1 = StudentFileRepository(fileName)
    assert  repo1.size() == 3

#test_disc_repo()

class GradeFileRepository:
    '''
    Class to manage grades
    '''
    def __init__(self, fileName):
        '''
        initialise repository
        :param fileName - string, file path where the grades are stored
        post: grades are loaded from the file
        '''
        self.__fileName = fileName

    def __loadFromFile(self):
        '''
        Load grades from file
        raise CorruptedFileException if there is an error reading from the file
        :return:
        '''
        try:
            f = open(self.__fileName, "r")
        except IOError:
            print("Me not real?")
            print(self.__fileName)
            #file doesn't exist
            return
        line = f.readline().strip()
        grades = []
        while line != "":
            attrs = line.split(",")
            grade = Grade(attrs[0], attrs[1], attrs[2])
            grades.append(grade)
            line = f.readline().strip()
        f.close()
        return grades

    def __storeToFile(self, allG):
        '''
        Store all grades into the file
        raise CorruptedFileException if we can not store to the file
        :return:
        '''
        #open file
        with open(self.__fileName, "w") as f:
            for grade in allG:
                strf = str(grade.discipline_id()) + "," + str(grade.student_id()) + "," + str(grade.grade_value())
                strf += "\n"
                f.write(strf)

    def store_grade_rep(self, grade):
        '''
        Add  grade to the repository
        :param grade: grade to be added
        :return:
        '''
        allG = self.__loadFromFile()
        allG.append(grade)
        self.__storeToFile(allG)
        return True

    def delete_last_grade_rep(self):
        '''
        Function that deletes the last added grade
        :return:
        '''
        allG = self.__loadFromFile()
        allG.pop()
        self.__storeToFile(allG)

    def delete_gstudent_rep(self, student_id):
        '''
        Delete a student from the repository
        :param student_id: id of a student to be deleted
        '''
        list_deleted = []
        allG = self.__loadFromFile()
        grades = allG.copy()
        for item in grades:
            if str(item.student_id()) == str(student_id):
                list_deleted.append(item)
                allG.remove(item)
        self.__storeToFile(allG)
        return list_deleted

    def assign_grades_rep(self, list_grades):
        '''
        Assign more grades given as a list with id, disc and grade
        :param list_grades:
        :return:
        '''

        for grade in list_grades:
            self.store_grade_rep(grade)

    def delete_gdiscipline_rep(self, discipline_id):
        '''
        Delete all grades at a discipline from the repository
        :param discipline_id: id of the given discipline
        '''
        list_deleted = []
        allG = self.__loadFromFile()
        disciplines = allG.copy()
        for item in disciplines:
            if str(item.discipline_id()) == str(discipline_id):
                list_deleted.append(item)
                allG.remove(item)
        self.__storeToFile(allG)
        return list_deleted

    def assign_grades_disc_rep(self, list_grades):
        '''
        Reassign more grades given as a list with id, disc and grade
        :param list_grades:
        :return:
        '''

        for grade in list_grades:
            self.store_grade_rep(grade)

    def get_students_at_discipline(self, discipline_id):
        '''
        Get all students from the repository that are enrolled at a given discipline
        :param discipline_id: id of the given discipline
        :return: list of all students enrolled at the given discipline
        '''
        new_list = []
        allG = self.__loadFromFile()
        for item in allG:
            if str(item.discipline_id()) == str(discipline_id):
                new_list.append(item.student_id())
        return new_list

    def student_average_at_discipline(self, student_id, discipline_id):
        '''
        Get a student average grade at a given discipline
        :param student_id: id of the given student
        :param discipline_id: id of the given discipline
        :return: average grade of the student
        '''
        new_list = []
        allG = self.__loadFromFile()
        for item in allG:
            if str(item.student_id()) == str(student_id) and str(item.discipline_id()) == str(discipline_id):
                new_list.append(item.grade_value())
        total = 0
        for grade in new_list:
            total += float(grade)

        return total / len(new_list)

    def student_average(self, student_id):
        '''
        Get the student average at all the disciplines he is enrolled to
        :param student_id: id of the given student
        :return: average grade
        '''
        new_list = []
        allG = self.__loadFromFile()
        for item in allG:
            if item.student_id() == student_id:
                new_list.append(item.grade_value())
        total = 0
        for grade in new_list:
            total += grade
        if len(new_list) > 0:
            return float(total / len(new_list))
        else:
            return 0

    def average_grade_rep(self, student_id, discipline_id):
        '''
        Get the aggregated grade of a student at a discipline
        :param student_id: id of the given student
        :param discipline_id: id of the given discipline
        :return: aggregated grade
        '''
        s = 0
        cont = 0
        allG = self.__loadFromFile()
        for item in allG:
            if item.student_id() == student_id and item.discipline_id() == discipline_id:
                s += float(item.grade_value())
                cont += 1
        if cont > 0:
            return float(s / cont)
        else:
            return 0

    def average_discipline_rep(self, discipline_id):
        '''
        Get the average of all the grades at a discipline
        :param discipline_id: id of the given discipline
        :return: average grade at the given discipline
        '''
        s = 0
        cont = 0
        allG = self.__loadFromFile()
        for item in allG:
            if item.discipline_id() == discipline_id:
                s += float(item.grade_value())
                cont += 1
        if cont > 0:
            return float(s / cont)
        else:
            return 0

    def get_all_grades_rep(self):
        '''
        Get all grades in the repository in the order they were added
        :return: list of all grades in the repository
        '''
        return self.__loadFromFile()

    def remove_all_grades_rep(self):
        self.__storeToFile([])