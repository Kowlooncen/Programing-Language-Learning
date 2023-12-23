// File: "LinqXml52"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml.Linq;
//
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqXml52");

            string name = GetString();
            XDocument d = XDocument.Load(name);

            foreach(var x in d.Descendants())
            {
                ShowLine(x);
                if(x.Name.LocalName!="date")
                {
                    x.AddFirst(new XElement("date",
                        new DateTime((int?)x.Attribute("year") ?? 2000,
                        (int?)x.Attribute("month") ?? 1,
                        (int?)x.Attribute("day") ?? 10
                     )));
                }
                x.Attributes("year").Remove();
                x.Attributes("month").Remove();
                x.Attributes("day").Remove();
            }
            d.Save(name);
        }
    }
}
