// File: "LinqXml89"
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
            Task("LinqXml89");
            string name = GetString();
            XDocument d = XDocument.Load(name);
            XNamespace ns = d.Root.Name.Namespace;
            var a = d.Root.Elements().Select(e=>{
                var s2 = e.Attribute("class").ToString().Substring(7);
                var s3 = e.Attribute("subject").ToString().Substring(9);
                return new{
                    clas = int.Parse(s2.Remove(s2.Length-1,1)),
                    subj = s3.Remove(s3.Length-1,1),
                    num = int.Parse(e.Value),
                    name = e.Name.LocalName
                };
            }).OrderBy(e=>e.subj).ThenBy(e=>e.clas);

            var f = Enumerable.Range(7, 5);

            d.Root.ReplaceNodes(a.GroupBy(e=>e.subj,(k,ee)=>
            new XElement(ns+k,
            f.GroupJoin(ee,e1=>e1,e2=>e2.clas,(e1,ee2)=>
                new XElement(ns+("class"+e1),
                    new XAttribute("pupil-count",ee2.GroupBy(e=>e.name).Any()?ee2.GroupBy(e=>e.name).Count():0),
                    new XAttribute("mark-count",ee2.Select(e=>e.num).Count())
                )
            ))));
            d.Save(name);
        }
    }
}
