using StudentsManagementApp.domain.entities;

namespace StudentsManagementApp.domain.validator
{
	public class HomeworkValidator : IValidator<Homework>
	{
		/// <inheritdoc />
		/// <summary>
		/// Function to validate a homework
		/// </summary>
		/// <param name="entity">Homework to be validated</param>
		/// <exception cref="ValidatorException">Throws this exception if homework fields are wrong!</exception>
		public void Validate(Homework entity)
		{
			var errs = "";

			if (entity.Id.Equals(""))
			{
				errs += "Id can't be empty!\n";
			}

			if (entity.Desc.Equals(""))
			{
				errs += "Description can't be empty!\n";
			}

			if (entity.DeadlineWeek < 0 || entity.DeadlineWeek > 14)
			{
				errs += "DeadlineWeek must be an integer between 0 and 14!\n";
			}

			if (entity.ReceivingWeek < 0 || entity.ReceivingWeek > 14)
			{
				errs += "ReceivingWeek must be an integer between 0 and 14!\n";
			}


			if (!string.IsNullOrEmpty(errs))
			{
				throw new ValidatorException(errs);
			}
		}
	}
}