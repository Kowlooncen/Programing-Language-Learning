using System;
using PT4;
using PT4Tasks;

namespace PT4Main
{
    class PTMain
    {
//--------------------------------------------------//
//       WARNING! Altering the Main function        //
//  may cause Programming Taskbook to malfunction.  //
//--------------------------------------------------//
        public static int Main(string[] args)
        {
            for (int i = 0; i < 10; i++)
            {
                TaskMaker.StartCS();
                try
                {
                    MyTask.Solve();
                }
                catch (Exception ex)
                {
                    TaskMaker.RaisePT(ex);
                }
                int res = TaskMaker.FreePT();
                if (res == 1)
                    break;
            }
            return 0;
        }
    }
}
