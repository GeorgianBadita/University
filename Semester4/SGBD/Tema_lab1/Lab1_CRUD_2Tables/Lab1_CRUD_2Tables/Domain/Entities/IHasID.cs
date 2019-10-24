using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_CRUD_2Tables.Domain.Entities
{
    /// <summary>
    /// Tid property
    /// </summary>
    /// <typeparam name="Tid"></typeparam>
    public interface IHasID<Tid>
    {
        Tid Id { get; set; }
    }
}
