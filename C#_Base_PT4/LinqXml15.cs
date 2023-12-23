// File: "LinqXml15"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml.Linq;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqXml15");
            XDocument d = XDocument.Load(GetString());
           
            var a = d.Root.Elements()
            .Select(e=> (e.Name.LocalName, e.Descendants().Where(x=>x.Attributes().Count()>=2).Count()))
            .OrderBy(e => e.Item1).ThenBy(e=>e.Item2)
            .Show();
           
            foreach (var e in a)
                Put(e.Item1, e.Item2);
        
        }
    }
}
