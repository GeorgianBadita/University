using System;
using StudentsManagementApp.domain.validator;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.student.studentCmds
{
	public class StudUpdCmd : ICommand
	{
		private readonly StudentService _srv;

		/// <summary>
		/// Constructor for StudUpdCmd class
		/// </summary>
		/// <param name="srv">Student service</param>
		public StudUpdCmd(StudentService srv)
		{
			_srv = srv;
		}
		
		public void Execute()
		{
			try
			{
				Console.WriteLine("\nPlease give student's Id - Integer: ");
				var id = int.Parse(Console.ReadLine());
				Console.WriteLine("\nPlease give student's name - string: ");
				var name = Console.ReadLine();
				Console.WriteLine("\nPlease give student's group - Integer: ");
				var @group = int.Parse(Console.ReadLine());
				Console.WriteLine("\nPlease give student's email - String: ");
				var email = Console.ReadLine();
				var retValue = _srv.UpdateStudent(id, name, group, email);
				
				Console.WriteLine(retValue == null ? "Student " + name +" was successfully added!" :
					"There is no student with the given id!");

			}
			catch (ValidatorException e)
			{
				Console.WriteLine("\n" + e.Message + "\n");
			}
			catch (FormatException e)
			{
				Console.WriteLine("\n" + e.Message + "\n");
			}

		}
	}
}