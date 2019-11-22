package ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.item

import android.app.Application
import android.util.Log
import androidx.lifecycle.*
import kotlinx.coroutines.launch
import ro.ubbcluj.cs.geo.myFirstAndroidApp.core.TAG
import ro.ubbcluj.cs.geo.myFirstAndroidApp.core.Result
import ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.data.Item
import ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.data.ItemRepository
import ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.data.local.TodoDatabase

class ItemEditViewModel(application: Application) : AndroidViewModel(application) {
    private val mutableFetching = MutableLiveData<Boolean>().apply { value = false }
    private val mutableCompleted = MutableLiveData<Boolean>().apply { value = false }
    private val mutableException = MutableLiveData<Exception>().apply { value = null }
    private val charPool : List<Char> = ('a'..'z') + ('A'..'Z') + ('0'..'9')

    val fetching: LiveData<Boolean> = mutableFetching
    val fetchingError: LiveData<Exception> = mutableException
    val completed: LiveData<Boolean> = mutableCompleted

    val itemRepository: ItemRepository

    init {
        val itemDao = TodoDatabase.getDatabase(application, viewModelScope).itemDao()
        itemRepository = ItemRepository(itemDao)
    }

    fun getItemById(itemId: String): LiveData<Item> {
        Log.v(TAG, "getItemById...")
        return itemRepository.getById(itemId)
    }

    fun saveOrUpdateItem(item: Item) {
        viewModelScope.launch {
            Log.v(TAG, "saveOrUpdateItem...");
            mutableFetching.value = true
            mutableException.value = null
            val result: Result<Item>
            if (item._id.isNotEmpty()) {
                result = itemRepository.update(item)
            } else {
                item._id = (1..16)
                    .map { kotlin.random.Random.nextInt(0, charPool.size) }
                    .map(charPool::get)
                    .joinToString("")
                result = itemRepository.save(item)
            }
            when(result) {
                is Result.Success -> {
                    Log.d(TAG, "saveOrUpdateItem succeeded");
                }
                is Result.Error -> {
                    Log.w(TAG, "saveOrUpdateItem failed", result.exception);
                    mutableException.value = result.exception
                }
            }
            mutableCompleted.value = true
            mutableFetching.value = false
        }
    }
}
