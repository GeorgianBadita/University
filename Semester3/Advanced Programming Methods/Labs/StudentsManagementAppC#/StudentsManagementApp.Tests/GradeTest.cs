using System.Collections.Generic;
using StudentsManagementApp.domain.entities;
using Xunit;

namespace StudentsManagementApp.Tests
{
	public class TestGrade
	{
		[Fact]
		public void GradeTest()
		{
			var grade = new Grade(1, "A", 2.5, "Gabi Mircea", "Blanitza");
			
			Assert.Equal(grade.Id.Key, 1);
			Assert.Equal(grade.Id.Value, "A");
			Assert.Equal(grade.Professor, "Gabi Mircea");
			Assert.Equal(grade.FeedBack, "Blanitza");

			grade.Id = new KeyValuePair<int, string>(2, "B");
			grade.GradeValue = 5.6;
			grade.Professor = "Vancea Alexandru";
			grade.FeedBack = "Mai baga!";
			
			Assert.Equal(grade, new Grade(2, "B", 5.6, "Vancea Alexandru", "Mai baga!"));
			Assert.NotEqual(grade, new Grade(1, "B", 5.6, "Vancea Alexandru", "Mai baga!"));
		}
	}
}