using System;
using StudentsManagementApp.service;

namespace StudentsManagementApp.ui.homework.homeworkCmds
{
	public class HomeworkExtendCmd : ICommand
	{

		private readonly HomeworkService _srv;

		/// <summary>
		/// Constructor for HomeworkExtendCmd class
		/// </summary>
		/// <param name="srv">HomeworkService</param>
		public HomeworkExtendCmd(HomeworkService srv)
		{
			_srv = srv;
		}
		
		
		public void Execute()
		{
			Console.WriteLine("Give the id of the homework to extend: ");
			var id = Console.ReadLine();
			_srv.ExtendHomework(id);
		}
	}
}