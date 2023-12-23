// File: "LinqBegin41"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        // static List<string> l = new List<string>();

        // public static void func(string s)
        // {
        //     if(s.IndexOf(".")==-1) l.Add(s);
        //     else {
        //         int n = s.IndexOf(".");
        //         l.Add(s.Substring(0, n));
        //         func(s.Substring(n+1));
        //     }
        // }
        public static void Solve()
        {
            Task("LinqBegin41");
            
            int K = GetInt();
            IEnumerable<string> S = GetEnumerableString();
            IEnumerable<string> s = S.SelectMany(x=>x.Split('.'));
            IEnumerable<string> str =
                from x in s
                where x.Length == K
                orderby x
                select x;
            str.Put();


            // foreach(string x in S)
            //     Show(x);
            // Show('\n');
            // foreach(string str in S)
            //    func(str);
            // foreach(string x in l)
            //     Show(x);

            // IEnumerable<string> I = 
            //     from x in l
            //     where x.Length == K
            //     select x;
            
            // var p = I.OrderBy(x=>x);
            // Show('\n');
            // foreach(string x in p)
            //     Show(x);
            // p.Put();
        }
    }
}
