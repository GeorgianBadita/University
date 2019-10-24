using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.filter.filterCmds
{
	public class FilterGradesByHwIdCmd : ICommand
	{
		private readonly GradeService _grService;

		public FilterGradesByHwIdCmd(GradeService grService)
		{
			_grService = grService;
		}
		
		
		
		public void Execute()
		{

			try
			{
				Console.WriteLine("Please give the homework id to filter by: ");
				var id = Console.ReadLine();

				Console.WriteLine();
				foreach (var hw in _grService.FilterGradesByHomeworkId(id))
				{
					Console.WriteLine(hw);
				}
			}
			catch (FormatException e)
			{
				Console.WriteLine(e.Message);
			}
		}
	}
}