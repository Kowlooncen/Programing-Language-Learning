// File: "LinqBegin29"
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
            Task("LinqBegin29");
            int D = GetInt();
            int K = GetInt();
            IEnumerable<int> I = GetEnumerableInt();
            
            IEnumerable<int> I1 = I.TakeWhile(x=> x <= D);  
            IEnumerable<int> I2 = I.Skip(K-1);
        
            var resultUnion = I1.Union(I2).Distinct().OrderByDescending(x=>x);

            foreach(int e in resultUnion)
            {
                Show(e);
            }
            
            resultUnion.Put();
        }
    }
}
