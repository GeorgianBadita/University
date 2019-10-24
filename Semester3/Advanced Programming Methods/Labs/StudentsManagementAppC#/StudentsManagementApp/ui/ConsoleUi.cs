using System;
using StudentsManagementApp.ui.filter;
using StudentsManagementApp.ui.grade;
using StudentsManagementApp.ui.homework;
using StudentsManagementApp.ui.report;
using StudentsManagementApp.ui.student;


namespace StudentsManagementApp.ui
{
	
	
	public class ConsoleUi : IConsole
	{

		private readonly StudentConsole _stuUi;
		private readonly HomeworkConsole _hwUi;
		private readonly GradeConsole _grUi;
		private readonly FilterConsole _flUi;
		private readonly ReportConsole _repUi;
 		
		/// <summary>
		/// Constructor for ConsoleUI class
		/// </summary>
		/// <param name="studUi">student ui</param>
		/// <param name="hwUi">homework ui</param>
		/// <param name="grUi">grade ui</param>
		public ConsoleUi(StudentConsole studUi, HomeworkConsole hwUi, GradeConsole grUi, FilterConsole flUi, ReportConsole repUi)
		{
			_stuUi = studUi;
			_hwUi = hwUi;
			_grUi = grUi;
			_flUi = flUi;
			_repUi = repUi;
		}
		
		
		
		public void Run()
		{
			while (true)
			{
				PrintMenu();
				var cmd = ReadCmd();
				switch (cmd)
				{
					case '1':
						_stuUi.Run();
						break;
					case '2':
						_hwUi.Run();
						break;
					case '3':
						_grUi.Run();
						break;
					case '4':
						_flUi.Run();
						break;
					case '5':
						_repUi.Run();
						break;
					case 'x':
						return;
					case '?':
						Console.WriteLine("Incorrect command, please try again!\n");
						continue;
				}

			}
		}

		public void PrintMenu()
		{
			Console.WriteLine("======MAIN MENU======\n" +
			                  "1. Student  menu\n" +
			                  "2. Homework menu\n" +
			                  "3. Grade Menu\n" +
			                  "4. Filter menu\n" +
			                  "5. Report menu\n" +
			                  "x To stop the program\n\n" +
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