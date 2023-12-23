// File: "LinqObj61"
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
            Task("LinqObj61");
            string[] subjects = { "Алгебра", "Геометрия", "Информатика" };
            var culture = new System.Globalization.CultureInfo("en-US");
            var r =
                from e in File.ReadLines(GetString(), Encoding.Default)
                let s = e.Split(' ')
                select new
                {
                    name = s[0] + " " + s[1],
                    subj = s[3],
                    mark = int.Parse(s[4])
                }
                into e
                 group e by e.name
                 into e
                 let avrs =
                    from e1 in subjects
                    join e2 in e
                    on e1 equals e2.subj
                    into ee
                    select
                       (from ee1 in ee
                        select ee1.mark)
//                 .DefaultIfEmpty().Average()
//                 orderby e.Key
                //select e.Key + avrs.Aggregate("", (a, d) => a + " " + d.ToString("f2", culture));
            
           // File.WriteAllLines(GetString(), r.ToArray(), Encoding.Default);
        }
    }
}
