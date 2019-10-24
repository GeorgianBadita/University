using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.student.studentCmds
{
	public class StudPrintCmd : ICommand
	{
		private readonly StudentService _srv;

		/// <summary>
		/// Constructor for StudPrintCmd class
		/// </summary>
		/// <param name="srv">Student service</param>
		public StudPrintCmd(StudentService srv)
		{
			_srv = srv;
		}
		
		public void Execute()
		{
			foreach (var stud in _srv.GetAllStudents())
			{
				Console.WriteLine(stud);
			}
			Console.WriteLine();
		}
	}
}