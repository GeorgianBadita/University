namespace StudentsManagementApp.domain.entities
{
	public class Homework : IHasId<string>
	{

		/// <summary>
		/// Constructor for Homework Object
		/// </summary>
		/// <param name="id">id of the homework</param>
		/// <param name="desc">description of the homework</param>
		/// <param name="receivingWeek">receiving week</param>
		/// <param name="deadlineWeek">deadline week</param>
		public Homework(string id, string desc, int receivingWeek, int deadlineWeek)
		{
			Id = id;
			Desc = desc;
			ReceivingWeek = receivingWeek;
			DeadlineWeek = deadlineWeek;
		}
		
		/// <summary>
		/// Id property
		/// </summary>
		public string Id { get; set; }
		
		/// <summary>
		/// Description property
		/// </summary>
		public string Desc { get; set; }
		
		/// <summary>
		/// Receiving week property 
		/// </summary>
		public int ReceivingWeek { get; set; }
		
		/// <summary>
		/// DeadlineWeek property
		/// </summary>
		public int DeadlineWeek { get; set; }

		/// <summary>
		/// Overriding Equals method
		/// </summary>
		/// <param name="o">object to be verified</param>
		/// <returns>true if the objects are equals, false otherwise</returns>
		public override bool Equals(object o)
		{
			if (!(o is Homework))
			{
				return false;
			}
			
			var hw = (Homework) o;
			return hw.Id.Equals(Id);
		}

		/// <summary>
		/// Overriding ToString method
		/// </summary>
		/// <returns>String form of Homework</returns>
		public override string ToString()
		{
			return "ID: " + Id.ToString() + " Desc: " + Desc + " RecvWeek " + ReceivingWeek + "  DeadlineWeke: " +
			       DeadlineWeek;
		}

		/// <summary>
		/// Overriding HashCode method for Homework class
		/// </summary>
		/// <returns>Hash of Homework Object</returns>
		public override int GetHashCode()
		{
			return Id.GetHashCode();
		}
	}
}