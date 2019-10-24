using System;
using System.IO;
using StudentsManagementApp.domain.validator;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.grade.gradeCmds
{
	public class GradeAddCmd : ICommand
	{
		private readonly GradeService _srv;

		/// <summary>
		/// Constructor for GradeAddCmd class
		/// </summary>
		/// <param name="srv">GradeService</param>
		public GradeAddCmd(GradeService srv)
		{
			_srv = srv;
		}

		
		
		public void Execute()
		{
			try
			{
				Console.WriteLine("Give id of the student - integer: ");
				var stId = int.Parse(Console.ReadLine());
				Console.WriteLine("Give id of the homework - string: ");
				var hwId = Console.ReadLine();
				Console.WriteLine("Give grade value - double: ");
				var grade = double.Parse(Console.ReadLine());
				Console.WriteLine("Give the name of the professor - string: ");
				var prof = Console.ReadLine();
				Console.WriteLine("Give feedback for the given grade - string:  ");
				var feedBack = Console.ReadLine();

				var retValue = _srv.AddGrade(stId, hwId, grade, prof, feedBack);

				Console.WriteLine(retValue == null
					? "The grade was added successfully!\n"
					: "The grade is already in the repository!\n");
			}
			catch (ValidatorException e)
			{
				Console.WriteLine(e.Message);
			}
			catch (FormatException e)
			{
				Console.WriteLine("\n" + e.Message + "\n");
			}
			catch (StudentOrHomeworNotFoundException e)
			{
				Console.WriteLine(e.Message);
			}
		}
	}
}