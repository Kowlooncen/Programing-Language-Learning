// File: "LinqObj71"
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
            Task("LinqObj71");
            var A = File.ReadLines(GetString(), Encoding.Default)
            .Select(e=>
                {
                    string[] s = e.Split(' ');
                    return new{
                        code = int.Parse(s[0]),
                        born = s[1]
                    };
                }
            );

            var C = File.ReadLines(GetString(), Encoding.Default)
            .Select(e=>
                {
                    string[] s = e.Split(' ');
                    return new{
                        code = int.Parse(s[0]),
                        discount = int.Parse(s[1]),
                        shop = s[2]
                    };
                }
            );

            var v = C.Join(A, e1=>e1.code, e2=>e2.code, (e1, e2)=>new{e1.shop, e1.code, e1.discount, e2.born})
            .GroupBy(e=>e.shop, (k, ee)=>new{shop = k, X = ee.OrderByDescending(e=>e.discount).ThenBy(e=>e.code).First()})
            .OrderBy(e=>e.shop)
            .Select(e=>e.shop +" "+ e.X.code+" "+e.X.born+" "+ e.X.discount).Show();

            File.WriteAllLines(GetString(), v.ToArray());
            
        }
    }
}
