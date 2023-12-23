// File: "LinqBegin57"
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
            Task("LinqBegin57");
            IEnumerable<int> I = GetEnumerableInt();
            var check = I.GroupBy(x=>Math.Abs(x)%10);
            //check.Show();
            IEnumerable<int> I1 = 
                    from x in check
                    select x.Max()
                    ;
            I1 = I1.OrderBy(x=>Math.Abs(x)%10);
            I1.Show();
            I1.Put();
        }
    }
}
