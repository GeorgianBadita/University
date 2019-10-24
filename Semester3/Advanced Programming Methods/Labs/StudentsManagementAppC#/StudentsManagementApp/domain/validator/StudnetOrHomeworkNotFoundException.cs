using System;

namespace StudentsManagementApp.domain.validator
{
	public class StudentOrHomeworNotFoundException : Exception
	{

		/// <summary>
		/// Constructor for StudentOrHomeworNotFoundException exception 
		/// </summary>
		/// <param name="err">Erro to be thrown</param>
		public StudentOrHomeworNotFoundException(string err) : base(err)
		{
			
		}
		
	}
}