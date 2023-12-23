// File: "OOP2Struc3"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public class TextView
        {
            // Do not change the implementation of the class
            int x, y;
            int width = 1, height = 1;
            public void GetOrigin(out int x, out int y)
            {
                x = this.x;
                y = this.y;
            }
            public void SetOrigin(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
            public void GetSize(out int width, out int height)
            {
                width = this.width;
                height = this.height;
            }
            public void SetSize(int width, int height)
            {
                this.width = width;
                this.height = height;
            }
        }

        public abstract class Shape
        {
            public abstract string GetInfo();
            public abstract void MoveBy(int a, int b);
        }

        // Implement the RectShape and TextShape descendant classes

        public class RectShape : Shape
        {
            string str = null;
            int x1, x2, y1, y2;

            public RectShape(int x1, int y1, int x2, int y2)
            {
                this.x1 = x1;
                this.x2 = x2;
                this.y1 = y1;
                this.y2 = y2;
            }
            public override string GetInfo()
            {
               // throw new NotImplementedException();
                str = str + "R" + "(" + Convert.ToString(x1) + "," + Convert.ToString(y1) + ")" +  "(" + Convert.ToString(x2) + "," + Convert.ToString(y2) + ")" + '\0';
                return str;
            }

            public override void MoveBy(int a, int b)
            {
                //throw new NotImplementedException();
                x1 = x1 + a;
                y1 = y1 + b;
                x2 = x2 + a;
                y2 = y2 + b;
            }
        }

        public class TextShape : Shape
        {
            string str = null;
            int x1, x2, y1, y2;

            public TextShape(int x1, int y1, int x2, int y2)
            {
                this.x1 = x1;
                this.x2 = x2;
                this.y1 = y1;
                this.y2 = y2;
            }
            public override string GetInfo()
            {
               // throw new NotImplementedException();
                str = str + "T" + "(" + Convert.ToString(x1) + "," + Convert.ToString(y1) + ")" +  "(" + Convert.ToString(x2) + "," + Convert.ToString(y2) + ")" + '\0';
                return str;
            }

            public override void MoveBy(int a, int b)
            {
                //throw new NotImplementedException();
                x1 = x1 + a;
                y1 = y1 + b;
                x2 = x2 + a;
                y2 = y2 + b;
            }
        }

        public static void Solve()
        {
            Task("OOP2Struc3");
            int N = GetInt();
            Shape[] arr= new Shape [N];

            for(int i = 0; i < N; i++)
            {
                char c = GetChar();
                int x1 = GetInt();
                int y1 = GetInt();
                int x2 = GetInt();
                int y2 = GetInt();
                
                if(c == 'T')
                    arr[i] = new TextShape(x1, y1,x2, y2);
                else  
                    arr[i] = new RectShape(x1, y1,x2, y2);
            }

            int A = GetInt();
            int B = GetInt();

            for(int i = 0; i < N; i++)
            {
                arr[i].MoveBy(A,B);
               
                Put(arr[i].GetInfo());
            }
        }
    }
}
