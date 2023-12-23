// File: "LinqObj47"
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
            Task("LinqObj47");
            string s1 = GetString();
            string s2 = GetString();

            var r = File.ReadLines(s1, Encoding.Default)
            .Select(e=>
            {
                string[] s = e.Split(' ');
                return new 
                {
                    company = s[1],
                    address = s[2],
                    type = s[3]
                };
            }).OrderBy(x=>x.company).ThenBy(x=>x.address).GroupBy(e=>new{e.company, e.address})
            .Where(e=>e.Count()>=2)
            .Select(e=>e.First().company+" "+ e.First().address +" "+ e.Count()).Show();

             File.WriteAllLines(s2, r.ToArray());

           
            
        }
    }
}
