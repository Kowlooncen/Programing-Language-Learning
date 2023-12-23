// File: "LinqXml54"
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
            Task("LinqXml54");
            string name = GetString();
            XDocument d = XDocument.Load(name);

            XNamespace  ns = d.Root.Name.Namespace;
            
            foreach (var e in d.Root.Elements())
            {
                e.Name = ns + e.Name.LocalName;
            }
            d.Root.Elements().Attributes("xmlns").Remove ();

            foreach (var e in d.Root.Elements().Elements())
            {
                e.Name = ns + e.Name.LocalName;
            }
            d.Root.Elements().Elements().Attributes("xmlns").Remove ();
            
            d.Save(name);
             
        }
    }
}
