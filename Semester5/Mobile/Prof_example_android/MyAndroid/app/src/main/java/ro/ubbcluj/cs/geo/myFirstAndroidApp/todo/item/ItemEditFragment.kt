package ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.item

import android.app.AlertDialog
import java.lang.Integer.parseInt
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.Fragment
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import androidx.navigation.fragment.findNavController
import kotlinx.android.synthetic.main.item_edit_fragment.*
import kotlinx.android.synthetic.main.item_edit_fragment.fab
import kotlinx.android.synthetic.main.item_edit_fragment.progress
import kotlinx.android.synthetic.main.item_list_fragment.*
import ro.ubbcluj.cs.geo.myFirstAndroidApp.R
import ro.ubbcluj.cs.geo.myFirstAndroidApp.core.TAG
import ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.data.Item
import java.lang.NumberFormatException

class ItemEditFragment : Fragment() {

    companion object {
        const val ITEM_ID = "ITEM_ID"
    }

    private lateinit var viewModel: ItemEditViewModel
    private var itemId: String? = null
    private var item: Item? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        arguments?.let {
            if (it.containsKey(ITEM_ID)) {
                itemId = it.getString(ITEM_ID).toString()
            }
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        Log.v(TAG, "onCreateView")
        return inflater.inflate(R.layout.item_edit_fragment, container, false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
    }

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
        Log.v(TAG, "onActivityCreated")
        setupViewModel()

        fab.setOnClickListener {
            Log.v(TAG, "save item")
            val i = item
            if (i != null) {
                i.productname = item_productName.text.toString();
                val pr = item_price.text.toString()
                var numeric = true
                try{
                    parseInt(pr)
                }catch(e: NumberFormatException){
                    numeric = false
                }
                if(!numeric){
                    val dialogBuilder = AlertDialog.Builder(context);
                    // set message of alert dialog
                    dialogBuilder.setMessage("Sorry, price must be an integer!")
                        // if the dialog is cancelable
                        .setCancelable(false)

                        // negative button text and action
                        .setNegativeButton("Ok") { dialog, _ -> dialog.cancel()
                        }

                    // create dialog box
                    val alert = dialogBuilder.create()
                    // set title for alert dialog box
                    alert.setTitle("Wrong price!")
                    // show alert dialog
                    alert.show()


                }else {
                    i.price = item_price.text.toString().toInt();
                    Log.v(TAG, i._id);
                    viewModel.saveOrUpdateItem(i)
                }
            }
        }

        fab.setOnClickListener {
           findNavController().navigate(R.id.login_fragment)
        }
    }

    private fun setupViewModel() {
        viewModel = ViewModelProviders.of(this).get(ItemEditViewModel::class.java)
        viewModel.fetching.observe(this, Observer { fetching ->
            Log.v(TAG, "update fetching")
            progress.visibility = if (fetching) View.VISIBLE else View.GONE
        })
        viewModel.fetchingError.observe(this, Observer { exception ->
            if (exception != null) {
                Log.v(TAG, "update fetching error")
                val message = "Fetching exception ${exception.message}"
                val parentActivity = activity?.parent
                if (parentActivity != null) {
                    Toast.makeText(parentActivity, message, Toast.LENGTH_SHORT).show()
                }
            }
        })
        viewModel.completed.observe(this, Observer { completed ->
            if (completed) {
                Log.v(TAG, "completed, navigate back")
                findNavController().popBackStack()
            }
        })
        val id = itemId
        if (id == null) {
            item = Item("", "", 0)
        } else {
            viewModel.getItemById(id).observe(this, Observer {
                Log.v(TAG, "update items")
                if (it != null) {
                    item = it
                    item_productName.setText(it.productname)
                    item_price.setText(it.price.toString())
                }
            })
        }

    }

}
