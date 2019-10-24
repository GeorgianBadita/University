using System;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.domain.validator;

namespace StudentsManagementApp.repository
{
	public class HomeworkFileRepository : StorageRepository<string, Homework>
	{
		/// <inheritdoc />
		/// <summary>
		/// Constructor for homeworkFileRepository
		/// </summary>
		/// <param name="val">validator for homework class</param>
		/// <param name="fileName">path to the file containing homework</param>
		public HomeworkFileRepository(IValidator<Homework> val,  string fileName) : 
			base(val, Homework2String, String2Homework, fileName)
		{
			
		}

		/// <summary>
		/// Function to transform a homework into String
		/// </summary>
		/// <param name="hw">homework to be transformed</param>
		/// <returns>string containing definition of a homework</returns>
		private static string Homework2String(Homework hw)
		{
			return $"{hw.Id}|{hw.Desc}|{hw.ReceivingWeek}|{hw.DeadlineWeek}";
		}

		/// <summary>
		/// Function to transform a string into homework
		/// </summary>
		/// <param name="hw">string representing a homework</param>
		/// <returns>Homework object represented by the given string</returns>
		private static Homework String2Homework(string hw)
		{
			var homework = hw.Split("|");
			return new Homework(homework[0], homework[1], int.Parse(homework[2]), int.Parse(homework[3]));
		}
	}
}