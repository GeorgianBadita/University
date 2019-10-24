using StudentsManagementApp.domain.entities;

namespace StudentsManagementApp.domain.validator
{
	public class StudentValidator : IValidator<Student>
	{
		/// <inheritdoc />
		/// <summary>
		/// Function to validate a student
		/// </summary>
		/// <param name="entity"> Student to be validated </param>
		/// <exception cref="ValidatorException">throws ValidatorException if Student fields are incorrect</exception>
		public void Validate(Student entity)
		{
			var errs = "";
			if (entity.Id < 0)
			{
				errs += "Id must be a positive integer!\n";
			}

			if (entity.Email.Equals(""))
			{
				errs += "Email can't be empty!\n";
			}

			if (entity.Group < 0)
			{
				errs += "Group must be a positive integer!\n";
			}

			if (entity.Name.Equals(""))
			{
				errs += "Name can't be empty!\n";
			}

			if (!string.IsNullOrEmpty(errs))
			{
				throw  new ValidatorException(errs);
			}
		}
	}
}