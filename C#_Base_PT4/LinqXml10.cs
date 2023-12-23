// File: "LinqXml10"
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
        // When solving tasks of the LinqXml group, the following
        // additional methods defined in the taskbook are available:
        // (*) Show() and Show(cmt) (extension methods) - debug output
        //       of a sequence, cmt - string comment;
        // (*) Show(e => r) and Show(cmt, e => r) (extension methods) -
        //       debug output of r values, obtained from elements e
        //       of a sequence, cmt - string comment.

        public static void Solve()
        {
            Task("LinqXml10");
        /*
            var a = File.ReadAllLines(GetString());
//创建一个包含根元素、一级行元素和处理指令（处理指令是根元素的子节点）的 XML 文档。
            XDocument d = new XDocument(
                new XDeclaration(null, "us-ascii", null),
                new XElement("root", 
                    a.Select(e=>new XElement("line", e)))
            );
            d.Save(GetString());

//如果文本文件行以文本“data:”开头，则将其（不带文本“data:”）作为数据添加到 XML 文档中，
//以用于下一个名为 instr 的处理指令，否则将该行添加为子文本节点到下一个行元素。
            e => e.StartsWith("data:") ?
            new XProcessingInstruction("instr", e.Substring(5)) :
            new XElement("line", e) as XNode;
        */

        var a = File.ReadAllLines(GetString());
            XDocument d = new XDocument(
                new XDeclaration(null, "us-ascii", null),
                new XElement("root", 
                    a.Select( e => e.StartsWith("data:") ?
            new XProcessingInstruction("instr", e.Substring(5)) :
            new XElement("line", e) as XNode))
            );
            d.Save(GetString());
        }
    }
}
