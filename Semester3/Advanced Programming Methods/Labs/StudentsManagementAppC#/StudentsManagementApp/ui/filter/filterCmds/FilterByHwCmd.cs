using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.filter.filterCmds
{
	public class FilterByHwCmd : ICommand
	{
		private readonly GradeService _grService;

		public FilterByHwCmd(GradeService grService)
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
				foreach (var hw in _grService.FilterHomeworkById(id))
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