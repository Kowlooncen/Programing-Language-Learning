// File: "LinqXml77"
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
            Task("LinqXml77");
                string name = GetString();
                XDocument d = XDocument.Load(name);
                XNamespace ns = d.Root.Name.Namespace;
               
                d.Root.ReplaceNodes(d.Root.Elements()
                    .Select(e=>
                    new{
                        house = int.Parse(e.Attribute("house").Value),
                        flat = int.Parse(e.Attribute("flat").Value),
                        name = e.Attribute("name").Value,
                        debt = e.Value
                    }
                    ).OrderBy(x=>x.house).ThenBy(x=>x.flat)
                    .Select(e=>
                        new XElement(ns + "address" + e.house.ToString()+"-"+e.flat.ToString(),
                        new XAttribute("name", e.name),
                        new XAttribute("debt", e.debt)
                        )
                    )
                );

                d.Save(name);

        }
    }
}
