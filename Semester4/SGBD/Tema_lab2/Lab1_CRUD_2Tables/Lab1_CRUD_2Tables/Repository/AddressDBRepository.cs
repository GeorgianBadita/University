using Lab1_CRUD_2Tables.Domain.Entities;
using Lab1_CRUD_2Tables.Domain.Validators;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;

namespace Lab1_CRUD_2Tables.Repository
{
    public class AddressDBRepository : AbstractCRUDRepository<int, Address>
    {
        /// <summary>
        /// Constructor for AddressDBRepository class
        /// </summary>
        /// <param name="val">Address Validator</param>
        /// <param name="connString">Connection String</param>
        /// <param name="funTe2InsCmd">Convert an Address Object to an insert command</param>
        /// <param name="funTe2DelCmd">Convert an Address Object to a delete command</param>
        /// <param name="funTe2UpdCmd">Convert an Address Object to an update command</param>
        /// <param name="funTe2FindCmd">Convert an Id to an find command</param>
        public AddressDBRepository(IValidator<Address> val, string connString) : 
                                    base(val, connString, funTe2InsCmd, funTe2DelCmd, funTe2UpdCmd, funTe2FindCmd)
        {

        }

        private static SqlCommand funTe2InsCmd(Address addr, SqlConnection sqlCon)
        {
            SqlCommand cmd = new SqlCommand("INSERT INTO Adresa " + "(Oras, Strada, Numar) " +
             "VALUES (@Oras, @Strada, @Numar)", sqlCon);


            cmd.Parameters.Add("@Oras", SqlDbType.VarChar);
            cmd.Parameters.Add("@Strada", SqlDbType.VarChar);
            cmd.Parameters.Add("@Numar", SqlDbType.Int);


            cmd.Parameters["@Oras"].Value = addr.City;
            cmd.Parameters["@Strada"].Value = addr.Street;
            cmd.Parameters["@Numar"].Value = Convert.ToInt32(addr.Number);

            return cmd;

        }

        private static SqlCommand funTe2FindCmd(int id, SqlConnection sqlCon)
        {
            SqlCommand cmd = new SqlCommand("SELECT * FROM Adresa WHERE Id_adr = @Adr", sqlCon);

            cmd.Parameters.Add("@Adr", SqlDbType.Int);

            cmd.Parameters["@Adr"].Value = id;

            return cmd;
        }

        private static SqlCommand funTe2DelCmd(Address addr, SqlConnection sqlCon)
        {
            return null;
        }

        private static SqlCommand funTe2UpdCmd(Address addr, SqlConnection sqlCon)
        {
            return null;
        }
    }
}
