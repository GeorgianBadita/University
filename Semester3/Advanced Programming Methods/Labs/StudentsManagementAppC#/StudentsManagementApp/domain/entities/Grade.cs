using System.Collections.Generic;

namespace StudentsManagementApp.domain.entities
{
	public class Grade : IHasId<KeyValuePair<int, string>>
	{


		public Grade(int studId, string hwId, double gradeValue, string professor, string feedBack)
		{
			Id = new KeyValuePair<int, string>(studId, hwId);
			GradeValue = gradeValue;
			Professor = professor;
			FeedBack = feedBack;

		}

		/// <summary>
		/// Function for getting student id
		/// </summary>
		/// <returns>Int - Id of the student</returns>
		public int GetStudId()
		{
			return Id.Key;
		}

		/// <summary>
		/// Function for getting homework id
		/// </summary>
		/// <returns>String - id of the homework</returns>
		public string GetHwId()
		{
			return Id.Value;
		}
		
		/// <summary>
		/// IHasId implementation
		/// </summary>
		public KeyValuePair<int, string> Id { get; set; }
		
		/// <summary>
		/// GradeValue property
		/// </summary>
		public double GradeValue { get; set; }
		
		/// <summary>
		/// Professor property
		/// </summary>
		public string Professor { get; set; }
		
		/// <summary>
		/// FeedBack property value
		/// </summary>
		public string FeedBack { get; set; }

		/// <summary>
		/// Overriding Equals method
		/// </summary>
		/// <param name="o">object to be verified</param>
		/// <returns>true if the objecs are equal, false otherwise</returns>
		public override bool Equals(object o)
		{
			if (!(o is Grade))
			{
				return false;
			}

			var gr = (Grade) o;
			return gr.Id.Equals(Id);
		}

		/// <summary>
		/// Overriding ToString method
		/// </summary>
		/// <returns>String form of Grade</returns>
		public override string ToString()
		{
			return "StId: " + GetStudId() + " HwId: " + GetHwId() + " Grade: " + GradeValue + 
				" Professor: " + Professor + " FeedBack: " + FeedBack;
		}
	}
}