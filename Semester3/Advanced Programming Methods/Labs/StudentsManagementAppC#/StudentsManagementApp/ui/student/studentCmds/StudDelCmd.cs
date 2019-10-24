using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.student.studentCmds
{
	public class StudDelCmd : ICommand
	{
		private readonly StudentService _srv;

		/// <summary>
		/// Constructor for StudDelCmd class
		/// </summary>
		/// <param name="srv">Student service</param>
		public StudDelCmd(StudentService srv)
		{
			_srv = srv;
		}
		
		public void Execute()
		{
			Console.WriteLine("\nPlease give the id of the student to delete: ");
			var id = int.Parse(Console.ReadLine());
			var retValue = _srv.DeleteStudent(id);
			if (retValue != null)
			{
				Console.WriteLine("Student " + retValue.Name + " was successfully deleted!");
			}
			else
			{
				Console.WriteLine("There is no student with the given id!");
			}
		}
	}
}