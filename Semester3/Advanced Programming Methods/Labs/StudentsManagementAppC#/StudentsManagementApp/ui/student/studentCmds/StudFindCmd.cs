using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.student.studentCmds
{
	public class StudFindCmd : ICommand
	{
		private readonly StudentService _srv;

		/// <summary>
		/// Constructor for StudFindCmd class
		/// </summary>
		/// <param name="srv">Student service</param>
		public StudFindCmd(StudentService srv)
		{
			_srv = srv;
		}
		public void Execute()
		{
			Console.WriteLine("\nPlease give the id of the student to find: ");
			var id = int.Parse(Console.ReadLine());
			var retValue = _srv.FindStudent(id);
			if (retValue != null)
			{
				Console.WriteLine("Student " + retValue.Name + " was successfully found!");
			}
			else
			{
				Console.WriteLine("There is no student with the given id!");
			}
		}
	}
}