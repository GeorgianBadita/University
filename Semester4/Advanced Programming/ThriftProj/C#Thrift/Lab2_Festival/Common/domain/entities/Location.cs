using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.domain.entities
{
    public class Location
    {
        /// <summary>
        /// Constructor for Location class
        /// </summary>
        /// <param name="id">location id</param>
        /// <param name="locName">location name</param>
        /// <param name="totalSeats">number of seats for the given locatio</param>
        public Location(int id, string locName, int totalSeats)
        {
            this.Id = id;
            this.LocName = locName;
            this.TotalSeats = totalSeats;
        }
        ///
        /// Getters and setters
        ///
        public int Id { get; set; }
        public string LocName { get; set; }
        public int TotalSeats { get; set; }


        /// <summary>
        /// Overriding equals method
        /// </summary>
        /// <param name="obj">object to be compared</param>
        /// <returns>true if the objects are equal, false otherwise</returns>
        public override bool Equals(object obj)
        {
            if (!(obj is Location)) return false;

            Location loc = (Location)obj;
            return loc.Id == Id;
        }

        /// <summary>
        /// Overriding hashCode function
        /// </summary>
        /// <returns>Integer value representing the hashCode for the current object</returns>
        public override int GetHashCode()
        {
            var hashCode = 1917924855;
            hashCode = hashCode * -1521134295 + Id.GetHashCode();
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(LocName);
            hashCode = hashCode * -1521134295 + TotalSeats.GetHashCode();
            return hashCode;
        }
    }
}
