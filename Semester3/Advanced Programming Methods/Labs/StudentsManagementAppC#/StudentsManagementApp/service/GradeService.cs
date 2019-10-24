using System;
using System.Collections.Generic;
using System.Linq;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.domain.validator;
using StudentsManagementApp.repository;
using StudentsManagementApp.utils;

namespace StudentsManagementApp.service
{
	public class GradeService
	{
		private readonly AbstractRepository<int, Student> _stRepo;
		private readonly AbstractRepository<string, Homework> _hwRepo;
		private readonly AbstractRepository<KeyValuePair<int, string>, Grade> _grRepo;
		
		
		/// <summary>
		/// Constructor for GradeService class
		/// </summary>
		/// <param name="stRepo">Student Repository object</param>
		/// <param name="hwRepo">Homework Repository object</param>
		/// <param name="grRepo">Grade Repository object</param>
		public GradeService(AbstractRepository<int, Student> stRepo,
							AbstractRepository<string, Homework> hwRepo,
							AbstractRepository<KeyValuePair<int, string>, Grade> grRepo)
		{
			_stRepo = stRepo;
			_hwRepo = hwRepo;
			_grRepo = grRepo;
		}

		/// <summary>
		/// Function to add a new grade to the repository
		/// </summary>
		/// <param name="stId">id of the student</param>
		/// <param name="hwId">id of the homework</param>
		/// <param name="gradeValue">grade value</param>
		/// <param name="professor">professor name</param>
		/// <param name="feedback">feedback</param>
		/// <exception cref="StudentOrHomeworNotFoundException">if the given homework or student does not exist</exception>
		/// <returns>null if the grade was added, the given grade otherwise</returns>
		public Grade AddGrade(int stId, string hwId, double gradeValue, string professor, string feedback)
		{
			var st = _stRepo.FindOne(stId);
			var hw = _hwRepo.FindOne(hwId);
			
			if (st == null || hw == null)
			{
				throw new StudentOrHomeworNotFoundException("The given student or homework does not exist!");
			}

			var diff = hw.DeadlineWeek - Utility.GetCurrentWeek();
			if (diff == -1 || diff == -2)
			{
				gradeValue += (2.5d) * diff;
			}
			else if(diff < -2)
			{
				gradeValue = 1.0d;
			}
			return _grRepo.Save(new Grade(stId, hwId, gradeValue, professor, feedback));
		}

		/// <summary>
		/// Function to delete a grade from the repository
		/// </summary>
		/// <param name="stId">id of the student</param>
		/// <param name="hwId">id of the homework</param>
		/// <returns>The deleted homework if it exists, null otherwise</returns>
		public Grade DeleteGrade(int stId, string hwId)
		{
			var pair = new KeyValuePair<int,string>(stId, hwId);
			return _grRepo.Delete(pair);
		}

		/// <summary>
		/// Function to find a grade in the repository
		/// </summary>
		/// <param name="stId">student id</param>
		/// <param name="hwId">homework id</param>
		/// <returns>the grade with the given id if it exists, null otherwise</returns>
		public Grade FindGrade(int stId, string hwId)
		{
			var pair = new KeyValuePair<int, string>(stId, hwId);
			return _grRepo.FindOne(pair);
		}

		/// <summary>
		/// Function to update 
		/// </summary>
		/// <param name="stId"></param>
		/// <param name="hwId"></param>
		/// <param name="gradeValue"></param>
		/// <param name="professor"></param>
		/// <param name="feedback"></param>
		/// <returns>null if the grade was updated, the given grade otherwise</returns>
		public Grade UpdateGrade(int stId, string hwId, double gradeValue, string professor, string feedback)
		{
			return _grRepo.Update(new Grade(stId, hwId, gradeValue, professor, feedback));
		}

		/// <summary>
		/// Function to get all the grades from the repository
		/// </summary>
		/// <returns>IEnumerable containing all grades from the repository</returns>
		public IEnumerable<Grade> GetAllGrades()
		{
			return _grRepo.FindAll();
		}

		/// <summary>
		/// 
		/// </summary>
		public void ShowAverageForAllStudents()
		{
			var weeks = from l in _hwRepo.FindAll()
				select l.DeadlineWeek - l.ReceivingWeek;

			var totalWeeks = weeks.Sum();
			var average = (from r in _grRepo.FindAll()
					group r by r.GetStudId()
					into studentGroup
					select new
					{
						studentId = studentGroup.Key,
						studName = _stRepo.FindOne(studentGroup.Key).Name,
						studentFinalGrade = (from sg in studentGroup
							                    from l in _hwRepo.FindAll()
							                    where sg.GetHwId() == l.Id
							                    select (l.DeadlineWeek -
							                            l.ReceivingWeek) * sg.GradeValue
						                    ).Sum() / totalWeeks,
					}
				);
			foreach (var a in average)
			{
				Console.WriteLine(a);
			}
		}

		/// <summary>
		/// 
		/// </summary>
		public void ShowHardestHomeworkAverage()
		{
			var hardestHomework = (from r in _grRepo.FindAll()
					group r by r.GetHwId()
					into labGroup
					select new
					{
						homeworkId = labGroup.Key,
						homeworkDesc = _hwRepo.FindOne(labGroup.Key).Desc,
						hwAvg = (from lg in labGroup
								select lg.GradeValue
							).Average()
					}
				).OrderBy(x => x.hwAvg).First();
			
			Console.WriteLine(hardestHomework);
		}

		/// <summary>
		/// 
		/// </summary>
		public void StudentsTakingExam()
		{
			var weeks = from l in _hwRepo.FindAll()
				select l.DeadlineWeek - l.ReceivingWeek;

			var totalWeeks = weeks.Sum();
			var average = (from r in _grRepo.FindAll()
					group r by r.GetStudId()
					into studentGroup
					select new
					{
						studentId = studentGroup.Key,
						studName = _stRepo.FindOne(studentGroup.Key).Name,
						studentFinalGrade = (from sg in studentGroup
							                    from l in _hwRepo.FindAll()
							                    where sg.GetHwId() == l.Id
							                    select (l.DeadlineWeek -
							                            l.ReceivingWeek) * sg.GradeValue
						                    ).Sum() / totalWeeks,
					}
				);

			var takingExam = (from avg in average
					where avg.studentFinalGrade >= 4
					select avg
				);

			foreach (var e in takingExam)
			{
				Console.WriteLine(e);
			}
		}
		

		/// <summary>
		/// /
		/// </summary>
		/// <param name="groupId"></param>
		/// <returns></returns>
		public List<Student> FilterStudentByGroup(int groupId)
		{

			var filtered = from student in this._stRepo.FindAll()
				where student.Group == groupId
				select student;
			return filtered.ToList();
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		public List<Homework> FilterHomeworkById(string id)
		{
			var filtered = from hw in this._hwRepo.FindAll()
				where hw.Id == id
				select hw;
			return filtered.ToList();
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="studId"></param>
		/// <returns></returns>
		public List<Grade> FilterGradesByStudentId(int studId)
		{
			var filtered = from gr in this._grRepo.FindAll()
				where gr.GetStudId().Equals(studId)
				select gr;
			return filtered.ToList();
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="hid"></param>
		/// <returns></returns>
		public List<Grade> FilterGradesByHomeworkId(string hid)
		{
			var filtered = from gr in this._grRepo.FindAll()
				where gr.GetHwId() == hid
				select gr;
			return filtered.ToList();
		}

	}


}