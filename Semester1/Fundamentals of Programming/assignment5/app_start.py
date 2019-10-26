from domain.Discipline import Discipline
from controller.DisciplineController import DisciplineController
from repository.DisciplineRepository import DisciplineRepository
from domain.Grade import Grade
from controller.GradeController import GradeController
from repository.GradeRepository import GradeRepository
from domain.Student import Student
from controller.StudentController import StudentController
from repository.StudentRepository import StudentRepository
from repository.fileRepo import StudentFileRepository, DisciplineFileRepository, GradeFileRepository
from validator.Validator import StudentValidator, DisciplineValidator, GradeValidator
from console_ui import UI

student_validator = StudentValidator()
discipline_validator = DisciplineValidator()
grade_validator = GradeValidator()

'''
initializing the repositories
including the validators of input data
'''

#student_repository = StudentRepository(student_validator)
#discipline_repository = DisciplineRepository(discipline_validator)
#grade_repository = GradeRepository(grade_validator)

student_repository = StudentFileRepository("test1.txt")
student_repository.remove_all_students_rep()
discipline_repository = DisciplineFileRepository("test2.txt")
discipline_repository.remove_all_disciplines_rep()
grade_repository = GradeFileRepository("test3.txt")
grade_repository.remove_all_grades_rep()
'''
adding items to the repositories
'''

student_repository.store_student_rep(Student(1, 'Tudor'))
student_repository.store_student_rep(Student(2, 'Razvan'))
student_repository.store_student_rep(Student(3, 'Diana'))
student_repository.store_student_rep(Student(4, 'Ana'))
student_repository.store_student_rep(Student(5, 'Alexandru'))
student_repository.store_student_rep(Student(6, 'Bogdan'))
student_repository.store_student_rep(Student(7, 'Izabela'))
student_repository.store_student_rep(Student(8, 'George'))
student_repository.store_student_rep(Student(9, 'Andrei'))
student_repository.store_student_rep(Student(10, 'Stefania'))
student_repository.store_student_rep(Student(11, 'Alexandra'))
student_repository.store_student_rep(Student(12, 'Eduard'))
student_repository.store_student_rep(Student(13, 'Cezar'))
student_repository.store_student_rep(Student(14, 'Paul'))
student_repository.store_student_rep(Student(15, 'Vlad'))
student_repository.store_student_rep(Student(16, 'Cristian'))
student_repository.store_student_rep(Student(17, 'Maria'))
student_repository.store_student_rep(Student(18, 'Mirela'))
student_repository.store_student_rep(Student(19, 'Mihai'))
student_repository.store_student_rep(Student(20, 'Claudiu'))


discipline_repository.store_discipline_rep(Discipline(1, 'Computer Systems Architecture'))
discipline_repository.store_discipline_rep(Discipline(2, 'Computational Logic'))
discipline_repository.store_discipline_rep(Discipline(3, 'Mathematical Analysis'))
discipline_repository.store_discipline_rep(Discipline(4, 'Algebra'))
discipline_repository.store_discipline_rep(Discipline(5, 'Fundamentals of programming'))
discipline_repository.store_discipline_rep(Discipline(6, 'Data Structures and Algorithms'))
discipline_repository.store_discipline_rep(Discipline(7, 'Graph Algorithms'))
discipline_repository.store_discipline_rep(Discipline(8, 'Operating Systems'))


grade_repository.store_grade_rep(Grade(1, 1, 3.5))
grade_repository.store_grade_rep(Grade(3, 1, 5.4))
grade_repository.store_grade_rep(Grade(5, 1, 2.5))
grade_repository.store_grade_rep(Grade(7, 1, 1.7))
grade_repository.store_grade_rep(Grade(2, 2, 6.5))
grade_repository.store_grade_rep(Grade(4, 2, 5.0))
grade_repository.store_grade_rep(Grade(6, 2, 4.8))
grade_repository.store_grade_rep(Grade(8, 2, 9.3))
grade_repository.store_grade_rep(Grade(1, 3, 8.5))
grade_repository.store_grade_rep(Grade(2, 3, 9.0))
grade_repository.store_grade_rep(Grade(3, 3, 7.0))
grade_repository.store_grade_rep(Grade(4, 3, 7.6))
grade_repository.store_grade_rep(Grade(5, 4, 9.4))
grade_repository.store_grade_rep(Grade(6, 4, 5.7))
grade_repository.store_grade_rep(Grade(7, 4, 7.7))
grade_repository.store_grade_rep(Grade(8, 4, 6.8))
grade_repository.store_grade_rep(Grade(8, 5, 7.6))
grade_repository.store_grade_rep(Grade(7, 5, 9.8))
grade_repository.store_grade_rep(Grade(6, 5, 4.3))
grade_repository.store_grade_rep(Grade(5, 5, 6.8))
grade_repository.store_grade_rep(Grade(4, 6, 8.4))
grade_repository.store_grade_rep(Grade(3, 6, 7.0))
grade_repository.store_grade_rep(Grade(2, 6, 5.5))
grade_repository.store_grade_rep(Grade(1, 6, 3.5))
grade_repository.store_grade_rep(Grade(8, 7, 8.3))
grade_repository.store_grade_rep(Grade(6, 7, 8.0))
grade_repository.store_grade_rep(Grade(4, 7, 4.2))
grade_repository.store_grade_rep(Grade(2, 7, 8.5))
grade_repository.store_grade_rep(Grade(7, 8, 9.6))
grade_repository.store_grade_rep(Grade(5, 8, 7.0))
grade_repository.store_grade_rep(Grade(3, 8, 4.5))
grade_repository.store_grade_rep(Grade(1, 8, 6.8))
grade_repository.store_grade_rep(Grade(1, 9, 5.0))
grade_repository.store_grade_rep(Grade(3, 9, 7.25))
grade_repository.store_grade_rep(Grade(5, 9, 9.0))
grade_repository.store_grade_rep(Grade(7, 9, 6.3))
grade_repository.store_grade_rep(Grade(2, 10, 7.4))
grade_repository.store_grade_rep(Grade(4, 10, 9.0))
grade_repository.store_grade_rep(Grade(6, 10, 8.2))
grade_repository.store_grade_rep(Grade(8, 10, 6.9))
grade_repository.store_grade_rep(Grade(1, 11, 5.25))
grade_repository.store_grade_rep(Grade(2, 11, 2.3))
grade_repository.store_grade_rep(Grade(3, 11, 5.0))
grade_repository.store_grade_rep(Grade(4, 11, 6.7))
grade_repository.store_grade_rep(Grade(5, 12, 6.0))
grade_repository.store_grade_rep(Grade(6, 12, 7.5))
grade_repository.store_grade_rep(Grade(7, 12, 8.0))
grade_repository.store_grade_rep(Grade(8, 12, 6.0))
grade_repository.store_grade_rep(Grade(8, 13, 5.5))
grade_repository.store_grade_rep(Grade(7, 13, 3.4))
grade_repository.store_grade_rep(Grade(6, 13, 8.0))
grade_repository.store_grade_rep(Grade(5, 13, 6.5))
grade_repository.store_grade_rep(Grade(4, 14, 4.0))
grade_repository.store_grade_rep(Grade(3, 14, 7.0))
grade_repository.store_grade_rep(Grade(2, 14, 6.75))
grade_repository.store_grade_rep(Grade(1, 14, 5.25))
grade_repository.store_grade_rep(Grade(8, 15, 9.5))
grade_repository.store_grade_rep(Grade(6, 15, 10.0))
grade_repository.store_grade_rep(Grade(4, 15, 9.0))
grade_repository.store_grade_rep(Grade(2, 15, 9.25))
grade_repository.store_grade_rep(Grade(7, 16, 7.2))
grade_repository.store_grade_rep(Grade(5, 16, 8.0))
grade_repository.store_grade_rep(Grade(3, 16, 6.75))
grade_repository.store_grade_rep(Grade(1, 16, 7.0))
grade_repository.store_grade_rep(Grade(5, 17, 9.0))
grade_repository.store_grade_rep(Grade(6, 17, 9.5))
grade_repository.store_grade_rep(Grade(7, 17, 9.7))
grade_repository.store_grade_rep(Grade(8, 17, 9.9))
grade_repository.store_grade_rep(Grade(8, 18, 8.0))
grade_repository.store_grade_rep(Grade(7, 18, 7.25))
grade_repository.store_grade_rep(Grade(6, 18, 7.5))
grade_repository.store_grade_rep(Grade(5, 18, 6.0))
grade_repository.store_grade_rep(Grade(4, 19, 4.9))
grade_repository.store_grade_rep(Grade(3, 19, 6.5))
grade_repository.store_grade_rep(Grade(2, 19, 7.0))
grade_repository.store_grade_rep(Grade(1, 19, 6.0))
grade_repository.store_grade_rep(Grade(8, 20, 8.0))
grade_repository.store_grade_rep(Grade(6, 20, 8.5))
grade_repository.store_grade_rep(Grade(4, 20, 9.25))
grade_repository.store_grade_rep(Grade(2, 20, 6.0))

'''
initializing the controllers
'''

student_controller = StudentController(student_repository)
discipline_controller = DisciplineController(discipline_repository)
grade_controller = GradeController(grade_repository)

'''
initializing the user interface
'''

user_interface = UI(student_controller, discipline_controller, grade_controller)

'''
starting the application's user interface
'''
user_interface.main_menu()
