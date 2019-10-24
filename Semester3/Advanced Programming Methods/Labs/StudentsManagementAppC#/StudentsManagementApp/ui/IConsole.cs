using System;

namespace StudentsManagementApp.ui
{
	public interface IConsole
	{
		/// <summary>
		/// Function tun run the UI 
		/// </summary>
		void Run();
		
		/// <summary>
		/// Function to print the UI Menu
		/// </summary>
		void PrintMenu();

		/// <summary>
		/// Function to read a command from the input
		/// </summary>
		/// <returns>the command if it was successfully read, '?' otherwise</returns>
		char ReadCmd();
	}
}