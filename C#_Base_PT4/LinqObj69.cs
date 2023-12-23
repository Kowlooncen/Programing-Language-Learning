// File: "LinqObj69"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj69");
            
            string s1 = GetString();
            string s2 = GetString();

            var r = File.ReadLines(s1, Encoding.Default)
            .Select(e=>
            {
                string[] s = e.Split(' ');
                return new
                {
                    Name = s[1] + " " + s[2],
                    Subj = s[3],
                    Mark = int.Parse(s[4]),
                    Class = int.Parse(s[0])
                };
            }) 
            .Where(e => e.Mark <= 2).OrderBy(e=>e.Name)
            .GroupBy(e=>e.Class, (k, ee)=>new {Class = k, X = ee.GroupBy(x=>x.Name).Where( x => x.Count() >= ee.GroupBy(x=>x.Name).Max(e=>e.Count() ))})
            .Select(e=>e.X);

            var v = 
                from x in r         //x班级
                from s in x         //s名字
                from y in s         //组内
                orderby y.Name
                select y.Name + " " + y.Class +" " + s.Count();

            v = v.Distinct().DefaultIfEmpty("Required students not found").Show();

            File.WriteAllLines(s2, v.ToArray());
        }
    }
}
