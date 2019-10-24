using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.filter.filterCmds
{
	public class FilterGradesByStudIdCmd : ICommand
	{
		private readonly GradeService _grService;

		public FilterGradesByStudIdCmd(GradeService grService)
		{
			_grService = grService;
		}
		
		
		
		public void Execute()
		{

			try
			{
				Console.WriteLine("Please give the student id to filter by: ");
				var gr = int.Parse(Console.ReadLine());

				Console.WriteLine();
				foreach (var st in _grService.FilterGradesByStudentId(gr))
				{
					Console.WriteLine(st);
				}
			}
			catch (FormatException e)
			{
				Console.WriteLine(e.Message);
			}
		}
	}
}