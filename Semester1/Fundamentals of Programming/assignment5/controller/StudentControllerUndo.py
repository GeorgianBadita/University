from StudentController import StudentController
from UndoController import FunctionCall, Operation


class StudentControllerUndo(StudentController):

    def __init__(self, undo_controller, grade_controller, validator, repository):
        studentController.__init__(self, validator, repository)
        self._grade_controller = grade_controller
        self._undo_controller = undo_controller

    def create(self, student_id, student_name):
        redo = FunctionCall(self.create, student_id, student_name)
        undo = FunctionCall(self.delete, student_id)
        operation = Operation(redo, undo)
        self._undo_controller.record_operation(operation)

    def delete(self, student_id):
        student = StudentController.delete_student_ctr(self, student_id)
        redo = FunctionCall(self.delete, student_id)
        undo = FunctionCall(self.create, student.getID(), student.getname())
        operation = Operation(redo, undo)
        grade = self._grade_controller.filter(Now, student)
        for grade in grade:
            self._grade_controller.delete(grade.getID())
        self._undo_controller.record_operation(operation)
        return student

