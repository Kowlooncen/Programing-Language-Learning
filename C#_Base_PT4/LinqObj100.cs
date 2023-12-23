// File: "LinqObj100"
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
            Task("LinqObj100");
            var A = File.ReadLines(GetString(), Encoding.Default)
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                {
                    code = int.Parse(s[1]),
                    year = s[2]
                };
            });

            var B = File.ReadLines(GetString(), Encoding.Default)
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                {
                    item = s[0],
                    country = s[1]
                };
            });

            var D = File.ReadLines(GetString(), Encoding.Default)
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                
                {
                    shop = s[0],
                    price = int.Parse(s[1]),
                    item = s[2]
                };
            });

            var E = File.ReadLines(GetString(), Encoding.Default)
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                {
                    item = s[0],
                    code = int.Parse(s[1]),
                    shop = s[2]
                };
            });

            var v = E.Join(A, e1=>e1.code, e2=>e2.code, (e1, e2)=>new{e1.code, e1.shop, e1.item, e2.year})
                .Join(B, e1 => e1.item, e2 => e2.item, (e1, e2) => new {e1.code, e1.item,e1.shop,e1.year,e2.country})
                .Join(D, e1 => e1.shop + e1.item, e2 => e2.shop + e2.item,
                (e1, e2) => new {
                e1.country, e1.shop,
                e1.code, e1.year, e1.item, e2.price
                }).OrderBy(e=>e.country).ThenBy(e=>e.shop)
                //.GroupBy(e=>(e.country+" "+e.shop))
                // .Select(e=>(e.First().country, e.First().shop))
                // .OrderBy(e=>e.country)
                .GroupBy(e=>(e.country+" "+e.shop),(k, ee)=>
                new {
                    country_shop = k,
                    X = ee.Where(x=>x.year ==ee.Max(x=>x.year) )
                         .GroupBy(x=>x.code)
                         .Select(e=>(e.First().country, e.First().shop, e.First().year, e.First().code, e.Select(x=>x.price).Sum()))
                         .OrderBy(x=>x.code)
                } )
                .Select(e=>e.X);

                var G = 
                from s in v
                from x in s
                select x.Item1+" " + x.Item2+" " +x.Item3+" " +x.Item4+" " +x.Item5;

                G.Show();
                File.WriteAllLines(GetString(), G.ToArray());
        }
    }
}
