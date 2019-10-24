using System;
using StudentsManagementApp.domain.entities;
using Xunit;

namespace StudentsManagementApp.Tests
{
	public class TestStudent
	{
		[Fact]
		public void StudentTest()
		{
			var st = new Student(1, "Geo", 221, "bmir2236@scs.ubbcluj.ro");
			Assert.Equal(st.Id, 1);
			Assert.Equal(st.Name, "Geo");
			Assert.Equal(st.Email, "bmir2236@scs.ubbcluj.ro");
			Assert.Equal(st.Group, 221);

			st.Id = 2;
			st.Name = "Gabi";
			st.Group = 222;
			st.Email = "boir2152@scs.ubbcluj.ro";
			
			Assert.Equal(st.Id, 2);
			Assert.Equal(st.Name, "Gabi");
			Assert.Equal(st.Email, "boir2152@scs.ubbcluj.ro");
			Assert.Equal(st.Group, 222);
			
			Assert.Equal(st, new Student(2, "Gabi", 222, "boir2152@scs.ubbcluj.ro"));
			Assert.NotEqual(st, new Student(1, "Gabi", 222, "boir2152@scs.ubbcluj.ro"));
		}
	}
}