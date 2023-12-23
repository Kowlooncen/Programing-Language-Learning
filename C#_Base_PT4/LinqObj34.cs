// File: "LinqObj34"
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
            Task("LinqObj34");
            string s1 = GetString();
            string s2 = GetString();

            var r = File.ReadLines(s1, Encoding.Default)
            .Select(e=>
                {
                    string[] s = e.Split(' ');
                    return new{
                        money = double.Parse(s[0]),
                        number = int.Parse(s[1]),
                        name = s[2],
                        floor = (int.Parse(s[1])-1) % 36 / 4 + 1
                    };
                }
            );

            double k = r.Average(x=>x.money);

            var r1 = r.Where(e=>e.money<=k).OrderByDescending(e=>e.floor)
            .ThenBy(x=>x.number)
            .Select(e=>e.floor+" "+e.number+" "+e.name+" "+e.money.ToString("f2")).Show();
            
             File.WriteAllLines(s2, r1.ToArray());
        }
    }
}
