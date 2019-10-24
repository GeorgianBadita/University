using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.report.reportCmds
{
	public class HardestHwCmd : ICommand
	{
		private readonly GradeService _grService;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="grService"></param>
		public HardestHwCmd(GradeService grService)
		{
			_grService = grService;
		}
		
		
		/// <summary>
		/// 
		/// </summary>
		public void Execute()
		{
			Console.WriteLine("\n\n");
			_grService.ShowHardestHomeworkAverage();
		}
	}
}