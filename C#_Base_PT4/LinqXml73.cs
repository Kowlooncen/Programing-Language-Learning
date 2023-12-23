// File: "LinqXml73"
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
            Task("LinqXml73");
            string name = GetString();
            XDocument d = XDocument.Load(name);
            XNamespace ns = d.Root.Name.Namespace;
            
            var a = d.Root.Elements()
                    .SelectMany(e=>e.Elements(),
                    (k, ee)=>new{
                        street = k.Name.LocalName,
                        company = ee.Attribute("name").Value,
                        brand = int.Parse(ee.Element(ns+"brand").Value),
                        price = int.Parse(ee.Element(ns+"price").Value)
                    }
                ).OrderBy(x=>x.company).ThenBy(x=>x.street).ThenBy(x=>x.brand)
                .GroupBy(e=>new{e.company, e.street}).Where(e=>e.Count()>=2).Show();
            d.Root.ReplaceNodes(
            from x in a
            select new XElement(ns+(x.First().company+"_"+x.First().street), 
                new XAttribute("brand-count",x.Count()),
                from s in x 
                select new XElement(ns+("b"+s.brand), new XAttribute("price",s.price))
            ));

            d.Save(name);
        }
    }
}
