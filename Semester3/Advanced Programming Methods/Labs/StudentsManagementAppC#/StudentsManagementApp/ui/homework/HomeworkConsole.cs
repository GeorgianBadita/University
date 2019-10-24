using System;
using StudentsManagementApp.service;
using StudentsManagementApp.ui.homework.homeworkCmds;

namespace StudentsManagementApp.ui.homework
{
	public class HomeworkConsole : IConsole
	{
		private readonly HomeworkService _srv;

		/// <summary>
		/// Constructor for HomeworkConsole class
		/// </summary>
		/// <param name="srv">Homework service</param>
		public HomeworkConsole(HomeworkService srv)
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
						toExecute = new HomeworkPrintCmd(_srv);
						break;
					case '2':
						toExecute = new HomeworkAddCmd(_srv);
						break;
					case '3':
						toExecute = new HomeworkExtendCmd(_srv);
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
			Console.WriteLine("======HOMEWORK MENU======\n" +
			                  "1. To list all homework\n" +
			                  "2. To add a homework\n" +
			                  "3. To extend a homework\n" +
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