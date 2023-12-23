// File: "LinqXml61"
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
            Task("LinqXml61");
            string name = GetString();
            XDocument d = XDocument.Load(name);
            XNamespace ns = d.Root.Name.Namespace;
            
            d.Root.Elements()
            .Select(e=>e.Element())
            .Show();
        }
    }
}
