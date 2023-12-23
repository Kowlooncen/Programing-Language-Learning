// File: "LinqObj98"
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
            Task("LinqObj98");
            var B = File.ReadLines(GetString(), Encoding.Default)
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                {
                    art = s[1],
                    cat = s[2]
                };
            });

            var C = File.ReadLines(GetString(), Encoding.Default)
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                {
                    discount = int.Parse(s[0]),
                    code = s[1],
                    shop = s[2]
                };
            });

            var D = File.ReadLines(GetString(), Encoding.Default)
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                
                {
                    art = s[0],
                    price = int.Parse(s[1]),
                    shop = s[2]
                };
            });

            var E = File.ReadLines(GetString(), Encoding.Default)
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                {
                    code = s[0],
                    art = s[1],
                    shop = 
                    s[2]
                };
            });

            var discounts = E.Join(B, e1=>e1.art, e2=>e2.art, (e1, e2)=>new{e1.code, e1.art, e1.shop, e2.cat})
            //申明需要B组加入，e1表示E，e2表示B，以共有的art为基准合并,加入分类cat
            .Join(D, e1 => e1.art + e1.shop, e2 => e2.art + e2.shop, (e1, e2) => new {e1.code, e1.art,e1.shop,e1.cat,e2.price})
            //申明需要D组加入，e1表示E，e2表示D，以共有的shop和art为基准合并，加入商品价格price
            .GroupJoin(C, e1 => e1.code + e1.shop, e2 => e2.code + e2.shop,
            (e1, ee2) => new {
                cat_shop = e1.cat + " " + e1.shop,
                discount = ee2.Select(e => e.discount).FirstOrDefault() * e1.price / 100 
            })
            //申明需要C组加入，e1表示E，e2表示C，ee2表示C组，以共有的shop和code为基准合并，选择C组中的折扣
            .Show();
           
            var cats = B.GroupBy(e => e.cat, (k, ee) => k);
            var shops = E.GroupBy(e => e.shop, (k, ee) => k);
            var r = cats
            .SelectMany(e1 => shops.Select(e2 => e1 + " " + e2))
            .OrderBy(e => e)
            .GroupJoin(discounts, e1 => e1, e2 => e2.cat_shop,
            (e1, ee2) => e1 + " " +
            ee2.Select(e => e.discount).DefaultIfEmpty(-1).Sum());
            File.WriteAllLines(GetString(), r.ToArray(), Encoding.Default);


        }
    }
}
