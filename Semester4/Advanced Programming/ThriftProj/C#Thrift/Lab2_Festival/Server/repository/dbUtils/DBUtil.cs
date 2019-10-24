using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.repository.dbUtils
{
    public static class DBUtil
    {
        private static IDbConnection instance = null;

        public static IDbConnection GetConnection(IDictionary<string, string> props)
        {
        
            if(instance == null || instance.State == System.Data.ConnectionState.Closed)
            {
                instance = GetNewConnection(props);
                instance.Open();
            }

            return instance;
        }

        private static IDbConnection GetNewConnection(IDictionary<string, string> props)
        {
            return DBUtils.ConnectionFactory.getInstance().createConnection(props);
        }
    }
}
