using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBUtils
{
    public class MySqlConnectionFactory : ConnectionFactory
    {
        public override IDbConnection createConnection(IDictionary<string, string> props)
        {
            //MySql Connection
            //String connectionString = "Database=festival; +
            //                          "Data Source=localhost;" +
            //                          "User id=test;" +
            //                          "Password=root123;";
            String connectionString = props["ConnectionString"];
            Console.WriteLine("MySql -- opens connection to ....{0}", connectionString);
            return new MySqlConnection(connectionString);
        }
    }
}
