// File: "LinqObj51"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
///
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj51");
            string s1 = GetString();
            string s2 = GetString();

            var r = File.ReadLines(s1, Encoding.Default)
            .Select(e=>
                {
                    string[] s = e.Split(' ');
                    return new{
                        school = int.Parse(s[5]),
                        name = s[3] + " " + s[4],
                        score = int.Parse(s[2])
                    };
                }
            ).GroupBy(e=>e.school, (k, ee)=>new{school = k, max = ee.Where(e=>e.score==ee.Max(x=>x.score)).First()})
            .OrderBy(e=>e.school)
            .Select(e=>e.school + " " + e.max.name + " " + e.max.score)
            .Show();
            File.WriteAllLines(s2, r.ToArray());
        }
    }
}
