package ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.items

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import androidx.recyclerview.widget.RecyclerView
import kotlinx.android.synthetic.main.item_view.view.*
import ro.ubbcluj.cs.geo.myFirstAndroidApp.R
import ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.data.Item
import ro.ubbcluj.cs.geo.myFirstAndroidApp.todo.item.ItemEditFragment

class ItemListAdapter(private val fragment: Fragment) : RecyclerView.Adapter<ItemListAdapter.ViewHolder>() {

    var items = emptyList<Item>()
        set(value) {
            field = value
            notifyDataSetChanged();
        }

    private var onItemClick: View.OnClickListener;

    init {
        onItemClick = View.OnClickListener { view ->
            val item = view.tag as Item
            fragment.findNavController().navigate(R.id.item_edit_fragment, Bundle().apply {
                putString(ItemEditFragment.ITEM_ID, item._id)
            })

        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.item_view, parent, false)
        return ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val item = items[position]
        holder.productName.text = item.productname
        holder.price.text = item.price.toString()
        holder.itemView.tag = item
        holder.itemView.setOnClickListener(onItemClick)
    }

    override fun getItemCount() = items.size

    inner class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val productName: TextView = view.productName
        val price: TextView = view.price
    }
}
