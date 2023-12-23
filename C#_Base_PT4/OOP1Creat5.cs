// File: "OOP1Creat5"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class AbstractButton
        {
            public abstract string GetControl();
        }

        // Implement the Button1 and Button2 descendant classes

        public class Button1 : AbstractButton //大写+【】
        {
            string s;
            public Button1(string text){
                text = text.ToUpper();
                this.s = "["+text+"]";
            }
            public override string GetControl(){
                return s; 
            }
        }

        public class Button2 : AbstractButton//小写+《》
        {
            string s;
            public Button2(string text)
            {
                text = text.ToLower();
                this.s = "<" +text+">";
            }
            public override string GetControl()
            {
                return s;
            }
        }

        public abstract class AbstractLabel
        {
            public abstract string GetControl();
        }

        // Implement the Label1 and Label2 descendant classes

        public class Label1 : AbstractLabel
        {
            string s;
            public Label1(string text){
                this.s = "=" + text.ToUpper() + "=";
            }
            public override string GetControl()
            {
                return s;
            }
        }

        public class Label2 : AbstractLabel
        {
            string s;
            public Label2(string text)
            {
                this.s = "\"" + text.ToLower() +"\"";
            }

            public override string GetControl()
            {
                return s;
            }
        }

        public abstract class ControlFactory
        {
            public abstract AbstractButton CreateButton(string text);
            public abstract AbstractLabel CreateLabel(string text);
        }

        // Implement the Factory1 and Factory2 descendant classes

        public class Factory1 : ControlFactory
        {
            public override AbstractButton CreateButton(string text){
                return new Button1(text);
            }
            public override AbstractLabel CreateLabel(string text){
                return new Label1(text);
            }
        }

        public class Factory2 : ControlFactory
        {
            public override AbstractButton CreateButton(string text){
                return new Button2(text);
            }
            public override AbstractLabel CreateLabel(string text){
                return new Label2(text);
            }
        }

        public class Client
        {
            // Add required fields
            string str;
            ControlFactory p;
            public Client(ControlFactory f)
            {
                // Implement the constructor
                p = f;
            }
            public void AddButton(string text)
            {
                // Implement the method
                ShowLine(str);
                if(str==null)
                {
                    str = str + p.CreateButton(text).GetControl();
                    Show("nice");
                }else{
                    str = str + " " + p.CreateButton(text).GetControl();
                    Show("ohohoh");
                }
            }
            public void AddLabel(string text)
            {
                // Implement the method
                if(str==null)
                {
                    str = str + p.CreateLabel(text).GetControl();
                    Show("Good");
                }else{
                    str = str + " " + p.CreateLabel(text).GetControl();
                }
            }
            public string GetControls()
            {
                return str;
                // Remove the previous statement and implement the method
            }
        }

        public static void Solve()
        {
            Task("OOP1Creat5");
            int N = GetInt();
            string[] str = new string [N]; 
            for(int i = 0; i < N; i++)
            {
                string s = GetString();
                str[i] = s;
            }
            Client c1 = new Client(new Factory1());
            for (int i = 0; i < N; i++)
            {
                if (str[i][0] == 'L') {
                    c1.AddLabel(str[i].Substring(2));
                }
                 else {
                    c1.AddButton(str[i].Substring(2));
                }
            }
            Put(c1.GetControls());
            Client c2= new Client(new Factory2());
            for (int i = 0; i < N; i++)
            {
                if (str[i][0] == 'L') {
                    c2.AddLabel(str[i].Substring(2));
                }
                 else {
                    c2.AddButton(str[i].Substring(2));
                }
            }
            Put(c2.GetControls());
        }
    }
}
