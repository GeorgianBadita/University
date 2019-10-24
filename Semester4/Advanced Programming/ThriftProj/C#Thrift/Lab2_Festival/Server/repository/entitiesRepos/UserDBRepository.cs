using Lab2_Festival.domain.entities;
using Lab2_Festival.domain.validators;
using Lab2_Festival.repository.dbUtils;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.repository.entitiesRepos
{
    public class UserDBRepository : ICRUDRepository<int, User>
    {
        private readonly IValidator<User> _validator;
        private readonly IDictionary<string, string> _props;


        public UserDBRepository(IDictionary<string, string> props, IValidator<User> validator)
        {
            this._props = props;
            this._validator = validator;

        }

        public User Delete(int id)
        {
            throw new NotImplementedException();
        }

        public IEnumerable<User> FindAll()
        {
            IList<User> users = new List<User>();

            var conn = DBUtil.GetConnection(_props);

            using(var comm = conn.CreateCommand())
            {
                comm.CommandText = "select * from user";

                using(var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        int userId = dataR.GetInt32(0);
                        string name = dataR.GetString(1);
                        string email = dataR.GetString(2);
                        string pass = dataR.GetString(3);

                        users.Add(new User(userId, email, name, pass));
                    }
                }
            }
            return users;
        }

        public User FindOne(int id)
        {
            throw new NotImplementedException();
        }

        public User Save(User e)
        {
            throw new NotImplementedException();
        }

        public int Size()
        {
            throw new NotImplementedException();
        }

        public User Update(User e)
        {
            throw new NotImplementedException();
        }
    }
}
