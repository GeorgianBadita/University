using System.Collections.Generic;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.repository;

namespace StudentsManagementApp.service
{
	public class StudentService
	{
		private readonly AbstractRepository<int, Student> _studRepo;

		/// <summary>
		/// Constructor for StudentService class
		/// </summary>
		/// <param name="studRepo">Student Repository type</param>
		public StudentService(AbstractRepository<int, Student> studRepo)
		{
			_studRepo = studRepo;
		}

		/// <summary>
		/// Function to add a new student to the repository
		/// </summary>
		/// <param name="id">id of the student to be added</param>
		/// <param name="name">name of the student</param>
		/// <param name="group">group of the student</param>
		/// <param name="email">email of the student</param>
		/// <returns>null if the student was added, the Student otherwise</returns>
		public Student AddStudent(int id, string name, int group, string email)
		{
			return _studRepo.Save(new Student(id, name, group, email));
		}


		/// <summary>
		/// Function to find a student
		/// </summary>
		/// <param name="id">id of the student to search</param>
		/// <returns>the student if it exists, null otherwise</returns>
		public Student FindStudent(int id)
		{
			return _studRepo.FindOne(id);
		}

		/// <summary>
		/// Function to update a student
		/// </summary>
		/// <param name="id">id of the student to be updated</param>
		/// <param name="name">name of the student to be updated</param>
		/// <param name="group">group of the student</param>
		/// <param name="email">email of the student</param>
		/// <returns>null if the student was updated, the given student otherwise</returns>
		public Student UpdateStudent(int id, string name, int group, string email)
		{
			return _studRepo.Update(new Student(id, name, group, email));
		}

		/// <summary>
		/// Function to delete a student from the repository
		/// </summary>
		/// <param name="id">id of the student to be deleted</param>
		/// <returns>the deleted student if it exists, null otherwise</returns>
		public Student DeleteStudent(int id)
		{
			return _studRepo.Delete(id);
		}

		/// <summary>
		/// Function to get all students as Enumerable
		/// </summary>
		/// <returns>Returns an Enumerable containing all students</returns>
		public IEnumerable<Student> GetAllStudents()
		{
			return _studRepo.FindAll();
		}
	}
}