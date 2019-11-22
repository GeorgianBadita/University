package ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.data

import androidx.lifecycle.LiveData
import ro.ubbcluj.cs.geo.myFirstAndroidApp.core.Result
import ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.data.local.ItemDao
import ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.data.remote.ItemApi

class ItemRepository(private val itemDao: ItemDao) {

  val items = itemDao.getAll()

  suspend fun refresh(): Result<Boolean> {
    try {
      val items = ItemApi.service.find()
      for (item in items) {
        itemDao.insert(item)
      }
      return Result.Success(true)
    } catch(e: Exception) {
      return Result.Error(e)
    }
  }

  fun getById(itemId: String): LiveData<Item> {
    return itemDao.getById(itemId)
  }

  suspend fun save(item: Item): Result<Item> {
    try {
      val createdItem = ItemApi.service.create(item)
      itemDao.insert(createdItem)
      return Result.Success(createdItem)
    } catch(e: Exception) {
      return Result.Error(e)
    }
  }

  suspend fun update(item: Item): Result<Item> {
    try {
      val updatedItem = ItemApi.service.update(item._id, item)
      itemDao.update(updatedItem)
      return Result.Success(updatedItem)
    } catch(e: Exception) {
      return Result.Error(e)
    }
  }
}