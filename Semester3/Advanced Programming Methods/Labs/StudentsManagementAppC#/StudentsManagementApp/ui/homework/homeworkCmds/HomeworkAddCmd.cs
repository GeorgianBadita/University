using System;
using StudentsManagementApp.domain.validator;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.homework.homeworkCmds
{
	public class HomeworkAddCmd : ICommand
	{
		private readonly HomeworkService _srv;

		/// <summary>
		/// Constructor for HomeworkAddCmd class
		/// </summary>
		/// <param name="srv">Homework service</param>
		public HomeworkAddCmd(HomeworkService srv)
		{
			_srv = srv;
		}
		
		public void Execute()
		{
			try
			{
				Console.WriteLine("\nPlease give homework's Id - string: ");
				var id = Console.ReadLine();
				Console.WriteLine("\nPlease give homework's description - string: ");
				var desc = Console.ReadLine();
				Console.WriteLine("\nPlease give homework's receiving week - integer: ");
				var @recvWeek = int.Parse(Console.ReadLine());
				Console.WriteLine("\nPlease give homework's deadline week - integer: ");
				var deadlineWeek = int.Parse(Console.ReadLine());
				var retValue = _srv.AddHomework(id, desc, recvWeek, deadlineWeek);

				Console.WriteLine(retValue == null
					? "The homework was added successfully!\n"
					: "The homework is already in the repository!\n");
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