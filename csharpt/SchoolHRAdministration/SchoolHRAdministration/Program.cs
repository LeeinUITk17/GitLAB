using HRAdministrationAPI;
using System;
using System.Collections.Generic;
using System.Linq;

namespace SchoolHRAdministration
{
    public enum EmployeeType
    {
        Teacher,
        HeadOfDepartment,
        DeputyHeadMaster,
        HeadMaster
    }
    class Program
    {
        static void Main(string[] args)
        {
            decimal totalSalaries = 0;
            List<IEmployee> employees = new List<IEmployee>();

           SeedData(employees);

           foreach(IEmployee employee in employees)
            {
                totalSalaries += employee.Salary;
            }
            Console.WriteLine($"Total Annual Salaries (including bonus): {totalSalaries}");
            //Console.WriteLine($"Total Annual Salaries (including bonus): {totalSalaries}");

            Console.WriteLine($"Total Annual Salaries (including bonus): {employees.Sum(e => e.Salary)}");
            List<IEmployee> examlist = employees.Where(e => e.Salary > 3000).ToList();
            foreach(IEmployee ex in examlist)
            {
                Console.WriteLine("\n\tID: " + ex.Id);
                Console.WriteLine("\tFullname: " + ex.FirstName + " " + ex.LastName);
                Console.WriteLine("\tSalary: " + ex.Salary+"\n");
            }
            Console.ReadKey();

        }
        public static void SeedData(List<IEmployee> employees)
        {
            IEmployee teacher1s = new Teacher()
            {
                Id=22521276,
                FirstName="tai",
                LastName="lee",
                Salary=2000
            };
            IEmployee teacher2s = new Teacher()
            {
                Id = 22521277,
                FirstName = "tuan",
                LastName = "lee",
                Salary = 3000
            };
            employees.Add(teacher1s);
            employees.Add(teacher2s);
            IEmployee headofdepartment = new HeadOfDepartment()
            {
                Id = 22521376,
                FirstName = "Tu",
                LastName = "lee",
                Salary = 5000
            };
            employees.Add(headofdepartment);
            IEmployee debutyheadmaster = new DeputyHeadMaster()
            {
                Id = 22531377,
                FirstName = "lee",
                LastName = "Park",
                Salary = 10000
            };
            employees.Add(debutyheadmaster);
            IEmployee headmaster = new HeadMaster()
            {
                Id = 22521313,
                FirstName = "Le Thanh",
                LastName = "Tai",
                Salary = 20000
            };
            employees.Add(headmaster);
        }
    }


    public class Teacher : EmployeeBase
    {
        public override decimal Salary { get => base.Salary + (base.Salary * 0.02m); }

    }

    public class HeadOfDepartment : EmployeeBase
    {
        public override decimal Salary { get => base.Salary + (base.Salary * 0.03m); }
    }

    public class DeputyHeadMaster : EmployeeBase
    {
        public override decimal Salary { get => base.Salary + (base.Salary * 0.04m); }
    }

    public class HeadMaster : EmployeeBase
    {
        public override decimal Salary { get => base.Salary + (base.Salary * 0.05m); }
    }


}