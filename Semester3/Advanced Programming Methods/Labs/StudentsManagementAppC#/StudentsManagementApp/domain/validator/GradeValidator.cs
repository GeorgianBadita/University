using System;
using StudentsManagementApp.domain.entities;

namespace StudentsManagementApp.domain.validator
{
	public class GradeValidator : IValidator<Grade>
	{
		/// <inheritdoc />
		/// <summary>
		/// Function to validate a grade
		/// </summary>
		/// <param name="entity">Grade to be validated</param>
		/// <exception cref="ValidatorException">Throws exception if grade fields are incorrect!</exception>
		public void Validate(Grade entity)
		{
			var errs = "";

			if (entity.GetStudId() < 0)
			{
				errs += "Student id must be a positive integer!\n";
			}
			
			if (entity.GetHwId().Equals(""))
			{
				errs += "Homework Id can't be an empty string!\n";
			}

			if (entity.GradeValue < 0.0 || entity.GradeValue > 10.0)
			{
				errs += "Grade value must be a real number between 0 and 10\n";
			}

			if (entity.Professor.Equals(""))
			{
				errs += "Professor field can't be empty!\n";

			}

			if (entity.FeedBack.Equals(""))
			{
				errs += "Feedback field can't be empty!\n";
			}

			if (!string.IsNullOrEmpty(errs))
			{
				throw new ValidatorException(errs);
			}
		}
	}
}