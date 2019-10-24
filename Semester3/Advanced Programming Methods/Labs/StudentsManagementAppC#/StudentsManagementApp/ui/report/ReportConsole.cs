using System;
using StudentsManagementApp.service;
using StudentsManagementApp.ui.filter.filterCmds;
using StudentsManagementApp.ui.grade.gradeCmds;
using StudentsManagementApp.ui.report.reportCmds;

namespace StudentsManagementApp.ui.report
{
	public class ReportConsole : IConsole
	{
		private readonly GradeService _srv;

		/// <summary>
		/// Constructor for GradeConsole class
		/// </summary>
		/// <param name="srv">Grade Service service</param>
		public ReportConsole(GradeService srv)
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
						toExecute = new StudentsAvgCmd(_srv);
						break;
					case '2':
						toExecute = new HardestHwCmd(_srv);
						break;
					case '3':
						toExecute = new StudentsTakingCmd(_srv);
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
			Console.WriteLine("======REPORT MENU======\n" +
			                  "1. To show students average\n" +
			                  "2. To show the hardest homework\n" +
			                  "3. To who students taking the exam\n"+	
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