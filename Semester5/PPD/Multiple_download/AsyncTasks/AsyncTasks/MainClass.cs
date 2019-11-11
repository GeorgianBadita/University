using System;
using System.Collections.Generic;
using Async_Tasks;

namespace Async_Tasks
{
    public class MainClass
    {
        private static List<String> hts = new List<String>();

        public static void Main(string[] args)
        {
            hts.Add("www.cs.ubbcluj.ro/~rlupsa/edu/pdp");
            hts.Add("youtube.com");
            hts.Add("google.com");

            //TaskMechanism.run(hts);
            //DirCallbacks.run(hts);
            AsyncTaskMechanism.run(hts);
        }
    }
}