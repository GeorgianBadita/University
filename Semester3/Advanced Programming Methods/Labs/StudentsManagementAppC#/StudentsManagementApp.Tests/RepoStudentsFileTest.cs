using System;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.domain.validator;
using StudentsManagementApp.repository;
using Xunit;

namespace StudentsManagementApp.Tests
{
	public class TestRepoStudentsFile
	{
		private StudentFileRepository _repo = null;
		
		private static void ClearFile()
		{
			System.IO.File.WriteAllText(@"/home/geo/Desktop/MapJavaToC#/StudentsManagementApp/StudentsManagementApp.Tests/files/studentsFile.txt",string.Empty);

		}

		private void AddStudents()
		{
			ClearFile();
			_repo = new StudentFileRepository(new StudentValidator(), "/home/geo/Desktop/MapJavaToC#/StudentsManagementApp/StudentsManagementApp.Tests/files/studentsFile.txt");_repo.Save(new Student(1, "Geo", 221, "bmir2236@scs.ubbcluj.ro"));
			_repo.Save(new Student(2, "Cristi", 215, "ncir2151@scs.ubbcluj.ro"));
			_repo.Save(new Student(3, "Gabi", 222, "boir2151@scs.ubbcluj.ro"));
		}

		private void TestAdd()
		{
			AddStudents();
			Assert.Equal(_repo.Save(new Student(4, "Anton", 221, "amir1234@scs.ubbcluj.ro")), null);
			Assert.Equal(_repo.FindAll().Count(), 4);
			Assert.NotEqual(_repo.Save(new Student(4, "Anton", 221, "amir1234@scs.ubbcluj.ro")), null);
			try
			{
				_repo.Save(new Student(-1, "", 12, ""));
				Assert.False(true);
			}
			catch (Exception e)
			{
				Assert.True(true);
			}
			
			try
			{
				_repo.Save(null);
				Assert.False(true);
			}
			catch (Exception e)
			{
				Assert.True(true);
			}
			ClearFile();
		}


		private void TestDelete()
		{
			AddStudents();
			Assert.Equal(_repo.Delete(1), new Student(1, "Geo", 221, "bmir2236@scs.ubbcluj.ro"));
			Assert.Equal(_repo.FindAll().Count(), 2);
			Assert.Equal(_repo.Delete(12), null);
			ClearFile();
		}

		private void TestUpdate()
		{
			AddStudents();
			Assert.Equal(_repo.Update(new Student(1, "Marian", 221, "bm@mail.com")), null);
			var st = _repo.FindOne(1);
			Assert.Equal(st.Name, "Marian");
			Assert.NotEqual(_repo.Update(new Student(10, "Marian", 221, "bm@mail.com")), null);
			try
			{
				_repo.Update(null);
				Assert.False(true);
			}
			catch (Exception e)
			{
				Assert.True(true);
			}
			ClearFile();
		}

		private void TestFindOne()
		{
			AddStudents();
			Assert.Equal(_repo.FindOne(1), new Student(1, "Geo", 221, "bmir2236@scs.ubbcluj.ro"));
			Assert.Equal(_repo.FindOne(10), null);
			ClearFile();
		}

		private void TestFindAll()
		{
			AddStudents();
			var numStuds = _repo.FindAll().Count();
			Assert.Equal(numStuds, 3);
			ClearFile();
		}
		
		[Fact]
		public void RepoStudentFileTest()
		{
			
			TestAdd();
			TestDelete();
			TestUpdate();
			TestFindOne();
			TestFindAll();
		}
	}
}