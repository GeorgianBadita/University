using System;
using StudentsManagementApp.service;
using StudentsManagementApp.ui.student.studentCmds;

namespace StudentsManagementApp.ui.student
{
	public class StudentConsole : IConsole
	{
		private readonly StudentService _srv;

		/// <summary>
		/// Constructor for StudentConsole class
		/// </summary>
		/// <param name="srv">Student service</param>
		public StudentConsole(StudentService srv)
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
						toExecute = new StudPrintCmd(_srv);
						break;
					case '2':
						toExecute = new StudAddCmd(_srv);
						break;
					case '3':
						toExecute = new StudDelCmd(_srv);
						break;
					case '4':
						toExecute = new StudUpdCmd(_srv);
						break;
					case '5':
						toExecute = new StudFindCmd(_srv);
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
			Console.WriteLine("======STUDENT MENU======\n" +
			                  "1. To list all students\n" +
			                  "2. To add a student\n" +
			                  "3. To remove a student\n" +
			                  "4. To update a student\n" +
			                  "5. To find a student\n" +
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