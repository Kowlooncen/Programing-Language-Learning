// File: "LinqBegin37"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin37");
            GetEnumerableString().Select((e, n)=> e + Convert.ToString(n+1)).Where(x => !char.IsDigit(x[0])).OrderBy(x=>x).Put();
        }
    }
}
