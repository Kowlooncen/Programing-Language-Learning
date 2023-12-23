// File: "LinqXml86"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml.Linq;
/////////////////////////////////////////
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqXml86");
            string name = GetString();
            XDocument d = XDocument.Load(name);
            XNamespace ns = d.Root.Name.Namespace;

            var r = d.Root.Elements()
                .Select(e=>
                    new{
                        Nam = e.Attribute("name").Value.Split(' ')[0]+"_"+e.Attribute("name").Value.Split(' ')[1],
                        Class = e.Attribute("class").Value,
                        Mark = int.Parse(e.Element(ns+"info").Attribute("mark").Value),
                        Subject = e.Element(ns+"info").Attribute("subject").Value
                    }
                )
                .OrderBy(e=>e.Nam).ThenByDescending(e=>e.Mark).ThenBy(e=>e.Subject);
            
             d.Root.ReplaceNodes(r.GroupBy(e=>e.Nam, 
                    (k,ee)=>new XElement(ns+(k),
                        new XAttribute("class", ee.First().Class),
                        from x in ee
                        select new XElement(ns+("mark"+x.Mark.ToString()),
                            new XAttribute("subject", x.Subject)    
                    )
                )));
            
            d.Save(name);
        }
    }
}


    
