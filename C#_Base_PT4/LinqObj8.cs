// File: "LinqObj8"
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
        // To read strings from the source text file into
        // a string sequence (or array) s, use the statement:
        //   s = File.ReadLines(GetString());
        // To write the sequence s of IEnumerable<string> type
        // into the resulting text file, use the statement:
        //   File.WriteAllLines(GetString(), s);
        // When solving tasks of the LinqObj group, the following
        // additional methods defined in the taskbook are available:
        // (*) Show() and Show(cmt) (extension methods) - debug output
        //       of a sequence, cmt - string comment;
        // (*) Show(e => r) and Show(cmt, e => r) (extension methods) -
        //       debug output of r values, obtained from elements e
        //       of a sequence, cmt - string comment.

        public static void Solve()
        {
            Task("LinqObj8");
            int k=GetInt();
            
            var r = File.ReadLines(GetString(), Encoding.Default)
            .Select(e=>
            {
                string[] s = e.Split(' ');
                return new 
                {
                    hours = int.Parse(s[0]),
                    code = int.Parse(s[1]),
                    year = int.Parse(s[2]),
                    month = int.Parse(s[3])
                };
            }).Where(e=>e.code == k)
            .GroupBy(e=>e.year,(k, ee) => new { year = k, min = ee.OrderBy(e => e.hours).First() })
            .OrderBy(e => e.min.hours).ThenBy(e => e.year)
            .Select(e=>e.min.hours+" "+e.year+" "+e.min.month)
            .DefaultIfEmpty("No data").Show();

            File.WriteAllLines(GetString(), r.ToArray());

        }
    }
}
