// File: "LinqXml20"
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
            Task("LinqXml20");
            
            XDocument d = XDocument.Load(GetString());
            
            foreach (var e1 in d.Root.Elements())
            {
                
                // Show(e1.Name.LocalName);               //Элемент первого уровня:就是第一级元素的开头<a>
                //int max = 
                Show(e1.Descendants()) ;
            //     .Select(e => e.Attributes().Count())
            //     .DefaultIfEmpty(-1).Max();
            //     Put(max);
            //     var a = e1.Descendants()
            //     .Where(e => e.Attributes().Count() == max)
            //     .Select(e => e.Name.LocalName)
            //     .OrderBy(e => e)
            //     .DefaultIfEmpty("no child");
            //     foreach (var e in a)
            //     Put(e);
             }
        }
    }
}
