using System;

namespace StudentsManagementApp.domain.validator
{
	public class ValidatorException : Exception
	{
		/// <inheritdoc />
		/// <summary>
		/// Constructor for ValidatorException
		/// </summary>
		/// <param name="err"></param>
		public ValidatorException(string err) : base(err)
		{
		}
	}
}