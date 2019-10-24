using System;

namespace StudentsManagementApp.domain.entities
{
	public class Student : IHasId<int>
	{

		/// <summary>
		/// Student object constructor
		/// </summary>
		/// <param name="id">Student's id</param>
		/// <param name="name">name of the student</param>
		/// <param name="group">group of the student</param>
		/// <param name="email">email of the student</param>
		public Student(int id, string name, int group, string email)
		{
			Id = id;
			Name = name;
			Group = group;
			Email = email;
		}
		
		/// <summary>
		/// Implementation of IHasId
		/// </summary>
		public int Id { get; set; }
		
		/// <summary>
		/// Name property
		/// </summary>
		public string Name { get; set; }
		
		/// <summary>
		/// Group property
		/// </summary>
		public int Group { get; set;}
		
		/// <summary>
		/// Email property
		/// </summary>
		public string Email { get; set; }

		/// <summary>
		/// Overriding Equals method
		/// </summary>
		/// <param name="o"></param>
		/// <returns>true if the objects are equal, false otherwise</returns>
		public override bool Equals(object o)
		{
			if (!(o is Student)) return false;
			var st = (Student) o;
			return st.Id == Id;

		}


		/// <summary>
		/// Overriding ToString method
		/// </summary>
		/// <returns></returns>
		public override string ToString()
		{
			return "Id: " + Id.ToString() + " Name: " + Name + " Group: " + Group.ToString() + " Email: " + Email;
		}

		/// <summary>
		/// Overriding the GetHashCode method
		/// </summary>
		/// <returns></returns>
		public override int GetHashCode()
		{
			return Id;
		}
	}
	
}