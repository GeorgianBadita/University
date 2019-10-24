using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Domain.Entities
{
    /// <summary>
    /// Address class
    /// relationship with Provider class (1-n) - parent table
    /// </summary>
    public class Address : IHasID<int>
    {

        /// <summary>
        /// Constructor for Address class
        /// </summary>
        /// <param name="id">Address id</param>
        /// <param name="city">Address city</param>
        /// <param name="street">Address street</param>
        /// <param name="number">Address number</param>
        public Address(int id, string city, string street, int number)
        {
            Id = id;
            City = city;
            Street = street;
            Number = number;
        }

        /// <summary>
        /// Get Id and Set Id implementations for the Address class
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        /// Get and Set mehtods for city
        /// </summary>
        public string City { get; set; }

        /// <summary>
        ///Get and Set methods for Street 
        /// </summary>
        public string Street { get; set; }

        /// <summary>
        /// Get and set methods for number
        /// </summary>
        public int Number { get; set; }

        /// <summary>
        /// Equals function override
        /// </summary>
        /// <param name="obj">object to be compared</param>
        /// <returns></returns>
        public override bool Equals(object obj)
        {
            if (!(obj is Address))
            {
                return false;
            }
            var addr = (Address)obj;
            return addr.Id.Equals(this.Id);
        }

        /// <summary>
        /// Overriding getHashCode method for address object
        /// </summary>
        /// <returns>hashcode for the given object</returns>
        public override int GetHashCode()
        {
            var hashCode = -2037618864;
            hashCode = hashCode * -1521134295 + Id.GetHashCode();
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(City);
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Street);
            hashCode = hashCode * -1521134295 + Number.GetHashCode();
            return hashCode;
        }
    }
}
