using System;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.domain.validator;

namespace StudentsManagementApp.repository
{
	public class StudentFileRepository : StorageRepository<int, Student>
	{
		
		/// <inheritdoc />
		/// <summary>
		/// Constructor for StudentFileRepository
		/// </summary>
		/// <param name="val">Validator for Student class</param>
		/// <param name="fileName">path to the file containing students</param>
		public StudentFileRepository(IValidator<Student> val, 
			string fileName) : base(val, Stud2String, String2Stud, fileName)
		{
			
		}

		/// <summary>
		/// Function to transform a student to a string
		/// </summary>
		/// <param name="st">Student to be transformed</param>
		/// <returns>String form of a student</returns>
		private static string Stud2String(Student st)
		{
			return $"{st.Id}|{st.Name}|{st.Group}|{st.Email}";
		}

		/// <summary>
		/// Function to transform a string into student
		/// </summary>
		/// <param name="st">String to extract the student from</param>
		/// <returns>Student contained by the given string</returns>
		private static Student String2Stud(string st)
		{
			var student = st.Split("|");
			return new Student(int.Parse(student[0]), student[1], int.Parse(student[2]), student[3]);
		}
	}
}