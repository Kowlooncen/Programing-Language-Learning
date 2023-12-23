// File: "LinqXml34"
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
            Task("LinqXml34");
            string name = GetString();
            XDocument d = XDocument.Load(name);
            foreach (var e in d.Root.Elements())
            {
                //Show(e.Attributes());
                if (e.Attributes().Count()>=1)
                {
                    e.ReplaceAttributes(e.Attributes()
                    .Select(attr=>new XElement(attr.Name, attr.Value)));
                }
            }
            d.Save(name);
        }
    }
}
