// File: "LinqBegin23"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
///
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin23");

            int K = GetInt();
            GetEnumerableInt().Skip(K-1)
            .Where(x => (Math.Abs(x) / 100 ==0 && Math.Abs(x) % 100 > 9 ) && Convert.ToBoolean(Math.Abs(x) % 2))
            .OrderByDescending(x=>x).Put();
        }
    }
}
