using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Domain.Entities
{
    /// <summary>
    /// Provider class
    /// Relationship with Address class (1-n) - child table
    /// </summary>
    class Provider : IHasID<int>
    {
       /// <summary>
       /// Provider class constructor
       /// </summary>
       /// <param name="id">Provider id</param>
       /// <param name="name">Provider name</param>
       /// <param name="quant">Provider quantity</param>
       /// <param name="idAddr">Provider address reference</param>
        public Provider(int id, string name, int quant, int idAddr)
        {
            Id = id;
            Name = name;
            Quant = quant;
            IdAddr = idAddr;
        }


        /// <summary>
        /// Get Id and SetId mehtods for IHasID interface
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        /// Get and Set for name attribute
        /// </summary>
        public string Name { get; set; }
        
        /// <summary>
        /// Get and Set for Quantity attribute
        /// </summary>
        public int Quant { get; set; }

        /// <summary>
        /// Get and Set for IdAddr attribute
        /// </summary>
        public int IdAddr { get; set; }

        /// <summary>
        /// Overriding equals method
        /// </summary>
        /// <param name="obj">object to be compared</param>
        /// <returns></returns>
        public override bool Equals(object obj)
        {
            if(!(obj is Provider))
            {
                return false;
            }

            var provider = (Provider)obj;

            return provider.Id.Equals(this.Id);
        }

        /// <summary>
        /// Overriding the hashcode method
        /// </summary>
        /// <returns>hashcode for the current object</returns>
        public override int GetHashCode()
        {
            var hashCode = -1069102699;
            hashCode = hashCode * -1521134295 + Id.GetHashCode();
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Name);
            hashCode = hashCode * -1521134295 + Quant.GetHashCode();
            hashCode = hashCode * -1521134295 + IdAddr.GetHashCode();
            return hashCode;
        }
    }
}
