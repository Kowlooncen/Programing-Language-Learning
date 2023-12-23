// File: "LinqObj18"
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
            Task("LinqObj18");
            IEnumerable<string> S=File.ReadLines(GetString());
            List<(string,string)> g=new List<(string, string)>();
            foreach(string s in S){
                string[] ss=s.Split(' ');
                g.Add((ss[0],ss[2]));
            }
            var g0=g.GroupBy(x=>x.Item1);
            //g0.Show();
            IEnumerable<(string,int)> G=
                from x in g0
                from s in x
                select (s.Item1,x.Count());
            G=G.Distinct();
            
            G=G.OrderByDescending(x=>x.Item2).ThenBy(x=>x.Item1);
            G.Show();
             int sum=G.Aggregate(0,(s,next)=>s+=next.Item2);
             Show(sum);
             
        }
    }
}
