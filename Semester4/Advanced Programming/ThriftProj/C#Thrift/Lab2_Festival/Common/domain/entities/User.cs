using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.domain.entities
{
    [Serializable]
    public class User
    {
        /// <summary>
        /// User class constructor
        /// </summary>
        /// <param name="id">id of the user</param>
        /// <param name="email">user's email</param>
        /// <param name="name">user's name</param>
        /// <param name="password">user's password</param>
        public User(int id, string email,
                    string name, string password)
        {
            this.Id = id;
            this.Name = name;
            this.Email = email;
            this.Password = password;
        }

        public User(string name, string password)
        {
            this.Name = name;
            this.Password = password;
            
        }

        ///
        /// Getters and setters
        ///
        public int Id { get; set; }
        public string Email { get; set; }
        public string Name { get; set; }
        public string Password { get; set; }

        /// <summary>
        /// Overriding equals method
        /// </summary>
        /// <param name="obj">object to be compared</param>
        /// <returns>true if the objects are equal, false otherwise</returns>
        public override bool Equals(object obj)
        {
            if (!(obj is User)) return false;

            var user = (User)obj;

            return user.Id == Id;
        }

        /// <summary>
        /// Overriding HashCode method
        /// </summary>
        /// <returns>hashcode value for the current object</returns>
        public override int GetHashCode()
        {
            var hashCode = 182800005;
            hashCode = hashCode * -1521134295 + Id.GetHashCode();
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Email);
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Name);
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Password);
            return hashCode;
        }

        public override string ToString()
        {
            return this.Name + " " + this.Password;
        }
    }
}
