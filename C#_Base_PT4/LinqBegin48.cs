// File: "LinqBegin48"
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
            Task("LinqBegin48");
            IEnumerable<string> A = GetEnumerableString();
            IEnumerable<string> B = GetEnumerableString();

            var result = from elem1 in A
                        join elem2 in B on elem1.Length equals elem2.Length
                        orderby elem1 , elem2 descending
                        select elem1 +":"+ elem2;

            foreach(var item in result)
            {
                Show(item);
            }
            result.Put();
        }
    }
}
