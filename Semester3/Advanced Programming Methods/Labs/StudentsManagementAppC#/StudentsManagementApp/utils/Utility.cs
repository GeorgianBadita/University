using System;

namespace StudentsManagementApp.utils
{
	public class Utility
	{
		/// <summary>
		/// Function which gets the current week relatively to 1-10-2018
		/// </summary>
		/// <returns>Integer representing the number of the current week</returns>
		public static int GetCurrentWeek()
		{
			var start = new DateTime(2018, 10, 1);
			var now = DateTime.Now;
			return (now - start).Days / 7 + 1;
		}
	}
}