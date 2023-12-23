// File: "LinqObj91"
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
            Task("LinqObj91");
            var A = File.ReadLines(GetString(), Encoding.Default)
            .Select(e=>
            {
                string[] s = e.Split(' ');
                return new
                {
                    address = s[0],
                    code = s[2]
                };
            });

            var B = File.ReadLines(GetString(), Encoding.Default)
            .Select(e=>
            {
                string[] s = e.Split(' ');
                return new{
                    item = s[0],
                    country = s[1],
                    cat = s[2]
                };
            });

            var E = File.ReadLines(GetString(), Encoding.Default)
            .Select(e=>
            {
                string[] s = e.Split(' ');
                return new{
                    item = s[1],
                    code = s[2]
                };
            });

            var c = B.Join(E, e1=>e1.item, e2=>e2.item, (e1, e2)=>new{e1.country, e1.cat, e2.code})
            .Join(A, e1=>e1.code, e2=>e2.code, (e1, e2)=>new{e2.address, e1.cat, e1.country})
            .Distinct().OrderBy(x=>x.address).ThenBy(x=>x.cat)
            .GroupBy(e=>new{e.address, e.cat})
            .Select(e=>e.First().address+" "+e.First().cat+" "+e.Count())
            ;

            File.WriteAllLines(GetString(), c.ToArray());
   
        }
    }
}
