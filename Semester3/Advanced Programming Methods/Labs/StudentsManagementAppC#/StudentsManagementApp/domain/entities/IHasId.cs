namespace StudentsManagementApp.domain.entities
{
   /// <summary>
   /// TId property
   /// </summary>
   /// <typeparam name="TId">Type of ID</typeparam>
    public interface IHasId<TId>
    {
        TId Id { get; set; }
    }
}