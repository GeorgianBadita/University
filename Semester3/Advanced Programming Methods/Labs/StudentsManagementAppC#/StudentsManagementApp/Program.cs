using System;
using System.Collections.Generic;
using System.Linq;
using StudentsManagementApp.domain.validator;
using StudentsManagementApp.repository;
using StudentsManagementApp.service;
using StudentsManagementApp.ui;
using StudentsManagementApp.ui.filter;
using StudentsManagementApp.ui.grade;
using StudentsManagementApp.ui.homework;
using StudentsManagementApp.ui.report;
using StudentsManagementApp.ui.student;
using StudentsManagementApp.utils;

namespace StudentsManagementApp
{
    class Felina
    {
        public virtual void ShowIdentity()
        {
            Console.Write("Felina ");
        }
    }


    class Ferrari : Felina
    {
        public new void ShowIdentity()
        {
            Console.Write("Ferrari ");
        }
    }
    
    internal static class Program
    {
        /*
        public static void Main(string[] args)
        {
            var studRepo = new StudentFileRepository(new StudentValidator(),
                "/home/geo/Desktop/MapJavaToC#/StudentsManagementApp/StudentsManagementApp/repository/files/students.txt");
           

            var homeworkRepo = new HomeworkFileRepository(new HomeworkValidator(),
                "/home/geo/Desktop/MapJavaToC#/StudentsManagementApp/StudentsManagementApp/repository/files/homework.txt");

            var gradeRepo = new GradeFileRepository(new GradeValidator(),
                "/home/geo/Desktop/MapJavaToC#/StudentsManagementApp/StudentsManagementApp/repository/files/grade.txt");

            var studSrv = new StudentService(studRepo);
            var hwSrv = new HomeworkService(homeworkRepo);
            var grSrv = new GradeService(studRepo, homeworkRepo, gradeRepo);

            var filterConsole = new FilterConsole(grSrv);
            var reportConsole = new ReportConsole(grSrv);
            var studConsole = new StudentConsole(studSrv);
            var hwConsole = new HomeworkConsole(hwSrv);
            var grConsole = new GradeConsole(grSrv);
            IConsole console = new ConsoleUi(studConsole, hwConsole, grConsole, filterConsole, reportConsole);
            console.Run(); 
        }*/
        public static void Main(string[] args)
        {
            Ferrari p1 = new Ferrari();
            Felina p2 = new Felina();
            ;
            p1.ShowIdentity();
            List<Felina> colectie = new List<Felina>();
            colectie.Add(p1);
            colectie.Add(p2);
            colectie.ForEach(x => {x.ShowIdentity();});
        }
    }
}