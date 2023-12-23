// File: "LinqBegin8"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        //
        public static void Solve()
        {
            Task("LinqBegin8");
            IEnumerable<int> I = GetEnumerableInt().Where(x => (x > 0) && x/100 ==0 && x%100 > 9);
            
            try
            {
                Put(I.Count(), I.Average());
            }
            catch (System.Exception)
            {
                Put(0, 0.00);
            }
        }
    }
}
