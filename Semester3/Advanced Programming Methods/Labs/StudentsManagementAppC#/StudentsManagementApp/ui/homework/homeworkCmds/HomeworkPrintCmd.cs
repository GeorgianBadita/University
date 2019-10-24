using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.homework.homeworkCmds
{
	public class HomeworkPrintCmd : ICommand
	{
		private readonly HomeworkService _srv;

		/// <summary>
		/// Constructor for HomeworkPrintCmd class
		/// </summary>
		/// <param name="srv">Homework service</param>
		public HomeworkPrintCmd(HomeworkService srv)
		{
			_srv = srv;
		}
		
		public void Execute()
		{
			foreach (var hw in _srv.GetAllHomework())
			{
				Console.WriteLine(hw);
			}
			Console.WriteLine();
		}
	}
}