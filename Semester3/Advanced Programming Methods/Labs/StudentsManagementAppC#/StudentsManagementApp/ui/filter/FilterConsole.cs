using System;
using StudentsManagementApp.service;
using StudentsManagementApp.ui.filter.filterCmds;
using StudentsManagementApp.ui.grade.gradeCmds;

namespace StudentsManagementApp.ui.filter
{
	public class FilterConsole : IConsole
	{
		private readonly GradeService _srv;

		/// <summary>
		/// Constructor for GradeConsole class
		/// </summary>
		/// <param name="srv">Grade Service service</param>
		public FilterConsole(GradeService srv)
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
						toExecute = new FilterByGroupCmd(_srv);
						break;
					case '2':
						toExecute = new FilterByHwCmd(_srv);
						break;
					case '3':
						toExecute = new FilterGradesByStudIdCmd(_srv);
						break;
					case '4':
						toExecute = new FilterGradesByHwIdCmd(_srv);
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
			Console.WriteLine("======Filter MENU======\n" +
			                  "1. To Filter by group\n" +
			                  "2. To Filter by homework\n" +
			                  "3. To Filter grades by student id\n"+
			                  "4. To Filter grades by homework id\n" +
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