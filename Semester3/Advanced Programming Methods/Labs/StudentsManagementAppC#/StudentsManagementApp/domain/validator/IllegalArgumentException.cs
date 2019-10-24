using System;

namespace StudentsManagementApp.domain.validator
{
	public class IllegalArgumentException : Exception
	{
		/// <inheritdoc />
		/// <summary>
		/// Constructor for IllegalArgumentException class
		/// </summary>
		/// <param name="err"></param>
		public IllegalArgumentException(string err) : base(err)
		{
			
		}
	}
}