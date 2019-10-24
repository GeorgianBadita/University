using System;
using StudentsManagementApp.service;
using StudentsManagementApp.ui.grade.gradeCmds;
using StudentsManagementApp.ui.homework.homeworkCmds;

namespace StudentsManagementApp.ui.grade
{
	public class GradeConsole : IConsole
	{
		private readonly GradeService _srv;

		/// <summary>
		/// Constructor for GradeConsole class
		/// </summary>
		/// <param name="srv">Grade Service service</param>
		public GradeConsole(GradeService srv)
		{
			_srv = srv;
		}


		public void Run()
		{
			while (true)
			{
				PrintMenu();
				var cmd = ReadCmd();
				ICommand toExecute = null;
				switch (cmd)
				{
					case '1':
						toExecute = new GradePrintCmd(_srv);
						break;
					case '2':
						toExecute = new GradeAddCmd(_srv);
						break;
					case 'x':
						return;
					case '?':
						Console.WriteLine("Incorrect command, please try again!\n");
						continue;
				}

				toExecute?.Execute();
			}
		}

		public void PrintMenu()
		{
			Console.WriteLine("======GRADE MENU======\n" +
			                  "1. To list all grades\n" +
			                  "2. To add a grade\n" +
			                  "x To go back\n\n" +
			                  "Please give a command: ");
		}

		public char ReadCmd()
		{
			var read = Console.ReadLine();
			if (read != null && read.Length != 1)
			{
				return '?';
			}

			if (read != null) return read[0];
			return '?';
		}
	}

}