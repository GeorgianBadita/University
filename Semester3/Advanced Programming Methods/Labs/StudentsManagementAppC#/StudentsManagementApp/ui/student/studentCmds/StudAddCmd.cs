using System;
using StudentsManagementApp.domain.validator;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.student.studentCmds
{
	public class StudAddCmd : ICommand
	{
		private readonly StudentService _srv;

		/// <summary>
		/// Constructor for StudAddCmd class
		/// </summary>
		/// <param name="srv">Student service</param>
		public StudAddCmd(StudentService srv)
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
				var retValue = _srv.AddStudent(id, name, group, email);

				Console.WriteLine(retValue == null
					? "The student was added successfully!\n"
					: "The student is already in the repository!\n");
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