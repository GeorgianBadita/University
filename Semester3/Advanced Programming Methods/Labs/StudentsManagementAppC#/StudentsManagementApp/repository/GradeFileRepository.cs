using System.Collections.Generic;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.domain.validator;

namespace StudentsManagementApp.repository
{
	public class GradeFileRepository : StorageRepository<KeyValuePair<int, string>, Grade>
	{
		/// <inheritdoc />
		/// <summary>
		/// Constructor for GradeFileRepository class
		/// </summary>
		/// <param name="val">validator for Grade class</param>
		/// <param name="fileName">path to file containing grades</param>
		public GradeFileRepository(IValidator<Grade> val,  string fileName) : 
			base(val, Grade2String, String2Grade, fileName)
		{ }

		/// <summary>
		/// Function to transform a grade into a string
		/// </summary>
		/// <param name="gr"> Grade to be converted </param>
		/// <returns>string containing a grade</returns>
		private static string Grade2String(Grade gr)
		{
			return $"{gr.Id.Key}|{gr.Id.Value}|{gr.GradeValue}|{gr.Professor}|{gr.FeedBack}";
		}

		/// <summary>
		/// Function to transform a string into a grade
		/// </summary>
		/// <param name="gr">grade to be transformed</param>
		/// <returns>Grade contained by the given string</returns>
		private static Grade String2Grade(string gr)
		{
			var grade = gr.Split("|");
			return new Grade(int.Parse(grade[0]), grade[1], double.Parse(grade[2]), grade[3], grade[4]);
		}
	}
}