using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.grade.gradeCmds
{
	public class GradePrintCmd : ICommand
	{
		private readonly GradeService _srv;

		/// <summary>
		/// Constructor for GradePrintCmd class
		/// </summary>
		/// <param name="srv">GradeService</param>
		public GradePrintCmd(GradeService srv)
		{
			_srv = srv;
		}
		
		
		public void Execute()
		{
			foreach (var grade in _srv.GetAllGrades())
			{
				Console.WriteLine(grade);
			}
			
			Console.WriteLine();
		}
	}
}