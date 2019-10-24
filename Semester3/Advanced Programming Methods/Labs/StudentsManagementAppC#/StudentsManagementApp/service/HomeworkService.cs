using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using StudentsManagementApp.domain.entities;
using StudentsManagementApp.repository;
using StudentsManagementApp.utils;

namespace StudentsManagementApp.service
{
	public class HomeworkService
	{
		private readonly AbstractRepository<string, Homework> _hwRepo;

		
		/// <summary>
		/// Constructor for HomeWorkService class
		/// </summary>
		/// <param name="hwRepo">HomeWork repository object</param>
		public HomeworkService(AbstractRepository<string, Homework> hwRepo)
		{
			_hwRepo = hwRepo;
		}

		/// <summary>
		/// Function to add a new homework into the repository
		/// </summary>
		/// <param name="id">id of the homework</param>
		/// <param name="desc">description of the homework</param>
		/// <param name="receivingWeek">receiving week</param>
		/// <param name="deadlineWeek">deadline week</param>
		/// <returns>null if the homework is added, the given homework otherwise</returns>
		public Homework AddHomework(string id, string desc, int receivingWeek, int deadlineWeek)
		{
			return _hwRepo.Save(new Homework(id, desc, receivingWeek, deadlineWeek));
		}

		/// <summary>
		/// Function to delete a homework from the repository
		/// </summary>
		/// <param name="id">id of the homework to be deleted</param>
		/// <returns>the deleted homework if it exists, null otherwise</returns>
		public Homework DeleteHomework(string id)
		{
			return _hwRepo.Delete(id);
		}

		/// <summary>
		/// Function to update a homework
		/// </summary>
		/// <param name="id">id of the homework to be updated</param>
		/// <param name="desc">new description of the homework</param>
		/// <param name="receivingWeek">new receiving week </param>
		/// <param name="deadlineWeek">new deadline week</param>
		/// <returns>null if the homework was updated, the given homework otherwise</returns>
		public Homework UpdateHomework(string id, string desc, int receivingWeek, int deadlineWeek)
		{
			return _hwRepo.Update(new Homework(id, desc, receivingWeek, deadlineWeek));
		}

		/// <summary>
		/// Function to get a homework by id
		/// </summary>
		/// <param name="id">id of the homework to search for</param>
		/// <returns>the homework with the given id if it exists, null otherwise</returns>
		public Homework FindHomework(string id)
		{
			return _hwRepo.FindOne(id);
		}

		/// <summary>
		/// Function to get all homework from the repository
		/// </summary>
		/// <returns>an IEnumerable containing all homework from the repository</returns>
		public IEnumerable<Homework> GetAllHomework()
		{
			return _hwRepo.FindAll();
		}

		/// <summary>
		/// Function to extend a given homework by one week
		/// </summary>
		/// <param name="hwId">id of the homework to be extended</param>
		/// <returns>true if the homework could be extended, false otherwise</returns>
		public bool ExtendHomework(string  hwId)
		{
			var retValue = _hwRepo.FindOne(hwId);
			if (Utility.GetCurrentWeek() + 1 > 14 || retValue == null)
			{
				
				return false;
			}
			else
			{
				retValue.DeadlineWeek += 1;
				_hwRepo.Update(retValue);
				return true;
			}
		}
	}
}