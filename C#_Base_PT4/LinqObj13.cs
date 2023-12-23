// File: "LinqObj13"
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
            Task("LinqObj13");
            string s1 = GetString(),
                   s2 = GetString();
            IEnumerable<string> S1 = File.ReadLines(s1);
            List<(int, int)> l = new List<(int, int)> ();
            foreach (string s in S1){
                string[] ss = s.Split(' ');
                l.Add((int.Parse(ss[1]), int.Parse(ss[0])));
            }
            //l.Show();
            Show('\n');
            var g1 = l.GroupBy(x=>x.Item1);
            
            //g1.Show();
            IEnumerable<string> S0 = 
            from x in g1
            from s in x
            where s.Item2 == x.Max(x=>x.Item2)
            orderby s.Item1
            select Convert.ToString(s.Item1)+" "+Convert.ToString(s.Item2);
            S0 = S0.Distinct();
            S0.Show();
            File.WriteAllLines(s2,S0);

        }
    }
}
