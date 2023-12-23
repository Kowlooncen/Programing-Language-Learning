// File: "LinqXml25"
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
            Task("LinqXml25");
            string name = GetString();
            XDocument d = XDocument.Load(name);
            foreach(var e in d.Root.Elements())
            {
                if (e.Attributes().Count()>1)
                    e.RemoveAttributes();
            }
                
            foreach(var e in d.Root.Elements().Elements())
            {
                if (e.Attributes().Count()>1)
                    e.RemoveAttributes();
            }
            d.Save(name);
        }
    }
}
