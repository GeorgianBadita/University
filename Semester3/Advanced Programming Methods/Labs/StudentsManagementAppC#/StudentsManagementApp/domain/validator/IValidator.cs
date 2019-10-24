namespace StudentsManagementApp.domain.validator
{
	public interface IValidator<TE>
	{
		/// <summary>
		/// Function to validate an entity E
		/// </summary>
		/// <param name="entity">entity to be validated</param>
		void Validate(TE entity);
	}
}