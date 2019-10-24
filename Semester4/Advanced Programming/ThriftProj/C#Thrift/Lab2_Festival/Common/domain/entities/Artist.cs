using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Festival.domain.entities
{
    public class Artist
    {
        /// <summary>
        /// Constructor for Artist class
        /// </summary>
        /// <param name="id">id of the artist</param>
        /// <param name="name">name of the artist</param>
        public Artist(int id, string name)
        {
            this.Id = id;
            this.ArtistName = name;
        }
        
        ///
        /// Gettesr and setters
        ///
        public int Id { get; set; }
        public string ArtistName { get; set; }

        /// <summary>
        /// Overriding equals method
        /// </summary>
        /// <param name="obj">object to be compared</param>
        /// <returns>true if the objects are equal, false otherwise</returns>
        public override bool Equals(object obj)
        {
            if (!(obj is Artist)) return false;
            var artist = (Artist)obj;
            return artist.Id == this.Id;
        }

        /// <summary>
        /// Overriding hashCode method
        /// </summary>
        /// <returns>integer representing the hashcode for the current element</returns>
        public override int GetHashCode()
        {
            var hashCode = 1183001917;
            hashCode = hashCode * -1521134295 + Id.GetHashCode();
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(ArtistName);
            return hashCode;
        }
    }
}
