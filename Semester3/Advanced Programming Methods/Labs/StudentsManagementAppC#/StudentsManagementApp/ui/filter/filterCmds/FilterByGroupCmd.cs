using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.filter.filterCmds
{
	public class FilterByGroupCmd : ICommand
	{

		private readonly GradeService _grService;

		public FilterByGroupCmd(GradeService grService)
		{
			_grService = grService;
		}
		
		
		
		public void Execute()
		{

			try
			{
				Console.WriteLine("Please give the group to filter by: ");
				var gr = int.Parse(Console.ReadLine());

				Console.WriteLine();
				foreach (var st in _grService.FilterStudentByGroup(gr))
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