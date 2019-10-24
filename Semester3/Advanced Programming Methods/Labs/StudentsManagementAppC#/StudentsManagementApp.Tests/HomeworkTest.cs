using StudentsManagementApp.domain.entities;
using Xunit;

namespace StudentsManagementApp.Tests
{
	public class TestHomework
	{
		[Fact]
		public void HomeworkTest()
		{
			var hw = new Homework("A", "Analiza R", 5, 7);
			
			Assert.Equal(hw.Id, "A");
			Assert.Equal(hw.Desc, "Analiza R");
			Assert.Equal(hw.DeadlineWeek, 7);
			Assert.Equal(hw.ReceivingWeek, 5);

			hw.Id = "B";
			hw.Desc = "ASC";
			hw.ReceivingWeek = 6;
			hw.DeadlineWeek = 10;

			Assert.Equal(hw, new Homework("B", "ASC", 6, 10));
			Assert.NotEqual(hw, new Homework("A", "ASC", 6, 10));
		}
	}
}