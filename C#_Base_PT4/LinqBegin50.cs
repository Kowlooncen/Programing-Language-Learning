// File: "LinqBegin50"
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
            Task("LinqBegin50");

            IEnumerable<string> A = GetEnumerableString();
            IEnumerable<string> B = GetEnumerableString();

            var result = 
                    from elem1 in A
                    join elem2 in B 
                    on elem1[0] equals elem2[0] into t
                    select elem1 + ":" +Convert.ToString(t.Count());

            result.Put();
        }
    }
}
